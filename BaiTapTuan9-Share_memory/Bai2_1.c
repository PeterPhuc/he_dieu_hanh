#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h> 

int main(int argc, char* argv[]){
	int pid;
	pid = fork();
	if(pid==0) { 
		sleep(5);                           
		key_t key2 = ftok("shmfile",65);
		int shmid2 = shmget(key2,1024,0666|IPC_CREAT);
		int *shm2 = (int*) shmat(shmid2,(void*)0,0);


		printf("Tong cac phan tu cua mang: %d\n", shm2[0]);


		shmdt(shm2);
		shmctl(shmid2,IPC_RMID,NULL);
		return 0;
	}

	else if(pid >0) { 
		int *shm1, shmid1;                   //Tien trinh cha ghi mang vao SM shm1 va share cho Bai2_2.out
		key_t key1 = ftok("shmfile",65);
		shmid1 = shmget(key1,1024,0666|IPC_CREAT);
		shm1 = (int*) shmat(shmid1, 0, 0);

		shm1[0] = argc - 1;
		int i;
		for(i = 1; i <= shm1[0]; i++){
			shm1[i] = atoi(argv[i]);
		}

		shmdt(shm1);
		return 0;
	}

	else { perror("Fork failed."); return 0; }
	
	return 0;
}
