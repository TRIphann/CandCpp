#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n=-1,i=1,dem=1 ,dk=0,tong=0,a=1;
	
	while (n<1){
	cin >>n;}
	
	while (dk==0){
		if ((i/n)>=1) dk++;
		else {
			i=i*10;
			dem++;
		}
	}
	
	while (dem>0){
		for (int i=1; i<dem; i++){
			a=a*10;
		}
		tong=tong+(n/a);
		n = n % a;
		dem--;
		a=1;
	}
	cout <<tong;
}
