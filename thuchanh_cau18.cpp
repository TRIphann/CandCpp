#include<iostream>
using namespace std;

int main(){
	int n=-1,i=1,dem=1 ,dk=0,a=1,tich=1,b[100],c=0;
	
	while (n<1){
	cin >>n;}
	
	while (dk==0){
		if ((i/n)>=1) dk++;
		else {
			i=i*10;
			dem++;
		}
	}
	
	while (dem>1){
		for (int i=1; i<dem-1; i++){
			a=a*10;
		}
		b[c]=n/a;

		n = n % a;
		dem--;
		a=1;
		c++;
	}	

	int sosanh=b[0];
	for (int i=1; i<c; i++){
		if(sosanh<b[i]){
			sosanh=b[i];
		}
	}
	cout << sosanh;
	
}
