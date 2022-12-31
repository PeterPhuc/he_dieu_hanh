#include <stdio.h>

struct PS {
	int x;
	int y;
};

void Nhapps(struct PS *ps1, struct PS *ps2){
	printf("PS 1: \n");
	printf("Nhap tu so: ");
	scanf("%d", &ps1->x);
	printf("Nhap mau so: ");
	scanf("%d", &ps1->y);

	printf("PS 2: \n");
	printf("Nhap tu so: ");
	scanf("%d", &ps2->x);
	printf("Nhap mau so: ");
	scanf("%d", &ps2->y);
}

void Xuatps(struct PS ps){
	printf("%d/%d\n", ps.x, ps.y);
}
