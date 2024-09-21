#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct Time{
	int ngay;
	int thang;
	int nam;
};
void nhapTime(Time &x, FILE *f1)
{
	fscanf(f1,"%d",&x.ngay);
	fscanf(f1,"%d",&x.thang);
	fscanf(f1,"%d",&x.nam);
}
struct BenhNhan{
	int stt;
	char Ho_Ten[50];
	Time Ngay_Sinh;
	int Tuoi;
	char GT[10];
	char Can_Benh[255];
	char Ho_Ten_BS[50];
 	Time Ngay_Vao_Vien;
 	Time Ngay_Xuat_Vien;
	unsigned long long Vien_Phi;
};

typedef struct BenhNhan BN;

void DocThongTin(BN &x, FILE *f1)
{
	fscanf(f1,"%d\n",&x.stt);
	fscanf(f1,"%[^\n]\n",x.Ho_Ten);
	nhapTime(x.Ngay_Sinh,f1);
	fscanf(f1,"%d\n",&x.Tuoi);
	fscanf(f1,"%[^\n]\n",x.GT);
	fscanf(f1,"%[^\n]\n",x.Can_Benh);
	fscanf(f1,"%[^\n]\n",x.Ho_Ten_BS);
	nhapTime(x.Ngay_Vao_Vien,f1);
	nhapTime(x.Ngay_Xuat_Vien,f1);
	fscanf(f1,"%llu",&x.Vien_Phi);		
}
void DocDS(int n, BN *a, FILE *f1)
{
	for (int i=0; i<n; i++)
	DocThongTin(*(a+i),f1);
}
void GhiThongTin(BN x,FILE *f2)
{
	fprintf(f2,"%d\t%-22s  %-2d/%-2d/%-6d %d\t\t%-9s  %-23s  %-19s %-2d/%-2d/%-8d %-2d/%-2d/%-8d  %llu\n",\
	x.stt, x.Ho_Ten, x.Ngay_Sinh.ngay, x.Ngay_Sinh.thang, x.Ngay_Sinh.nam, \
	x.Tuoi, x.GT, x.Can_Benh, x.Ho_Ten_BS, x.Ngay_Vao_Vien.ngay, x.Ngay_Vao_Vien.thang, x.Ngay_Vao_Vien.nam, \
	x.Ngay_Xuat_Vien.ngay, x.Ngay_Xuat_Vien.thang, x.Ngay_Xuat_Vien.nam, x.Vien_Phi);
}
void XuatDS(int n, BN *a,FILE *f2)
{
	for (int  i=0; i<n; i++)
	{
		GhiThongTin(*(a+i),f2);
	}
}
void SapXepTheoTen(int n, BN *a)
{
	BN t;
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if (strcmp((a+i)->Ho_Ten,(a+j)->Ho_Ten)>0)
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}	
}
void SapXepTheoBS(int n, BN *a)
{
	BN t;
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if (strcmp((a+i)->Ho_Ten_BS,(a+j)->Ho_Ten_BS)>0)
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}	
}
void SapXepTheoTuoi(int n, BN *a)
{
	BN t;
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if ((a+i)->Tuoi < (a+j)->Tuoi)
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}	
}
int SoSanhTime(Time a, Time b)
{
	if (a.nam > b.nam) return 1;
	else if (a.nam < b.nam) return -1;
	else
		{
			if (a.thang > b.thang) return 1;
			else if (a.thang < b.thang) return -1;
			else
				{
					if (a.ngay > b.ngay) return 1;
					else if (a.ngay < b.ngay) return -1;
					else return 0;
				}
		}
}
void SapXepTheoNgayVaoVien(int n, BN *a)
{
	BN t;
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	if (SoSanhTime((a+i)->Ngay_Vao_Vien, (a+j)->Ngay_Vao_Vien) > 0 )
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}
}
void SapXepTheoNgayXuatVien(int n, BN *a)
{
	BN t;
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	if (SoSanhTime((a+i)->Ngay_Xuat_Vien, (a+j)->Ngay_Xuat_Vien) > 0 )
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}
}
void TimKiemTheoTen(int n, BN *a, char s[], FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (strcmp((a+i)->Ho_Ten, s)==0)  GhiThongTin(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoTenBS(int n, BN *a, char s[], FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (strcmp((a+i)->Ho_Ten_BS, s)==0)  GhiThongTin(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoTuoi(int n, BN *a, int tuoi, FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if ( (a+i)->Tuoi == tuoi )  GhiThongTin(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoNgayVaoVien(int n, BN *a, Time day, FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if ((a+i)->Ngay_Vao_Vien.ngay==day.ngay &&  (a+i)->Ngay_Vao_Vien.thang==day.thang &&  (a+i)->Ngay_Vao_Vien.nam==day.nam )  
		GhiThongTin(*(a+i),f2);
		else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoNgayXuatVien(int n, BN *a, Time day, FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if ((a+i)->Ngay_Xuat_Vien.ngay==day.ngay &&  (a+i)->Ngay_Xuat_Vien.thang==day.thang &&  (a+i)->Ngay_Xuat_Vien.nam==day.nam )  
		GhiThongTin(*(a+i),f2);
		else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
unsigned long long TinhVienPhi(int n, BN *a, int nam, FILE *f2)
{
	SapXepTheoNgayXuatVien(n,a);
unsigned long long Tong=0,t;

	int i=0;
	while ((a+i)->Ngay_Xuat_Vien.nam != nam) i++;
	int j=i+1;
	while ((a+i)->Ngay_Xuat_Vien.nam == (a+j)->Ngay_Xuat_Vien.nam)
	j++;
	t=(a+i)->Vien_Phi;
	for (int k=i; k<j; k++)
	{ 
		if ((a+k)->Ngay_Xuat_Vien.thang == (a+k+1)->Ngay_Xuat_Vien.thang)
		t=t+(a+k+1)->Vien_Phi;
		else
		{
			fprintf(f2,"Vien phi thang %d: %lluVND\n",(a+k)->Ngay_Xuat_Vien.thang,t);
			t=(a+k+1)->Vien_Phi;
		}
	}
	for (int k=i; k<j; k++)
	Tong=Tong+(a+k)->Vien_Phi;
	return Tong;		
}
int main()
{	
	FILE *f1,*f2;
	int n,choose;	
	f1 = fopen("Danh_Sach_Benh_Nhan_INP.txt","r");
	f2 = fopen("Danh_Sach_Benh_Nhan_OUT.txt","w");
	fscanf(f1,"%d",&n);	
	BN *a=(BN*)malloc(n*sizeof(BN));
	DocDS(n,a,f1);
	
	printf("-----------------MENU-------------------\n");
	printf("\t1. In danh sach benh nhan\n");
	printf("\t2. Sap xep theo tieu chi\n");
	printf("\t3. Tim kiem theo tieu chi\n");
	printf("\t4. Tinh tong vien phi cua benh vien thu duoc theo nam\n");
	printf("\t5. Exit\n");
	printf("----------------------------------------\n");
	printf("Nhap yeu cau:"); scanf("%d",&choose);
	switch (choose)
	{
	case 1: fprintf(f2,"STT\tHo va ten\t\t\t\tNgay Sinh\tTuoi  Gioi tinh    Can benh\t\t\t\t\tBS dieu tri\t\t\tNgay vao vien  Ngay xuat vien  Vien phi\n");	 
			XuatDS(n,a,f2);	break;
	case 2: printf("\t\t1. Theo ho ten benh nhan\n");
			printf("\t\t2. Theo ho ten bac si\n");
			printf("\t\t3. Theo tuoi benh nhan\n");
			printf("\t\t4. Theo ngay vao vien\n");
			printf("\t\t5. Theo ngay xuat vien\n");
			printf("\t\t6. Exit\n");
			printf("Nhap tieu chi:"); 
			int tieuchi1;
			scanf("%d",&tieuchi1);
			fprintf(f2,"STT\tHo va ten\t\t\t\tNgay Sinh\tTuoi  Gioi tinh    Can benh\t\t\t\t\tBS dieu tri\t\t\tNgay vao vien  Ngay xuat vien  Vien phi\n");
			switch (tieuchi1)
			{
				case 1: 	SapXepTheoTen(n,a); XuatDS(n,a,f2); 			break;
				case 2: 	SapXepTheoBS(n,a); XuatDS(n,a,f2); 				break;
				case 3: 	SapXepTheoTuoi(n,a); XuatDS(n,a,f2); 			break;
				case 4: 	SapXepTheoNgayVaoVien(n,a); XuatDS(n,a,f2); 	break;
				case 5: 	SapXepTheoNgayXuatVien(n,a); XuatDS(n,a,f2); 	break;
				case 6:		break;
				default:    printf("Gia tri khong hop le! Only enter 1 -> 6");
			} 			break;
	case 3: printf("\t\t1. Theo ho ten benh nhan\n");
			printf("\t\t2. Theo ho ten bac si\n");
			printf("\t\t3. Theo tuoi benh nhan\n");
			printf("\t\t4. Theo ngay vao vien\n");
			printf("\t\t5. Theo ngay xuat vien\n");
			printf("\t\t6. Exit\n");
			printf("Nhap tieu chi:"); 
			int tieuchi2;
			scanf("%d",&tieuchi2);
			fprintf(f2,"STT\tHo va ten\t\t\t\tNgay Sinh\tTuoi  Gioi tinh    Can benh\t\t\t\t\tBS dieu tri\t\t\tNgay vao vien  Ngay xuat vien  Vien phi\n");
			switch (tieuchi2)
			{
				case 1: printf("Nhap ho ten benh nhan muon tim kiem:");	 fflush(stdin);
						char s1[50]; 	scanf("%[^\n]",s1);
						TimKiemTheoTen(n,a,s1,f2);  		break;
				case 2: printf("Nhap ho ten bac si muon tim kiem:");	 fflush(stdin);
						char s2[50]; 	scanf("%[^\n]",s2);
						TimKiemTheoTenBS(n,a,s2,f2);  		break;
				case 3: printf("Nhap tuoi benh nhan muon tim kiem:");	 fflush(stdin);
						int s3; 	scanf("%d",&s3);
						TimKiemTheoTuoi(n,a,s3,f2);  		break;
				case 4: printf("Nhap ngay vao vien muon tim kiem:");	 fflush(stdin);
							Time s4; 	
							scanf("%d",&s4.ngay);
							scanf("%d",&s4.thang);
							scanf("%d",&s4.nam);
						TimKiemTheoNgayVaoVien(n,a,s4,f2);  break;
				case 5: printf("Nhap ngay xuat vien muon tim kiem:");	 fflush(stdin);
							Time s5; 	
							scanf("%d",&s5.ngay);
							scanf("%d",&s5.thang);
							scanf("%d",&s5.nam);
						TimKiemTheoNgayXuatVien(n,a,s5,f2); break;
				case 6:		break;
				default:    printf("Gia tri khong hop le! Only enter 1 -> 6");
			}    break;
	case 4: int Nam;
			printf("Ban muon tinh tong vien phi cua nam:"); scanf("%d",&Nam);
			fprintf(f2,"Tong vien phi cua benh vien trong nam %d la %lluVND ",Nam,TinhVienPhi(n,a,Nam,f2));
				break;
	case 5: break; 
	default: printf("Gia tri khong hop le! Only enter 1 -> 5");
	}
	free(a); 
	fclose(f1);
	fclose(f2);
	return 0;
}
