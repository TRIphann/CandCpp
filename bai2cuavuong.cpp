#include <stdio.h>
#include <math.h>

int main(){
	int n;
	float x,s;
	printf("nhap n:"); scanf("%d",&n);
	printf("nhap x:"); scanf("%f",&x);
	s=sqrt(pow(x,n));
	for (int i=1;i<n;i++)
	 s=sqrt(pow(x,n-i)+s);
	printf("%.3f",s);
}
