#include <iostream>
using namespace std;

int main(){
	int n=-1,i=1,dem=1 ,dk=0;
	
	while (n<1){
	cin >>n;}
	
	while (dk==0){
		if ((i/n)>=1) dk++;
		else {
			i=i*10;
			dem++;
		}
	}
	cout <<dem;
}
