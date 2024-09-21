#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main(){
	srand(time(NULL));
	int a;
	cout << "Hay chon so tu 1 den 999999: ";
	cin >> a;
	
    if(a < 1 || a > 999999) {
        cout << "So ban nhap khong hop le!" << endl;
        return 1;
    }

    
    int number = rand() % 999999 + 1;
    cout << "So ngau nhien la: " << number << endl;

    if(a == number) {
        cout << "Chuc mung! Ban da chon dung so!" << endl;
    } else {
        cout << "Ban khong trung so nay." << endl;
    }
    
    return 0;
}

