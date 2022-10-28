#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int giaithua(int n){
	int i, s = 1;
	for(i = 1; i <= n; i++){
		s *= i;
	}
	return s;
}

int main(int argc, char *argv[]){
	int fp1[2], fp2[2], pid;
	if(argc < 2){
		printf("Doi so thieu.\n");
		return -1;
	}
	if(pipe(fp1) == 0 && pipe(fp2) == 0){
		pid = fork();
		if(pid < 0) printf("Fork failed.\n");
		else if(pid == 0){
			int n, kq;
			close(fp1[1]);
			read(fp1[0], &n, sizeof(n));
			
			kq = giaithua(n);
			
			close(fp2[0]);
			write(fp2[1], &kq, sizeof(kq));
			
		}else{
			int n = atoi(argv[1]), kq;
			if(n <= 3){
				printf("Doi so phai lon hon 3\n");
				exit(0);
			}
			close(fp1[0]);
			write(fp1[1], &n, sizeof(n));

			close(fp2[1]);
			read(fp2[0], &kq, sizeof(kq));

			printf("%d! = %d\n", n, kq);
		}
	} 
	else printf("pipe failed.\n");
	return 0;
}









































