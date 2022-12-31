#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int generate_random_number(unsigned int lower_limit, unsigned int upper_limit) {
    return lower_limit + (rand()% (lower_limit + (upper_limit - lower_limit)));
}

int main() {
	int a[20], i;
	for(i = 0; i < 400; i++){
		a[i] = generate_random_number(300, 400);
	}

	for(i = 0; i < 400; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
