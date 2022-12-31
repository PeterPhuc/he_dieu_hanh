#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

struct arr {
	int n1, n2;
	int a1[100], a2[100];
};

int array1[100], array2[100];

void merge(int a[], int left, int mid, int right){
	int i,j,k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];
	for(i = 0; i < n1; i++){
		L[i] = a[left + i];
	}
	for(j = 0; j < n2; j++){
		R[j] = a[mid + 1 +j];
	}
	i = 0;
	j = 0;
	k = left;
	
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		a[k] = R[j];
		j++;
		k++;
	}	
}

void MergeSort(int a[], int l, int r){
	if(l < r){
		int m = l + (r-l)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);

		merge(a,l,m,r);
	}
}

void xuatmang(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}


void chepMang(int a[], int a1[], int startIndex, int endIndex){
	int i, j = 0;
	for(i = startIndex; i < endIndex; i++){
		a1[j] = a[i];
		j++;
	}
}

void* thrl1(void* ar){
	struct arr *ap = (struct arr*) ar;
	MergeSort(ap->a1,0,(ap->n1) - 1);
	chepMang(ap->a1, array1, 0, ap->n1);
	sleep(2);
}

void* thrl2(void* ar){
	struct arr *ap = (struct arr*) ar;
	MergeSort(ap->a2,0,(ap->n2) - 1);
	chepMang(ap->a2, array2, 0, ap->n2);
	sleep(2);
}

void noiMang(int newarr[], int arr1[], int n1, int arr2[], int n2){
	int i = 0, j = 0;
	while(i < n1){
		newarr[i] = arr1[i];
		i++;
	}
	while(j < n2){
		newarr[i] = arr2[j];
		i++;
		j++;
	}

	xuatmang(newarr, n1 + n2);
}

int main(int argc, char* argv[]){
	int a[100], newarr[100];
	int n = argc - 1, i;
	for(i = 1; i <= n; i++){
		a[i-1] = atoi(argv[i]);
	}

	struct arr ar;
	ar.n1 = (int)(n/2);
	ar.n2 = n - ar.n1;
	chepMang(a, ar.a1, 0, ar.n1);
	chepMang(a, ar.a2, ar.n1, n);


	pthread_t tid[2];

	pthread_create(&tid[0], NULL, &thrl1, &ar);
	pthread_create(&tid[1], NULL, &thrl2, &ar);

	if(!pthread_join(tid[0], NULL) && !pthread_join(tid[1], NULL)){
		noiMang(newarr, array1, ar.n1, array2, ar.n2);
	}
	return 0;
}



























