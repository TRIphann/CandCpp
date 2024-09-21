#include<iostream>
#include<math.h> 

using namespace std;

void inputNumber(float &a){
	cin >> a;
}

void inputSign(int &b){
	cout << "1.Cong\n2.Tru\n3.Nhan\n4.Chia\n5.Luy thua\n6.Bang\n";
	cin >> b;
}

int count(float &a, int b, float c){
	switch (b){
		case 1:
			a=a+c;
			return a;
		case 2:
			a=a-c;
			return a;
		case 3:
			a=a*c;
			return a;
		case 4:
			a=a/c;
			return a;
		case 5:
			a=(pow(a,c));
			return a;
	}
}

int main(){
	int a=0;
	float number1;
	inputNumber(number1);
	while (a==0){
		int choose;
		inputSign(choose);
		if (choose==5){
			cout << "=" <<number1;
			break;
		}
		cout << "\n";
		float number2;
		inputNumber(number2);
		count(number1,choose,number2);
		
	}
} 
