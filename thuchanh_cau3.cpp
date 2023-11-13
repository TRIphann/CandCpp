#include <iostream>
using namespace std;

int main(){
	int n,tong;
	cin >>n;
	for (int i=1; i<=n; i++){
		tong=tong + i*i*i;
	}
	cout << tong;
}
