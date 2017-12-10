#include <arpa/inet.h>
#include <stdio.h>

int main () {

	struct in_addr addr;
	char ip[16] = {0};	
	scanf("%s", ip);
	
	if (0 == inet_aton(ip, &addr)) {
		fprintf(stderr, "Invalid address\n");	
		return 1;
	}

	printf("0x%08x\n", addr.s_addr);
	
	return 0;
}
