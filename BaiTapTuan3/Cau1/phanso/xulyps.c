#include <stdio.h>

struct PS {
	int x;
	int y;
};

int main(){
	struct PS ps1;
	struct PS ps2;
	struct PS kq;
	Nhapps(&ps1, &ps2);

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
