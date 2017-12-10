#include <stdio.h>
#include <arpa/inet.h>

int main () {
	
	char ip[16] = {0};
	scanf("%s", ip);

	printf("0x%08x\n", inet_addr(ip));
	return 0;
}
