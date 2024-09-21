#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

class PhanSo
{
private:
    ll tu;
    ll mau;

public:
    PhanSo();
    PhanSo(ll tu, ll mau);
    void nhap(PhanSo &);
    void xuat() const;
    friend istream &operator>>(istream &in, PhanSo &x);
    friend ostream &operator<<(ostream &out, const PhanSo &x);
    ll getTu() const;
    ll getMau() const;
    void setTu(ll tu);
    void setMau(ll mau);
    void nghichDao();
    void rutgon();
    PhanSo operator+(const PhanSo &) const;
    PhanSo operator-(const PhanSo &) const;
    PhanSo operator*(const PhanSo &) const;
    PhanSo operator/(const PhanSo &) const;
    PhanSo& operator=(const PhanSo &);
    PhanSo& operator+=(const PhanSo &);
    PhanSo& operator-=(const PhanSo &);
    bool operator>(const PhanSo &) const;
    bool operator<(const PhanSo &) const;
    bool operator==(const PhanSo &) const;
    bool operator>=(const PhanSo &) const;
    bool operator<=(const PhanSo &) const;
    bool operator!=(const PhanSo &) const;
    PhanSo operator++();
    PhanSo operator--();
    operator float() const;
    operator int() const;
    int soSanh(const PhanSo &) const;
};

PhanSo::PhanSo()
{
    tu = 0;
    mau = 1;
}

PhanSo::PhanSo(ll tu, ll mau)
{
    this->tu = tu;
    this->mau = mau;
}

void PhanSo::nhap(PhanSo &ps)
{
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    cout << "Nhap mau so: ";
    cin >> ps.mau;
    while (ps.mau == 0)
    {
        cout << "Mau so khong the bang 0, vui long nhap lai: " << endl;
        cin >> ps.mau;
    }
}

void PhanSo::xuat() const
{
    if (tu == 0)
        cout << 0;
    else if (mau == 1)
        cout << tu;
    else if (mau == -1)
        cout << -tu;
    else
        cout << (mau < 0 ? -tu : tu) << "/" << abs(mau);
}

istream& operator>>(istream &in, PhanSo &x) {
    in >> x.tu;
    in >> x.mau;

    while (x.mau == 0) {
        cout << "Mau so khong the bang 0, vui long nhap lai: ";
        in >> x.mau;
    }

    return in;
}

ostream& operator<<(ostream &out, const PhanSo &x) {
    if (x.tu == 0) 
        out << 0;
    else if (x.mau == 1) 
        out << x.tu;
    else if (x.mau == -1) 
        out << -x.tu;
    else 
        out << (x.mau < 0 ? -x.tu : x.tu) << "/" << abs(x.mau);
    return out;
}


ll PhanSo::getTu() const
{
    return this->tu;
}

ll PhanSo::getMau() const
{
    return this->mau;
}

void PhanSo::setTu(ll tu)
{
    this->tu = tu;
}

void PhanSo::setMau(ll mau)
{
    this->mau = mau;
}

void PhanSo::nghichDao()
{
    if (tu == 0)
    {
        cout << "Tu so = 0 nen khong the nghich dao !";
        return;
    }
    int tmp = tu;
    tu = mau;
    mau = tmp;
}

void PhanSo::rutgon()
{
    ll g = gcd(tu, mau);
    tu /= g;
    mau /= g;
}

PhanSo PhanSo::operator+(const PhanSo &a) const
{
    ll mc = lcm(mau, a.mau);
    ll new_tu = mc / mau * tu + mc / a.mau * a.tu;
    return PhanSo(new_tu, mc).rutgon(), PhanSo(new_tu, mc);
}

PhanSo PhanSo::operator-(const PhanSo &a) const
{
    ll mc = lcm(mau, a.mau);
    ll new_tu = mc / mau * tu - mc / a.mau * a.tu;
    return PhanSo(new_tu, mc).rutgon(), PhanSo(new_tu, mc);
}

