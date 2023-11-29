#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void ktra(int a[], int b){
	int sodem=0;
	for (int i=0; i<b; i++) {
		int c=0;
		if (a[i]<100){
			for (int j=2; j<a[i]; j++){
				if (a[i]%j==0) c++;
			}
		}
		if (c==0) sodem++;
	}
	printf("%d", sodem);
}

int main(){
	int a[100],b;
	scanf("%d", &b);
	nhapmang(a,b);
	ktra(a,b);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
