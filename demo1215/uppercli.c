//uppercli.c

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 9002
#define MAXSIZE 1024

int main()
{
	int ret;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in servaddr;
	socklen_t servlen;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
	if (ret < 0) {
		perror("connect");
		exit(-1);
	}

	write(sockfd, "Hello world", 11);

	char buffer[MAXSIZE];
	ssize_t size = read(sockfd, buffer, MAXSIZE);
	if (size < 0) {
		perror("read");
		exit(-1);
	}

	buffer[size] = '\0';

	printf("receive from server:%s\n", buffer);

	return 0;
}