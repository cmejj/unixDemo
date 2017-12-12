#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>


int main () 
{
	int sockfd, ret;
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	socklen_t cliaddrlen;

	//配置服务端socket地址
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8080);
	//创建client socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		exit(-1);
	}
	//发起连接请求
	ret = connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
	if (ret < 0) {
		perror("connect");
		exit(-1);
	}
	//查看client socket地址
	cliaddrlen =sizeof (cliaddrlen);
	ret = getsockname(sockfd, (struct sockaddr*) &cliaddr, &cliaddrlen);
	if (ret < 0) {
		perror("getsockname");
		exit(-1);		
	}
	printf("%s : %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddrlen.sin_port));

	return 0;
}