 //Nh?p 1 m?ng g?m n phân s? (M?i phân s? g?m t? s? và m?u s?). Tính t?ng, hi?u, tích, thuong, rút g?n phân s?
 #include<stdio.h>
 
 void nhapmang(int a[100][2], int n){
 	for (int i=0; i<n; i++){
 		scanf("%d", &a[i][0]);
 		scanf("%d", &a[i][1]);
	 }
 }
 
 int rutgon(int a[100][2], int i) {
 	int c;
 	if (a[i][0]%a[i][1]==0) return a[i][0]/a[i][1];
 	else if (a[i][1]%a[i][0]==0) {
 		printf("1/"); return a[i][1]/a[i][0];
	 }
	else {
		if (a[i][0]>a[i][i]) c=a[i][0];
		else c=a[i][1];
		for (int j=c-1; j>0; j--) {
			if (a[i][0]%j==0 && a[i][1]%j==0) {
				printf("%d/", a[i][0]/j);
				return a[i][1]/j;
			}
		} 
		
	}
 }
 
void tong(int a[100][2], int b, int c){
 	int mangkhac[100][2];
	mangkhac[0][1]=a[b][1]*a[c][1];
	mangkhac[0][0]=a[b][0]*a[c][1]+a[c][0]*a[b][1];
 	printf("%d",rutgon(mangkhac,0));
 }
 
 void hieu(int a[100][2], int b, int c){
 	a[c][0]=-a[c][0];
 	tong(a, b, c);
 	a[c][0]=-a[c][0];
 }
 
 void tich(int a[100][2], int b, int c){
 	int mangkhac[100][2];
 	mangkhac[0][0]=a[b][0]*a[c][0];
 	mangkhac[0][1]=a[b][1]*a[c][1];
 	printf("%d",rutgon(mangkhac,0));
 }
  
void thuong(int a[100][2], int b, int c){
	int doi=a[c][0];
	a[c][0]=a[c][1];
	a[c][1]=doi;
	
	tich(a, b, c);
}
  
 int main (){
 	int n, pso[100][2],vtri1,vtri2;
 	printf("nhap so phan so: "); scanf("%d", &n);
	printf("nhap lan luot tu va mau: ");
 	nhapmang(pso,n);
 	printf("nhap vi tri cua 2 phan tu ban muon tinh tong/hieu/thuong/tich: "); scanf("%d %d", &vtri1,&vtri2);
 	printf("tong la\n");
 	tong(pso,vtri1,vtri2);
 	printf("\nhieu la\n");
 	hieu(pso,vtri1,vtri2);
 	printf("\ntich la\n");
 	tich(pso,vtri1,vtri2);
 	printf("\nthuong la\n");
 	thuong(pso,vtri1,vtri2);
}
 
