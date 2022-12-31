#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	printf("Id tien trinh hien tai: %d\n", getpid());
	printf("Id tien trinh cha cua tien trinh hien tai: %d\n", getppid());

	pid_t pid = fork();
	if(pid == 0){
		printf("\nThan chuong trinh con\n");
		printf("Id tien trinh con: %d\n", getpid());
		printf("Id tien trinh cha cua no: %d\n", getppid());
	}
	else{
		if(pid > 0){
			wait(NULL);
			printf("\nThan chuong trinh cha\n");
			printf("Id tien trinh cha: %d\n", getpid());
			printf("Id tien trinh cha cua no: %d\n", getppid());
		}else{
			printf("Khong the tao tien trinh moi!!!\n");
		}
	}
	
	return 0;
}
