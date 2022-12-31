#include <stdio.h>

int isNumberCheck(char s[]){
	int i = 0;
	if(s[0]=='-' && s[1]=='\0') return 0;
	if(s[0]=='-' && s[1]!='\0') i++;
	while(s[i]!='\0'){
		if((int)s[i]<48 || 57<(int)s[i])
			return 0;
		i++;
	}
	return 1;
}

int main(int argc, char **argv){
	if(argc != 4){
		printf("Doi so truyen vao khong dung\n");
	}
	else {
		if(isNumberCheck(argv[1]) == 1 && isNumberCheck(argv[2]) == 1 && (argv[3][0] == '+' || argv[3][0] == '-') ){
			int a = atol(argv[1]);
			int b = atol(argv[2]);

			if(argv[3][0] == '+'){
				printf("%d\n",add(a,b));
			}
			else if(argv[3][0] == '-'){
				printf("%d\n",sub(a,b));
			}
		}
		else printf("Doi so truyen vao khong dung\n");
	}		
	return 0; 
}
