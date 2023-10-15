#include<stdio.h>
#include<math.h>

 int GPTBH(float a, float b, float c, int &x1, int &x2) {

	int denta=(b*b-4*a*c);  
	if (a==0) {
 		return -c/b; 
	 } 
	else if (denta==0) {
		return -b/(2*a); 
	}
	else if (denta>0) {
		int x1=((-b+sqrt(denta))/(2*a));
		int x2=((-b-sqrt(denta))/(2*a));
		int *nghiem1=&x1;
 		int *nghiem2=&x2;
 		printf("%d  ", *nghiem2);
		return x1;
	}
	else {
		printf("so nghiem cua phuong trinh la: ");
		return 0;
	}
 }
 
 
  
  
 int main() {
 	float a,b,c;
	int x1,x2; 
	if
 	printf("nhap he so a,b,c: "); scanf("%f %f %f", &a,&b,&c);
 	printf("%d", GPTBH(a,b,c,x1,x2));

 	
 }
