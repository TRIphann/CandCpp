/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;

//###INSERT CODE HERE -

struct day {
	int ngay;
	int thang;
	int nam;
}; 

struct CB {
	string machuyenbay;
	day ngaybay;
	float giobay;
	char noiden[35];
};

void nhapDSChuyenBay(CB a[],int &n){
	cin >> n;
	cin.ignore();
	for (int i=0; i<n; i++){
		getline(cin, a[i].machuyenbay);
		cin >> a[i].ngaybay.ngay >> a[i].ngaybay.thang >> a[i].ngaybay.nam;
		cin >> a[i].giobay;
		cin.ignore();
		cin.getline(a[i].noiden, 35); 
	} 
}

void check(CB a[], int n, const char* c){
	float max=a[0].giobay;
	int vitri=0;
	for (int i=1; i<n; i++){
		if (a[i].giobay>max){
			max=a[i].giobay;
			vitri=i;
		}
	}
	if (strncmp(a[vitri].noiden + strlen(a[vitri].noiden) - strlen(c), c, strlen(c))==0) cout <<"YES";
	else cout <<"NO";
}

int main()
{
    CB a[100];
    int n;
    char b[30];

    nhapDSChuyenBay(a,n); // Nhap danh sach cac chuyen bay
	cin.getline(b, 30); 
	
    check(a,n,b);

    return 0;
}
