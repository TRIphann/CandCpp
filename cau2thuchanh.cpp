#include<stdio.h>
#include<math.h>

float dientich(float x1, float y1, float x2, float y2, float x3, float y3){
	float s=0.5*abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
	return (s);
}

int main(){
	float x1,y1,x2,y2,x3,y3;
	printf("nhap toa do diem dau: "); scanf("%f %f", &x1,&y1);
	printf("nhap toa do diem thu 2: "); scanf("%f %f", &x2,&y2);
	printf("nhap toa do diem thu 3: "); scanf("%f %f", &x3,&y3);
	printf("khoang cach 2 diem la: %2.f", dientich(x1,y1,x2,y2,x3,y3));
} 
