#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class HocSinh {
	private:
		string ten;
		float toan, van;
		int ma; 
		static int maHS;
	public:
		HocSinh();
		HocSinh(string ten, float toan, float van);
		HocSinh(string ten);
		HocSinh(const HocSinh &p);
		~HocSinh();
		friend istream &operator>>(istream &in, HocSinh &p);
		friend ostream &operator<<(ostream &out, HocSinh p);
		friend bool operator>(const HocSinh &a, const HocSinh &b);
		float adv() const;
		friend bool operator>=(const HocSinh &a, const HocSinh &b);
  		friend bool operator<(const HocSinh &a, const HocSinh &b);
    	friend bool operator<=(const HocSinh &a, const HocSinh &b);
    	friend bool operator==(const HocSinh &a, const HocSinh &b);
    	friend bool operator!=(const HocSinh &a, const HocSinh &b);
    	HocSinh &operator=(const HocSinh &a);
		
};
int HocSinh::maHS = 1000;

bool operator>=(const HocSinh &a, const HocSinh &b) {
    return a.adv() >= b.adv();
}

bool operator<=(const HocSinh &a, const HocSinh &b) {
    return a.adv() <= b.adv();
}

bool operator<(const HocSinh &a, const HocSinh &b) {
    return a.adv() < b.adv();
}

bool operator==(const HocSinh &a, const HocSinh &b) {
    return a.adv() == b.adv();
}

bool operator!=(const HocSinh &a, const HocSinh &b) {
    return a.adv() != b.adv();  // S?a l?i ? ðây
}

HocSinh &HocSinh::operator=(const HocSinh &a) {
    if (this != &a) {
        this->ten = a.ten;
        this->toan = a.toan;
        this->van = a.van;
    }
    return *this;
}

float HocSinh::adv() const {
	return (this->toan + this->van) / 2;
}					

bool operator>(const HocSinh &a, const HocSinh &b) {
	return a.adv() > b.adv();
}

ostream &operator<<(ostream &out, HocSinh p) {
	out << p.ten << " " << p.toan << " " << p.van;
	return out;
}

istream &operator>>(istream &in, HocSinh &p) {
	getline(in, p.ten);  // Nh?p tên
	in >> p.toan;
	in >> p.van;
	in.ignore();  // B? qua k? t? xu?ng d?ng sau khi nh?p s?
	return in;
}

HocSinh::HocSinh() {
	ten = " ";
	toan = van = 0;
	ma = maHS++;
}

HocSinh::HocSinh(string ten) {
	this->ten = ten;
	this->toan = this->van = 0;
}

HocSinh::HocSinh(string ten, float toan, float van) {
	this->ten = ten;
	this->toan = toan;
	this->van = van;
}

HocSinh::HocSinh(const HocSinh &p) {
	ten = p.ten;
	toan = p.toan;
	van = p.van;
}

HocSinh::~HocSinh() {}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore();  // B? qua k? t? xu?ng d?ng sau khi nh?p s? lý?ng

    HocSinh *ds = new HocSinh[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":" << endl;
        cin >> ds[i];
        cout << endl;
    }

    cout << "Danh sach hoc sinh:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ds[i] << endl;
    }

    delete[] ds;
    return 0;
}

