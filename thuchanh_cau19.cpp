#include<iostream>
using namespace std;

int main(){
	for (int i=1; i<100; i++){
		if ((i%2==1)&&(i!=7)&&(i!=5)&&(i!=93)){
			cout << i<<" ";
		}
	}
}
