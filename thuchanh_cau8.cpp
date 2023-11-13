#include<iostream>
using namespace std;

int main(){
	int a,b,c,d=0;
	cin >>a;
	cin >>b;
	if (a<b) c=a;
	else c=b;
	
	for (int i=c-1; i>1; i--){
		if ((a%i==0) && (b%i==0)){
		cout << "UCLN la:" <<i;
		d++;
		break;
	}}
	if (d==0) cout << "khong co UCLN";
}
