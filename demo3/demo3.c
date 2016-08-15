#include "apue.h"
#include <errno.h>

/*
this is a demo of errno using.
@aythor: Kingchin
*/

int main(int argc,char* argv[]){

	fprintf(stderr,"EACCES: %s\n",strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	
	return 0;
}
