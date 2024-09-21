#include<iostream>
#include<time.h>
using namespace std;

int main() {
	cout << "Nhap so tu 1 toi 999999: ";
	int ve_so;
	srand(time(NULL));
	cin >> ve_so;
	if(ve_so > 999999) {
		cout << "Vuot qua gioi han !";
		return 0;
	}
	int randomNumber = rand() % 999999 + 1;
	if(randomNumber != ve_so) {
		cout << "Chuc ban may man lan sau !" << endl;
		cout << "Ve so trung thuong co so: " << randomNumber;
	}else {
		cout << "Ban da trung thuong !";
	}
}
