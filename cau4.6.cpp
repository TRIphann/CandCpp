#include<iostream>
#include<cstdlib>
#include<windows.h>

void dq(int n, int tinh){
	if (n>=2) {
		tinh=tinh*n;
		dq(n-1,tinh);
	}
	else printf("%d", tinh);
}

int main(){
	int n=0,tinh=1;
	while (n<=0) scanf("%d", &n);
	dq(n,tinh);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
