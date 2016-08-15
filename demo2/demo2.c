#include "apue.h"
#include <sys/wait.h>

/*writing by Kingchin*/

int main(){

	char	buf[MAXLINE];	//from apue.h
	pid_t	pid;
	int	status;

	printf("%% ");		/*print prompt (printf requirs %% to print %)*/
	while(fgets(buf,MAXLINE,stdin) != NULL){
		if(buf[strlen(buf) - 1] == '\n'){
			buf[strlen(buf) - 1] = 0; /*replace new line with null*/
		}
		
		
		if((pid = fork()) < 0){
			err_sys("fork error");
		}
		else if(pid == 0){	/*child process*/
			execlp(buf, buf, (char*) 0);
			err_ret("coludn't execute: %s",buf);
			exit(127);
		}

		
		/*parent's process*/
		if((pid = waitpid(pid, &status, 0)) < 0){
			err_sys("waitpid error");
		}
		printf("%% ");

	}
	exit(0);

	return 0;
}
