#include <iostream>
using namespace std;

void inputArray(int a[], int na){
	for (int i=0; i<na; i++){
		cin >> a[i];
	}
}

void outputArray(int a[], int na){
	for (int i=0; i<na; i++){
		cout << a[i] << " ";
	}
}

bool KTSNT(int x)
{
	if(x<2)
		return false;
	for(int i=2; i<=x/2; i++)
		if(x%i==0)
			return false;
	return true;
}

void filterPrimes (int a[],int na,int b[],int nb,int m){
	int count =0;
	for (int i=0; i<na; i++){
		if (KTSNT(a[i])) {
			b[count]=a[i];
			count ++;
		}
	}
	
	if (count ==0 ) cout << "Mang a khong chua so nguyen to";
	else {
		if (count > nb){
			cout << "Mang a khong co du 10 so nguyen to";
			int* pNb = &nb;     
			int* pCount = &count;
			*pNb = *pCount;
		}
	}
	
	cout << nb;
}

int main()
{
    int na, a[100],nb, b[100];
    cin>>na;
    inputArray(a,na);
    cout<<"Mang a:"<<endl;
    outputArray(a,na);
    cout<<endl;
    int m;cin>>m;
    filterPrimes(a,na,b,nb,m);
    
}
