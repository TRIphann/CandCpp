#include<iostream>
#include<cstdlib>
#include<windows.h>

void cau2(int n){
	int sodem=0;
	for (int j=1; j<n; j++){
		for (int i=2; i<j; i++){
			if (j%i==0) sodem++;
		}
		if (sodem==0) printf("%d ", j);
		sodem=0;
}
}

int main(){
	int n=0;
	while (n<=0) scanf ("%d", &n);
	cau2(n);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
