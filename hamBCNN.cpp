//BCNN, UCll

#include<stdio.h>

 void BCNN(int a, int b) {
 	int ketqua;
 	if (a%b==0) printf ("BCNN la %d", a); 
 	else if (b%a==0) printf ("BCNN la %d", b);
 	else {
 		for (int i=1; i<=(a*b); i++) {
 			if (i%b==0 && i%a==0) {
 				ketqua=i;
 				break;
			 }
		 }
		if (ketqua==0) ketqua==(a*b);
		printf ("BCNN la %d", ketqua);
	 }
	
 }
 
 void UCLN (int a, int b){
 	int c,ketqua=0;
 	if (a>b) c=b;
	else c=a;
	
	for (int i=1; i<=c; i++) {
		if (a%i==0 && b%i==0) {
			ketqua=i;
		}
		
	}
 	printf ("\nUCLN la %d", ketqua);
 }
 
 
 
 int main() {
 	int a,b;
 	printf ("nhap 2 so :"); scanf("%d%d", &a, &b);
 	BCNN(a,b);
 	UCLN(a,b);
 }
