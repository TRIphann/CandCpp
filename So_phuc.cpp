#include<iostream>
#include<cmath>
using namespace std;

class SoPhuc {
private:
    int thuc;
    int ao;
public:
    SoPhuc();
    SoPhuc(int thuc, int ao);
    SoPhuc(int thuc);
    SoPhuc(const SoPhuc &x);

    friend istream &operator>>(istream &in, SoPhuc &x);
    friend ostream &operator<<(ostream &out, const SoPhuc &x);
    void nhap();
    void xuat() const;

    int getThuc() const;
    int getAo() const;
    void setThuc(int);
    void setAo(int);

    int module() const;
    
    SoPhuc operator + (const SoPhuc&) const;
    SoPhuc operator - (const SoPhuc&) const;
    SoPhuc operator * (const SoPhuc&) const;
    SoPhuc operator / (const SoPhuc&) const;
    SoPhuc& operator=(const SoPhuc&);
    SoPhuc& operator+=(const SoPhuc&);
    SoPhuc& operator-=(const SoPhuc&);

    bool operator>(const SoPhuc&) const;
    bool operator<(const SoPhuc&) const;
    bool operator==(const SoPhuc&) const;
    bool operator>=(const SoPhuc&) const;
    bool operator<=(const SoPhuc&) const;
    bool operator!=(const SoPhuc&) const;

    SoPhuc operator++(int);
    SoPhuc operator--(int);

    operator float() const;
    operator int() const;
};

SoPhuc::SoPhuc() {
    thuc = 0;
    ao = 0;
}

SoPhuc::SoPhuc(int thuc, int ao) {
    this->thuc = thuc;
    this->ao = ao;
}

SoPhuc::SoPhuc(int thuc) {
    this->thuc = thuc;
    this->ao = 0;
}

SoPhuc::SoPhuc(const SoPhuc &x) {
    *this = x;
}

int SoPhuc::getThuc() const {
    return this->thuc;
}

int SoPhuc::getAo() const {
    return this->ao;
}

void SoPhuc::setThuc(int t) {
    this->thuc = t;
}

void SoPhuc::setAo(int a) {
    this->ao = a;
}

void SoPhuc::nhap() {
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
} 

void SoPhuc::xuat() const {
    if(thuc == 0) {
        if(ao != 0) {
            if(ao == 1) cout << "i";
            else if(ao == -1) cout << "-i";
            else cout << ao << "i";
        }
        else cout << "0";
    } else {
        cout << thuc;
        if(ao != 0) {
            if(ao > 0) cout << "+";
            if(ao == 1) cout << "i";
            else if(ao == -1) cout << "-i";
            else cout << ao << "i";
        }
    }
}

istream &operator >> (istream &in, SoPhuc &x) {
    in >> x.thuc;
    in >> x.ao;
    return in;
}

ostream &operator << (ostream &out, const SoPhuc &x) {
    if(x.thuc == 0) {
        if(x.ao != 0) {
            if(x.ao == 1) out << "i";
            else if(x.ao == -1) out << "-i";
            else out << x.ao << "i";
        }
        else out << "0";
    } else {
        out << x.thuc;
        if(x.ao != 0) {
            if(x.ao > 0) out << "+";
            if(x.ao == 1) out << "i";
            else if(x.ao == -1) out << "-i";
            else out << x.ao << "i";
        }
    }
    return out;
}

int SoPhuc::module() const {
    return sqrt(thuc * thuc + ao * ao);
}

SoPhuc SoPhuc::operator + (const SoPhuc &a) const {
    return SoPhuc(thuc + a.thuc, ao + a.ao);
}

SoPhuc SoPhuc::operator - (const SoPhuc &a) const {
    return SoPhuc(thuc - a.thuc, ao - a.ao);
}

SoPhuc SoPhuc::operator * (const SoPhuc &a) const {
    return SoPhuc(thuc * a.thuc - ao * a.ao, thuc * a.ao + ao * a.thuc);
}

SoPhuc SoPhuc::operator / (const SoPhuc &a) const {
    int mau = a.thuc * a.thuc + a.ao * a.ao;
    if(mau == 0){
        cout << "Khong The chia vi module = 0" << endl;
    }
    return SoPhuc((thuc * a.thuc + ao * a.ao) / mau, (ao * a.thuc - thuc * a.ao) / mau);
}

SoPhuc& SoPhuc::operator=(const SoPhuc &a) {
    if(*this != a) {
        this->thuc = a.thuc;
        this->ao = a.ao;
    }
    return *this;
}

SoPhuc& SoPhuc::operator+=(const SoPhuc &a) {
    *this = *this + a;
    return *this;
}

SoPhuc& SoPhuc::operator-=(const SoPhuc &a) {
    *this = *this - a;
    return *this;
}

bool SoPhuc::operator>(const SoPhuc&a) const {
    return module() > a.module();
}

bool SoPhuc::operator<(const SoPhuc&a) const {
    return module() < a.module();
}

bool SoPhuc::operator == (const SoPhuc &a) const {
    return (thuc == a.thuc && ao == a.ao);
}

bool SoPhuc::operator>=(const SoPhuc&a) const {
    return !(*this < a);
}

bool SoPhuc::operator<=(const SoPhuc&a) const {
     return !(*this > a);
}

bool SoPhuc::operator!=(const SoPhuc&a) const {
    return !(*this == a);
}

SoPhuc SoPhuc::operator++(int) {
    SoPhuc temp = *this;
    this->thuc += 1;
    return temp; 
}

SoPhuc SoPhuc::operator--(int) {
    SoPhuc temp = *this;
    this->thuc -= 1;
    return temp; 
}



SoPhuc::operator float() const {
    return float(thuc);
}

SoPhuc::operator int() const {
    return int(thuc);
}

int main() {
    SoPhuc sp1, sp2, ketqua;

    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    cout << "So phuc thu nhat: ";
    sp1.xuat();

    cout << "\nSo phuc thu hai: ";
    sp2.xuat();

    ketqua = sp1 + sp2;
    cout << "\nTong: ";
    ketqua.xuat();

    ketqua = sp1 - sp2;
    cout << "\nHieu: ";
    ketqua.xuat();

    ketqua = sp1 * sp2;
    cout << "\nTich: ";
    ketqua.xuat();

    ketqua = sp1 / sp2;
    cout << "\nThuong: ";
    ketqua.xuat();

    if (sp1 == sp2) {
        cout << "\nsp1 = sp2\n";
    } else {
        cout << "\nsp1 != sp2\n";
    }

    if (sp1 > sp2) {
        cout << "So phuc thu nhat co module lon hon so phuc thu hai.\n";
    } else if (sp1 < sp2) {
        cout << "So phuc thu hai co module lon hon so phuc thu nhat.\n";
    } else {
        cout << "Hai so phuc co module bang nhau.\n";
    }

    SoPhuc sp3 = sp1;
    cout << "So phuc sp3 sau khi gan sp1: ";
    sp3.xuat();

    sp3++;
    cout << "\nSo phuc sp3 sau khi gia tang: ";
    sp3.xuat();

    sp3--;
    cout << "\nSo phuc sp3 sau khi giam: ";
    sp3.xuat();

    float f = float(sp1);
    int i = int(sp2);

    cout << "\nfloat(sp1) = " << f;
    cout << "\nint(sp2) = " << i;

    return 0;
}
