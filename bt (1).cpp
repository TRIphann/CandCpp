#include<stdio.h>
void NhapMatran(int Mang[100][100], int d, int c);
int main(){
	int c, d, demSNT=0, tong=0;
	int a[100][100];
	printf("Nhap so hang d (d>0):");
	scanf("%d", &d);
	printf("Nhap so cot c (c<=100):");
	scanf("%d", &c);
	printf("Nhap vao ma tran: \n");
	NhapMatran(a,d,c);
	//dem snt
	for(int i=0;i<d;i++){
		
		for(int j=0;j<c;j++){
			int dem=0;
			for(int k=2;k<=a[i][j]/2;k++){
				if(a[i][j]%k==0)
					dem++;
			}
		if(dem==0)
			demSNT++;
		}
	}
	if(demSNT==0)
		printf("Ma tran khong co so nguyen to.\n");
	else
		printf("Co %d so nguyen to trong ma tran.\n", demSNT);
	
	//tinh tong
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++){
			tong=tong+a[i][j];
		}
	}
	printf("Tong cac phan tu trong ma tran la: %d", tong);
}
void NhapMatran(int Mang[100][100], int d, int c){
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++){
			scanf("%d", &Mang[i][j]);	
		}
	}
}
