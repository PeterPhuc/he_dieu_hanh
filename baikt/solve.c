#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <math.h>


#define UPPER_LIM 1000 //so ngau nhien lon nhat
int isPrime(int n); //ham kiem tra so nguyen to
int isSquare(int n); // ham kiem tra so chinh phuong

// khai bao cau truc de luu tru du lieu
struct data{
	long mesg_type;
	int n; // so phan tu cua mang
	int a[UPPER_LIM]; // cac phan tu  cua mang
}array;
//thread de kiem tra phan tu nao la nguyen to
void* prime(void* array){
	
	
}
//thread de kiem tra phan tu nao so chinh phuong
void* square(void* array){
	
}
int main()
{
	// Hay viet message queue de nhan gia tri array tu main gui qua
	

	// Thuc hien goi 2 thread thuc thi nhu da khai bao
	
	return 0;
}
// Ham kiem tra so nguyen to
int isPrime(int n)
{
	if (n<2)
		return 0;
	int square=(int)sqrt(n);
	int i;
	for (i=2;i<=square;i++)
		if (n%i==0)
			return 0;
	return 1;
}
// Ham kiem tra so chinh phuong
int isSquare(int n)
{
	int sqr=sqrt(n);
	if (sqr*sqr==n)
		return 1;
	else
		return 0;
}
