//echoserv.c
#include <stdio.h>
#include <sys/socket.h>	//for socket etc.
#include <netinet/in.h> //for sockaddr_in
#include <arpa/inet.h> 	//for inet_addr etc.
#include <stdlib.h>		//for exit
#include <unistd.h> 	//for read write

#define PORT 9002

int main () {
	int ret;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	addr.sin_port = htons(PORT);

	ret = bind(sockfd, (struct sockaddr*) &addr, sizeof(addr));
	if (ret < 0) {
		perror("bind");
	}

	ret = listen(sockfd, 100);
	if (ret < 0) {
		perror("listen");
	}

	struct sockaddr_in cliaddr;
	socklen_t clisocklen;
	int clisock;
	
	char buffer[1024];

	clisock = accept(sockfd, (struct sockaddr*) &cliaddr, &clisocklen);
	if (clisock <= 0) {
		perror("accept");
	}

	//handle a connection
	int len = read(clisock, buffer, 1024);
	if (len > 1024) {
		perror("read");
		exit(-1);
	}
		
	buffer[len] = '\0';
	printf("%s:%d  %s", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), buffer);
		
	write(clisock, "hello world!", 13);

	return 0;
}