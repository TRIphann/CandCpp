#include <stdio.h>

int main () {
	int n,x,a[100],c=0;
	printf("nhap so phan tu cua mang: ");
	scanf("%d", &n);
	printf("nhap x: ");
	scanf("%d", &x);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++) {
	   for (int j=i+1; j<n; j++) {
	   		if (a[i]+a[j]==x) {
	   			printf ("cap a[%d]=%d va a[%d]=%d thoa man dieu kien", i,a[i],j,a[j]);
	 			c++;  	
			   }   	
		}
	}
	if (c==0) {printf("khong co cap phan tu nao thoa man dieu kien");}
} 
