#include<stdio.h>
#include<math.h>

int main () {
	int n,toado[10][10];
	float dodai=0;
	printf("nhap so N: ");
	scanf("%d", &n);
	
	if (n<=1) {printf("vi co be hon 2 diem tren duong gap khuc nen do dai =0");
	}
	else {
		for (int i=0; i<n; i++) {
			printf("nhap toa do cho diem M(X%d,Y%d) ", i+1,i+1);
			scanf("%d %d", &toado[i][1], &toado[i][2]);
		}
		for (int i=0; i<n-1; i++) {
			dodai=sqrt(pow(toado[i+1][1]-toado[i][1],2)+pow(toado[i+1][2]-toado[i][2],2))+dodai;
		}		
		printf("\ndo dai la :%.2f", dodai);
}
	
}
