
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

using namespace std;

//###INSERT CODE HERE -

void inputArray(int a[],int &n){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
}

void printArray(int a[], int n){
	for (int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

void reverseArray(int a[], int b, int c){
	while(b<c){
		if ((a[b]%2==0)&&(a[c]%2==0)){
			int trade=a[b];
			a[b]=a[c];
			a[c]=trade;
			b++;
			c--;
		}
		if ((a[b]%2!=0)&&(a[c]%2==0)){
			b++;	
		}
		if ((a[b]%2==0)&&(a[c]%2!=0)){
			c--;
		}
		if ((a[b]%2!=0)&&(a[c]%2!=0)){
			b++;
			c--;
		}
	}
}

int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien dao mang
    *  Ham co 3 tham so, 2 tham so cuoi cung tuong ung voi chi so dau va chi so cuoi cua mang
    */
    reverseArray(a, 0, n-1);

    cout << "Reversed array is" << endl;

    // In mang sau khi dao
    printArray(a, n);

    return 0;
}
