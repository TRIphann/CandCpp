#include<iostream>

using namespace std;

void input(int a[], int n){
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

void output(int a[], int n, int k, int x){
	for (int i=n-1; i>=(k-1); i--){
        a[i+1]=a[i];
    }
    a[k-1]=x;
    for (int i=0; i<n+1; i++){
        cout << a[i]<<" ";
    }
}

int main(){
    int a[100],n,k,x;
    cin >> n;
    input(a,n);
    cin >> k >> x;
    output(a,n,k,x);
}
