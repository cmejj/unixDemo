#include <stdio.h>
#include <arpa/inet.h>

int main () {

	int net, host;
	struct in_addr addr;
	
	scanf("%x %x", &net, &host);
	addr = inet_makeaddr(net, host);
	printf("0x%08x\n", addr.s_addr);
	return 0;
}
