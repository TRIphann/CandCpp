#include <iostream>
#include <cmath>
using namespace std;

class DonThuc
{
private:
    int heSo;
    int soMu;

public:
    DonThuc();
    DonThuc(int heSo, int soMu);
    DonThuc(const DonThuc &p);

    int getHeSo() const;
    void setHeSo(int heSo);
    int getSoMu() const;
    void setSoMu(int soMu);

    void nhap();
    void xuat() const;

    friend istream &operator>>(istream &in, DonThuc &x);
    friend ostream &operator<<(ostream &out, const DonThuc &x);

    int tinhGiaTri(int x);

    DonThuc operator+(const DonThuc &x) const;
    DonThuc operator-(const DonThuc &x) const;
    DonThuc operator*(const DonThuc &x) const;
    DonThuc operator/(const DonThuc &x) const;

    DonThuc& operator=(const DonThuc &x);
    DonThuc& operator+=(const DonThuc &x);
    DonThuc& operator-=(const DonThuc &x);

    bool operator>(const DonThuc &x) const;
    bool operator<(const DonThuc &x) const;
    bool operator==(const DonThuc &x) const;
    bool operator>=(const DonThuc &x) const;
    bool operator<=(const DonThuc &x) const;

    DonThuc& operator++();
    DonThuc& operator--();

    DonThuc operator!();
    DonThuc operator~();
};


DonThuc::DonThuc(){
	heSo=0;
	soMu=0;
}

DonThuc::DonThuc(int heSo, int soMu){
	this->heSo=heSo;
	this->soMu=soMu;
}

DonThuc::DonThuc(const DonThuc &p){
	heSo=p.heSo;
	soMu=p.soMu;
}


int DonThuc::getHeSo() const {
    return heSo;
}

void DonThuc::setHeSo(int heSo) {
    this->heSo = heSo;
}

int DonThuc::getSoMu() const {
    return soMu;
}

void DonThuc::setSoMu(int soMu) {
    this->soMu = soMu;
}

void DonThuc::nhap() {
    cout << "Nhap he so: ";
    cin >> heSo;
    cout << "Nhap so mu: ";
    cin >> soMu;
}

void DonThuc::xuat() const {
    if (heSo == 0) cout << 0;
    else {
        if (heSo == -1) cout << "-";
        else if (heSo != 1) cout << heSo;
        if (soMu != 0) {
            cout << "x";
            if (soMu != 1) cout << "^" << soMu;
        }
    }
}

istream &operator>>(istream &in, DonThuc &x) {
    in >> x.heSo >> x.soMu;
    return in;
}

ostream &operator<<(ostream &out, const DonThuc &x) {
    if (x.heSo == 0) out << 0;
    else {
        if (x.heSo == -1) out << "-";
        else if (x.heSo != 1) out << x.heSo;
        if (x.soMu != 0) {
            out << "x";
            if (x.soMu != 1) out << "^" << x.soMu;
        }
    }
    return out;
}

int DonThuc::tinhGiaTri(int x) {
    return heSo * pow(x, soMu);
}

DonThuc DonThuc::operator+(const DonThuc &x) const {
    if (soMu == x.soMu) {
        return DonThuc(heSo + x.heSo, soMu);
    }
    return DonThuc(0, 0);
}

DonThuc DonThuc::operator-(const DonThuc &x) const {
    if (soMu == x.soMu) {
        return DonThuc(heSo - x.heSo, soMu);
    }
    return DonThuc(0, 0);
}

DonThuc DonThuc::operator*(const DonThuc &x) const {
    return DonThuc(heSo * x.heSo, soMu + x.soMu);
}

DonThuc DonThuc::operator/(const DonThuc &x) const {
    if (x.heSo == 0) {
        cout << "Khong the chia cho 0!";
        return DonThuc();
    }
    return DonThuc(heSo / x.heSo, soMu - x.soMu);
}

DonThuc& DonThuc::operator=(const DonThuc &x) {
    if (this != &x) {
        heSo = x.heSo;
        soMu = x.soMu;
    }
    return *this;
}

DonThuc& DonThuc::operator+=(const DonThuc &x) {
    if (soMu == x.soMu) {
        heSo += x.heSo;
    }
    return *this;
}

DonThuc& DonThuc::operator-=(const DonThuc &x) {
    if (soMu == x.soMu) {
        heSo -= x.heSo;
    }
    return *this;
}

bool DonThuc::operator>(const DonThuc &x) const {
    return heSo > x.heSo;
}

bool DonThuc::operator<(const DonThuc &x) const {
    return heSo < x.heSo;
}

bool DonThuc::operator==(const DonThuc &x) const {
    return (soMu == x.soMu && heSo == x.heSo);
}

bool DonThuc::operator>=(const DonThuc &x) const {
    return !(heSo < x.heSo);
}

bool DonThuc::operator<=(const DonThuc &x) const {
    return !(heSo > x.heSo);
}

DonThuc& DonThuc::operator++() {
    soMu += 1;
    return *this;
}

DonThuc& DonThuc::operator--() {
    soMu -= 1;
    return *this;
}

DonThuc DonThuc::operator!() {
    if (soMu == 0) {
        return DonThuc(0, 0);
    }
    return DonThuc(heSo * soMu, soMu - 1);
}

DonThuc DonThuc::operator~() {
    return DonThuc(heSo / (soMu + 1), soMu + 1);
}

int main() {
    DonThuc dt1, dt2;

    cout << "Nhap don thuc thu nhat:\n";
    dt1.nhap();

    cout << "Nhap don thuc thu hai:\n";
    dt2.nhap();

    cout << "Don thuc thu nhat: " << dt1 << endl;
    cout << "Don thuc thu hai: " << dt2 << endl;

    DonThuc tong = dt1 + dt2;
    cout << "Tong hai don thuc: " << tong << endl;

    DonThuc hieu = dt1 - dt2;
    cout << "Hieu hai don thuc: " << hieu << endl;

    DonThuc tich = dt1 * dt2;
    cout << "Tich hai don thuc: " << tich << endl;

    DonThuc thuong = dt1 / dt2;
    cout << "Thuong hai don thuc: " << thuong << endl;

    if (dt1 == dt2) {
        cout << "Don thuc 1 va Don thuc 2 la bang nhau." << endl;
    } else if (dt1 > dt2) {
        cout << "Don thuc 1 co he so lon hon Don thuc 2." << endl;
    } else {
        cout << "Don thuc 1 co he so nho hon Don thuc 2." << endl;
    }

    DonThuc dt3 = dt1;
    cout << "Don thuc 3 (sau khi gan don thuc 1): " << dt3 << endl;

    ++dt3;
    cout << "Don thuc 3 (sau khi tang so mu): " << dt3 << endl;

    --dt3;
    cout << "Don thuc 3 (sau khi giam so mu): " << dt3 << endl;

    DonThuc daoHamDt1 = !dt1;
    cout << "Dao ham don thuc 1: " << daoHamDt1 << endl;

    DonThuc nguyenHamDt2 = ~dt2;
    cout << "Nguyen ham don thuc 2: " << nguyenHamDt2 << endl;

    return 0;
}

