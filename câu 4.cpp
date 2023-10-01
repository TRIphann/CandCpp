#include <stdio.h>

int main () {
	float hsl;
	char hoten[50];
	printf ("ho va ten :");
	gets(hoten);
	printf ("nhap he so luong: ");
	scanf ("%f", &hsl);
	
	printf ("so tien nhan: %f", ((hsl*1.49)*96.5)/100);
	
}