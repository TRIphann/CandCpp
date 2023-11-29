#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void ktra(int a[], int b){
	int c=0;
	for (int i=0; i<b; i++){
		if (a[i]%2==0 && a[i]<2004) c++;
	}
	if (c!=0) printf("Co");
	else printf("Khong");
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
