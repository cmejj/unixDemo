#include <stdio.h>
#include <arpa/inet.h>

union Int {
	char data[4];
	int x;
};

int main () 
{
	union Int a;
	union Int b;

	a.x = 0x10203040;
	b.x = htonl(a.x);

	printf("a = 0x%08x\n", a.x);
	int i;
	for (i = 0; i < 4; ++i) {
		printf("[%p]: %02x\n", a.data + i, a.data[i]);
	}

	
	printf("b = 0x%8x\n", b.x);
	for (i = 0; i < 4; ++i) {
		printf("[%p]:%02x\n", b.data + i, b.data[i]);
	}

	return 0;
}
