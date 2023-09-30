//Hãy vi?t chuong trình tìm tích c?a 2 ma tr?n Amxn và Bnxp
#include<stdio.h>
 int main() {
 	int a[100][100], b[100][100], m,n,p, so=0;
 	printf("nhap cac so m,n,p:");
 	scanf("%d%d%d", &m,&n,&p);
 	
 	printf("nhap mang A\n");
 	for (int i=0; i<m; i++) {
 		for (int j=0; j<n; j++) {
 			scanf("%d",&a[i][j]);
		 }
	 }
	
	printf("\nnhap mang B\n");
	for (int j=0; j<n; j++) {
		for (int k=0; k<p; k++) {
			scanf("%d", &b[j][k]);
		}
	}
	printf("\n");
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int x=0; x<n; x++) {
				so=a[i][x]*b[x][j]+so;
			}
			printf("%d ", so);
			so=0;
		}
		printf("\n");
	}
 }
 
 // 3 2 3
 
 //-1 3 1
 //-2 2 0
 
 //2 0
 //3 1
 //9 -1
 
 //16 2
 //2 2

