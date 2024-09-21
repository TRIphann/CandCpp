#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


struct Node{
	BN data;
	Node *pNext;
};

struct List{
	Node *pHead, *pTail;
};
void Init(List &l)
{
	l.pHead= NULL;
	l.pTail= NULL;
}
Node *creatnode(BN x)
{
	Node *p=new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addnode(List &l, Node *p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void nhapBN(BN &x, FILE *f1)
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
void nhap(int n, List &l, FILE *f1)
{
	
	BN x;
	for (int i=0; i < n ; i++)
	{
		nhapBN(x,f1);
		Node *p= creatnode(x);
		addnode(l,p);	
	}
}

void GhiThongTin(BN x, FILE *f2)
{
	fprintf(f2,"%d\t%-22s  %-2d/%-2d/%-6d %d\t\t%-9s  %-23s  %-19s %-2d/%-2d/%-8d %-2d/%-2d/%-8d  %llu\n",\
	x.stt, x.Ho_Ten, x.Ngay_Sinh.ngay, x.Ngay_Sinh.thang, x.Ngay_Sinh.nam, \
	x.Tuoi, x.GT, x.Can_Benh, x.Ho_Ten_BS, x.Ngay_Vao_Vien.ngay, x.Ngay_Vao_Vien.thang, x.Ngay_Vao_Vien.nam, \
	x.Ngay_Xuat_Vien.ngay, x.Ngay_Xuat_Vien.thang, x.Ngay_Xuat_Vien.nam, x.Vien_Phi);
}
void Xuat(List l,FILE *f2)
{
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
    GhiThongTin(k->data,f2);
}
void SapXepTheoTen(List &l)
{
	BN T;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (strcmp(k->data.Ho_Ten, q->data.Ho_Ten)  > 0 )
	{
		T= k->data;
		k->data = q->data;
		q->data = T;
	}	
}
void SapXepTheoBS(List &l)
{
	BN T;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (strcmp(k->data.Ho_Ten_BS, q->data.Ho_Ten_BS)  > 0 )
	{
		T= k->data;
		k->data = q->data;
		q->data = T;
	}	
}
void SapXepTheoTuoi(List &l)
{
	BN T;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (k->data.Tuoi < q->data.Tuoi)
	{
		T= k->data;
		k->data = q->data;
		q->data = T;
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
void SapXepTheoNgayVaoVien(List &l)
{
	BN T;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (SoSanhTime(k->data.Ngay_Vao_Vien, q->data.Ngay_Vao_Vien) < 0 )
	{
		T= k->data;
		k->data = q->data;
		q->data = T;
	}
}
void SapXepTheoNgayXuatVien(List &l)
{
	BN T;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (SoSanhTime(k->data.Ngay_Xuat_Vien, q->data.Ngay_Xuat_Vien) < 0 )
	{
		T= k->data;
		k->data = q->data;
		q->data = T;
	}
}
void TimKiemTheoTen(int n,List &l, char s[], FILE *f2)
{
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.Ho_Ten, s)==0)  GhiThongTin(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoTenBS(int n,List &l, char s[], FILE *f2)
{
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.Ho_Ten_BS, s)==0)  GhiThongTin(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoTuoi(int n, List &l, int tuoi, FILE *f2)
{
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if ( k->data.Tuoi == tuoi )  GhiThongTin(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoNgayVaoVien(int n, List &l, Time day, FILE *f2)
{
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (k->data.Ngay_Vao_Vien.ngay==day.ngay &&  k->data.Ngay_Vao_Vien.thang==day.thang &&  k->data.Ngay_Vao_Vien.nam==day.nam )  
		GhiThongTin(k->data,f2);
		else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
void TimKiemTheoNgayXuatVien(int n, List &l, Time day, FILE *f2)
{
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (k->data.Ngay_Xuat_Vien.ngay==day.ngay &&  k->data.Ngay_Xuat_Vien.thang==day.thang &&  k->data.Ngay_Xuat_Vien.nam==day.nam )  
		GhiThongTin(k->data,f2);
		else j++;	
	if (j==n)  fprintf(f2,"KHONG TIM THAY!");
}
unsigned long long TinhVienPhi(List &l, int nam, FILE *f2)
{
	SapXepTheoNgayXuatVien(l);
	unsigned long long Tong=0,t;
	Node *i=l.pHead;
	while (i->data.Ngay_Xuat_Vien.nam != nam) i=i->pNext; 
	Node *j=i->pNext;
	while (j->data.Ngay_Xuat_Vien.nam == j->pNext->data.Ngay_Xuat_Vien.nam)
	j=j->pNext;
	
	t=i->data.Vien_Phi;
	for (Node *k=i; k<j; k=k->pNext)
	{ 
		if (k->data.Ngay_Xuat_Vien.thang == k->pNext->data.Ngay_Xuat_Vien.thang)
		t=t+k->pNext->data.Vien_Phi;
		else
		{
			fprintf(f2,"Vien phi thang %d: %lluVND\n",k->data.Ngay_Xuat_Vien.thang,t);
			t=k->pNext->data.Vien_Phi;
		}
	}
	for (Node *k=i; k<j; k=k->pNext)
	Tong=Tong+k->data.Vien_Phi;
	return Tong;		
}
int main()
{
	List L;
	int n,choose;
	FILE *f1, *f2;
	f1 = fopen("DSLK_INP.txt","r");
	f2 = fopen("DSLK_OUT.txt","w");
	fscanf(f1,"%d",&n);
	Init(L);
	nhap(n,L,f1);
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
			Xuat(L,f2);		break;
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
				case 1: 	SapXepTheoTen(L); Xuat(L,f2); 				break;
				case 2: 	SapXepTheoBS(L); Xuat(L,f2); 				break;
				case 3: 	SapXepTheoTuoi(L); Xuat(L,f2); 				break;
				case 4: 	SapXepTheoNgayVaoVien(L); Xuat(L,f2); 	break;
				case 5: 	SapXepTheoNgayXuatVien(L); Xuat(L,f2); 	break;
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
						TimKiemTheoTen(n,L,s1,f2);  		break;
				case 2: printf("Nhap ho ten bac si muon tim kiem:");	 fflush(stdin);
						char s2[50]; 	scanf("%[^\n]",s2);
						TimKiemTheoTenBS(n,L,s2,f2);  		break;
				case 3: printf("Nhap tuoi benh nhan muon tim kiem:");	 fflush(stdin);
						int s3; 	scanf("%d",&s3);
						TimKiemTheoTuoi(n,L,s3,f2);  		break;
				case 4: printf("Nhap ngay vao vien muon tim kiem:");	 fflush(stdin);
							Time s4; 	
							scanf("%d",&s4.ngay);
							scanf("%d",&s4.thang);
							scanf("%d",&s4.nam);
						TimKiemTheoNgayVaoVien(n,L,s4,f2);  break;
				case 5: printf("Nhap ngay xuat vien muon tim kiem:");	 fflush(stdin);
							Time s5; 	
							scanf("%d",&s5.ngay);
							scanf("%d",&s5.thang);
							scanf("%d",&s5.nam);
						TimKiemTheoNgayXuatVien(n,L,s5,f2); break;
				case 6:		break;
				default:    printf("Gia tri khong hop le! Only enter 1 -> 6");
			}    break;
	case 4: int Nam;
			printf("Ban muon tinh tong vien phi cua nam:"); scanf("%d",&Nam);
			fprintf(f2,"Tong vien phi cua benh vien trong nam %d la %lluVND ",Nam,TinhVienPhi(L,Nam,f2));
				break;
	case 5: break; 
	default: printf("Gia tri khong hop le! Only enter 1 -> 5");
	} 
	fclose(f1);
	fclose(f2);
	return 0;
}

