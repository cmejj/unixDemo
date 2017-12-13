//echocli.c
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define SERVPORT 9002

int main ()
{
	int ret;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in addr;
	socklen_t socklen;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVPORT);

	ret = connect(sockfd, (struct sockaddr*) &addr, sizeof (addr));
	if (ret < 0) {
		perror("connect");
		exit(-1);
	}

	char buffer[1024];
	write(sockfd, "hello world!", 13);
	int len = read(sockfd, buffer, 1024);
	buffer[len] = '\0';

	printf("receive from server:%s", buffer);
	return 0;
}