#include <stdio.h>

struct PS {
	int x;
	int y;
};

void xulyhonso(int pn, struct PS *ps){
	ps->x = pn*(ps->y) + ps->x;
}

int main(){
	struct PS ps1;
	struct PS ps2;
	struct PS kq;
	int m, n;
	printf("Nhap phan nguyen cua hon so 1: ");
	scanf("%d", &m);
	printf("Nhap phan nguyen cua hon so 2: ");
	scanf("%d", &n);
	Nhapps(&ps1, &ps2);

	xulyhonso(m, &ps1);
	xulyhonso(n, &ps2);

	Cong(ps1, ps2, &kq);
	Xuatps(kq);

	Tru(ps1, ps2, &kq);
	Xuatps(kq);

	Nhan(ps1, ps2, &kq);
	Xuatps(kq);

	Chia(ps1, ps2, &kq);
	Xuatps(kq);

	return 0;
}
