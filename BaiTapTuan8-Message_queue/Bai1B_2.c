#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message, message2; 

unsigned long long int giaithua(int n){
	if(n < 1){
		return 1;
	}else{
		return giaithua(n - 1) * n;
	}
}

int main(int argc, char *argv[]){
	unsigned long long int kq;

	key_t key; 
	int msgid; 
	key = ftok(".", 1);                                
	msgid = msgget(key, 0666 | IPC_CREAT);

	int checkms = msgrcv(msgid, &message, sizeof(message), 1, 0);
	if(checkms == -1){
		exit(0);
	}
			
	int n = atoi(message.mesg_text);	
	kq = giaithua(n);
	msgctl(msgid, IPC_RMID, NULL);
			

	key_t key2; 
	int msgid2;
	key2 = ftok(".", 1); 
	msgid2 = msgget(key2, 0666 | IPC_CREAT); 
	message2.mesg_type = 1;
			
	char tam[100] = "";
	sprintf(tam, "%llu\n", kq);

	strcpy(message2.mesg_text, tam);
	msgsnd(msgid2, &message2, sizeof(message2), 0);    
	return 0;
}

