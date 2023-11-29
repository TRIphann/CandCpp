#include<iostream>
#include<cstdlib>
#include<windows.h>

void dq(int tinh, int a[]){
	if (tinh==0) {
		a[0]=0;
		dq(tinh+1,a);
	}
	else if (tinh==1) {
		a[1]=1;
		dq(tinh+1,a);
	}
	else if (tinh>1 && tinh<10) {
		a[tinh]=a[tinh-1]+a[tinh-2];
		dq(tinh+1,a);
	}
	else if (tinh=10){
		for (int i=0; i<10; i++) printf("%d ", a[i]);
	}
}

int main(){
	int tinh=0,a[15];
	dq(tinh,a);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
