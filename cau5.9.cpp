#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void phan5(int a[], int b){
	for (int i=b-1; i>=1; i--){
		for (int j=0; j<i; j++){
			if (a[j]>a[j+1]){
				int doi=a[j];
				a[j]=a[j+1];
				a[j+1]=doi;
			}
		}
	}
}

void xuatmang(int a[], int b){
	for (int i=0; i<b; i++) printf("%d ", a[i]);
}


int main(){
	int *a=new int[100];
	int b;
	scanf("%d", &b);
	nhapmang(a,b);
	phan5(a,b);
	xuatmang(a,b);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
