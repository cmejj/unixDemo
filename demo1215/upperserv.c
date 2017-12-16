//upperserv.c

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 9002
#define MAXSIZE 1024

void handle(int sock);
void upper(char *buufer, size_t size);

int main () {
	
	int ret;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		exit(-1);
	}
	
	struct sockaddr_in addr;
	socklen_t len;
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

	struct sockaddr_in cliaddr;
	socklen_t clilen;
	int clisock;

	clisock = accept(sockfd, (struct sockaddr*) &cliaddr, &clilen);
	if (clisock < 0) {
		perror("accept");
		exit(-1);
	}

	printf("client addr:%s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

	ret = getsockname(clisock, (struct sockaddr*) &cliaddr, &clilen);
	if (ret < 0) {
		perror("getsockname");
		exit(-1);
	}

	printf("client addr:%s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

	handle(clisock);

	return 0;
}

void handle(int sock)
{
	char buffer[MAXSIZE];
	ssize_t size;
	size = read(sock, buffer, MAXSIZE);
	if (size < 0) {
		perror("handle error");
		exit(-1);
	}

	buffer[size] = 0;
	printf("receive from client:%s\n", buffer);
	upper(buffer, size);

	write(sock, buffer, size);
}

void upper(char *buffer, size_t size)
{
	int i = 0;
	for (i = 0; i < size; ++i) {
		buffer[i] = toupper(buffer[i]);
	}
}