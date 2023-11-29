#include<iostream>
#include<cstdlib>
#include<windows.h>

void tien(int vao, int ra){
	if (vao<=12){
		if(vao>=6){
			if (ra<12){
				printf("%d d", (ra-vao)*6000);
			}
			if (ra>=12){
				if (ra<18) printf("%d d", (12-vao)*6000+(ra-12)*7500);
				else printf("%d d", (12-vao)*6000+(18-12)*7200);
			}
		}
		else {
			if (ra<12){
				printf("%d d", (ra-6)*6000);
			}
			if (ra>=12){
				if (ra<18) printf("%d d", (12-6)*6000+(ra-12)*7500);
				else printf("%d d", (12-6)*6000+(18-12)*7200);
		}
	}}
	else {
		if (vao<18) {
			if (ra<18) printf("%d d", (vao-12)*7500+(ra-12)*7500);
			else printf("%d d", (vao-12)*6000+(18-12)*7200);
		}
	}	
}


int main(){
	int vao,ra;
	scanf("%d%d", &vao,&ra);
	if ((vao<6)&&(ra<6) || (vao>ra) || (vao>18)&&(ra>18)){
		printf("0d");
	}
	else tien(vao,ra);
	
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
