#include <stdio.h>
#include <stdlib.h> // exit, EXIT_FAILURE
#include <ctype.h>  // isprint
#include <unistd.h>  // read
#include <sys/socket.h>  // socket, connect, accept
// #include <sys/types.h>
// "POSIX.1-2001 does not require the inclusion of <sys/types.h>,
// and this header file is not required on Linux. However, some historical (BSD) implementations required
// this header file, and portable applications are probably wise to include it."
#include <netinet/in.h>  // sock_addr_in
#include <arpa/inet.h>  // htons
// "Some systems require the inclusion of <netinet/in.h> instead of <arpa/inet.h>."

const int BUFFER_SIZE = 100;
char BUFFER[BUFFER_SIZE];

void report_error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int read_from_sock(int sockfd) {
    int size_r = read(sockfd, buffer, size);
    if (size_r == -1) {
        report_error("Read error");
    }
    int i = 0;
    for(i=0; i<size_r; i++) {
        if(isprint(buffer[i]))
            putchar(buffer[i]);
    }
    fflush(stdout);

    return size_r;
}

int main(int argc, char* argv[]) {

    if(argc != 3) {
        report_error("Arguments error");
    }

    struct sockaddr_in addr_ssh;
    addr_ssh.sin_family = AF_INET;
    addr_ssh.sin_port = htons(atoi(argv[2]));
    addr_ssh.sin_addr.s_addr = inet_addr(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        report_error("Socket error");
    }

    int connectfd = connect(sockfd, (struct sockaddr*)&addr_ssh, sizeof(addr_ssh));
    if (connectfd == -1) {
        report_error("Connect error");
    }

    int size_r = 0;
    do{
        size_r = read_from_socket(sockfd);
    } while (size_r >= BUFFER_SIZE);
    printf("\n");
    
    return 0;
}
