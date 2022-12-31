#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void ProcessInfo(){
	printf("Thong tin tien trinh hien tai: %d\n", getpid());
	printf("Thong tin tien trinh cha cua no: %d\n", getppid());
}

int main(){
	pid_t pidA1 = fork();
	if(pidA1 == 0){
		pid_t pidB1 = fork();
		if(pidB1 == 0){
			printf("\nD\n");
			ProcessInfo();
			exit(0);
		}else{
			wait(NULL);
			pid_t pidB2 = fork();
			if(pidB2 == 0){
				printf("\nE\n");
				ProcessInfo();
				exit(0);
			}else{
				wait(NULL);
				printf("\nB\n");
				ProcessInfo();
				exit(0);
			}
		}
	}else{
		wait(NULL);
		pid_t pidA2 = fork();
		if(pidA2 == 0){
			pid_t pidC = fork();
			if(pidC == 0){
				printf("\nH\n");
				ProcessInfo();
				exit(0);
			}else{
				wait(NULL);
				printf("\nC\n");
				ProcessInfo();
				exit(0);
			}
		}else{
			wait(NULL);
			printf("\nA\n");
			ProcessInfo();
		}
	}
	
	return 0;
}











































