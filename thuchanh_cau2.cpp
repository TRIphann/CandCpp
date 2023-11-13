#include <iostream> 
using namespace std;

int main(){
	int thang=-1,sodem=0;
	while (thang<0 || thang>13) {
		if (sodem>0) cout << "nhap lai so thang: ";
		cin >> thang;
		sodem ++;
	}
	if (thang==1 || thang ==2 || thang == 3 ){
		cout << "quy 1";
	}
	else if (thang ==4 || thang==5 || thang==6){
		cout << "quy 2 ";
	}
	else if (thang ==7|| thang==8|| thang==9){
		cout << "quy 3";
	}
	else cout <<"quy 4";
}
