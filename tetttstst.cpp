
#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;


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

void xuatChuyenBayToiTinh(CB a[], int n, const char* c){		
	for (int i=0; i<n; i++){
		if (strcmp(a[i].noiden, c) == 0) {
			cout << a[i].machuyenbay << "\t" << a[i].ngaybay.ngay <<"/"<< a[i].ngaybay.thang <<"/"<< a[i].ngaybay.nam <<"\t"<<a[i].giobay<<"\t"<<a[i].noiden;
			if (i!=n-1) cout <<"\n"; 
		}
	}
	
}

int main()
{
    CB a[100];
    int n;

    nhapDSChuyenBay(a,n); // Nhap danh sach cac chuyen bay


    cout<<"Machuyen\t|Ngaybay\t|Giobay\t|Noiden\n";
    xuatChuyenBayToiTinh(a,n,"Ha Noi");

    return 0;
}

