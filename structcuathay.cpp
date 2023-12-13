#include<iostream>
#include<stdlib.h>
using namespace std;

struct PhanSo
{
	int tu, mau;
};
typedef PhanSo PS;

void NhapMotPhanSo(PhanSo *x) {
	printf("\nNhap vao tu so = ");
	scanf("%d", &x->tu);
	printf("\nNhap vao mau so = ");
	scanf("%d", &x->mau);
}

void XuatMotPhanSo(PS x) {
	printf("Phan so : %d/%d", x.tu, x.mau);
}

int TimUCLN(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
PS RutGonPS(PS m) {
	int ucln = TimUCLN(m.tu, m.mau);
	m.tu /= ucln;
	m.mau /= ucln;
	return m;
}

PS TruHaiPhanSo(PS x, PS y) {
	PS z; //z= x-y
	z.tu = x.tu*y.mau - y.tu*x.mau;
	z.mau = x.mau*y.mau;
	return z;
}

int main() {
	PS x, y, z;
	printf("Nhap vao phan so dau tien !");
	NhapMotPhanSo(&x);
	printf("\nNhap vao phan so thu hai!");
	NhapMotPhanSo(&y);
	z = TruHaiPhanSo(x, y);
	printf("\nKet qua tru hai PS truoc khi rut gon !");
	XuatMotPhanSo(z);
	printf("\nKet qua tru hai PS sau khi rut gon !");
	PS m = RutGonPS(z);
	XuatMotPhanSo(m);
	printf("\n");
	system("pause");
	return 0;

}
