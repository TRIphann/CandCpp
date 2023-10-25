#include <stdio.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

void NhapMang(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i);
        printf("Nhap tu so: ");
        scanf("%d", &a[i].tu);
        printf("Nhap mau so: ");
        scanf("%d", &a[i].mau);
    }
}

void XuatPs(PhanSo a) {
    	if(a.mau==1)
    		printf("%d  ",a.tu);
    	else if(a.tu==a.mau)
    		printf("%d  ",1);
    	else
    		printf("%d/%d  ", a.tu, a.mau);
}
int UCLN(int a, int b){
	int UCLN1;
	int min=a<b?a:b;
	for(int i=min;i>=1;i--)
		if(a%i==0 && b%i==0){
			UCLN1=i;
			break;
		}
	return UCLN1;
}
PhanSo RutgonPs(PhanSo a){
	PhanSo x;
	x.tu=a.tu/UCLN(a.tu,a.mau);
	x.mau=a.mau/UCLN(a.tu,a.mau);
	return x;
}
PhanSo TinhTong(PhanSo a, PhanSo b){
	PhanSo c;
	c.tu=a.tu*b.mau+b.tu*a.mau;
	c.mau=a.mau*b.mau;
	c=RutgonPs(c);
	return c;
}
PhanSo TinhHieu(PhanSo a, PhanSo b){
	PhanSo c;
	c.tu=a.tu*b.mau-b.tu*a.mau;
	c.mau=a.mau*b.mau;
	c=RutgonPs(c);
	return c;
}
PhanSo Tich(PhanSo a, PhanSo b){
	PhanSo c;
	c.tu=a.tu*b.tu;
	c.mau=a.mau*b.mau;
	c=RutgonPs(c);
	return c;
}
PhanSo Thuong(PhanSo a, PhanSo b){
	PhanSo c;
	c.tu=a.tu*b.mau;
	c.mau=a.mau*b.tu;
	c=RutgonPs(c);
	return c;
}

int main() {
    int n;
    do{
    printf("Nhap so phan so: ");
    scanf("%d", &n);
    }
    while(n<1);
	
	PhanSo a[100], Tong, Hieu, TichPs, ThuongPs;
    NhapMang(a, n);
    printf("Mang da nhap la :\n");
    for(int i=0;i<n;i++)
    	XuatPs(a[i]	);
    	//	Tong
    printf("\nTong la:");
    Tong = a[0];
    for(int i=1; i<n; i++){
    	Tong = TinhTong(Tong, a[i]);
  	}
  	XuatPs(Tong);
  		//Hieu
  	printf("\nHieu la:");
  	Hieu=a[0];
    for(int i=1; i<n; i++){
    	Hieu = TinhHieu(Hieu,a[i]);
  	}
  	XuatPs(Hieu);
  		//Tich
  	printf("\nTich la:");
  	TichPs=a[0];
    for(int i=1; i<n; i++){
    	TichPs = Tich(TichPs,a[i]);
  	}
  	XuatPs(TichPs);
  		//Thuong
  	printf("\nThuong la:");
  	ThuongPs=a[0];
    for(int i=1; i<n; i++){
    	ThuongPs = Thuong(ThuongPs,a[i]);
  	}
  	XuatPs(ThuongPs);
}
