#include<iostream>
#include<cstdlib>
#include<windows.h>

struct Baitap{
	int matinh;
	char tentinh[100];
	int danso,dientich;
	
};

typedef Baitap BT;

void nhap(Baitap &BT){
	printf("nhap ma tinh: ");
	scanf("%d", &BT.matinh);
	printf("nhap ten tinh: ");
	getchar();
	gets(BT.tentinh);
	printf("nhap dan so (tram nghin nguoi): ");
	scanf("%d", &BT.danso);
	printf("nhap dien tich (met vuong): ");
	scanf("%d", &BT.dientich);
}

void xuat(BT ds[], int &sizes){
	printf("Ma tinh: %d ",ds[sizes].matinh);
	printf("Ten tinh: %s ",ds[sizes].tentinh);
	printf("So dan: %d ", ds[sizes].danso);
	printf("Dien tich: %d ", ds[sizes].dientich);
}

void nhapdanhsach(BT ds[], int &sizes){
	for (int i=sizes-1; i<sizes; i++){
		nhap(ds[i]);
	}
}

void danhsach(BT ds[], int &sizes){
	for (int i=0; i<sizes-1; i++){
		xuat(ds,i);
		printf("\n");
	}
}

void dansolon(BT ds[], int &sizes){
	printf("Tinh co so dan lon hon 1 trieu la: \n");
	for (int i=0; i<sizes-1; i++){
		if (ds[i].danso>=10){
			printf("Ma tinh: %d , Ten tinh la: %s\n", ds[i].matinh,ds[i].tentinh);
		}
	}
}

void Slon(BT ds[], int &sizes){
	int ss=ds[0].dientich;
	int sodem=0;
	for (int i=1; i<sizes-1; i++){
		if (ss<ds[i].dientich){
			ss=ds[i].dientich;
			sodem=i;
		}
	}
	printf("Tinh co dien tich lon nhat xom la tinh: %s , co ma so la : %d\n ", ds[sodem].tentinh,ds[sodem].matinh);
	
}

int menu(){

	int chon;
	printf("=====MENU=====");
	printf("\n1. Xem danh sach");
	printf("\n2. Them tinh moi");
	printf("\n3. Tinh co so dan lon hon 1 trieu");
	printf("\n4. Tinh co dien tich lon nhat");
	printf("\n0. Thoat chuong trinh\n");
	
	printf("\nLua chon cua ban la: "); scanf("%d", &chon);
	printf("\n");
	return chon; 
}

int main(){
	int sotinh=1;
	BT ds[100];
	BT bt1;
	
	
	while (true){
	Baitap *tinh = new Baitap[sotinh];
	
	int chon=menu();

	switch(chon){
		case 1:
			danhsach(ds, sotinh);
			break;
		case 2:
			nhapdanhsach(ds, sotinh); 
			sotinh++;
			break;
		case 3:
			dansolon(ds, sotinh);
			break;
		case 4:
			Slon(ds, sotinh);
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
	if (a==0) {
		printf("bye ");
		break;
	}}

	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;

}
