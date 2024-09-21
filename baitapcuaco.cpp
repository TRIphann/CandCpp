/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;



//###INSERT CODE HERE -

void inputArray(int a[], int na){
	for (int i = 0; i < na; i++){
		cin >> a[i];
	}
}

void outputArray(int a[], int na){
	for (int i = 0; i < na; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

bool KTSNT(int x){
	if (x < 2)
		return false;
	for (int i = 2; i <= x / 2; i++)
		if (x % i == 0)
			return false;
	return true;
}

void filterPrimes(int a[], int na, int b[], int &nb, int m){
	int count = 0;
	for (int i = 0; i < na; i++){
		if (KTSNT(a[i])) {
			b[count] = a[i];
			count++;
		}
	}

	nb = count;
	
	if (count == 0) {
		cout << "Mang a khong chua so nguyen to\n";
	} else {
		if (count < m) {
			cout << "Mang a khong co du " << m << " so nguyen to\n";
		} else {
			nb = m; 
		}
	}
}



int main()
{
    int na, a[100],nb, b[100];
    cin>>na;
    inputArray(a,na);
    cout<<"Mang a:"<<endl;
    outputArray(a,na);
    cout<<endl;
    int m;cin>>m;
    filterPrimes(a,na,b,nb,m); //tao ra mang b bang cach tach m so nguyen to tu a
    cout<<"Mang b:"<<endl;   
    outputArray(b,nb);

    return 0;
}

