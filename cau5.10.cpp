#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void ktra(int a[], int b, int n){
	int sodem=0;
	printf("%d\n", n);
	for (int i=0; i<b; i++){
		if (a[i]==n){
			sodem ++;
			printf("vi tri trung: %d\n", i);
		}
	}
	if (sodem==0) printf("ko co phan tu nao trung");
}

int main(){
	int a[100],b,n;
	printf("so phan tu va so can tim lan luot la \n");
	scanf("%d %d", &b,&n);
	nhapmang(a,b);
	ktra(a,b,n);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
