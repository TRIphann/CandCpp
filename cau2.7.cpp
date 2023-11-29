#include<iostream>
#include<cstdlib>
#include<windows.h>

void nghiem(float a, float b, float c, float d, float e, float f){
	float x,y;
	if((a==0 && b==0)||(b==0 && e==0)) printf("pt bac nhat");
	else if (a==0){
		y=c/b;
		x=(f-e*y)/d; 
	}
	else if (d==0){
		x=f/e;
		y=(c-b*y)/a; 
	}
	else if (b==0){
		x=c/a;
		y=(-d*x+f)/e; 
	}
	else if (e==0){
		x=f/d;
		y=(-a*x+c)/b;
	}
	else {
		y=(c*d-a*f)/(b*d-e*a);
		x=(c-b*y)/a;
	}
	printf("x=%f y=%f", x,y);
}

int main(){
	float a,b,c,d,e,f;
	scanf("%f%f%f%f%f%f", &a,&b,&c,&d,&e,&f);
	nghiem(a,b,c,d,e,f);
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
