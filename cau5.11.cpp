#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void phan5(int a[], int b){
	int sodem=0;
	for (int i=0; i<b; i++){
		if (a[i]<0){
			sodem++;
			printf("%d ", i);
		}
	} 
	if (sodem==0) printf("mang khong co so am");
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
