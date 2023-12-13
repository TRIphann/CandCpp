#include <iostream>
#include <math.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
struct Date{
	int ngay, thang, nam;
};
void Nhap(Date &x)
{
	printf("Nhap ngay:"); 	scanf("%d",&x.ngay);
	printf("Nhap thang:");  scanf("%d",&x.thang);
	printf("Nhap nam:"); 	scanf("%d",&x.nam);
}
void NhapDS(int &n,Date a[])
{
	for (int i=0;i<n;i++)
	{
		printf("\nNhap date thu %d:\n",i+1);
		Nhap(a[i]);
	}
}
void Xuat(Date x)
{
	printf("%d/%d/%d",x.ngay,x.thang,x.nam);
}
void XuatDS(int &n,Date a[])
{
	for (int i=0;i<n;i++)
	{
	Xuat(a[i]);
	printf("\n");
	}
}
int NgayTrongThang(int thang,int nam)
{
	switch (thang){
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31; break;
		case 4:case 6:case 9:case 11: return 30; break;
		case 2: if (nam%4==0 )	return 29; else return 28; break;
	}
}
bool KiemTra(Date x)
{
	if (x.nam<0) return false;
	if (x.thang<0 || x.thang>12) return false;
	if (x.ngay > NgayTrongThang(x.thang,x.nam) ) return false;
	return true;
}
//Bi thuat chuyen date thanh number
long NgayThanhSo(int ngay, int thang, int nam)
{
	long So;	//chuyen ngay bat ki thanh so bat ki
	So=nam*365+nam/4+ngay; 		//Cong tat ca cac ngay cua nam thuong va nam nhuan *
	for (int i=1;i<thang;i++)	//Cong tat ca cac ngay cua thang thuc thi
	So+=NgayTrongThang(i,nam);
	if (nam%4==0) So=So-1;		//Do nam dang xet la nam nhuan nhung da cong roi o tren (*)
	return So;
}
//Bi thuat chuyen number thanh date
Date SoThanhNgay(long So)
{
	Date date;
	date.nam=So/365;		//tinh nam bang So chia nguyen cho 365
	int du=So%365;			//Tinh phan du 					
	while (du<date.nam/4)
	{								//Neu du nho hon phan ngay cua nam nhuan thi nam giam di 1
		date.nam--;
		du+=365;
		} 
	date.ngay=So-date.nam*365-date.nam/4;		//(#)
	date.thang=1;								//Tinh thang
	if (date.nam%4==0) date.ngay=date.ngay+1;	//Neu nam thuc thi la nhuan thi cong lai 1 do tru o (#)
	while (date.ngay > NgayTrongThang(date.thang,date.nam))
	{
		date.ngay=date.ngay-NgayTrongThang(date.thang,date.nam);	//So du cuoi cung se la ngay
		date.thang++;
	}
	return date;
}
Date DateHomqua(Date x)
{
	long i=NgayThanhSo(x.ngay,x.thang,x.nam);
	i--;
	return SoThanhNgay(i);
}
Date DateNgaymai(Date x)
{
	long i=NgayThanhSo(x.ngay,x.thang,x.nam);
	i++;
	return SoThanhNgay(i);
}
Date Themngay(Date &x,int c)
{
	fflush(stdin);
	printf("\nNhap so ngay can them:"); scanf("%d",&c);
	printf("Ngay sau khi da cong %d ngay:",c);
	long i=NgayThanhSo(x.ngay,x.thang,x.nam);
	x=SoThanhNgay(i+c);
	return x;
}
Date Trungay(Date &x,int b)
{
	fflush(stdin);
	printf("Nhap so ngay can tru:"); scanf("%d",&b);
	printf("Ngay sau khi da tru di %d ngay:",b);
	long i=NgayThanhSo(x.ngay,x.thang,x.nam);
	x=SoThanhNgay(i-b);
	return x;
}
int Khoangcach(Date x,Date y)
{
	long k=abs(NgayThanhSo(x.ngay,x.thang,x.nam)-NgayThanhSo(y.ngay,y.thang,y.nam));
	return k;
}
int DemDauThang(int n, Date a[])
{

	int dau=0;
	for (int i=0;i<n;i++)
	if (a[i].ngay==1)	dau++;
	return dau;
}
int DemCuoiThang(int n, Date a[])
{
	int cuoi=0;
	for (int i=0;i<n;i++)
	if (a[i].ngay==NgayTrongThang(a[i].thang,a[i].nam))	cuoi++;
	return cuoi;
}
void SapXep(int &n,Date a[])
{
	Date T;
	for (int i=0;i<n-1;i++)
	for (int j=i+1;j<n;j++)
	if (NgayThanhSo(a[i].ngay,a[i].thang,a[i].nam)>NgayThanhSo(a[j].ngay,a[j].thang,a[j].nam))
	{	T=a[i];
		a[i]=a[j];
		a[j]=T;		}
}
int main()
{	
	int c,b,n;
	Date A,B;
	printf("Nhap ngay thang nam cua date thu nhat\n");
	Nhap(A);
	printf("Ngay vua nhap la:");
	Xuat(A);
	///////
	printf("\nKiem tra ngay vua nhap: ");
	if (KiemTra(A)== true) 
		printf("Hop le\n");
		else
		printf("Khong hop le\n");
	////////
	printf("Ngay hom qua la:");
	Xuat(DateHomqua(A));
	printf("\nNgay mai la:");
	Xuat(DateNgaymai(A));
	///////
	Xuat(Themngay(A,c));
	printf("\n");
	Xuat(Trungay(A,b));	
	////////
	fflush(stdin);
	printf("\nNhap ngay thang nam cua date thu hai\n");
	Nhap(B);
	printf("Khoang cach giua 2 ngay tren la: %d ngay\n",Khoangcach(A,B));
	fflush(stdin);
	printf("--------------------------\n");
	printf("Nhap so luong date:"); scanf("%d",&n);
	Date a[n];
	NhapDS(n,a);
	printf("Cac ngay vua nhap la:\n");
	XuatDS(n,a);
	printf("\nSo luong date dau thang la:%d\n",DemDauThang(n,a));
	printf("So luong date cuoi thang la:%d\n",DemCuoiThang(n,a));
	printf("Cac date duoc sap xep theo thu tu tang dan la:\n");
	SapXep(n,a);
	XuatDS(n,a);
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) {
	std::cout << "Ten may tinh la: " << computerName << std::endl;
	}
	system("pause");
	return 0;
}
