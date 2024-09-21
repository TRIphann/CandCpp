#include<iostream>

using namespace std; 

int main(){
    int a[100], n = 1, m, sochan = 0, count = 0, counts = 0, b = 0;
    bool ctn = false;
    
    cin >> a[0];
    while (a[n-1] != -1) {
        cin >> a[n];
        n++;
    }
    
    cin >> m;
    
    cout << "Before:";
    for (int i = 0; i < n-1; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    
    if (m == 0) {
        cout << "No deletion required";
        ctn = true;
    }
    for (int i = 0; i < n-1; i++) {
        if (a[i] % 2 == 0) sochan++;
    }
    if (sochan == 0) {
        cout << "There are no even numbers in the array";
        ctn = true;
    } else if (m == sochan) {
        cout << "After: Empty";
        ctn = true;
    } else if (m > sochan) {
        cout << "Not enough " << m << " even numbers but still delete\n";
    }
    
    if (!ctn) {
        cout << "After:";
        for (int i = 0; i < n-1; i++) {
            if (counts < m && a[i] % 2 == 0) {
                counts++;
                continue;
            }
            cout << " " << a[i];
            b++;
        }
        if (b == 0) cout << " Empty";
    }

    return 0;
}
