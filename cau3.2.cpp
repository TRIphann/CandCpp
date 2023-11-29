#include<iostream>
#include<cstdlib>
#include<windows.h>

void ham(int &a){
	int tong=1;
	for (int i=1; i<=a; i++){
		tong=tong*i;
	}
	printf("%d", tong);
}

int main(){
	int n;
	scanf("%d", &n);
	ham(n);
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
