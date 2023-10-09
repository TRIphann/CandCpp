//nh?p ma tr?n s? nguyên g?m d d?ng và c c?t (d>0, c<=100)
//Ð?m s? lý?ng s? nguyên t? c?a ma tr?n
//Tính t?ng ma tr?n

#include<stdio.h>

void nhapmang(int a, int b, int c[100][100]) {
	printf("nhap mang :\n");
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			scanf("%d", & c[i][j]);
		}
	}
} 

int sont(int a){
	int sodem=0;
	
	for (int i=2; i<(a/2 +1); i++){
		if (a%i==0) {
			sodem++;
		}
	}
	return sodem;
}

int main () {
	int cot,hang,mang[100][100],sodem=0,tong=0;
	printf("nhap hang,cot :"); scanf("%d%d", &hang, &cot);
	nhapmang(hang, cot, mang); 
	for (int i=0; i<hang; i++) {
		for (int j=0; j<cot; j++) {
			if (sont(mang[i][j])==0) {
				printf("mang[%d][%d] la so nguyen to\n", i,j);
				sodem++;
			}
			
		}
	}
	if (sodem==0) printf("mang ko co so nguyen to");
	
	for (int i=0; i<hang; i++) {
		for (int j=0; j<cot; j++) {
			tong += mang[i][j];
		}
	}
	printf("tong mang la: %d", tong);
	
}
