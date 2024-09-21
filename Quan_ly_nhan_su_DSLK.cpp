#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// stt, tên, gioi tinh, ngay sinh, vi trí, chúc vuj, bo phan, so dien thoai, gio vao, gio ra
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

struct Node{
	dd data;
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
Node *creatnode(dd x)
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

void nhapthongtin(List &l ,int n, FILE *f1){
	dd a;
	for (int i=0; i<n; i++){
		thongtin(a,f1);
		Node *b= creatnode(a);
		addnode(l,b);
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
void xuat(List l, FILE *f2){
	for (Node *k=l.pHead; k!=NULL; k=k->pNext) {
    	xuat1(k->data,f2);
	}
}

void demgioitinh(List l, FILE *f2){
	int nam=0;
    int nu=0;
    for (Node *k=l.pHead; k!=NULL; k=k->pNext) {
        if (strcmp(k->data.gioi_tinh, "nu\n") == 0) nu++;
        else if (strcmp(k->data.gioi_tinh, "nam\n") == 0) nam++;
    }
    fprintf(f2, "Nam: 2,   Nu: 3", nam, nu);
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

int dembophan(int n, Node* a) {
    int c = 0;
    Node* current = a;
    Node* b[100];    
    while (current != NULL) {
        int dem = 0;
        for (int j = 0; j < c; j++) {
            if (strcmp(current->data.bo_phan, b[j]->data.bo_phan) == 0) {
                dem++;
                break;
            }
        }
        if (dem == 0) {
            b[c] = current;
            c++;
        }
        current = current->pNext;
    }    
    return c;
}

void quanly(List l, FILE *f2) {
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        int dem = 0;
        if (strcmp(k->data.chuc_vu, "Quan ly\n") == 0) {
            fprintf(f2, "%s%sbo phan %s", k->data.ten, k->data.chuc_vu, k->data.bo_phan);
            for (Node* j = l.pHead; j != NULL; j = j->pNext) {
                if (strcmp(k->data.bo_phan, j->data.bo_phan) == 0) {
                    dem++;
                }
            }
            fprintf(f2, "So nhan su: %d\n\n", dem);
        }
    }
}


void thongtinchung(List l, int n, FILE *f2){
	int dem=0;
	fprintf(f2, "GIOI TINH: \n"); 
	demgioitinh(l,f2);
	fprintf(f2, "\n\n");
	
	fprintf(f2, "TUOI: \n"); 
	int max=l.pHead->data.ngay_sinh.year, tong=0;
	float tbc=0;
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		tong=tong+(2024-k->data.ngay_sinh.year);
	}
	tbc=tong/n;
	fprintf(f2, "Trung binh: %.2f\nNguoi lon tuoi nhat: ", tbc);
	time maxa=l.pHead->data.ngay_sinh;
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		if (sstime((k->data.ngay_sinh), maxa)<0) {
			maxa=k->data.ngay_sinh;
		}
	}
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		if ((maxa.day==k->data.ngay_sinh.day) && (maxa.month==k->data.ngay_sinh.month) && (maxa.year==k->data.ngay_sinh.year)){
			fprintf(f2, "%s", k->data.ten);
			for (Node *j = k->pNext; j != NULL; j = j->pNext) {
				if ((maxa.day==j->data.ngay_sinh.day) && (maxa.month==j->data.ngay_sinh.month) && (maxa.year==j->data.ngay_sinh.year)){
					fprintf(f2, ", %s", j->data.ten);
				}
			}
			fprintf(f2, ": %.0f\n" ,(2024-maxa.year));
			break;
		}
		
	}
	fprintf(f2, "Nguoi nho tuoi nhat: ");
	time min=l.pHead->data.ngay_sinh;
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		if (sstime((k->data.ngay_sinh), min)>0) {
			min=k->data.ngay_sinh;
		}
	}
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		if ((min.day==k->data.ngay_sinh.day) && (min.month==k->data.ngay_sinh.month) && (min.year==k->data.ngay_sinh.year)){
			fprintf(f2, "%s", k->data.ten);
			for (Node *j = k->pNext; j != NULL; j = j->pNext) {
				if ((min.day==j->data.ngay_sinh.day) && (min.month==j->data.ngay_sinh.month) && (min.year==j->data.ngay_sinh.year)){
					fprintf(f2, ", %s", j->data.ten);
				}
			}
			fprintf(f2, ": %.0f\n" ,(2024-min.year));
			break;
		}
	
	}
	fprintf(f2, "\n\n");

	fprintf(f2, "BO PHAN: \n"); 
	fprintf(f2, "So bo phan: %d\n", dembophan(n,l.pHead));
	quanly(l,f2);
}


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void sxten(List &l){
	dd name;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (strcmp(k->data.ten, q->data.ten)  > 0 )	{
		name= k->data;
		k->data = q->data;
		q->data = name;
	}
}

