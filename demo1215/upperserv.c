//upperserv.c

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 9002
#define MAXSIZE 1024

void handle(int sock);

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
	while(1) {
		clisock = accept(sockfd, (struct sockaddr*) &cliaddr, &clilen);
		if (clisock < 0) {
			perror("accept");
			continue;
		}

		upperHandle(clisock);
	}

	return 0;
}

void handle(int sock)
{
	char buffer[MAXSIZE];
	size_t size;
	size = read(sock, buffer, MAXSIZE);
	if ()
}