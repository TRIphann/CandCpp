//viet chuonwg trinh chuyen he 10 ->2 
#include <stdio.h>

int main () {
	int n, a[100], i=0;
	printf("nhap n :");
	scanf ("%d", &n);
	while (n!=0) {
		n=n/2;
		a[i]=n%2;
		i++;
	}
	for (int j=i; j>0; j--) {
		printf("%d",a[j]);
	}

} 
