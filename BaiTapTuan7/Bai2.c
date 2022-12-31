#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int fp1[2], fp2[2], pid;
	if(argc < 4){
		printf("Doi so thieu.\n");
		return -1;
	}
	if(pipe(fp1) == 0 && pipe(fp2) == 0){
		pid = fork();
		if(pid < 0) printf("Fork failed.\n");
		else if(pid == 0){
			int i, so1, so2;
			float kq; 
			char tam[100];

			close(fp1[1]);
			read(fp1[0], tam, strlen(tam));			

			char str1[2] = {tam[0], '\0'};
			char str2[2] = {tam[1], '\0'};
			char str3[2] = {tam[2], '\0'};
			so1 = atoi(str1);
			so2 = atoi(str2);

			if(strcmp(str3, "+") == 0) kq = so1 + so2;
			else if(strcmp(str3, "-") == 0) kq = so1 - so2;
			else if(strcmp(str3, "x") == 0) kq = so1 * so2;
			else if(strcmp(str3, "/") == 0) kq = (float)so1 / so2;

			
			close(fp2[0]);
			write(fp2[1], &kq, sizeof(kq));
			
		}else{
			float kq;
			close(fp1[0]);

			write(fp1[1], argv[1], strlen(argv[1]));
			write(fp1[1], argv[2], strlen(argv[2]));
			write(fp1[1], argv[3], strlen(argv[3]));


			close(fp2[1]);
			read(fp2[0], &kq, sizeof(kq));
			
			printf("%f\n", kq);
		}
	} 
	else printf("pipe failed.\n");
	return 0;
}









































