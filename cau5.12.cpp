#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void phan5(int a[], int b){
	int sodem=0;
	for (int i=b-1; i>=0; i--){
		if (a[i]%2==0){
			printf("%d", a[i]);
			sodem++;
			break;
		}
	}
	if(sodem==0) printf("-1");
}

int main(){
	int *a=new int[100];
	int b;
	scanf("%d", &b);
	nhapmang(a,b);
	phan5(a,b);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
