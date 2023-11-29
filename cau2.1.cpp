#include<iostream>
#include<cstdlib>
#include<windows.h>

void svav(int a, int b){
	printf("chu vi la:%d \ndien tich la:%d" ,2*(a+b) ,a*b);
}

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	svav(a,b) ;
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
