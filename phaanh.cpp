#include <stdio.h>
#include <math.h>
int main (){
    float xA,yA,xB,yB,xC,yC;
    float AB,AC,BC,p,Cvi,S;
    printf ("Nhap toa do diem A:");
    scanf ("%f%f", &xA,&yA);
    printf ("Nhap toa do diem B:");
    scanf ("%f%f", &xB,&yB);
    printf ("Nhap toa do diem C:");
    scanf ("%f%f", &xC,&yC);
    printf ("A(%.2f,%.2f)", xA, yA);
    printf ("\nB(%.2f,%.2f)", xB, yB);
    printf ("\nC(%.2f,%.2f)", xC, yC);
    AB = sqrt(pow(xB-xA,2)+pow(yB-yA,2));
    AC = sqrt(pow(xC-xA,2)+pow(yC-yA,2));
    BC = sqrt(pow(xC-xB,2)+pow(yC-yB,2));
    Cvi =AB+AC+BC;
    p = Cvi/2;
    S = sqrt(p*(p-AB)*(p-AC)*(p-BC));
   
    printf ("Dien tich tam giac: %.2f",S);
    printf ("%f", Cvi);
}