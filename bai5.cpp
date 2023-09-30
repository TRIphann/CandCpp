//Hãy vi?t chuong trình gi?i phuong trình b?c 2 ax2+ bx + c = 0 
#include<stdio.h>
#include<math.h>

int main() {
	int a,b,c,denta;
	float nghiem;
	printf("nhap cac he so a,b,c: ");
	scanf("%d%d%d", &a,&b,&c); 

	
	denta=b*b-4*a*c;
	
	if (denta>0) {
	
		printf("phuong trinh co 2 nghiem lan luot la :%.2f", (-b-sqrt(denta))/(2*a));
		printf(" va %.2f", (-b+sqrt(denta))/(2*a));
	}
	else if (denta==0) {
		nghiem=-b/(2*a);
		printf("phuong trinh co 1 nghiem kep :%.2f", nghiem);
		
	}
	else {
		
		printf("phuong trinh vo nghiem");
	}
	
}
