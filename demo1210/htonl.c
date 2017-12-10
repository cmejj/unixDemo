#include <stdio.h>
#include <arpa/inet.h>

int main () {

	int host;
	scanf("%x", &host);
	printf("0x%08x\n", htonl(host));
	return 0;
}
