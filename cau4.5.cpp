#include<iostream>
#include<cstdlib>
#include<windows.h>

void dq(int n, int m){
	if (n/m>=10) dq(n,m*10);	
	else printf("%d", n/m);
}

int main(){
	int n=0, m=1; 
	while (n<=0) scanf("%d", &n);
	dq(n,m);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
