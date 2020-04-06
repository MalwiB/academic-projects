#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "find_mx.h"

void report_error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void check_error_code(int code) {
    if(code == '5' || code == '4')
        exit(EXIT_FAILURE);
}

int isalphanumpunct(char* s) {
    int i;
    for(i=0; i<strlen(s); i++)
        if(!(isalnum(s[i]) || ispunct(s[i])))
            return 0;
    return 1;
}

void send_command(int sockfd, char* command, char* arg) {
    int size = 200;
    char conc_command[size];
    strcpy(conc_command, command);
    strcat(conc_command, arg);
    strcat(conc_command, "\r\n");
    printf("%s", conc_command);
    if(write(sockfd, conc_command, strlen(conc_command)) == -1) {
        report_error("Write error");
    }
}

int receive_response(int sockfd) {
    int size_r, size=20, i;
    char buffer[size+1];
    char error_code;
    size_r = read(sockfd, buffer, size);
    for(i=0; i<size_r; i++) {
        putchar(buffer[i]);
    }
    fflush(stdout);
    if (size_r == -1) {
        report_error("Read error");
    }
    if(size_r > 0) {
        error_code = buffer[0];
    }
    do {
        size_r = read(sockfd, buffer, size);
        if (size_r == -1) {
            report_error("Read error");
        }
        for(i=0; i<size_r; i++) {
            putchar(buffer[i]);
        }
        fflush(stdout);
    } while(size_r >= size);
    printf("\n");
    return error_code;
}

int main(int argc, char* argv[]) {
    int i;
    for(i=0;i < argc - 1; i++) {
        
        struct sockaddr_in addr;
        struct in_addr* addr_tab;
        
        char* to = argv[i+1];
        
        memset(&addr, 0, sizeof(addr));
        
        printf("Checking: %s\n", to);
        
        char* domain = strchr(to, '@') + 1;
        if(domain == NULL)
            report_error("Invalid email address (strchr)");
        printf("Domain: %s\n", domain);
        
        addr_tab = find_mail_exchanges(domain);
        
        addr.sin_family = AF_INET;
        addr.sin_port = htons(25);
        if(addr_tab[0].s_addr == INADDR_ANY)
            report_error("No addresses");
        char buf[INET_ADDRSTRLEN];
        if (inet_ntop(AF_INET, addr_tab, buf, sizeof(buf)) == NULL) {
            report_error("inet_ntop error");
        }
        printf("Address: %s\n", buf);
        addr.sin_addr.s_addr = inet_addr(buf);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1){
            report_error("Socket error");
        }

        int connectfd = connect(sockfd, (struct sockaddr*) &addr, sizeof(addr));
        if (connectfd == -1) {
            report_error("Connect error");
        }
                
        int error_code;
        
        error_code = receive_response(sockfd);
        check_error_code(error_code);
        
        char* from = "malwina.borysionek@student.uj.edu.pl";
        if(!(isalphanumpunct(from) && isalphanumpunct(to))) {
            report_error("Arguments error");
        }
        
        send_command(sockfd, "helo ", domain);
        error_code = receive_response(sockfd);
        check_error_code(error_code);
        
        send_command(sockfd, "MAIL FROM:", from);
        error_code = receive_response(sockfd);
        check_error_code(error_code);
        
        send_command(sockfd, "RCPT TO:", to);
        error_code = receive_response(sockfd);
        if(error_code == '5' || error_code == '4')
            printf("Invalid email address\n");
        else
            printf("Valid email address\n");
        
        send_command(sockfd, "QUIT", "");
        error_code = receive_response(sockfd);
        check_error_code(error_code);
        
        free(addr_tab);
    }
    
    return 0;
}
