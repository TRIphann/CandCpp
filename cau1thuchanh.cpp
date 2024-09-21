#include<stdio.h>
#include<math.h>

float kc(float a, float b, float c, float d){
	float r=sqrt(pow((a-b),2) + pow((c-d),2));
	return (r);
}

int main(){
	float x1,y1,x2,y2;
	printf("nhap toa do diem dau: "); scanf("%f %f", &x1,&y1);
	printf("nhap toa do diem thu 2: "); scanf("%f %f", &x2,&y2);
	printf("khoang cach 2 diem la: %2.f", kc(x1,y1,x2,y2));
} 
