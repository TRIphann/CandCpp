#include<stdio.h>

int main () {
	int n, a[30], sodem=0;
	float ketqua=0;
	printf("nhap so phan tu cua mang ");
	scanf("%d", &n);
	
	
	printf("nhap mang ");
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i=0; i<n; i++) {
		for (int j=1; j<a[i]/2; j++) {
			if (j*j==a[i]) {
				ketqua=ketqua+a[i];
				sodem++;
			}
		}
	}
	if (sodem>0) {
		ketqua=ketqua/sodem;
		printf("tbc cac phan tu chinh phuong la: %.2f", ketqua);
	}
	else {
		printf("mang ko co so chinh phuong");
	}
}
