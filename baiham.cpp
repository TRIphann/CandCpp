//hieu tich thuong
#include<stdio.h>

int hieu(int a, int b) {
	return a-b;
} 

int tich(int a, int b){
	return a*b;
}

float thuong(int a, int b) {
	return a/b;
}

int main() {
	int a,b;
	printf("nhap 2 so :"); scanf("%d%d", &a,&b);
	printf("hieu la :%d", hieu(a,b));
	printf ("\ntich la :%d", tich(a,b));
	printf("\nthuong la :%.2f", thuong(a,b));
} 
