#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>

#define MAX_EVENTS 20
#define LISTEN_BACKLOG 50


void report_error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
 
    struct sockaddr_in addr, addr_get;
    struct epoll_event event, events[MAX_EVENTS];
    
    memset((char *) &addr, 0, sizeof(addr));
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8888);
    
    int size_addr_get = sizeof(addr_get);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        report_error("Socket error");
    }

    if(bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        report_error("Bind error");
    }
    
    if(listen(sockfd, LISTEN_BACKLOG) == -1) {
        report_error("Listen error");
    }
    
    // tworzenie instancji epoll i zwrocenie deskryptora
    int eventfd = epoll_create1(0);
    if(eventfd == -1){
        report_error("Epoll error");
    }
    
    event.data.fd = sockfd;
    // EPOLLIN - wskazuje, ze ze zrodla/deskryptora bedziemy odczytywac
    // EPOLLET - wyzwalanie zboczem
    event.events = EPOLLIN | EPOLLET;
    
    // epoll_ctl jest interfejsem do epoll
    // za pomoca epoll_ctl mozna dodawac deskryptory do obserwowania i laczyc z nimi wydarzenia
    if(epoll_ctl(eventfd, EPOLL_CTL_ADD, sockfd, &event) == -1) {
        report_error("Epoll_ctl add error");
    }
    
    int nfds, sock_get;
    int size_buff = 100;
    char buffer[size_buff];
    
    while(1) {
        printf("\tWaiting for events...\n");
        nfds = epoll_wait(eventfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            report_error("Epoll_wait error");
        }
        int i;
        for(i=0; i<nfds; i++) {
            // mamy przychodzace polaczenia, nalezy dodac je do zbioru obserwowanych deskryptorow
            if (events[i].data.fd == sockfd) {
                sock_get = accept(sockfd, (struct sockaddr *) &addr_get, (socklen_t *) &size_addr_get);
                printf("Connected with client %d.\n", sock_get);
                if(sock_get == -1) {
                    report_error("Accept error");
                }
                // poniższy kod ustawia gniazdo na nie blokujące
                // gdy ustawimy gniazdo na nie blokujace, bedzie ono w stanie przerwac operacje np. laczenia
                // w wypadku, gdy mamy wiele socketow, uzycie nie blokujacych gniazd skutkuje to tym, ze zadne z nich nie moze zablokowac wykonywania programu
                int status = fcntl(sock_get, F_SETFL, fcntl(sock_get, F_GETFL, 0) | O_NONBLOCK);
                if (status == -1) {
                    report_error("fcntl error");
                }
                
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = sock_get;
                if (epoll_ctl(eventfd, EPOLL_CTL_ADD, sock_get, &event) == -1) {
                    report_error("epoll_ctl add error");
                }
            }
            // w innym przypadku wydarzeniem jest otrzymanie danych z gniazda
            // dane sa odczytywane i wyswietlana jest ilosc otrzymanych bitow danych
            else {
                int size_r;
                int bits_sum = 0;
                int end = 0;
                size_r = read(events[i].data.fd, buffer, size_buff);
                if(size_r > 0) {
                    printf("Receiving data from client %d: ", events[i].data.fd);
                    do {
                        printf("%d bits received.\n",size_r);
                        bits_sum += size_r;
                        size_r = read(events[i].data.fd, buffer, size_buff);
                        if (size_r == -1) {
                             if (errno != EAGAIN) {
                                 end = 1;
                                 report_error("Read error");
                             }
                            break;
                        }
                        if (size_r == 0) {
                            end = 1;
                        }
                    } while(size_r >= 0);
                    if(end == 1) {
                        // usuwanie deskryptora gniazda z obserwowanych wydarzen
                        if (epoll_ctl(eventfd, EPOLL_CTL_DEL, events[i].data.fd, &event) == -1) {
                            report_error("epoll_ctl delete error");
                        }
                        close(events[i].data.fd);
                    }
                }
            }
        }
    
    }
    
    close(sockfd);

}
