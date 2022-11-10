#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h> 

int main(int argc, char* argv[]) {
	sleep(2);
	key_t key1 = ftok("shmfile",65);               //Doc SM shm1
	int shmid1 = shmget(key1,1024,0666|IPC_CREAT);
	int *shm1 = (int*) shmat(shmid1,(void*)0,0);


	int i, s = 0, n = shm1[0];      //xu ly du lieu doc duoc
	for(i = 1; i <= shm1[0]; i++){
		s += shm1[i];
	}


	shmdt(shm1);
	shmctl(shmid1,IPC_RMID,NULL);

	
	


	int *shm2, shmid2;                             //Ghi SM shm2
	key_t key2 = ftok("shmfile",65);
	shmid2 = shmget(key2,1024,0666|IPC_CREAT);
	shm2 = (int*) shmat(shmid2, 0, 0);     //Gan ket qua da xu ly vao SM shm2

	shm2[0] = s;                     

	shmdt(shm2);
	return 0;
}
