#include<iostream>

using namespace std;

int negative (int a){
	int b;
	if (a==0) b=1;
	else b=0;
	return b;
}

int multiplication (int p, int q){
	int a;
	if (p & q) a=1;
	else a=0;
	return a;
}

int Recruitment_permit (int p, int q){
	int a;
	if (p || q) a=1;
	else a=0;
	return a;
}

int entailment (int p, int q){
	int a;
	if ((p==1)||(q==1)) a=1;
	else a=0;
	return a;
}

int Two_way_permission (int p, int q){
	int a;
	if (p==q) a=1;
	else a=0;
	return a;
}
 
int main (){
	int p,q, select;
	cout << "1.Phep phu dinh\n2.Phep hoi\n3.Phep tuyen\n4.Phep keo theo\n5.Phep keo theo 2 chieu\nChon phep toan: "; 
	cin >> select;
	switch(select){
		case 1:
			cout << "Nhap so p: ";
			cin >> p;
			cout << negative(p);
			break;
		case 2:
			cout << "Nhap so p: ";
			cin >> p;
			cout << "Nhap so q: ";
			cin >> q;
			cout << multiplication(p,q);
			break;
		case 3:
			cout << "Nhap so p: ";
			cin >> p;
			cout << "Nhap so q: ";
			cin >> q;
			cout << Recruitment_permit(p,q);
			break;
		case 4:
			cout << "Nhap so p: ";
			cin >> p;
			cout << "Nhap so q: ";
			cin >> q;
			cout << entailment(p,q);
			break;
		case 5:
			cout << "Nhap so p: ";
			cin >> p;
			cout << "Nhap so q: ";
			cin >> q;
			cout << Two_way_permission(p,q);
			break;
		case 6:
			cout << "Loi !";
			break;
	}
	
}
