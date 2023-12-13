#include<iostream>
#include<cstdlib>
#include<windows.h>

struct Baitap{
	int bac;
	int heso[100];
	
};

void nhap(Baitap *a){
	printf("nhap so bac: ");
	scanf("%d", &a->bac);
	printf("nhap he so: ");
	for (int i=0; i<=a->bac; i++){
		scanf("%d", &a->heso[i]);
	}
}

void xuat(Baitap *a){
	for (int i=0; i<=a->bac; i++){
		printf("%d", a->heso[i]);
	}
}

void tong(Baitap *a, Baitap *b){
		int dem, c[100];
		if (a->bac > b->bac) dem=a->bac;
		else dem=b->bac;
		
		for (int i=1; i<=dem+1; i++){
			if ((i<=a->bac+1)&&(i<=b->bac+1)){
				c[(dem+1)-i]=a->heso[(a->bac+1)-i]+b->heso[(b->bac+1)-i];
			}
			else{
				if (a->bac > b->bac) c[dem+1-i]=a->heso[(a->bac+1)-i];
				else c[dem+1-i]=b->heso[(b->bac+1)-i];
			}
		}
		for (int i=0; i<=dem; i++){
			printf("%d ", c[i]);
		}
		printf("\n");
}

void hieu(Baitap *a, Baitap *b){
		int dem, c[100];
		if (a->bac > b->bac) dem=a->bac;
		else dem=b->bac;
		
		for (int i=1; i<=dem+1; i++){
			if ((i<=a->bac+1)&&(i<=b->bac+1)){
				c[(dem+1)-i]=a->heso[(a->bac+1)-i]-b->heso[(b->bac+1)-i];
			}
			else{
				if (a->bac > b->bac) c[dem+1-i]=a->heso[(a->bac+1)-i];
				else c[dem+1-i]=- b->heso[(b->bac+1)-i];
			}
		}
		for (int i=0; i<=dem; i++){
			printf("%d ", c[i]);
		}
		printf("\n");
}

void nhan(Baitap *a, Baitap *b){
	int c[100];
	for (int i=0; i<100; i++){
		c[i]=0;
	}
	
		for (int i=0; i<=a->bac; i++){
			for (int j=0; j<=b->bac; j++){
				c[i+j]=c[i+j]+(a->heso[i]*b->heso[j]);
			}
		}
		for (int i=0; i<=a->bac+b->bac; i++){
			printf("%d ", c[i]);
		}
		printf("\n");
}

int main(){
	Baitap dathuc1,dathuc2;
	printf("nhap da thuc thu 1\n");
	nhap(&dathuc1);
	printf("\nnhap da thuc thu 2\n");
	nhap(&dathuc2);
	tong(&dathuc1,&dathuc2);
	hieu(&dathuc1,&dathuc2);
	nhan(&dathuc1,&dathuc2);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;

}
	
