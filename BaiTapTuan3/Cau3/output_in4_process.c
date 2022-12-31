#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void ProcessInfo(){
	printf("Thong tin tien trinh hien tai: %d\n", getpid());
	printf("Thong tin tien trinh cha cua no: %d\n", getppid());
}


int main(){
	printf("Id tien trinh hien tai: %d\n", getpid());
	pid_t pid = fork();
	if(pid == 0){
		printf("\nB\n");
		ProcessInfo();
	}
	else{
		pid_t pid2 = fork();
		if(pid2 == 0){
			printf("\nC\n");
			ProcessInfo();
		}else{
			wait(NULL);
			printf("\nA\n");
		}
	}

/*	pid_t pidA1 = fork(); 
	pid_t pidA2 = fork(); 

	if(pidA1 == 0){
		pid_t pidB1 = fork(); 
		pid_t pidB2 = fork(); 
		if(pidB1 == 0){
			printf("\nD\n");
			exit(0);
		}
		else if(pidB2 == 0){
			printf("\nE\n");
			exit(0);
		}
		else{
			wait(NULL);
			printf("\nB\n");
			exit(0);
		}
		exit(0);
	}	


	else if(pidA2 == 0){
		pid_t pidC = fork(); 
		if(pidC == 0){
			printf("\nH\n");
			exit(0);
		}else{
			wait(NULL);
			printf("\nC\n");
			exit(0);
		}
		exit(0);
	}


	else{
		wait(NULL);
		printf("\nA\n");
	}
*/

	
	return 0;
}
