#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SEED  200 //sinh so ngau nhien
#define UPPER_LIM 1000 //so ngau nhien lon nhat
#define LOWER_LIM  1 //so ngau nhien nho nhat

// khai bao ham
int generate_random_number(unsigned int lower_limit, unsigned int upper_limit);
// khai bao cau truc de luu tru du lieu
struct data{
	long mesg_type;
	int n; // so phan tu cua mang
	int a[UPPER_LIM]; // cac phan tu  cua mang
}array1,array2,array3; //cac bien struct su dung trong bai


struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message, message2; 


//Tao thread de khoi tao cac phan tu cua mang
void* init_data(void *array)
{
	struct data *ap = (struct data*) array;
	int i;
	for(i = 0; i < ap->n; i++){
		ap->a[i] = generate_random_number(300, 400);
	}
}



//Ham noi mang sau khi chay thread
void merge_data(struct data array1, struct data array2, void* array3){
	struct data *ap = (struct data*) array3;	
	ap->n=array1.n + array2.n;
	
	printf("Show me: %d\n", ap->n);

	int i;
	for (i=0;i<array1.n;i++){
		ap->a[i]= array1.a[i];
		printf("%d ", array1.a[i]);
	}

	printf("\n");

	for (i=0;i<array2.n;i++){
		int temp=array1.n+i;
		ap->a[temp]=array2.a[i];
		printf("%d ", array2.a[i]);
	}

	printf("\n");
}


//Ham luu du lieu vao file
void Save_file(struct data array)
{
	int i;
	for(i = 0; i < array.n; i++){
		printf("%d ", array.a[i]);
	}
}


int main(int argc, char* argv[]){
	/*struct data array1;
	struct data array2;*/

	//Truyen doi so n la so phan tu cua mang.
	array1.n=atoi(argv[1])/2;
	array2.n=atoi(argv[1])-array1.n;
	
	pthread_t tid[1];
	pthread_create(&tid[0], NULL, &init_data,(void*) &array1);
	pthread_create(&tid[1], NULL, &init_data,(void*) &array2);


	merge_data(array1,array2,(void*) &array3);
	//Save_file(array3);
	//Hay tao ra message queue gui ket qua cua array3 o tren sang chuong
	//trinh solve.c	

	key_t key;
	int msgid;

	key = ftok(".", 1);
	
	return 0;
}
// ham sinh so ngau nhien
int generate_random_number(unsigned int lower_limit, unsigned int upper_limit) {
    return (rand()% (lower_limit + (upper_limit - lower_limit)));
}