void sxtuoi(List &l){
	dd tuoi;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if ((2024-k->data.ngay_sinh.year) < (2024-q->data.ngay_sinh.year)) {
		tuoi= k->data;
		k->data = q->data;
		q->data = tuoi;
	}	
}

void sxngayvaoct(List &l){
	dd t;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (sstime(k->data.ngay_vaoct, q->data.ngay_vaoct) > 0 )
	{
		t= k->data;
		k->data = q->data;
		q->data = t;
	}
}

void sxngayract(List &l){
	dd t;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	for (Node *q=k->pNext; q!=NULL; q=q->pNext)
	if (sstime(k->data.ngay_ract, q->data.ngay_ract) > 0 )
	{
		t= k->data;
		k->data = q->data;
		q->data = t;
	}
}

void tkten(int n,List &l, char s[], FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.ten, s)==0)  xuat1(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi");
}

void tkgt(int n,List &l, char s[], FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.gioi_tinh, s)==0)  xuat1(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tktuoi(int n,List &l, int tuoi, FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if ( (2024-k->data.ngay_sinh.year) == tuoi )  xuat1(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkchucvu(int n,List &l, char s[], FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.chuc_vu, s)==0)  xuat1(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkbophan(int n,List &l, char s[], FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.bo_phan, s)==0)  xuat1(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tksdt(int n,List &l, char s[], FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if (strcmp(k->data.sdt, s)==0)  xuat1(k->data,f2);
	else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}

void tkngayvaoct(int n,List &l, time ngay, FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext){
		if ((k->data.ngay_vaoct.day==ngay.day) &&  (k->data.ngay_vaoct.month==ngay.month )&&  (k->data.ngay_vaoct.year==ngay.year ) ) 
			xuat1(k->data,f2);
		else j++;	
	}
	if (j==n)  fprintf(f2,"Loi!");
}

void tkngayroict(int n, List &l, time ngay, FILE *f2){
	int j=0;
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	if ((k->data.ngay_ract.day==ngay.day )&&  (k->data.ngay_ract.month==ngay.month )&&  (k->data.ngay_ract.year==ngay.year )  )
		xuat1(k->data,f2);
		else j++;	
	if (j==n)  fprintf(f2,"Loi!");
}


int isValidDate(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ki?m tra nãm nhu?n
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        daysInMonth[1] = 29; // Nãm nhu?n tháng 2 có 29 ngày
    } else {
        daysInMonth[1] = 28; // Nãm không nhu?n tháng 2 có 28 ngày
    }

    // Ki?m tra tính h?p l? c?a ngày tháng nãm
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1]) {
        return 0; // Ngày tháng nãm không h?p l?
    }

    // Ki?m tra không vý?t quá ngày hi?n t?i (25/06/2024)
    if (year > 2024 || (year == 2024 && (month > 6 || (month == 6 && day > 25)))) {
        return 0; // Ngày tháng nãm vý?t quá ngày hi?n t?i
    }

    return 1; // Ngày tháng nãm h?p l?
}


void nhapNhanVienMoi(List &l, FILE *f2) {
    dd a;

    printf("Nhap STT: ");
    scanf("%d", &a.stt);
    getchar();  // Ð? ãn k? t? newline sau khi nh?p s? nguyên.

    printf("Nhap ho va ten: ");
    fgets(a.ten, sizeof(a.ten), stdin);
    remove_newline(a.ten);

    printf("Nhap gioi tinh: ");
    fgets(a.gioi_tinh, sizeof(a.gioi_tinh), stdin);
    remove_newline(a.gioi_tinh);

    printf("Nhap ngay sinh (day month year): ");
    scanf("%d %d %f", &a.ngay_sinh.day, &a.ngay_sinh.month, &a.ngay_sinh.year);
    getchar();  // Ð? ãn k? t? newline sau khi nh?p s?.

    printf("Nhap chuc vu: ");
    fgets(a.chuc_vu, sizeof(a.chuc_vu), stdin);
    remove_newline(a.chuc_vu);

    printf("Nhap bo phan: ");
    fgets(a.bo_phan, sizeof(a.bo_phan), stdin);
    remove_newline(a.bo_phan);

    printf("Nhap so dien thoai: ");
    fgets(a.sdt, sizeof(a.sdt), stdin);
    remove_newline(a.sdt);

    printf("Nhap ngay vao cong ty (day month year): ");
    scanf("%d %d %f", &a.ngay_vaoct.day, &a.ngay_vaoct.month, &a.ngay_vaoct.year);
    getchar();  // Ð? ãn k? t? newline sau khi nh?p s?.

    printf("Nhap ngay roi cong ty (day month year): ");
    scanf("%d %d %f", &a.ngay_ract.day, &a.ngay_ract.month, &a.ngay_ract.year);
    getchar();  // Ð? ãn k? t? newline sau khi nh?p s?.

    Node *newNode = creatnode(a);
    addnode(l, newNode);
	xuat(l, f2);
    printf("Nhan vien moi da duoc them vao danh sach.\n");
}



