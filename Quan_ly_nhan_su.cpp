#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stt, tên, gioi tinh, ngay sinh, vi trí, chúc vuj, bo phan, so dien thoai, email, gio vao, gio ra
struct time{
	int day;
	int month;
	float year; 
}; 

struct diemdanh{
	int stt;
	char ten[50];
	char gioi_tinh[50];
	time ngay_sinh;
	char chuc_vu[50];
	char bo_phan[50];
	char sdt[50];
	time ngay_vaoct;
	time ngay_ract;	
}; 

typedef struct diemdanh dd;

void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void nhaptime(time &a, FILE *f1){
    fscanf(f1, "%d", &a.day);
    fscanf(f1, "%d", &a.month);
    fscanf(f1, "%f\n", &a.year);

}

void thongtin(dd &a, FILE *f1) {
    fscanf(f1, "%d\n", &a.stt);
    fgets(a.ten, sizeof(a.ten), f1);
    remove_newline(a.ten);
    fgets(a.gioi_tinh, sizeof(a.gioi_tinh), f1);
    remove_newline(a.gioi_tinh);
    nhaptime(a.ngay_sinh, f1);
    fgets(a.chuc_vu, sizeof(a.chuc_vu), f1);
    remove_newline(a.chuc_vu);
    fgets(a.bo_phan, sizeof(a.bo_phan), f1);
    remove_newline(a.bo_phan);
    fscanf(f1, "%s\n", &a.sdt);
    remove_newline(a.sdt);
    nhaptime(a.ngay_vaoct, f1);
    nhaptime(a.ngay_ract, f1);
}


void nhapthongtin(dd *a ,int n, FILE *f1){
	for (int i=0; i<n; i++){
		thongtin(*(a+i),f1);
	}
}

void xuat1(dd a, FILE *f2){
	remove_newline(a.ten);
	remove_newline(a.gioi_tinh);
	remove_newline(a.chuc_vu);
	remove_newline(a.bo_phan);
	remove_newline(a.sdt);
	fprintf(f2, "%d  %s\t\t %s  \t    %d %d %.0f\t\t %s    \t\t%s\t\t%s\t\t   %d %d %.0f\t\t\t   %d %d %.0f", a.stt, a.ten, a.gioi_tinh, a.ngay_sinh.day, a.ngay_sinh.month, a.ngay_sinh.year, a.chuc_vu, a.bo_phan, a.sdt, a.ngay_vaoct.day, a.ngay_vaoct.month, a.ngay_vaoct.year, a.ngay_ract.day, a.ngay_ract.month, a.ngay_ract.year);
	fprintf(f2, "\n\n\n");
}	
void xuat(dd *a, int n, FILE *f2){
	for (int i=0; i<n; i++){
		xuat1(*(a+i),f2);
	}
}

void demgioitinh(int n, dd *a, FILE *f2){
	int nam=0;
    int nu=0;
    for (int i=0; i<n; i++){
        if (strcmp((a+i)->gioi_tinh, "nu\n") == 0) nu++;
        else if (strcmp((a+i)->gioi_tinh, "nam\n") == 0) nam++;
    }
    fprintf(f2, "Nam: %d,   Nu: %d", nam, nu);
}

int sstime(time a, time b){
	if (a.year > b.year) return 1;
	else if (a.year < b.year) return -1;
	else
		{
			if (a.month > b.month) return 1;
			else if (a.month < b.month) return -1;
			else
				{
					if (a.day > b.day) return 1;
					else if (a.day < b.day) return -1;
					else return 0;
				}
		}
}

int dembophan(int n, dd *a){
    char *b[100];
    int c = 1;
    int dem = 0;
    b[0] = a[0].bo_phan;
    for (int i = 1; i < n; i++) {
        dem = 0;
        for (int j = 0; j < c; j++) {
            if (strcmp(a[i].bo_phan, b[j]) == 0) {
                dem++;
                break;
            }
        }
        if (dem == c) {
            b[c] = a[i].bo_phan;
            c++;
        }
    }
    return c; 
}

void quanly(int n, dd *a, FILE *f2) {
    int dem=0;
    for (int i = 0; i < n; i++) {
        if (strcmp((a+i)->chuc_vu, "Quan ly\n") == 0) {
            fprintf(f2, "%s%sbo phan %s", (a+i)->ten, (a+i)->chuc_vu, (a+i)->bo_phan);
            for (int j=0; j<n; j++){
            	if (strcmp((a+i)->bo_phan, (a+j)->bo_phan) == 0) {
           			 dem++;
			}
        }
        fprintf(f2, "So nhan su: %d\n\n\n", dem);
        dem=0;
    }
}
}


