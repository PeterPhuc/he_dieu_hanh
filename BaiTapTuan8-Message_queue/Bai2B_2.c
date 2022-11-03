#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text1[100], mesg_text2[100], mesg_text3[1]; 
} message, message2;  

int main(int argc, char *argv[]){
	int soA, soB; 
	float kq;
	char pheptoan[1];

	key_t key; 
	int msgid; 
	key = ftok(".", 1);                                
	msgid = msgget(key, 0666 | IPC_CREAT);

	msgrcv(msgid, &message, sizeof(message), 1, 0);
	soA = atoi(message.mesg_text1);
	soB = atoi(message.mesg_text2);
	strcpy(pheptoan, message.mesg_text3);

	if(strcmp(pheptoan, "+") == 0) kq = soA + soB;
	else if(strcmp(pheptoan, "-") == 0) kq = soA - soB;
	else if(strcmp(pheptoan, "x") == 0) kq = soA * soB;
	else if(strcmp(pheptoan, "/") == 0) kq = (float)soA / soB;
	msgctl(msgid, IPC_RMID, NULL);

	key_t key2; 
	int msgid2;
	key2 = ftok(".", 1); 
	msgid2 = msgget(key2, 0666 | IPC_CREAT); 
	message2.mesg_type = 1;

	char tam[100] = "";
	sprintf(tam, "%.6f\n", kq);

	strcpy(message2.mesg_text1, tam);
	strcpy(message2.mesg_text2, "");
	strcpy(message2.mesg_text3, "");
	msgsnd(msgid2, &message2, sizeof(message2), 0);    
	return 0;
}

