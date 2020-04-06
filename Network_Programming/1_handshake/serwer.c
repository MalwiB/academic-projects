#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define LISTEN_BACKLOG 50

void report_error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
        report_error("Arguments error");
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));

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

    struct sockaddr_in addr_get;

    char * message = "Hello world!\r\n";

    while(1) {
        int size = sizeof(addr_get);
        int sock_get = accept(sockfd, (struct sockaddr *) &addr_get, (socklen_t*)&size);
        if(sock_get == -1) {
            report_error("Accept error");
        }

        if(write(sock_get, message, strlen(message)) == -1) {
            report_error("Write error");
        }
    }
}
