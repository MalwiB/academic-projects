#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define LISTEN_BACKLOG 50

void report_error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int isnum(char* s) {
    int len = strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(!isdigit(s[i]))
            return 0;
    }
    return 1;
}

//argv[1] - sleep time
int main(int argc, char* argv[]) {

    if(argc != 2) {
        report_error("Arguments error");
    }
    
    if(!isnum(argv[1]))
        report_error("Sleep time must be number");
    
    int sleep_time = atoi(argv[1]);
    
    struct sockaddr_in addr, addr_get;
    
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

    int size_buff = 131072;
    char buffer[size_buff];
    
    int sock_get = accept(sockfd, (struct sockaddr *) &addr_get, (socklen_t *) &size_addr_get);
    if(sock_get == -1) {
        report_error("Accept error");
    }

    while(1) {
        int read_flag = 0;
        int size_r, i;
        int bits_sum = 0;
        size_r = read(sock_get, buffer, size_buff);
        if(size_r > 0) {
            fputs("Rozpoczeto odbieranie danych od klienta.\n", stdout);
            do {
                printf("Odebrano %d bitow.\n",size_r);
                bits_sum += size_r;
                sleep(sleep_time);
                size_r = read(sock_get, buffer, size_buff);
                if (size_r == -1) {
                    report_error("Read error");
                }
            } while(size_r > 0);
            fputs("Zakonczono odbieranie danych od klienta.\n", stdout);
        }
    }
}
