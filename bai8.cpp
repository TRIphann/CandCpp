#include<stdio.h>

int main() {
	int n,a[20],doi;
	printf("nhap so phan tu trong mang ");
	scanf("%d", &n);
	
	printf("nhap mang: ");
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	printf("\n");
	for (int i=n-1; i>0; i--) {
		for (int j=0; j<i; j++) {
			if (a[j]<a[j+1]) {
				doi=a[j];
				a[j]=a[j+1];
				a[j+1]=doi;
		}
	} 
}	
	for (int i=0; i<n; i++) {
		printf("%d ", a[i]);
	}

	
}
