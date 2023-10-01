//Viết chương trình nhập tọa độ của 3 điểm A, B, C trên mặt phẳng. 
// Tính và in ra màn hình chu vi, diện tích của tam giác ABC.
#include <stdio.h>
#include<math.h>

int main () {
  float Xa, Ya, Xb, Yb, Xc, Yc;
  printf ("nhap hoanh do cua A: ");
  scanf ("%f", &Xa);
  printf ("nhap tung do cua A: ");
  scanf ("%f", &Ya);
  printf ("nhap hoanh do cua B: ");
  scanf ("%f", &Xb); 
  printf ("nhap tung do cua B: ");
  scanf ("%f", &Yb);
  printf ("nhap hoanh do cua C: ");
  scanf ("%f", &Xc);
  printf ("nhap tung do cua C: ");
  scanf ("%f", &Yc);
  
  if ( ((Xa==Xb) && (Ya==Yb)) || ((Xa==Xc) && (Ya==Yc)) || ((Xb==Xc) && (Yb==Yc))) {
  	printf ("đay khong phai la hinh vuong ");
    
  }
  else {
  
  

  
  printf ("chu vi la : %.1f", (sqrt((Xb-Xa)*(Xb-Xa)+(Yb-Ya)*(Yb-Ya))+sqrt((Xc-Xb)*(Xc-Xb)+(Yc-Yb)*(Yc-Yb))+sqrt((Xa-Xc)+(Ya*Yc))));
  printf ("\ndien tich la: %.1f", (abs((Xb-Xa)*(Yc-Ya)-(Xc-Xa)*(Yb-Ya)))/2);
}


  
  
  
  
}