#include <iostream> 
using namespace std;

int main (){
	int a,b,c;
	cin >>a;
	cin >>b;
	cin >>c;

	if (a>b) {
		if (a>c) cout << "so lon nhat la a: " <<a;
		else if (a<c) cout << "so lon nhat la c: " <<c;
		else cout << "co 2 so lon nhat la a=" <<a<<" va c="<<c;
	}
	else if (a<b){

		if (b>c) cout << "so lon nhat la b: "<<b;
		else if (b<c) cout <<"so lon nhat la c: " <<c;
		else cout << "co 2 so lon nhat la b=" <<b<<" va c"<<c;
	}
	else {
		if (a<c) cout << "so lon nhat la c: "<<c;
		else cout <<"co 2 so lon nhat la a="<<a<<" va b="<<b;
	}
	

	

}
