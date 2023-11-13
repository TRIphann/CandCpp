#include<iostream>
using namespace std;

int main(){
		int n=-1,i=1,dem=1 ,dk=0,a=1,tich=1;
	
	while (n<1){
	cin >>n;}
	
	while (dk==0){
		if ((i/n)>=1) dk++;
		else {
			i=i*10;
			dem++;
		}
	}
	
	for (int i=1; i<dem-1; i++){
		a=a*10;
	}
	cout<< "chu so dau tien la: "<< n/a;
	
}
