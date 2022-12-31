#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
struct arr {
	int n;
};

int ktsnt(int n){
	if(n < 2) return 0;
	else{
		int i;
		double sqrt_n = n/2;
		for(i = 2; i <= sqrt_n; i++){
			if(n % i == 0) return 0;
		}
		return 1;
	}
}
void* thrl(void* ar){
	struct arr *ap = (struct arr*) ar;
	int i;
	for(i = 2; i <= ap->n; i++){
		if(ktsnt(i)){
			printf("%d ", i);
		}
	}
	printf("\n");
	sleep(1);
}

int main(int argc, char* argv[]){
	struct arr ar;
	ar.n = atoi(argv[1]);
	
	pthread_t tid;
	pthread_create(&tid, NULL, &thrl, &ar);

	sleep(1);
	return 0;
}
























