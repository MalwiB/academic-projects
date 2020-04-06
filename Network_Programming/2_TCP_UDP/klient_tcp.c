#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

//argv[1] - bits, argv[2] - sleep time
int main(int argc, char* argv[]) {

    if(argc != 3) {
        report_error("Arguments number error");
    }
    
    if(!(isnum(argv[1]) && isnum(argv[2])))
        report_error("Bits number and sleep time must be numbers");
    
    int bits = atoi(argv[1]);
    int sleep_time = atoi(argv[2]);
    
    struct sockaddr_in addr;
    
    memset(&addr, 0, sizeof(addr));
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("Socket error");
        exit(1);
    }

    int connectfd = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (connectfd == -1) {
        perror("Connect error");
        exit(1);
    }

    char znak = 'A';
    int size = bits/sizeof(znak);
    char buffer[size];
    memset(buffer, znak, size);
    
    int i;
    for(i=0; i<3; i++) {
        fputs("Sending data to serwer begins.\n", stdout);
        if(write(sockfd, buffer, size) == -1) {
            report_error("Write error");
        }
        printf("Sending %d bits..\n", size);
        fputs("Data sent.\n\n", stdout);
        sleep(sleep_time);
    }
    return 0;
}
