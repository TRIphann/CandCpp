#include <iostream>
#include <math.h>
using namespace std;

class PhanSo
{
	private:
		int tuso, mauso;
	public: 
		PhanSo();
		PhanSo(int tuso, int mauso);
		PhanSo(const PhanSo &p); 
		
		friend istream& operator >> (istream& is, PhanSo &p);   
		friend ostream& operator << (ostream& os, PhanSo p);
		
		PhanSo operator + (PhanSo a);
		PhanSo operator - (PhanSo a);
		PhanSo operator * (PhanSo a);
		PhanSo operator / (PhanSo a);

		bool operator == (PhanSo a);
		bool operator > (PhanSo a);
		bool operator < (PhanSo a);
		bool operator >= (PhanSo a);
		bool operator <= (PhanSo a);
		bool operator!= (PhanSo a);

		void operator ++();
		void operator --();

		void Rutgon();
};

PhanSo::PhanSo(){
	tuso=0;
	mauso=1;
}

PhanSo::PhanSo(int tuso, int mauso){
	this->tuso=tuso;
	this->mauso=mauso;
}

PhanSo::PhanSo(const PhanSo &p){
	tuso=p.tuso;
	mauso=p.mauso;
}

istream& operator >> (istream& is, PhanSo &p)
{
	cout << "Nhap tu so: "; is >> p.tuso;
	cout << "Nhap mau so: "; is >> p.mauso;
	while(p.mauso == 0)
	{
		cout << "Mau phai khac 0. Vui long nhap lai: "; is >> p.mauso;
	}
	return is;
}

ostream& operator << (ostream& os, PhanSo p)
{
	if (p.mauso == 1) os << p.tuso;
	else if (p.mauso == 0) 
	{
		os << "Phan so khong ton tai!";
	}
	else if (p.tuso == 0) os << 0;
	else
		os << p.tuso << "/" << p.mauso;
	return os;
}

int ucln(int a, int b)
{
	a = abs(a);  b = abs(b);
	if (a == 0 || b == 0) return 1;
	while (a != b)
	{
		(a > b) ? a -= b : b -= a;
	}
	return a;	
}

void PhanSo::Rutgon()
{
	int uc = ucln(tuso, mauso);
	tuso = tuso / uc;
	mauso = mauso / uc;
}

PhanSo PhanSo::operator + (PhanSo a)
{
	PhanSo ketqua;
	ketqua.tuso = this->tuso * a.mauso + this->mauso * a.tuso;
	ketqua.mauso = this->mauso * a.mauso;
	ketqua.Rutgon();
	return ketqua;
}

PhanSo PhanSo::operator - (PhanSo a)
{
	PhanSo ketqua;
	ketqua.tuso = this->tuso * a.mauso - this->mauso * a.tuso;
	ketqua.mauso = this->mauso * a.mauso;
	ketqua.Rutgon();
	return ketqua;
}

PhanSo PhanSo::operator * (PhanSo a)
{
	PhanSo ketqua;
	ketqua.tuso = this->tuso * a.tuso;
	ketqua.mauso = this->mauso * a.mauso;
	ketqua.Rutgon();
	return ketqua;
}

PhanSo PhanSo::operator / (PhanSo a)
{
	PhanSo ketqua;
	ketqua.tuso = this->tuso * a.mauso;
	ketqua.mauso = this->mauso * a.tuso;
	ketqua.Rutgon();
	return ketqua;
}

bool PhanSo::operator == (PhanSo a)
{
	return tuso * a.mauso == mauso * a.tuso;		
}

bool PhanSo::operator > (PhanSo a)
{
	return tuso * a.mauso > mauso * a.tuso;		
}

bool PhanSo::operator < (PhanSo a)
{
	return tuso * a.mauso < mauso * a.tuso;	
}

bool PhanSo::operator >= (PhanSo a)
{
	return tuso * a.mauso >= mauso * a.tuso;	
}

bool PhanSo::operator <= (PhanSo a)
{
	return tuso * a.mauso <= mauso * a.tuso;	
}

bool PhanSo::operator!= (PhanSo a)
{
	return tuso * a.mauso != mauso * a.tuso;	
}

void PhanSo::operator ++()
{
	tuso = tuso + mauso;
}

void PhanSo::operator --()
{
	tuso = tuso - mauso;
}

int main()
{
	PhanSo p1, p2, tong, hieu, tich, thuong;
	cout << "Nhap phan so P1:\n"; cin >> p1; p1.Rutgon();
	cout <<"Phan so P1 vua nhap: " << p1 << endl;
	
	cout << "\nNhap phan so P2:\n"; cin >> p2;  p2.Rutgon();
	cout <<"Phan so P2 vua nhap: " << p2 << endl;
	
	cout << "\nKet qua phep toan:" << endl;
	tong = p1 + p2; hieu = p1 - p2; tich = p1 * p2; thuong = p1 / p2;
	cout << p1 << " + " << p2 << " = " << tong << endl;
	cout << p1 << " - " << p2 << " = " << hieu << endl;
	cout << p1 << " * " << p2 << " = " << tich << endl;
	cout << p1 << " / " << p2 << " = " << thuong << endl;
	
	cout << "\nSo sanh phan so:" << endl;
	cout << "== : "; if (p1 == p2) cout << p1 << " bang " << p2 << endl; else cout << p1 << " khong bang " << p2 <<  endl;
	cout << "> : "; if (p1 > p2) cout << p1 << " lon hon " << p2 << endl; else cout << p1 << " khong lon hon " << p2 << endl;
	cout << "< : "; if (p1 < p2) cout << p1 << " nho hon " << p2 << endl; else cout << p1 << " khong nho hon " << p2 << endl;
	cout << ">= : "; if (p1 >= p2) cout << p1 << " lon hon hoac bang " << p2 << endl; else cout << p1 << " khong lon hon hoac bang " << p2 << endl;
	cout << "<= : "; if (p1 <= p2) cout << p1 << " nho hon hoac bang " << p2 << endl; else cout << p1 << " khong nho hon hoac bang " << p2 << endl;
	cout << "!= : "; if (p1 != p2) cout << p1 << " khac " << p2 << endl; else cout << p1 << " khong khac " << p2 << endl;
	
	cout << "\nToan tu mot ngoi:" << endl;	 
	cout << p1 << "++"; ++p1; cout << " = " << p1 << endl; --p1;
	cout << p1 << "--"; --p1; cout << " = " << p1 << endl; 
	cout << p2 << "++"; ++p2; cout << " = " << p2 << endl; --p2;
	cout << p2 << "--"; --p2; cout << " = " << p2 << endl;
	return 0;
}

