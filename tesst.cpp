#include <iostream>
#include <algorithm>

using namespace std;

// H�m �?m s? l�?ng ph?n t? k trong m?ng
int count(int a[], int n, int k) {
    int counts = 0;
    for (int i = 0; i < n; i++) {
        if (k == a[i]) counts++;
    }
    return counts;
}

// H�m nh?p m?ng
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// H�m xu?t m?ng v� �?m s? l�?ng ph?n t?
void output(int a[], int n) {
    int b[100] = {0};  // Kh?i t?o m?ng b v?i gi� tr? 0
    int z = 0;
    sort(a, a + n);  // S?p x?p m?ng theo th? t? t�ng d?n
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < z; j++) {
            if ((a[i] == b[j]) || (a[i]!=0)){
                found = true;
                break;
            }
        }
        if (!found) {
            int counts = count(a, n, a[i]);
            cout << a[i] << " - " << counts << "; ";
            b[z] = a[i];
            z++;
        }
    }
}

int main() {
    int n, a[100];
    cin >> n;
    input(a, n);
    output(a, n);
}