void thongtinchung(dd *a, int n, FILE *f2){
	int dem=0;
	fprintf(f2, "GIOI TINH: \n"); 
	demgioitinh(n,a,f2);
	fprintf(f2, "\n\n");
	
	fprintf(f2, "TUOI: \n"); 
	int max=a[0].ngay_sinh.year, tong=0;
	float tbc=0;
	for (int i=0; i<n; i++){
		tong=tong+(2024-a[i].ngay_sinh.year);
	}
	tbc=tong/n;
	fprintf(f2, "Trung binh: %.2f\nNguoi lon tuoi nhat: ", tbc);
	time maxa=a[0].ngay_sinh;
	for (int i=1; i<n; i++){
		if (sstime((a[i].ngay_sinh), maxa)<0) {
			maxa=a[i].ngay_sinh;
		}
	}
	for (int i=0; i<n; i++){
		if ((maxa.day==a[i].ngay_sinh.day) && (maxa.month==a[i].ngay_sinh.month) && (maxa.year==a[i].ngay_sinh.year)){
			fprintf(f2, "%s", a[i].ten);
			for (int j=i+1; j<n; j++){
				if ((maxa.day==a[j].ngay_sinh.day) && (maxa.month==a[j].ngay_sinh.month) && (maxa.year==a[j].ngay_sinh.year)){
					fprintf(f2, ", %s", a[j].ten);
				}
			}
			fprintf(f2, ": %.0f\n" ,(2024-maxa.year));
			break;
		}
		
	}
	fprintf(f2, "Nguoi nho tuoi nhat: ");
	time min=a[0].ngay_sinh;
	for (int i=1; i<n; i++){
		if (sstime((a[i].ngay_sinh), min)>0) {
			min=a[i].ngay_sinh;
		}
	}
	for (int i=0; i<n; i++){
		if ((min.day==a[i].ngay_sinh.day) && (min.month==a[i].ngay_sinh.month) && (min.year==a[i].ngay_sinh.year)){
			fprintf(f2, "%s", a[i].ten);
			for (int j=i+1; j<n; j++){
				if ((min.day==a[j].ngay_sinh.day) && (min.month==a[j].ngay_sinh.month) && (min.year==a[j].ngay_sinh.year)){
					fprintf(f2, ", %s", a[j].ten);
				}
			}
			fprintf(f2, ": %.0f\n", (2024-min.year));
			break;
		}
	}
	fprintf(f2, "\n\n");

	fprintf(f2, "BO PHAN: \n"); 
	fprintf(f2, "So bo phan: %d\n", dembophan(n,a));
	quanly(n,a,f2);
}

void sxten(int n, dd *a)
{
	dd t;
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if (strcmp((a+i)->ten,(a+j)->ten)>0)
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}	
}

void sxtuoi(int n, dd *a)
{
	dd t;
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if ((2024-a[i].ngay_sinh.year) < (2024-a[j].ngay_sinh.year))
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}	
}

void sxngayvaoct(int n, dd *a)
{
	dd t;
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	if (sstime((a+i)->ngay_vaoct, (a+j)->ngay_vaoct) > 0 )
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}
}

void sxngayract(int n, dd *a)
{
	dd t;
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	if (sstime((a+i)->ngay_ract, (a+j)->ngay_ract) > 0 )
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}
}

void tkten(int n, dd *a, char s[], FILE *f2)
{
	
    int j = 0;
    for (int i = 0; i < n; i++) {
//    	remove_newline((a+1)->ten);
//    	remove_newline(s);
        if (strcmp((a + i)->ten, s) == 0) {
            xuat1(*(a + i), f2);
            return; 
        } else {
            j++;
        }
    }
    if (j == n) {
        fprintf(f2, "Loi!");
    }
}

