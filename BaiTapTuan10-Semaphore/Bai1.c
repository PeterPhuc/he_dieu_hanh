#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
void* thread1(void* arg) {
	int i;
	for(i = 1; i <= 11; i += 2){
		sem_post(&mutex);
		printf("%d\n", i);
		sleep(1);
	}
}

void* thread2(void* arg) {
	int i;
	for(i = 2; i <= 10; i += 2){
		sem_wait(&mutex);
		printf("%d\n", i);
	}	
}

int main() {
	sem_init(&mutex, 0, 0);
	pthread_t t1,t2;

	pthread_create(&t1,NULL,thread1,NULL);
	pthread_create(&t2,NULL,thread2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}
