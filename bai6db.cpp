

#include <iostream>
using namespace std;


void bai6(int a[], int n, int m, int sochan){
	int dem=0;
	if (sochan < m && sochan !=0){
		cout << "Not enough "<<m<<" even numbers but still delete\n";
		cout <<"After:";
		for (int i=0; i<n-1; i++){
			if (a[i]%2==0) continue;
			cout << a[i] << " ";
			dem++;
		}
		if (dem==0) cout<<"Empty";
		return;
	}
	if (sochan==0) {
		cout << "There are no even numbers in the array";
		return;
	}
	if (m==0){
		cout << "No deletion required";
		return;
	}
	cout <<"After:";
		for (int i=0; i<n-1; i++){
			if (a[i]%2==0&&dem<m) continue;
			cout << a[i] << " ";
			dem++;
		}
		if (dem==0) cout<<"Empty";
}


int main() {
    int a[100], n = 1, m, sochan = 0, counts = 0, b = 0;
    bool ctn = false;

    cin >> a[0];
    while (a[n-1] != -1) {
        cin >> a[n];
        n++;
    }
    cin >> m;
	
	for (int i=0; i< n-1 ; i++){
		cout << a[i] << " ";
	} 
	cout << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) sochan++;
    }
	
	bai6(a,n,m,sochan); 
	
    return 0;
}
