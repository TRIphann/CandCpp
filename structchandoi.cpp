#include<iostream>
#include<cstdlib>
#include<windows.h>

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

void xuat(Baitap *bts[], int a){
		printf("so bac la: %d\n", bts[a]->bac);
		printf("he so lan luot la: ");
		for (int i=0; i<=bts[a]->bac; i++){
			printf("%d ", bts[a]->heso[i]);
		}
}

void nhap(Baitap *bts, int sizes){
	Baitap new_bt;
	printf("nhap thong tin da thuc moi\n");
	nhaps(&new_bt);
	
	int new_size=sizes+1;
	Baitap *bt_moi = new Baitap[new_size];
	for (int i=0; i<sizes; i++){
		bt_moi[i]=bts[i];
	}
	bt_moi[new_size-1]=new_bt;
	delete[] bts;
	bts=bt_moi;	
	
//	bts[sizes]=new_bt;
	xuat(&bts, sizes);
}

void danhsach(Baitap *bts, int sizes){
	if (!sizes){
		printf("chua co da thuc nao\n");
	}
	else {
		for (int i=0; i<sizes; i++){
			xuat(&bts, i);
			printf("\n");
		}
	}
}


int menu(){
	system("cls");
	int chon;
	printf("=====MENU=====");
	printf("\n1. Xem danh sach da thuc");
	printf("\n2. Them da thuc moi");
	printf("\n3. Xoa da thuc cu");
	printf("\n4. Tinh toan voi da thuc");
	printf("\n0. Thoat chuong trinh\n");
	
	printf("\nLua chon cua ban la: "); scanf("%d", &chon);
	return chon; 
}

int main(){
	int sizes=0;
	
	while (true){
		Baitap *bts = new Baitap[100];
		int chon=menu();
		system ("cls");
		switch(chon){
			case 1:
				danhsach(bts, sizes);
				break;
			case 2:
				nhap(bts, sizes); 
				sizes++;
				break;
			case 3:
				//xoa
				break;
			case 4:
				//tinh toan
				break;
			case 0:
				printf("Bye");
				return 0;
			default:
				printf("lua chon ko hop le\n");
		}
		printf("Ban muon tiep tuc khong? (1/0) ");
		int a;
		scanf("%d", &a);
		if (a=0) {
			printf("bye ");
			break;
		}
		printf("hoanf thanh");
		
	}



	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
