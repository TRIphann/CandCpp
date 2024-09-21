#include <iostream>

using namespace std;

int main() {
    int n, a[100][100], m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j=0; j < n; j++){
        	cin >> a[i][j];
		}
    }
    int sum;
    for (int i = 0; i < n; i++) {
        for (int j=0; j < n; j++){
        	sum = sum + a[i][j];
		}
    }
    
    cout << sum;
}

