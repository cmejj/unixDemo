//servlisten.c
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>     //for sleep

#define PORT 9002

int main () 
{
    int ret;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (socket < 0) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;
    socklen_t addrlen;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    addr.sin_port = htons(PORT);
    
    ret = bind(sockfd, (struct sockaddr*) &addr, sizeof(addr));
    if (ret < 0) {
        perror("bind");
        exit(-1);
    }
    
    ret = listen(sockfd, 5);
    if (ret < 0) {
        perror("listen");
        exit(-1);
    }

    while(1) {
        sleep(1000);
    }

    printf("ok\n");

    return 0;
}
