// nhap va xuat 1 mang so nguyen
// tong day so
// trung binh cong day so
// dem xem day so co bao nhieu so duong
// xuat ra man hinh cac so am
// tim so lon nhat
// tim so am nho nhat
#include<stdio.h>
int main(){
	int a[100], n, soduong=0, max=0, min=0, songuyento=0, khongcosodem=0;
	float S=0;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	//nhap mang
	for(int i=0;i<n;i++){
		printf("Nhap a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	//xuat mang
	printf("Mang da nhap vao la: ");
	for(int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	//tong day so
	for(int i=0;i<n;i++)
		S=S+a[i];
	printf("\nTong day so: %.2f", S);
	float tbc=S/n;
	printf("\nTrung binh cong day so: %.2f", tbc);
	
	//dem so duong
	for (int i=0; i<n; i++) {
		if (a[i]>0) {
			soduong += 1;
		} 
		else { printf("\ncac so am la: %d", a[i]);
		}
	}
	printf ("\nso duong la :%d", soduong);
	
	//so lon nhat
	for (int i=0; i<n; i++) {
		if (a[i]>max) {
			max=a[i];
		}
	}
	printf("\nso lon nhat: %d", max);
	
	//so am nho nhat
	for (int i=0; i<n; i++) {
		if ((a[i]<min)&&(a[i]<0) ){
			min=a[i];
		}
	}
	if (min<0) {
		printf("\nso nho nhat: %d", min);
	}
	else {
		printf("\nkhong co so am ");
}
	for (int i=0; i<n; i++) {
		for (int j=2; j<=(a[i])/2; j++) {
			if (a[i]%j==0) {
				songuyento ++;
			}
			else { khongcosodem++;
		}
		}
		if (songuyento==0) {
			printf("\na[%d]=%d la so nguyen to", i,a[i]);
		}
		
	} 
	if (khongcosodem==n) {printf("\nko co so nguyen to");
	}
	
}

