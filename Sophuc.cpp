#include<iostream>
#include<cmath>
using namespace std;

class Sophuc {
    private:
        float thuc, ao;
    public:
        void nhap();
        void xuat();
        float getthuc();
        void setthuc(float thuc);            
        float getao();
        void setao(float ao);
        float module() const ;
        friend Sophuc cong(const Sophuc &p1,const Sophuc &p2);
        friend Sophuc tru(const Sophuc &p1,const Sophuc &p2);
        friend Sophuc nhan(const Sophuc &p1,const Sophuc &p2);
        friend Sophuc chia(const Sophuc &p1,const Sophuc &p2);
        friend int sosanh(const Sophuc &p1,const Sophuc &p2);
};

int sosanh(const Sophuc &p1,const Sophuc &p2){
    if (p1.module() > p2.module()) return 1;
    if (p1.module() < p2.module()) return 2;
    return 3;
}

Sophuc chia(const Sophuc &p1,const Sophuc &p2) {
    Sophuc t;
    float mau = p2.thuc * p2.thuc + p2.ao * p2.ao;
    t.thuc = (p1.thuc * p2.thuc + p1.ao * p2.ao) / mau;
    t.ao = (p1.ao * p2.thuc - p1.thuc * p2.ao) / mau;
    return t;
}

float Sophuc::module() const{
    return sqrt(thuc * thuc + ao * ao);
}

float Sophuc::getthuc() {
    return thuc;
}

float Sophuc::getao() {
    return ao;
}

void Sophuc::setthuc(float thuc) {
    this->thuc = thuc;
}

void Sophuc::setao(float ao) {
    this->ao = ao;
}

void Sophuc::nhap() {
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}

void Sophuc::xuat() {
    cout << thuc;
    if (ao > 0) cout << " + " << ao << "i";
    else if (ao < 0) cout << " - " << -ao << "i";
}

Sophuc cong(const Sophuc &p1,const Sophuc &p2) {
    Sophuc t;
    t.thuc = p1.thuc + p2.thuc;
    t.ao = p1.ao + p2.ao;
    return t;
}

Sophuc tru(const Sophuc &p1,const Sophuc &p2) {
    Sophuc t;
    t.thuc = p1.thuc - p2.thuc;
    t.ao = p1.ao - p2.ao;
    return t;
}

Sophuc nhan(const Sophuc &p1,const Sophuc &p2) {
    Sophuc t;
    t.thuc = p1.thuc * p2.thuc - p1.ao * p2.ao;
    t.ao = p1.thuc * p2.ao + p2.thuc * p1.ao;
    return t;
}

int main() {
    Sophuc a, b, t;
    cout << "Nhap so phuc thu nhat: " << endl;
    a.nhap();
    cout << "Nhap so phuc thu hai: " << endl;
    b.nhap();

    cout << endl;
    cout << "Tong: ";
    t = cong(a, b);
    t.xuat();
    cout << endl;

    cout << "Hieu: ";
    t = tru(a, b);
    t.xuat();
    cout << endl;

    cout << "Tich: ";
    t = nhan(a, b);
    t.xuat();
    cout << endl;

    cout << "Thuong: ";
    t = chia(a, b);
    t.xuat();
    cout << endl;

    if (sosanh(a, b) == 1) {   
        cout << "So lon hon la: ";
        a.xuat();
    }
    else if (sosanh(a, b) == 2) {
        cout << "So lon hon la: ";
        b.xuat();
    }
    else {
        cout << "2 so bang nhau!!!";
    }
}
