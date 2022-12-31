#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(argc > 2) printf("\nQua nhieu doi so!!!\n");
	else if(argc <= 1) printf("\nVui long nhap doi so!!!\n");
	else {
		int n = atoi(argv[1]), S = 0;
		pid_t pid = fork();
		if(pid == 0){
			int i;
			for(i = 1; i <= n; i++){
				if(n%i == 0) S+=i;
			}
			printf("\nS1 = %d\n", S);
			printf("Thong tin tien trinh hien tai: %d\n", getpid());
			printf("Thong tin tien trinh cha cua no: %d\n", getppid());
		}
		else{
			//wait(NULL);
			int i;
			for(i = 1; i <= n; i++){
				S+=i;
			}
			printf("\nS2 = %d\n", S);
			printf("Thong tin tien trinh hien tai: %d\n", getpid());
			printf("Thong tin tien trinh cha cua no: %d\n", getppid());
		}
	}
	return 0;
}
