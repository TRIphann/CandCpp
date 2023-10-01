// 1. Viết chương trình cho nhập các hệ số của phương trình bậc nhất 1 ẩn
// ax+b=0 (với a≠0) hãy in ra màn hình nghiệm của phương trình đã  cho.
#include <stdio.h>

int main () {
	float a, b, x;
	printf ("nhap he so a: ");
	scanf ("%f",&a);
	while (a==0) {
	    printf ("nhap lai so a khac: ");
	    scanf ("%f",&a);
	}
	printf ("nhap he so b: ");
	scanf ("%f",&b);
	printf ("nghiem cua phuong trinh la: %.1f", -b/a);
	
	return 0; 
}