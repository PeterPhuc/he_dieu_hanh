#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

float tbc;
int max, min;

struct arr {
	int n;
	int a[100];
};

void* thrl1(void* ar){
	struct arr *ap = (struct arr*) ar;
	int i, sum = 0;
	for(i = 0; i < ap->n; i++){
		sum += ap->a[i];
	}
	tbc = (float)sum/ap->n;
	sleep(1);
}

void* thrl2(void* ar){
	struct arr *ap = (struct arr*) ar;
	int i;
	max = ap->a[0];
	for(i = 1; i < ap->n; i++){
		if(max < ap->a[i]){
			max = ap->a[i];
		}
	}
	sleep(1);
}

void* thrl3(void* ar){
	struct arr *ap = (struct arr*) ar;
	int i, sum = 0;
	min = ap->a[0];
	for(i = 1; i < ap->n; i++){
		if(min > ap->a[i]){
			min = ap->a[i];
		}
	}
	sleep(1);
}
int main(int argc, char* argv[]){
	int i, status, *pstatus = &status;
	struct arr ar;
	ar.n = argc - 1;
	for(i = 1; i <= ar.n; i++){
		ar.a[i-1] = atoi(argv[i]);
	}
	
	pthread_t tid[3];

	pthread_create(&tid[0], NULL, &thrl1, &ar);
	pthread_create(&tid[1], NULL, &thrl2, &ar);
	pthread_create(&tid[2], NULL, &thrl3, &ar);

	if(pthread_join(tid[0], NULL) == 0){
		printf("Gia tri trung binh: %f\n", tbc);
	}
	if(pthread_join(tid[1], NULL) == 0){
		printf("Gia tri lon nhat: %d\n", max);
	}
	if(pthread_join(tid[2], NULL) == 0){
		printf("Gia tri nho nhat: %d\n", min);	
	}
	return 0;
}
