#include<iostream>
#include<cstdlib>
#include<windows.h>

void gt(int n){
	int gtt=1;
	for (int i=2; i<=n; i++){
		gtt=gtt*i;
	}
	printf("%d", gtt);
}


int main(){
	int n;
	scanf("%d", &n); 
	gt(n);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
