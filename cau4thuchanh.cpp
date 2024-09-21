#include<stdio.h>
#include<math.h>

struct Point {
	int x,y;
};
	
void inputPoint(char name, struct Point *a){
	printf("nhap toa do diem %c: ", name);
	scanf("%d %d", &a->x, &a->y);
}

int distancePoint(struct Point a, struct Point b){
	return(sqrt(pow((a.x-a.y),2) + pow((b.x-b.y),2)));
} 

void checkLine(struct Point a, struct Point b, struct Point c){
	if ((distancePoint(a,b)+distancePoint(c,b)==distancePoint(a,c)) || distancePoint(a,b)+distancePoint(a,c)==distancePoint(c,b) || distancePoint(c,b)+distancePoint(a,c)==distancePoint(a,b)){
		printf("3 diem la 1 duong thang");		
	}
	else printf("3 diem khong thang hang");		
}

int main(){
	struct Point a,b,c;
	inputPoint('A',&a);
	inputPoint('B',&b); 
	inputPoint('C',&c);
	
	checkLine(a,b,c);
}
