//echoserv.c
#include <stdio.h>
#include <sys/socket.h>

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
	while(1) {
		clisock = accept(sockfd, (struct addrsock*) &cliaddr, clisocklen);
		if (clisock <= 0) {
			perror("accept");
			continue;
		}

		//handle a connection
		int len = read(clisock, buffer, 1024);
		if (len > 1024) {
			perror("read");
		}
		else {
			buffer[len] = '\0';
		}
		
		write(clisock, buffer, len);
	}

	return 0;
}