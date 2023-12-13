#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}


int main(){
	int *a= new int[100]; 
	int b;
	scanf("%d", &b);
	nhapmang(a,b);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
