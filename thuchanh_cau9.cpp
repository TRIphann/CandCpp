#include<iostream>
using namespace std;

int main (){
	int n,dem=0;
	cin >>n;
	for (int i=2; i<n; i++){
		if (n%i==0){
			cout << n<< " khong phai la so nguyen to";
			dem++;
			break;
		}
	}
	if (dem==0) cout << n<< " la so nguyen to";
}
