//clilisten.c
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVPORT 9002

int main () 
{
    int ret;
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(SERVPORT);

    ret = connect(sockfd, (struct sockaddr*) &servaddr, sizeof (servaddr));
    if (ret < 0 ) {
        perror("connect");
        exit(-1);
    }

    printf("connect successful\n");
    return 0;
}
