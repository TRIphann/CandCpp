//H�y vi?t chuong tr�nh t�m v� in ra c�c s? l� s? nguy�n t? trong d�y s? a1, a2,...,aN
#include <stdio.h>

int main () {
	int n,mang[100],sodem=0,sodem1=0;
	printf("so gia tri trong mang ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		scanf("%d", &mang[i]);
	}
	
	for (int i=0; i<n; i++) {
		for (int j=2; j<mang[i]; j++) {
			if (mang[i]%j==0) {
				sodem ++;
			}
		}
			
		if (sodem==0) {
			printf("\nso nguyen to la :%d", mang[i]);
			sodem1++;
		}
		else { sodem=0;
		}
		
	}
	if (sodem1==0) {printf("day khong co so nguyen to");	}
}
