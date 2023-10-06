//viet ham tim so lon thu hai cua mang 
//viet ham tim vi tri suat hien dau tien cua 1 so nguyen x trong day so 

#include<stdio.h>

void NhapMang(int a[], int n){
	for (int i=0; i<n; i++) {
		scanf ("%d", &a[i]);
	}
}

int solonthuhai(int a[], int n) {
	int solonnhat=a[0],b=0;
	for (int i=1; i<n; i++) {
		if (a[i] > solonnhat) {
			b=solonnhat;
			solonnhat=a[i];
	}}
	return b;
}

int vitridautien(int a[], int n, int m ){
	int c=-1;
	for (int i=0; i<n; i++) {
		if (a[i]==m) {
            return i;
		}
	}
	return c;
}

int main() {
	int sopt,mang[10000],socantim;
	printf("nhap so phan tu cua mang "); scanf("%d", &sopt);
	printf("nhap mang \n");
	NhapMang(mang,sopt);
	printf ("so lon hai la: %d", solonthuhai(mang,sopt));
	printf("\nso can tim: "); scanf("%d", &socantim);
	if (vitridautien(mang,sopt,socantim)>0) {
		printf("vi tri so can tim: %d", vitridautien(mang,sopt,socantim));
	}
	else printf("mang ko co so do");
	
}
