#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <sys/wait.h> 

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text1[100], mesg_text2[100], mesg_text3[1]; 
} message, message2; 

int main(int argc, char *argv[]){
	int pid;
	if(argc < 4){
		printf("Doi so thieu.\n");
		return -1;
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

			msgctl(msgid, IPC_RMID, NULL);
			
			printf("%s\n", message2.mesg_text1);

			exit(0);
		}else{
			key_t key; 
			int msgid;
			key = ftok(".", 1); 
			msgid = msgget(key, 0666 | IPC_CREAT); 
			message.mesg_type = 1; 
			
			strcpy(message.mesg_text1, argv[1]);
			strcpy(message.mesg_text2, argv[2]);
			strcpy(message.mesg_text3, argv[3]);
			msgsnd(msgid, &message, sizeof(message), 0);    
		}
	return 0;
}

