#include<stdio.h>
#include<math.h>

int main() {
	int n,x;
	float ketqua=0;
	printf("nhap so x: ");
	scanf("%d", &x);
	printf("nhap so n: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		ketqua=sqrt(pow(x, n-i)+ketqua); 
	}
	printf("ket qua la :%.2f", ketqua);
	
	
}
