#include<iostream>

struct Baitap{
	int bac;
	int heso[100];
	
};

void nhaps(Baitap *bt){
	printf("nhap so bac: ");
	scanf("%d", &bt->bac);
	printf("nhap cac he so: ");
	for (int i=0; i<=bt->bac; i++){
		scanf("%d", &bt->heso[i]);
	}
}

void xuat(Baitap *bts[]){
	for (int l=0; l<=0; l++)
		printf("so bac la: %d\n", bts[0]->bac);
		printf("he so lan luot la: ");
		for (int i=0; i<=bts[0]->bac; i++){
			printf("%d ", bts[0]->heso[i]);
		}
}

int main (){
	int sizes=0;
	Baitap *bts = new Baitap[sizes];
	Baitap new_bt;
	nhaps(&new_bt);
	bts[0]=new_bt;
	xuat(&bts);
}
