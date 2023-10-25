#include<stdio.h>
int main (){
 int n;
 scanf("%d", &n);
 if((n%400 == 0) || ((n%4 ==0)&& (n% 100 != 0)));{
 	printf(" nam nhuan! ");
 }
 
 else
 {
 	printf(" Khong phai nam nhuan!");
 }
 return 0;
}
