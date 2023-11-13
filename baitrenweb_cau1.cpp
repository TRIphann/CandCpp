#include<iostream>
using namespace std;

int main(){
	int n,a[100][100],b=0,c[100],dem=0;
	cin >>n;
	for (int i=1; i<n/2; i++){
		if (n%i==0){
			a[b][0]=i;
			a[b][1]=n/i;
			b++;
		}
	}
	
	for (int i=0; i<b; i++){
		c[i]=a[i][1]-a[i][0];
	}
	

	int doi=c[0];
	for (int i=1; i<b; i++){
		if (doi>c[i] && c[i]>=0) {
			doi=c[i];
			dem=i;
	}
	}
	cout << a[dem][0]<<" "<<a[dem][1];
	
}  
