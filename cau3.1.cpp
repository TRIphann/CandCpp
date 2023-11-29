#include<iostream>
#include<cstdlib>
#include<windows.h>

void doi(int &a, int &b){
	int khac=a;
	a=b;
	b=khac;
}

int main(){
	int a,b;
	scanf("%d%d", &a,&b);
	doi(a,b);
	printf("%d %d", a,b);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
