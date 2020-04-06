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
    if(error_code == '5' || error_code == '4')
        exit(1);
    return 1;
}


int main() {
    
    struct sockaddr_in addr;
    
    memset(&addr, 0, sizeof(addr));
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(25);
    char address[16] = "213.199.154.42";
    addr.sin_addr.s_addr = inet_addr(address);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        report_error("Socket error");
    }

    int connectfd = connect(sockfd, (struct sockaddr*) &addr, sizeof(addr));
    if (connectfd == -1) {
        report_error("Connect error");
    }
    
    receive_response(sockfd);
    
    char* helo = "student.uj.edu.pl";
    char* from = "malwina.borysionek@student.uj.edu.pl";
    char* to = "malwina.borysionek@student.uj.edu.pl";
    char* subject = "Test";
    if(!(isalphanumpunct(helo) && isalphanumpunct(from) && isalphanumpunct(to) && isalphanumpunct(subject))) {
        report_error("Arguments error");
    }
    
    send_command(sockfd, "helo ", helo);
    receive_response(sockfd);
    
    send_command(sockfd, "MAIL FROM:", from);
    receive_response(sockfd);
    
    send_command(sockfd, "RCPT TO:", to);
    receive_response(sockfd);
    
    send_command(sockfd, "DATA", "");
    receive_response(sockfd);
    
    send_command(sockfd, "From: ", from);
    
    send_command(sockfd, "To: ", to);
    
    send_command(sockfd, "Subject: ", subject);
    
    send_command(sockfd, "", "");
    
    char* message = "Wiadomosc tekstowa.";
    
    send_command(sockfd, "", message);

    if(write(sockfd, ".\r\n", sizeof(".\r\n")) == -1) {
        report_error("Write error");
    }
    receive_response(sockfd);
    send_command(sockfd, "QUIT", "");
    receive_response(sockfd);
    
    return 0;
}
