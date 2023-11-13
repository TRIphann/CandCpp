#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	cin >>a>>b>>c;
	if ((a+b<=c) || (a+c<=b) || (b+c<=a)) cout << "day khong phai la 1 tam giac";
	else if ((a*a==b*b+c*c) || (b*b==a*a+c*c) || (c*c==b*b+c*c)) cout << "day la tam giac vuong";
	else if ((a==b)&&(b==c)) cout << "day la tam giac can";
	else if ((a==b)||(b==c)||(c==a)) cout << "day la tam giac deu";
	else if ((a*a>b*b+c*c) || (b*b>a*a+c*c) || (c*c>b*b+c*c)) cout << "day la tam giac tu";
	else cout <<"day la tam giac nhon";
} 
