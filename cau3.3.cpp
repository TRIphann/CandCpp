#include<iostream>
#include<cstdlib>
#include<windows.h>

void ham(int &a, int &b){
	printf("tong la:%d tich la:%d", a+b,a*b);
}

int main(){
	int a,b;
	scanf("%d %d", &a,&b);
	ham(a,b);
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
