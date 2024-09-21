#include <iostream>
using namespace std;

class PhanSo
{
	private:
		int tu, mau;
	public: 
		//Toán tử nhập xuất
		friend istream& operator >> (istream& is, PhanSo &p);   
		friend ostream& operator << (ostream& os, PhanSo p);
		//Toán tử số học
		PhanSo operator + (PhanSo a);
		PhanSo operator - (PhanSo a);
		PhanSo operator * (PhanSo a);
		PhanSo operator / (PhanSo a);
		//Toán tử so sánh
		bool operator == (PhanSo a);
		bool operator > (PhanSo a);
		bool operator < (PhanSo a);
		bool operator >= (PhanSo a);
		bool operator <= (PhanSo a);
		bool operator!= (PhanSo a);
		//Toán tử một ngôi;
		void operator ++();
		void operator --();
		//Một sô hàm hỗ trợ khác
		void Rutgon();
};
//Toán tử nhập xuất
istream& operator >> (istream& is, PhanSo &p)
{
	cout << "Nhap tu so: "; is >> p.tu;
	cout << "Nhap mau so: "; is >> p.mau;
	while(p.mau==0)
	{
		cout << "Mau phai khac 0. Vui long nhap lai: "; is >> p.mau;
	}
	return is;
}

ostream& operator << (ostream& os, PhanSo p)
{
	if (p.mau==1) os << p.tu;
	else if (p.mau==0) 
	{
		os << "Phan so khong ton tai!";
	}
	else if (p.tu==0) os << 0;
	else
	os << p.tu << "/" << p.mau;
	return os;
}

int ucln(int a, int b)
{
	a = abs(a);  b = abs(b);  //TH ước với số âm
	if (a==0 || b==0) return 1;
	while (a!=b)
	{
		(a>b)? a-=b : b-=a;
	}
	return a;	
}

void PhanSo::Rutgon()
{
	int uc = ucln(tu,mau);
	tu = tu / uc;
	mau = mau / uc;
}
//Toán tử số học
PhanSo PhanSo::operator + (PhanSo a)
{
	PhanSo kq;
	kq.tu = this->tu*a.mau + this->mau*a.tu;
	kq.mau = this->mau*a.mau;
	kq.Rutgon();
	return kq;
}
PhanSo PhanSo::operator - (PhanSo a)
{
	PhanSo kq;
	kq.tu = this->tu*a.mau - this->mau*a.tu;
	kq.mau = this->mau*a.mau;
	kq.Rutgon();
	return kq;
}
PhanSo PhanSo::operator * (PhanSo a)
{
	PhanSo kq;
	kq.tu = this->tu*a.tu;
	kq.mau = this->mau*a.mau;
	kq.Rutgon();
	return kq;
}
PhanSo PhanSo::operator / (PhanSo a)
{
	PhanSo kq;
	kq.tu = this->tu*a.mau;
	kq.mau = this->mau*a.tu;
	kq.Rutgon();
	return kq;
}

//Toán tử so sánh
bool PhanSo::operator == (PhanSo a)
{
	return tu*a.mau == mau*a.tu;		
}
bool PhanSo::operator > (PhanSo a)
{
	return tu*a.mau > mau*a.tu;		
}
bool PhanSo::operator < (PhanSo a)
{
	return tu*a.mau < mau*a.tu;	
}
bool PhanSo::operator >= (PhanSo a)
{
	return tu*a.mau >= mau*a.tu;	
}
bool PhanSo::operator <= (PhanSo a)
{
	return tu*a.mau <= mau*a.tu;	
}
bool PhanSo::operator!= (PhanSo a)
{
	return tu*a.mau != mau*a.tu;	
}
//Toán tử một ngôi
void PhanSo::operator ++()
{
	tu = tu + mau;
}
void PhanSo::operator --()
{
	tu = tu - mau;
}
int main()
{
	PhanSo a,b, tong, hieu, tich, thuong;
	cout << "Nhap phan so A:\n"; cin >> a; a.Rutgon();
	cout <<"Phan so A vua nhap: " << a << endl;
	
	cout << "\nNhap phan so B:\n"; cin >> b;  b.Rutgon();
	cout <<"Phan so B vua nhap: " << b << endl;
	
	cout << "\nKet qua so hoc:" << endl;
	tong=a+b; hieu=a-b; tich=a*b; thuong=a/b;
	cout << a << " + " << b << " = " << tong << endl;
	cout << a << " - " << b << " = " << hieu << endl;
	cout << a << " * " << b << " = " << tich << endl;
	cout << a << " / " << b << " = " << thuong << endl;
	
	cout << "\nKet qua so sanh:" << endl;
	cout << "== : "; if (a==b) cout << a << " bang " << b << endl; else cout << a<< " khong bang " << b <<  endl;
	cout << "> : "; if (a>b) cout << a << " lon hon " << b << endl; else cout << a << " khong lon hon " << b << endl;
	cout << "< : "; if (a<b) cout << a << " be hon " << b << endl; else cout << a << " khong be hon " << b << endl;
	cout << ">= : "; if (a>=b) cout << a << " lon hon hoac bang " << b << endl; else cout << a << " khong lon hon hoac bang " << b << endl;
	cout << "<= : "; if (a<=b) cout << a << " nho hon hoac bang " << b << endl; else cout << a << " khong nho hon hoac bang " << b << endl;
	cout << "!= : "; if (a!=b) cout << a << " khac " << b << endl; else cout << a << " khong khac " << b << endl;
	
	cout << "\nKet qua toan tu mot ngoi:" << endl;	 
	cout << a << "++"; ++a; cout << " = " << a << endl; --a;
	cout << a << "--"; --a; cout << " = " << a << endl; 
	cout << b << "++"; ++b; cout << " = " << b << endl; --b;
	cout << b << "--"; --b; cout << " = " << b << endl;
	return 0;
}