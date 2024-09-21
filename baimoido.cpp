#include<iostream>

using namespace std;

int main(){
	int n,a[100],c[100], count=0;
	char b[100]; 
	cin >> n;
	for (int i=0; i<n; i++){	
		cin >> b[i];
	} 
	for (int i=0; i<n; i++){
		a[i]=static_cast<int>(b[i]);
	} 

	for (int i = 0; i < n; i++) {
        bool exists = false;
        if ( ((a[i]>64)&&(a[i])<91) || ((a[i]>96)&&(a[i]<123)) ) exists = false;
        else exists = true ;
        for (int j = 0; j < count; j++) {
            if (a[i] == c[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            if (a[] < 91) {
                if (count < 98) { 
                    c[count] = a[i];
                    c[count+1] = a[i] + 32 ;
                    count += 2;
                }
            } 
			else {
                if (count < 98) { 
                	c[count+1] = a[i];
                    c[count] = a[i] - 32 ;
                    count += 2;
                }
            }
        }
    }
    cout << 26-(count/2);
}
