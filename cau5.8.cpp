#include<iostream>
#include<cstdlib>
#include<windows.h>

void nhapmang(int a[], int b){
	for (int i=0; i<b; i++) scanf("%d", &a[i]);
}

void phan5(int a[], int b){
	int c=0;
	for (int i=0; i<b-1; i++){
		if (a[i]>a[i+1]) {
			c++;
			break;
		}
	}
	if (c>0) printf("khong tang dan");
	else printf("tang dan");
}

int main(){
	int a[100],b;
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
