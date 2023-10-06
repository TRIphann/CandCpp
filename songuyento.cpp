//viet ham kiem tra so nguyen to 

#include<stdio.h> 

void songuyento(int a) {
	int sodem=0;
	for (int i=2; i<=a/2 +1; i++) {
		if (a%i==0) {
			sodem++;
		}
	}
	if (sodem==0) printf("%d la so nguyen to", a);
	else printf("%d khong phai la so nguyen to", a);
}

int main () {
	int a;
	printf ("nhap a ");
	scanf("%d", &a);
	songuyento(a);
}
