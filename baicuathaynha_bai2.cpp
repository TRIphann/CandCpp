#include <iostream> 
using namespace std;

int toida(int a[][100], int n, int b ) {
	int doi=a[0][b]; 
	for (int i=1; i<n; i++){
		if (doi<a[i][b]) {
			doi=a[i][b];
		}
	}
	return doi;
}


int main() {
	int n,a[100][100],b[100],doi;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<11; j++) {
		cin >> a[i][j];
	}
	}

	
	for (int i=0; i<11; i++) {
		b[i]=toida(a,n,i);
	}
	
 
} 
	