PhanSo PhanSo::operator*(const PhanSo &a) const
{
    ll new_tu = tu * a.tu;
    ll new_mau = mau * a.mau;
    return PhanSo(new_tu, new_mau).rutgon(), PhanSo(new_tu, new_mau);
}

PhanSo PhanSo::operator/(const PhanSo &a) const
{
    if (a.tu == 0)
    {
        cout << "Khong the chia cho 0!" << endl;
        return PhanSo(0, 1);
    }
    ll new_tu = tu * a.mau;
    ll new_mau = mau * a.tu;
    return PhanSo(new_tu, new_mau).rutgon(), PhanSo(new_tu, new_mau);
}

PhanSo& PhanSo::operator=(const PhanSo &a)
{
    if (*this != a)
    {
        tu = a.tu;
        mau = a.mau;
    }
    return *this;
}

PhanSo& PhanSo::operator+=(const PhanSo &a) {
    *this = *this + a; 
    return *this; 
}

PhanSo& PhanSo::operator-=(const PhanSo &a) {
    *this = *this - a; 
    return *this; 
}

bool PhanSo::operator>(const PhanSo &a) const
{
    ll mc = lcm(mau, a.mau);
    ll tu1 = mc / mau * tu;
    ll tu2 = mc / a.mau * a.tu;
    return tu1 > tu2;
}

bool PhanSo::operator<(const PhanSo &a) const
{
    ll mc = lcm(mau, a.mau);
    ll tu1 = mc / mau * tu;
    ll tu2 = mc / a.mau * a.tu;
    return tu1 < tu2;
}

bool PhanSo::operator==(const PhanSo &a) const
{
    return tu * a.mau == mau * a.tu;
}

bool PhanSo::operator>=(const PhanSo &a) const
{
    return *this > a || *this == a;
}

bool PhanSo::operator<=(const PhanSo &a) const
{
    return *this < a || *this == a;
}

bool PhanSo::operator!=(const PhanSo &a) const
{
    return tu * a.mau != mau * a.tu;
}

PhanSo PhanSo::operator++()
{
    tu += mau;
    this->rutgon();
    return *this;
}

PhanSo PhanSo::operator--()
{
    tu -= mau;
    this->rutgon();
    return *this;
}

PhanSo::operator float() const
{
    return (float)tu / (float)mau;
}

PhanSo::operator int() const
{
    return (int)(tu / mau);
}

int PhanSo::soSanh(const PhanSo &a) const
{
    ll mc = lcm(mau, a.mau);
    ll tu1 = mc / mau * tu;
    ll tu2 = mc / a.mau * a.tu;
    if (tu1 == tu2)
        return 0;
    else if (tu1 > tu2)
        return 1;
    else
        return -1;
}

int main()
{
    PhanSo ps1, ps2, ps3;

    cout << "Nhap phan so thu nhat:" << endl;
    cin >> ps1;
    cout << "Nhap phan so thu hai:" << endl;
    cin >> ps2;

    cout << "Phan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << endl;

    ps3 = ps1 + ps2;
    cout << "Tong: " << ps3 << endl;

    ps3 = ps1 - ps2;
    cout << "Hieu: " << ps3 << endl;

    ps3 = ps1 * ps2;
    cout << "Tich: " << ps3 << endl;

    ps3 = ps1 / ps2;
    cout << "Thuong: " << ps3 << endl;

    int t = ps1.soSanh(ps2);
    if (t == 0)
        cout << ps1 << " = " << ps2 << endl;
    else if (t == 1)
        cout << ps1 << " > " << ps2 << endl;
    else
        cout << ps1 << " < " << ps2 << endl;

    ps1 += ps2;
    cout << "ps1 += ps2 => ps1 = " << ps1 << endl;

    ps1 -= ps2;
    cout << "ps1 -= ps2 => ps1 = " << ps1 << endl;

    ++ps1;
    cout << "++ps1 = " << ps1 << endl;

    --ps1;
    cout << "--ps1 = " << ps1 << endl;

    float f = float(ps1);
    int i = int(ps2);
    cout << "float(ps1) =  " << f << endl;
    cout << "int(ps2) =  " << i << endl;

    return 0;
}
