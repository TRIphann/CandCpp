#include(stdio.h)
#include(math.h)

float kc(float a, float b, float c, float d){
	float r=sqrt(pow((a-b),2) + pow((c-d),2));
	return (r);
}

bool xet(float a, float b, float c, float d, float f){
	if (kc(a,b,d,f)<=c) return(1);
	return 0;
}

int main(){
	float r1,r2,r,x,y;
	printf("nhap toa do ban kinh "); scanf("%f %f", &r1,&r2);
	printf("nhap ban kinh "); scanf("%f", &r);
	printf("nhap toa do diem dang xet "); scanf("%f %f", &x,&y);
	if (xet(r1,r2,r,x,y)) pritnf("diem dang xet nam trong hinh tron");
	else pritnf("diem dang xet khong nam trong hinh tron");
}

