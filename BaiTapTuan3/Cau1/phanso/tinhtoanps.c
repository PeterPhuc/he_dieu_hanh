#include <stdio.h>

struct PS {
	int x;
	int y;
};

void Cong(struct PS ps1, struct PS ps2, struct PS *kq){
	kq->x = ps1.x*ps2.y + ps2.x*ps1.y;
	kq->y = ps1.y*ps2.y;
}

void Tru(struct PS ps1, struct PS ps2, struct PS *kq){
	kq->x = ps1.x*ps2.y - ps2.x*ps1.y;
	kq->y = ps1.y*ps2.y;
}

void Nhan(struct PS ps1, struct PS ps2, struct PS *kq){
	kq->x = ps1.x*ps2.x;
	kq->y = ps1.y*ps2.y;
}

void Chia(struct PS ps1, struct PS ps2, struct PS *kq){
	kq->x = ps1.x*ps2.y;
	kq->y = ps1.y*ps2.x;
}

