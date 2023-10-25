//Nh?p n t? bàn phím 0<n<100
//Nh?p ð?n khi th?a ðk
//N?u 10<n in h?nh vuông r?ng c?nh n kí t? &.
//N?u n>=10 in ra 10 d?ng n kí t?

#include<iostream>

int main(){
	int n=-1;
	while (n<0 || n>=100) {
	printf ("nhap n: "); scanf("%d", &n);}
	
	if (n>=10) {
		for (int i=0; i<10; i++){
			for (int j=0; j<n; j++){
				printf ("*");
			}
			printf("\n");
		}
	}
	else {
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (j==0 || j==n-1 || i==0 || i==n-1) {
					printf("&");
				}
				else printf(" ");
			}
			printf("\n");
		}
	}
}
