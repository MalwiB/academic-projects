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

    struct sockaddr_in addr, addr_other;

    memset(&addr_other, 0, sizeof(addr_other));
    
    addr_other.sin_family = AF_INET;
    addr_other.sin_port = htons(8888);
    addr_other.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1){
        perror("Socket error");
        exit(1);
    }
    
    char znak = 'A';
    int buffer_size = bits/sizeof(znak);
    char buffer[buffer_size];
    
    memset(buffer, znak, buffer_size);
    
    int i;
    for(i=0; i<3; i++) {
        fputs("Sending data to serwer begins.\n", stdout);
        if(sendto(sockfd, buffer, buffer_size, 0, (struct sockaddr *) &addr_other, sizeof(addr_other)) == -1) {
            report_error("Sendto error");
        }
        printf("Sending %d bits.\n", buffer_size);
        fputs("Data sent.\n\n", stdout);
        sleep(sleep_time);
    }
    return 0;
}
