#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <sys/wait.h> 

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message, message2; 

int main(int argc, char *argv[]){
	int pid;
	if(argc < 2){
		printf("Doi so thieu.\n");
		return -1;
	}

	int n = atoi(argv[1]);
	unsigned long long int kq;
			
	if(n <= 3){
		printf("Doi so phai lon hon 3\n");
		exit(0);
	}

	pid = fork();
	if(pid < 0) printf("Fork failed.\n");
	else if(pid == 0){
			
		sleep(5);                        
		int msgid; 
		key_t key;
		key = ftok(".", 1); 
		msgid = msgget(key, 0666 | IPC_CREAT); 
			

		key_t key2; 
		int msgid2;
		key2 = ftok(".", 1); 
		msgid2 = msgget(key2, 0666 | IPC_CREAT); 
		msgrcv(msgid2, &message2, sizeof(message2), 1, 0);

		kq = atoi(message2.mesg_text);
		msgctl(msgid, IPC_RMID, NULL);

		printf("%d! = %llu\n", n, kq);

		exit(0);
	}else{
		key_t key; 
		int msgid;
		key = ftok(".", 1); 
		msgid = msgget(key, 0666 | IPC_CREAT); 
		message.mesg_type = 1; 
			
		strcpy(message.mesg_text, argv[1]);
		msgsnd(msgid, &message, sizeof(message), 0);
	}
	return 0;
}

