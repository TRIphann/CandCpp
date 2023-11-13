#include <iostream> 
using namespace std;

int main () {
	int n,thu[100],chiphi[100],a[100],dem=0,b=0;
	cin >> n;
	
	for (int i=0; i<n; i++){
		cin >>thu[i];
	}
	
	for (int i=0; i<n; i++){
		cin >> chiphi[i];
	}
	
	for (int i=0; i<n; i++){
		if (thu[i]>=chiphi[i]) {
			dem++;
		}
		else {
			a[b]=dem;
			dem=0;
			b++;
		}
	}
	
	
	int c=a[0];
	for (int i=1; i<b; i++){
		if (c<a[i]){
			c=a[i];
		}

	}
	cout << c;
} 
// 4 5 10 11 3 16 8 9
// 3 6 10 7 3 12 1 10
