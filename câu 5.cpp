#include <stdio.h>
#include<math.h>

int main () {
  float Xa, Ya, Xb, Yb, Xc, Yc, h;
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
  printf ("nhap chieu cao: ");
  scanf ("%f", &h);
  
  if ( ((Xa==Xb) && (Ya==Yb)) || ((Xa==Xc) && (Ya==Yc)) || ((Xb==Xc) && (Yb==Yc))) {
  	printf ("day khong phai la hinh vuong ");
  }
  else { 
  printf ("the tich la: %.1f", (abs((Xb-Xa)*(Yc-Ya)-(Xc-Xa)*(Yb-Ya))*h)/6);
}
}