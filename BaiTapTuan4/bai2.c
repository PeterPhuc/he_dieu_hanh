#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>


int main(){
	pid_t pid;
	int status;

	pid = fork();
	if(pid > 0){
		printf("Day la tien trinh cha %d\n", getpid());
		sleep(10);
		exit(0);
	}else{
		if(pid == 0){
			printf("Day la tien trinh con %d\n", getpid());
			exit(0);
		}else{
			printf("error \n");
		}
	}
	return 0;
}
