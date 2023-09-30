// nhap va xuat 1 mang so nguyen
// tong day so
// trung binh cong day so
// dem xem day so co bao nhieu so duong
// xuat ra man hinh cac so am
// tim so lon nhat
// tim so am nho nhat
#include<stdio.h>
int main(){
 int a[100], n, S=0;
 printf("Nhap so phan tu: ");
 scanf("%d",&n);
 //nhap mang
 for(int i=0;i<n;i++){
  printf("Nhap a[%d] = ",i);
  scanf("%d",&a[i]);
 }
 //xuat mang
 printf("Mang da nhap vao la: ");
 for(int i=0;i<n;i++){
  printf("%d  ",a[i]);
 }
 //tong day so
 for(int i=0;i<n;i++)
  S=S+a[i];

 printf("\nTong day so: %d", S);
 //trung binh cong
 int TBC;
 TBC = S/n;
 printf("\nTrung binh cong : %d\n",TBC);
 //dem so duong
 int b;
 printf("Dem cac so duong : ");
 for(int i = 0; i < n;i++)
 {
     if(a[i] > 0)
     {
         b++;
     }
 }
 printf("%d",b);
 //xuat ra man hinh cac do am
 printf("\nCac so am :");
 for(int i = 0; i < n;i++)
 {
     if(a[i] < 0)
     {
       printf("%d ",a[i]);
     }
  }
 //Tim so lon nhat
 int Max = a[0];
 for(int i = 1;i < n;i++)
 {
     if(a[i] > Max)
     {
         Max = a[i];
     }
  }
   printf("\nSo lon nhat : %d",Max);
 //Tim so nho nhat
 int Min = a[0];
 for(int i = 1;i < n;i++)    
 {
     if(Min > a[i])
     {
         Min = a[i];
     }
  }
   printf("\nSo nho nhat : %d",Min);
}
