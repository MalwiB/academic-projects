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
        report_error("Arguments number error");
    }
    
    if(!isnum(argv[1]))
        report_error("Sleep time must be number");
    
    int sleep_time = atoi(argv[1]);

    struct sockaddr_in addr, addr_other;
    
    memset((char *) &addr, 0, sizeof(addr));
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8888);

    socklen_t other_size = sizeof(addr_other);
    
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1){
        report_error("Socket error");
    }

    if(bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        report_error("Bind error");
    }

    int size_buff = 4096;
    char buffer[size_buff];

    while(1) {
        int size_r, i;
        int bits_sum = 0;
        size_r = recvfrom(sockfd, buffer, size_buff, 0, (struct sockaddr *) &addr_other, &other_size);
        if(size_r > 0) {
            fputs("Receiving data from client begins.\n", stdout);
            do {
                printf("Received %d bits.\n",size_r);
                bits_sum += size_r;
                sleep(sleep_time);
                size_r = recvfrom(sockfd, buffer, size_buff, 0, (struct sockaddr *) &addr_other, &other_size);
                if (size_r == -1) {
                    report_error("Revfrom error");
                }
            } while(size_r > 0);
            fputs("Data received.\n", stdout);
        }
    }
}
