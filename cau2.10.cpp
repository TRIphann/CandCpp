#include<iostream>
#include<cstdlib>
#include<windows.h>

void tong(int n){
	int s=0;
	for (int i=2; i<=2*n; i=i+2){
	
		s=s+i;		
	}
	printf("%d", s);
}

int main(){
	int n; scanf("%d", &n);
	tong(n);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
