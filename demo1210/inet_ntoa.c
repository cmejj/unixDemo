#include <stdio.h>
#include <arpa/inet.h>

int main () {
	
	struct in_addr addr;
	addr.s_addr = 0;
	
	scanf("%x", &addr.s_addr);
	printf("%s\n", inet_ntoa(addr));	

	return 0;
}