void tkgt(int n, dd *a, char s[], FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (strcmp((a+i)->gioi_tinh, s)==0)  xuat1(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tktuoi(int n, dd *a, int tuoi, FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if ( (2024-a[i].ngay_sinh.year) == tuoi )  xuat1(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkchucvu(int n, dd *a, char s[], FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (strcmp((a+i)->chuc_vu, s)==0)  xuat1(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkbophan(int n, dd *a, char s[], FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (strcmp((a+i)->bo_phan, s)==0)  xuat1(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tksdt(int n, dd *a, char sdt[], FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (strcmp((a+i)->bo_phan, sdt)==0)  xuat1(*(a+i),f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkngayvaoct(int n, dd *a, time ngay, FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (((a+i)->ngay_vaoct.day==ngay.day) &&  ((a+i)->ngay_vaoct.month==ngay.month )&&  ((a+i)->ngay_vaoct.year==ngay.year ) ) 
		xuat1(*(a+i),f2);
		else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkngayroict(int n, dd *a, time ngay, FILE *f2)
{
	int j=0;
	for (int i=0; i<n; i++)
	if (((a+i)->ngay_ract.day==ngay.day )&&  ((a+i)->ngay_ract.month==ngay.month )&&  ((a+i)->ngay_ract.year==ngay.year )  )
		xuat1(*(a+i),f2);
		else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

int main(){
	FILE *f1, *f2;
	int n,choose;	
	f1 = fopen("Quan_ly_nhan_su_INP.txt","r");
	f2 = fopen("Quan_ly_nhan_su_OUT.txt","w");
	fscanf(f1,"%d",&n);	
	dd *a=(dd*)malloc(n*sizeof(dd));
	nhapthongtin(a,n,f1);

	printf("-----------------MENU-------------------\n");
	printf("\t1. In danh sach benh nhan\n");
	printf("\t2. Thong tin chung\n");
	printf("\t3. Sap xep danh sach\n");
	printf("\t4. Tim kiem phan tu\n");
	printf("\t5. Exit\n");
	printf("----------------------------------------\n");
	printf("Nhap yeu cau:"); scanf("%d",&choose);
	switch (choose)
	{
	case 1: fprintf(f2,"STT\tHo va ten\t\t\tGioi tinh   Ngay sinh\t     Chuc vu   \t\t   Bo phan      So dien thoai \t Ngay vao cong ty \t Ngay roi cong ty\n");	 
			xuat(a,n,f2);	break;
	case 2: thongtinchung(a,n,f2);
			break;
	case 3:printf("\t\t1. Theo ten nhan vien\n");
			printf("\t\t2. Theo tuoi nhan vien\n");
			printf("\t\t3. Theo ngay vao cong ty\n");
			printf("\t\t4. Theo ngay roi cong ty\n");
			printf("\t\t5. Exit\n");
			printf("Nhap tieu chi:"); 
			int tieuchi1;
			scanf("%d",&tieuchi1);
			fprintf(f2,"STT\tHo va ten\t\t\tGioi tinh   Ngay sinh\t     Chuc vu   \t\t   Bo phan     So dien thoai \t Ngay vao cong ty \t Ngay roi cong ty\n");
			switch (tieuchi1)
			{
				case 1: 	sxten(n,a); xuat(a,n,f2); break;
				case 2: 	sxtuoi(n,a); xuat(a,n,f2); break;
				case 3: 	sxngayvaoct(n,a); xuat(a,n,f2); break;
				case 4: 	sxngayract(n,a); xuat(a,n,f2); break;
				case 5:		break;
				default:    printf("Loi!");
			} 			break;
	case 4: printf("\t\t1. Theo ho ten \n");
			printf("\t\t2. Theo gioi tinh\n");
			printf("\t\t3. Theo tuoi\n");
			printf("\t\t4. Theo chuc vu\n");
			printf("\t\t5. Theo bo phan\n");
			printf("\t\t6. Theo so dien thoai\n");
			printf("\t\t7. Theo ngay vao cong ty\n");
			printf("\t\t8. Theo ngay roi cong ty\n");
			printf("\t\t9. Exit\n");
			printf("Nhap tieu chi:"); 
			int tieuchi2;
			scanf("%d",&tieuchi2);
			fprintf(f2,"STT\tHo va ten\t\t\tGioi tinh   Ngay sinh\t     Chuc vu   \t\t   Bo phan    So dien thoai \t Ngay vao cong ty \t Ngay roi cong ty\n");
			switch (tieuchi2)
			{
				case 1: printf("Nhap ten muon tim kiem:");	 fflush(stdin);
						char s1[50]; 	scanf("%[^\n]",s1);
						tkten(n,a,s1,f2);  	break;
				case 2: printf("Nhap gioi tinh muon tim kiem:");	 fflush(stdin);
						char s2[50]; 	scanf("%[^\n]",s2);
						tkgt(n,a,s2,f2);  		break;
				case 3: printf("Nhap tuoi muon tim kiem:");	 fflush(stdin);
						int s3; 	scanf("%d",&s3);
						tktuoi(n,a,s3,f2);  		break;
				case 4: printf("Nhap chuc vu muon tim kiem:");	 fflush(stdin);
						char s4[50]; 	scanf("%[^\n]",s4);
						tkchucvu(n,a,s4,f2);  		break;
				case 5: printf("Nhap bo phan muon tim kiem:");	 fflush(stdin);
						char s5[50]; 	scanf("%[^\n]",s5);
						tkbophan(n,a,s5,f2);  		break;
				case 6: printf("Nhap so dien thoai muon tim kiem:");	 fflush(stdin);
						char s6[50]; 	scanf("%[^\n]", s6);
						tksdt(n,a,s6,f2); 			break;
				case 7: printf("Nhap ngay vao cong ty muon tim kiem:");	 fflush(stdin);
							time s7; 	
							scanf("%d",&s7.day);
							scanf("%d",&s7.month);
							scanf("%d",&s7.year);
						tkngayvaoct(n,a,s7,f2);  break;
				case 8: printf("Nhap ngay roi cong ty muon tim kiem:");	 fflush(stdin);
							time s8; 	
							scanf("%d",&s8.day);
							scanf("%d",&s8.month);
							scanf("%d",&s8.year);
						tkngayvaoct(n,a,s8,f2);  break;
				case 9:		break;
				default:    printf("Loi!");
			}    break;
	case 5: break; 
	default: printf("Loi!");
	}
	free(a); 
	fclose(f1);
	fclose(f2);
	return 0;
}







