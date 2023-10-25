#include <stdio.h>
#include <math.h>
float GPTBH(float a, float b, float c, float &x1, float &x2);
int main(){
	float a, b, c, x1, x2, delta;
	printf("Nhap he so a, b, c:");
	scanf("%f%f%f ", &a, &b, &c);
	if(GPTBH(a,b,c,x1,x2)==0)
		printf("PTVN");
	else if(GPTBH(a,b,c,x1,x2)==1)
		printf("PTVSN");
	else if(a==0)
		printf("Pt co nghiem x=%.2f", GPTBH(a,b,c,x1,x2));
	else if(GPTBH(a,b,c,x1,x2)==-b/(2*a))
		printf("Pt co 1 nghiem x=%.2f", GPTBH(a,b,c,x1,x2));
	else {
	printf("Pt co nghiem :x1=%.2f , x2=%.2f", x1, x2);
	}
}
float GPTBH(float a, float b, float c, float &x1, float &x2){
	
	if(a==0){
		if(b==0){
			if(c==0)
				return 1;
		return 0;			
		}
	return x1=-c/b;
	}
	float delta=b*b-4*a*c;
	if(delta==0){
		x1=x2=-b/(2*a);
		return x1;
	}
	else if(delta>0){
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		
		return x1;
	}
	else 
		return 0;
}

