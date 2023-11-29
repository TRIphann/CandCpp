#include<iostream>
#include<cstdlib>
#include<windows.h>

void tong(float n){
	float s=0;
	for (float i=1; i<=n; i++){
		s=s+1/(i*(i+1));
	}
	printf("%f", s);
}

int main(){
	float n; scanf("%f", &n);
	tong(n);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
