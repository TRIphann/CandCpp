#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void gtln(int a[], int b){
	int c=a[0];
	for (int i=1; i<b; i++){
		if (c<a[i]) c=a[i];
	}
	printf("%d", c);
}

int main(){
	int a[100],b;
	scanf("%d", &b);
	nhapmang(a,b);
	gtln(a,b);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