void xoaNhanVien(List &l, int stt, FILE *f2) {
    Node *current = l.pHead;
    Node *previous = NULL;

    while (current != NULL && current->data.stt != stt) {
        previous = current;
        current = current->pNext;
    }

    if (current == NULL) {
        printf("Khong tim thay nhan vien co stt %d!\n", stt);
        return;
    }

    if (previous == NULL) { // Xóa node ð?u
        l.pHead = current->pNext;
        if (l.pHead == NULL) {
            l.pTail = NULL;
        }
    } else {
        previous->pNext = current->pNext;
        if (current == l.pTail) {
            l.pTail = previous;
        }
    }

    delete current;
    printf("Da xoa nhan vien co stt %d!\n", stt);
    xuat(l, f2);
}

void chinhSuaNhanVien(List &l, int stt, FILE *f2) {
    Node *current = l.pHead;
    while (current != NULL && current->data.stt != stt) {
        current = current->pNext;
    }

    if (current == NULL) {
        printf("Khong tim thay nhan vien co stt %d!\n", stt);
        return;
    }

    int choose;
    do {
        printf("Chon thong tin can chinh sua:\n");
        printf("1. Ho va ten\n");
        printf("2. Gioi tinh\n");
        printf("3. Ngay sinh\n");
        printf("4. Chuc vu\n");
        printf("5. Bo phan\n");
        printf("6. So dien thoai\n");
        printf("7. Ngay vao cong ty\n");
        printf("8. Ngay roi cong ty\n");
        printf("9. Hoan tat\n");
        printf("Lua chon: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap ten moi: ");
                fflush(stdin);
                fgets(current->data.ten, sizeof(current->data.ten), stdin);
                remove_newline(current->data.ten);
                break;
            case 2:
                printf("Nhap gioi tinh moi: ");
                fflush(stdin);
                fgets(current->data.gioi_tinh, sizeof(current->data.gioi_tinh), stdin);
                remove_newline(current->data.gioi_tinh);
                break;
            case 3:
			    printf("Nhap ngay sinh moi (dd mm yyyy): ");
			    do {
			        scanf("%d %d %d", &current->data.ngay_sinh.day, &current->data.ngay_sinh.month, &current->data.ngay_sinh.year);
			        if (!isValidDate(current->data.ngay_sinh.day, current->data.ngay_sinh.month, current->data.ngay_sinh.year)) {
			            printf("Ngay thang nhap khong hop le. Vui long nhap lai: ");
			        }
			    } while (!isValidDate(current->data.ngay_sinh.day, current->data.ngay_sinh.month, current->data.ngay_sinh.year));
			    break;
            case 4:
                printf("Nhap chuc vu moi: ");
                fflush(stdin);
                fgets(current->data.chuc_vu, sizeof(current->data.chuc_vu), stdin);
                remove_newline(current->data.chuc_vu);
                break;
            case 5:
                printf("Nhap bo phan moi: ");
                fflush(stdin);
                fgets(current->data.bo_phan, sizeof(current->data.bo_phan), stdin);
                remove_newline(current->data.bo_phan);
                break;
            case 6:
                printf("Nhap so dien thoai moi: ");
                fflush(stdin);
                fgets(current->data.sdt, sizeof(current->data.sdt), stdin);
                remove_newline(current->data.sdt);
                break;
            case 7:
			    printf("Nhap ngay vao cong ty moi (dd mm yyyy): ");
			    do {
			        scanf("%d %d %d", &current->data.ngay_vaoct.day, &current->data.ngay_vaoct.month, &current->data.ngay_vaoct.year);
			        if (isValidDate(current->data.ngay_vaoct.day, current->data.ngay_vaoct.month, current->data.ngay_vaoct.year)) {
			            printf("Ngay thang nhap khong hop le. Vui long nhap lai: ");
			        }
			    } while (isValidDate(current->data.ngay_vaoct.day, current->data.ngay_vaoct.month, current->data.ngay_vaoct.year));
			    break;
			
			case 8:
			    printf("Nhap ngay roi cong ty moi (dd mm yyyy): ");
			    do {
			        scanf("%d %d %d", &current->data.ngay_ract.day, &current->data.ngay_ract.month, &current->data.ngay_ract.year);
			        if (isValidDate(current->data.ngay_ract.day, current->data.ngay_ract.month, current->data.ngay_ract.year)) {
			            printf("Ngay thang nhap khong hop le. Vui long nhap lai: ");
			        }
			    } while (isValidDate(current->data.ngay_ract.day, current->data.ngay_ract.month, current->data.ngay_ract.year));
			    break;
            case 9:
                printf("Hoan tat chinh sua.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choose != 9);
    xuat(l, f2);
}



int main(){
	List l;
	FILE *f1, *f2;
	int n,choose;	
	f1 = fopen("Quan_ly_nhan_su_DSLK_INP.txt","r");
	f2 = fopen("Quan_ly_nhan_su_DSLK_OUT.txt","w");
	fscanf(f1,"%d",&n);	
	Init(l);
	nhapthongtin(l,n,f1);

	printf("-----------------MENU-------------------\n");
	printf("\t1. In danh sach nhan vien\n");
	printf("\t2. Thong tin chung\n");
	printf("\t3. Sap xep danh sach\n");
	printf("\t4. Tim kiem phan tu\n");
	printf("\t5. Chinh sua thong tin nhan vien\n");
	printf("\t6. Exit\n");
	printf("----------------------------------------\n");
	printf("Nhap yeu cau:"); scanf("%d",&choose);
	switch (choose)
	{
	case 1: fprintf(f2,"STT\tHo va ten\t\t\tGioi tinh   Ngay sinh\t     Chuc vu   \t\t   Bo phan      So dien thoai \t Ngay vao cong ty \t Ngay roi cong ty\n");	 
			xuat(l,f2);	break;
	case 2: thongtinchung(l,n,f2);
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
				case 1: 	sxten(l); xuat(l,f2); break;
				case 2: 	sxtuoi(l); xuat(l,f2); break;
				case 3: 	sxngayvaoct(l); xuat(l,f2); break;
				case 4: 	sxngayract(l); xuat(l,f2); break;
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
						tkten(n,l,s1,f2);  		break;
				case 2: printf("Nhap gioi tinh muon tim kiem:");	 fflush(stdin);
						char s2[50]; 	scanf("%[^\n]",s2);
						tkgt(n,l,s2,f2);  		break;
				case 3: printf("Nhap tuoi muon tim kiem:");	 fflush(stdin);
						int s3; 	scanf("%d",&s3);
						tktuoi(n,l,s3,f2);  		break;
				case 4: printf("Nhap chuc vu muon tim kiem:");	 fflush(stdin);
						char s4[50]; 	scanf("%[^\n]",s4);
						tkchucvu(n,l,s4,f2);  		break;
				case 5: printf("Nhap bo phan muon tim kiem:");	 fflush(stdin);
						char s5[50]; 	scanf("%[^\n]",s5);
						tkbophan(n,l,s5,f2);  		break;
				case 6: printf("Nhap so dien thoai muon tim kiem:");	 fflush(stdin);
						char s6[50]; 	scanf("%[^\n]", s6);
						tksdt(n,l,s6,f2); 			break;
				case 7: printf("Nhap ngay vao cong ty muon tim kiem:");	 fflush(stdin);
							time s7; 	
							scanf("%d",&s7.day);
							scanf("%d",&s7.month);
							scanf("%f",&s7.year);
						tkngayvaoct(n,l,s7,f2);  break;
				case 8: printf("Nhap ngay roi cong ty muon tim kiem:");	 fflush(stdin);
							time s8; 	
							scanf("%d",&s8.day);
							scanf("%d",&s8.month);
							scanf("%f",&s8.year);
						tkngayroict(n,l,s8,f2);  break;
				case 9:		break;
				default:    printf("Loi!");
			}    break;
	case 5:
		printf("\t\t1. Nhap nhan vien moi\n");
		printf("\t\t2. Xoa nhan vien\n");
		printf("\t\t3. Chinh sua thong tin\n");
		int chonthaydoi;
		printf("Nhap yeu cau: ");
		scanf("%d",&chonthaydoi);
		switch (chonthaydoi)
		{
			case 1:
				printf("Nhap thong tin nhan vien moi:\n");
				nhapNhanVienMoi(l, f2);
				n++;
				break;
			
			case 2:
				printf("Nhap stt nhan vien muon xoa: ");
                int stt_xoa;
                scanf("%d", &stt_xoa);
                xoaNhanVien(l, stt_xoa, f2);
                n--;  
                break;

			case 3:
				printf("Nhap stt nhan vien muon chinh sua: ");
                int stt_chinh_sua;
                scanf("%d", &stt_chinh_sua);
                chinhSuaNhanVien(l, stt_chinh_sua, f2);
                break;
			
		} break;
                
	case 6: break; 
	default: printf("Loi!");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

