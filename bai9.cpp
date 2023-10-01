#include<stdio.h>

int main() {
	int n,a[120], sodem=0, sodem1=0;
	printf("nhap so phan tu cua mang: ");
	scanf("%d", &n);
	
	printf("nhap mang\n");
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	
	
	for (int i=n-1; i>0; i--) {
		for (int j=0; j<i; j++) {
			sodem=a[j]+sodem;
		}
		if (a[i]==sodem) {
			printf("a[%d] thoa man dieu kien\n", i);
			sodem1++;
		}
		sodem=0;
	}
	if (sodem1==0) {
		printf("khong co phan tu nao thoa man dieu kien");
	}
}
