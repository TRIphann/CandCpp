#include<stdio.h>
#include<math.h>

struct Point {
	int x,y;
};

void inputPoint(struct Point *a, struct Point *b, char name){
	printf ("nhap toa do dinh duoi cua %s", name);
	scanf ("%d %d", &a->x, &a->y);
	printf ("nhap toa do dinh tren cua %s", name);
	scanf ("%d %d", &b->x, &b->y);
}

bool checkPoint(struct Point tren, struct Point duoi){
	if ((tren.x-duoi.x>0)&&(tren.y-duoi.y>0)) return(1);
	return(0);
}

int acreage(struct Point tren, struct Point duoi){
	return((tren.x-duoi.x)*(tren.y-duoi.y));
}

int main(){
	struct Point tren1,duoi1,tren2,duoi2;
	inputPoint(&tren1,&duoi1, 'A');
	inputPoint(&tren2,&duoi2, 'B');
	
	if (checkPoint(tren1,duoi2)){
		printf ("Co giao nhau voi dien tich :%d", acreage(tren1,duoi2));
	}
	else if (checkPoint(tren2,duoi1)){
		printf("Co giao nhau voi dien tich :%d", acreage(tren1,duoi2));
	}
	else printf("khong giao nhau");
}
