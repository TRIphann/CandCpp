/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;


//###INSERT CODE HERE -

void inputArray(int a[100][100], int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
}

void horizontal_invert(int a[100][100], int n, int m){
	int i=0,j=n-1;
	while (j>i){
		for (int k=0; k<m; k++){
			int trade=a[i][k];
			a[i][k]=a[j][k];
			a[j][k]=trade;
		}
		i++;
		j--;
	}
}

void outputArray(int a[100][100], int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << a[i][j] << " ";
		}
		if (i!=n-1) cout <<"\n";
	}
}

int main()
{
    int n, m;
    cin >> n >> m;


    int a[100][100];

    inputArray(a, n, m);

    horizontal_invert(a, n, m);

    outputArray(a, n, m);

    return 0;
}
