#include <iostream>
#include <math.h>

using namespace std;
class PhanSo {
    private:
        int tuSo, mauSo;
    public:
        void nhap();
        void xuat();
        int getTuSo();
        void setTuSo(int tuSo);            
        int getMauSo();
        void setMauSo(int mauSo); 
        void RutGon();
        void NghichDao();
        PhanSo Cong(const PhanSo &p);// ham thanh phan cua lop
        friend PhanSo Cong1(const PhanSo &p1, const PhanSo &p2);
        friend PhanSo Tru(const PhanSo &p1, const PhanSo &p2);
        friend PhanSo Nhan(const PhanSo &p1, const PhanSo &p2);
        friend PhanSo Chia(const PhanSo &p1, const PhanSo &p2);
        friend int Sosanh(const PhanSo &p1, const PhanSo &p2);
};

int Sosanh(const PhanSo &p1, const PhanSo &p2){
	if ((p1.tuSo*p2.mauSo)>(p2.tuSo*p1.mauSo)){
		return 1;
	}
	else if ((p1.tuSo*p2.mauSo)<(p2.tuSo*p1.mauSo)){
		return 2;
	}
	else return 3;
}

PhanSo Chia(const PhanSo &p1, const PhanSo &p2){
	PhanSo t=p2;
	t.NghichDao();    
	PhanSo z=Nhan(p1,t);
	if(z.mauSo == 0) {
        cout << "Mau = 0" << endl;
    } else {
        z.RutGon();
    }
    return z; 
}

PhanSo Cong1(const PhanSo &p1, const PhanSo &p2){
	PhanSo t;
	t.tuSo=p1.tuSo*p2.mauSo+p1.mauSo*p2.tuSo;
	t.mauSo=p1.mauSo*p2.mauSo;
	t.RutGon();
	return t;
}

PhanSo Tru(const PhanSo &p1, const PhanSo &p2){
	PhanSo t;
	t.tuSo=p1.tuSo*p2.mauSo-p1.mauSo*p2.tuSo;
	t.mauSo=p1.mauSo*p2.mauSo;
	if(t.mauSo == 0) {
        cout << "Mau = 0" << endl;
    } else {
        t.RutGon();
    }
	return t;
}

PhanSo Nhan(const PhanSo &p1, const PhanSo &p2){
	PhanSo t;
	t.tuSo=p1.tuSo*p2.tuSo;
	t.mauSo=p1.mauSo*p2.mauSo;
	if(t.mauSo == 0) {
        cout << "Mau = 0" << endl;
    } else {
        t.RutGon();
    }
	return t;
} 

PhanSo PhanSo::Cong(const PhanSo &p){
	PhanSo t;
	t.tuSo=this->tuSo*p.mauSo+this->mauSo*p.tuSo;
	t.mauSo=this->mauSo*p.mauSo;
	t.RutGon();
	return t;
}
void PhanSo::NghichDao(){
	if(tuSo==0)
		cout<<"Khong nghich dao duoc";
	else{		
		int temp=tuSo;
		tuSo=mauSo;
		mauSo=temp;
	}	
}
int UCLN(int a, int b){
	a=abs(a);
	b=abs(b); 
	if(a!=0){
		while(a!=b){
		(a>b)?a=a-b:b=b-a;
	}
		return a;
	}
	return b;
}

void PhanSo::RutGon(){
	int uc=UCLN(tuSo,mauSo);
	tuSo/=uc;
	mauSo/=uc;	
	
	if(mauSo < 0){
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}
void PhanSo::nhap() {
    cout << "Nhap tu so: ";
    cin >> tuSo;
    do {
        cout << "Nhap mau so: ";
        cin >> mauSo;
        if (mauSo == 0) {
            cout << "Mau so khong duoc bang 0! Nhap lai:" << endl;
        }
    } while (mauSo == 0);
}

void PhanSo::xuat() {
    cout << tuSo << "/" << mauSo << endl;
}

int PhanSo::getTuSo() {
    return this->tuSo;
}

int PhanSo::getMauSo() {
    return this->mauSo;
}
void PhanSo::setTuSo(int tuSo) {
    this->tuSo = tuSo;
}
void PhanSo::setMauSo(int x) {
    if (x != 0) {
        mauSo = x;
    } else 
        cout << "Mau so khong duoc bang 0." << endl;
} 

int main() {
    PhanSo p1,p2,t;
    p1.nhap();
    p2.nhap();
    cout << "cong: ";
	t=Cong1(p1,p2);
	t.xuat();
	cout << "tru: ";
	t=Tru(p1,p2);
	t.xuat();
	cout << "nhan: ";
	t=Nhan(p1,p2);
	t.xuat();
	cout << "chia: ";
	t=Chia(p1,p2);
	t.xuat();
	if (Sosanh(p1,p2)==1){
		cout << "so lon hon la: ";
		p1.xuat();
	}
	else if (Sosanh(p1,p2)==2){
		cout << "so lon hon la: ";
		p2.xuat();
	}
	else cout <<"2 so bang nhau";
}
