#include<iostream>
using namespace std;

int main (){
	int n,tong=0;
	cin >>n;
	for (int i=0; i<n; i++){
		if (i%2==1) tong=tong+i;
	}
	cout << tong;
}
