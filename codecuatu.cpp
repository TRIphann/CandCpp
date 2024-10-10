#include <iostream>
using namespace std;
int main (){
	int t, n, count = 0; cin >> t;
	string a [1000];
	while(t--){
		cin >> n;
		for( int i = 0; i<n; i++){
			cin>>a[i];
		}
		for( int i = 0; i<n; i++)
			if(a[i]=="."){
				continue;
			}else if(a[i]=="@"){
				count ++;
			}else{
				break;
			}
		cout << count << endl;
		}
}
