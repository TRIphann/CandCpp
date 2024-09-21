/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -

void inputMatrix(char a[100][100], int &n){
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if ((a[i][j]==120)||(a[i][j]==111)){
				a[i][j]=a[i][j]-32;
			}
		}
	}
}

void outputMatrix(char a[100][100], int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << a[i][j] << " ";
		}
		if (i!=n-1) cout << "\n";
	}
	cout << endl;
}

void checkWin(char a[100][100], int n, int x, int y){
	if ((x<0)||(x>2)||(y<0)||(y>2)){
		cout << "Invalid";
	}
	else if (a[x][y]!=45) {
		cout <<"Not empty";
	}
	else {
		bool b=false;
		if (!b){
			int count=0;
			for (int i=0; i<3; i++){
				if (a[x][i]==88) count++;
			}
			if (count == 2){
				cout<<"You win at row "<< x;
				b=true;
			}
			
		}
		
		if (!b){
			int count=0;
			for (int i=0; i<3; i++){
				if (a[i][y]==88) count++;
			}
			if (count == 2){
				cout<<"You win at column "<< y;
				b=true;
			}
		}
		
		if (!b){
			if (x==y){
				int count=0;
				for (int i=0; i<3; i++){
					if (a[i][i]==88) count++;
				}
				if (count == 2){
					cout<<"You win on the main diagonal ";
					b=true;
				}
			}
		}
		if (!b){
			int count=0;
			if ( ( (x==0)&&(y==2) ) || ((x==1)&&(y==1)) || ((x==2)&&(y==0)) ){
				int k=0,h=2;
				while (h>0) {
					if (a[k][h]==88) count ++;
					k++;
					h--;
				}
				if (count == 2){
					cout<<"You win on the secondary diagonal ";
					b=true;
				}
			}
		}
		if (!b) {
			int count=0;
			for (int i=0; i<3; i++){
				for (int j=0; j<3; j++){
					if ((i==x)&&(j==y)) continue;
					if (a[i][j]==45) count++;
				}
			}
			if (count == 0) cout<<"Game over";
			else cout <<"My turn";
		}
	}
}

int main()
{
    int n; char a[100][100];
    inputMatrix(a,n);
    cout<<"Board:\n";
    outputMatrix(a,n);
    int x,y;
    cin>>x>>y;
    cout<<"You just place an X on ("<<x<<","<<y<<")"<<endl;
    checkWin(a,n,x,y);
    return 0;
}

