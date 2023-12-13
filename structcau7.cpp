#include<stdio.h>
#include<cstdlib>
#include<windows.h>

struct Baitap{
	int ngay,thang,nam;
};

typedef Baitap BT;

void nhap(Baitap bt[], int a){
	printf("Nhap ngay: "); scanf("%d", &bt[a].ngay);
	printf("nhap thang: "); scanf("%d", &bt[a].thang);
	printf("nhap 2 so cuoi nam 2000: "); scanf("%d", &bt[a].nam);
}

void xuat(Baitap bt[], int a){
	int b=a;
	if (bt[b].ngay<10) printf("0%d/", bt[b].ngay);
	else printf("%d/",bt[b].ngay);
	if (bt[b].thang<10) printf("0%d/", bt[b].thang);
	else printf("%d/",bt[b].thang);
	if (bt[b].nam<10) printf("200%d", bt[b].nam);
	else printf("20%d", bt[b].nam);
}

void kiemtra(Baitap bt[], int a){
	int dem=0;
	if ((bt[a].thang<0) || (bt[a].thang>12)) dem++;
	else if (((bt[a].nam % 4 == 0) && (bt[a].nam % 100!= 0)) || (bt[a].nam%400 == 0)) {
		if ((bt[a].ngay<0) || (bt[a].ngay>29)) dem++;
	}
	else{
		if((bt[a].thang==1) || (bt[a].thang==3) ||(bt[a].thang==5) ||(bt[a].thang==7) ||(bt[a].thang==8) ||(bt[a].thang==10) ||(bt[a].thang==12) ){
			if ((bt[a].ngay<0) || (bt[a].ngay>31)) dem++;
		} 
		else if((bt[a].thang==4) || (bt[a].thang==6) ||(bt[a].thang==9) ||(bt[a].thang==11)){
			if ((bt[a].ngay<0) || (bt[a].ngay>30)) dem++;
		}
		else if(bt[a].thang==2){
			if ((bt[a].ngay<0) || (bt[a].ngay>28)) dem++;
		}
		else dem++;
	}
	if (dem!=0) printf("Khong hop le\n");
	else printf("Hop le\n");
}

void quamai(Baitap bt[], int a){
	int luungay,luuthang;
	if((bt[a].thang==1) || (bt[a].thang==3) ||(bt[a].thang==5) ||(bt[a].thang==7) ||(bt[a].thang==8) ||(bt[a].thang==10) ||(bt[a].thang==12) ){
		printf("ngay hom qua la: ");
		if ((bt[a].ngay>1)){
			bt[a].ngay--;
			xuat(bt,a);
			bt[a].ngay++;
			}
		else {
			if (bt[a].thang!=1){
				luungay=bt[a].ngay;
				luuthang=bt[a].thang;
				bt[a].ngay=30;
				bt[a].thang=bt[a].thang-1;
				xuat(bt,a);
				bt[a].ngay=luungay;
				bt[a].thang=luuthang;
			}
			else printf("31/12/%d", 2000+bt[a].nam-1);
		}
		printf("\nngay mai la: ");
		if ((bt[a].ngay<31)){
			bt[a].ngay++;
			xuat(bt,a);
			bt[a].ngay--;
		}
		else{
			if (bt[a].thang!=12){
				int luuthang=bt[a].thang;
				int luungay=bt[a].ngay;
				bt[a].thang=bt[a].thang+1;
				bt[a].ngay=1;
				xuat(bt,a);
				bt[a].thang=luuthang;
				bt[a].ngay=luungay;
				}
			else printf("01/01/%d", 2000+bt[a].nam+1);
		} 
		}
		
		
	else if((bt[a].thang==4) || (bt[a].thang==6) ||(bt[a].thang==9) ||(bt[a].thang==11)){
		printf("ngay hom qua la: ");
			if ((bt[a].ngay>1)){
			bt[a].ngay--;
			xuat(bt,a);
			bt[a].ngay++;
			}
		else {
				luungay=bt[a].ngay;
				luuthang=bt[a].thang;
				bt[a].ngay=31;
				bt[a].thang=bt[a].thang-1;
				xuat(bt,a);
				bt[a].ngay=luungay;
				bt[a].thang=luuthang;
	}
				
		printf("\nngay mai la: ");
		if ((bt[a].ngay<30)){
			bt[a].ngay++;
			xuat(bt,a);
			bt[a].ngay--;
		}
		else{
			int luuthang=bt[a].thang;
			int luungay=bt[a].ngay;
			bt[a].thang=bt[a].thang+1;
			bt[a].ngay=1;
			xuat(bt,a);
			bt[a].thang=luuthang;
			bt[a].ngay=luungay;
			}
		}
		
		
	else{
		printf("ngay hom qua la: ");
		if ((bt[a].ngay>1)){
			bt[a].ngay--;
			xuat(bt,a);
			bt[a].ngay++;
			}
		else {
			luungay=bt[a].ngay;
			luuthang=bt[a].thang;
			bt[a].ngay=31;
			bt[a].thang=bt[a].thang-1;
			xuat(bt,a);
			bt[a].ngay=luungay;
			bt[a].thang=luuthang;
	}
		if (((bt[a].nam % 4 == 0) && (bt[a].nam % 100!= 0)) || (bt[a].nam%400 == 0)) {
			printf("\nngay mai la: ");
			if ((bt[a].ngay<29)){
				bt[a].ngay++;
				xuat(bt,a);
				bt[a].ngay--;
			}	
			else{
				int luuthang=bt[a].thang;
				int luungay=bt[a].ngay;
				bt[a].thang=bt[a].thang+1;
				bt[a].ngay=1;
				xuat(bt,a);
				bt[a].thang=luuthang;
				bt[a].ngay=luungay;
				}
		}
		else{
			printf("\nngay mai la: ");
			if ((bt[a].ngay<28)){
				bt[a].ngay++;
				xuat(bt,a);
				bt[a].ngay--;
			}	
			else{
				int luuthang=bt[a].thang;
				int luungay=bt[a].ngay;
				bt[a].thang=bt[a].thang+1;
				bt[a].ngay=1;
				xuat(bt,a);
				bt[a].thang=luuthang;
				bt[a].ngay=luungay;
				}
		}
	}  
	}

void cong(Baitap bt[], int a, int x){
	int them,luungay,luuthang,luunam,dem=0,ngaythang2,dem1=0;
	if((bt[a].thang==1) || (bt[a].thang==3) ||(bt[a].thang==5) ||(bt[a].thang==7) ||(bt[a].thang==8) ||(bt[a].thang==10) ||(bt[a].thang==12) ){
		if (x-(31-bt[a].ngay)<=0){
			luungay=bt[a].ngay;
			bt[a].ngay=bt[a].ngay+x;
			xuat(bt,a);
			bt[a].ngay=luungay;
			dem++;
		}
		else x=x-(31-bt[a].ngay);
	}
	else if((bt[a].thang==4) || (bt[a].thang==6) ||(bt[a].thang==9) ||(bt[a].thang==11)){
		if (x-(30-bt[a].ngay)<=0){
			luungay=bt[a].ngay;
			bt[a].ngay=bt[a].ngay+x;
			xuat(bt,a);
			bt[a].ngay=luungay;
			dem++;
		}
		else x=x-(30-bt[a].ngay);
	}
	else {
		if (((bt[a].nam % 4 == 0) && (bt[a].nam % 100!= 0)) || (bt[a].nam%400 == 0)) {
			ngaythang2=29;
			if (x-(29-bt[a].ngay)<=0){
				luungay=bt[a].ngay;
				bt[a].ngay=bt[a].ngay+x;
				xuat(bt,a);
				bt[a].ngay=luungay;
				dem++;
			}
			else x=x-(29-bt[a].ngay);
		}
		else{
			ngaythang2=28;
			if (x-(28-bt[a].ngay)<=0){
				luungay=bt[a].ngay;
				bt[a].ngay=bt[a].ngay+x;
				xuat(bt,a);
				bt[a].ngay=luungay;
				dem++;
			}
			else x=x-(28-bt[a].ngay);
		} 
	}
	luungay=bt[a].ngay;
	luuthang=bt[a].thang;
	luunam=bt[a].nam;
	while (dem1==0){
		bt[a].thang++;
		if((bt[a].thang==1) || (bt[a].thang==3) ||(bt[a].thang==5) ||(bt[a].thang==7) ||(bt[a].thang==8) ||(bt[a].thang==10) ||(bt[a].thang==12) ){
			if (x<=31){
				bt[a].ngay=x;
				dem1++;
			}
			else x=x-31;
		}	
		else if((bt[a].thang==4) || (bt[a].thang==6) ||(bt[a].thang==9) ||(bt[a].thang==11)){
			if (x<=30){
				bt[a].ngay=x;
				dem1++;
			}
			else x=x-30;
		}
		else{
			if (((bt[a].nam % 4 == 0) && (bt[a].nam % 100!= 0)) || (bt[a].nam%400 == 0)) {
				if (x<=29){
					bt[a].ngay=x;
					dem1++;
			}
				else x=x-29;
			}
			else{
				if (x<=28){
					bt[a].ngay=x;
					dem1++;
			}
				else x=x-28;
			}
		}
		
	}
	while (bt[a].thang>12){
		bt[a].nam++;
		bt[a].thang=bt[a].thang-12;
	}
	if (dem==0) xuat(bt,a);
	dem++;
	bt[a].ngay=luungay;
	bt[a].thang=luuthang;
	bt[a].nam=luunam;
	
}

int sosanh(Baitap bt[], int a, int b){
	int c=1, d=0;
	if (bt[a].nam>bt[b].nam) return c;
	else if (bt[a].nam<bt[b].nam) return d;
	else {
		if (bt[a].thang>bt[b].thang) return c;
		else if (bt[a].thang<bt[b].thang) return d;
		else {
			if (bt[a].ngay>bt[b].ngay) return c;
			else if (bt[a].ngay<bt[b].ngay) return d;
			else return c;
		}
	} 
}

void khoangcach(Baitap bt[], int a, int b){
	int max=0,min=0,luunama,luuthanga,luungaya,luunamb,luuthangb,luungayb;
	luunama=bt[a].nam;
	luuthanga=bt[a].thang;
	luungaya=bt[a].ngay;
	luunamb=bt[b].nam;
	luuthangb=bt[b].thang;
	luungayb=bt[b].ngay;
	if (bt[a].nam>bt[b].nam) {
		for(int i=bt[b].nam; i<bt[a].nam; i++){
			bt[a].thang=bt[a].thang+12;
		}
	}
	else if (bt[a].nam<bt[b].nam){
		for(int i=bt[a].nam; i<bt[b].nam; i++){
			bt[b].thang=bt[b].thang+12;
		}
	}

	if (bt[a].thang>bt[b].thang){
		for (int i=bt[b].thang; i<bt[a].thang; i++){
			int c;
			if (i>12) c=i-12;
			else c=i;
			if((c==1) || (c==3) ||(c==5) ||(c==7) ||(c==8) ||(c==10) ||(c==12) ){
				bt[a].ngay=bt[a].ngay+31;}
			else if((c==4) || (c==6) ||(c==9) ||(c==11)){
				bt[a].ngay=bt[a].ngay+30;
			}
			else{
				if (((bt[a].nam % 4 == 0) && (bt[a].nam % 100!= 0)) || (bt[a].nam%400 == 0)) {
					bt[a].ngay=bt[a].ngay+29;
			}
				else bt[a].ngay=bt[a].ngay+28;
		}
	}
}

	else if (bt[a].thang<bt[b].thang){
		for (int i=bt[a].thang; i<bt[b].thang; i++){
			int c;
			if (i>12) c=i-12;
			else c=i;
			if((c==1) || (c==3) ||(c==5) ||(c==7) ||(c==8) ||(c==10) ||(c==12) ){
				bt[b].ngay=bt[b].ngay+31;
			}
			else if((c==4) || (c==6) ||(c==9) ||(c==11)){
				bt[b].ngay=bt[b].ngay+30;
		
			}
			else{
				if (((bt[b].nam % 4 == 0) && (bt[b].nam % 100!= 0)) || (bt[b].nam%400 == 0)) {
					bt[b].ngay=bt[b].ngay+29;
	
			}
				else bt[b].ngay=bt[b].ngay+28;
			
		}
	}
}
	if (bt[a].ngay>=bt[b].ngay) printf("khoang cach= %d", bt[a].ngay-bt[b].ngay);
	else printf("khoang cach= %d", -bt[a].ngay+bt[b].ngay);
	bt[a].nam=luunama;
	bt[a].thang=luuthanga;
	bt[a].ngay=luungaya;
	bt[b].nam=luunamb;
	bt[b].thang=luuthangb;
	bt[b].ngay=luungayb;
}

int xet(Baitap bt[], int a){
	int b=1;
	if (bt[a].ngay==1) return b;
	if((bt[a].thang==1) || (bt[a].thang==3) ||(bt[a].thang==5) ||(bt[a].thang==7) ||(bt[a].thang==8) ||(bt[a].thang==10) ||(bt[a].thang==12) ){
		if (bt[a].ngay==31) return b;
	}
	else if((bt[a].thang==4) || (bt[a].thang==6) ||(bt[a].thang==9) ||(bt[a].thang==11)){
		if (bt[a].ngay==30) return b;		
	}
	else{
		if (((bt[a].nam % 4 == 0) && (bt[a].nam % 100!= 0)) || (bt[a].nam%400 == 0)) 
			if (bt[a].ngay==29) return b;
		else if (bt[a].ngay==28) return b;}
	
	return b-1;
}

void sapxep(Baitap bt[], int a){
	Baitap doi;
	for (int j=0; j<a-1; j++){
		for (int i=a-1; i>j; i--){
			if (!sosanh(bt,i,i-1)){
				doi=bt[i];
				bt[i]=bt[i-1];
				bt[i-1]=doi;
			}
		}
	}
	for (int h=0; h<a; h++){ 
		xuat(bt,h);
		printf("\n"); }

}

int main(){
	BT ngay[100];
	int x,stt=0,n,dem=0;
	nhap(ngay,stt);
	kiemtra(ngay,stt);
	quamai(ngay,stt);
	printf("\nNhap x: "); scanf("%d", &x);
	cong(ngay,stt,x);
	stt++;
	printf("\nNhap ngay moi\n");
	nhap(ngay,stt);
	printf("So sanh 2 ngay tren, ngay lon hon la: ");
	if ((ngay[stt].nam==ngay[stt-1].nam) && (ngay[stt].thang==ngay[stt-1].thang) && (ngay[stt].ngay==ngay[stt-1].ngay)) printf("bang nhau");
	else if (sosanh(ngay,stt-1,stt)) xuat(ngay,stt-1);
	else xuat(ngay,stt);
	printf("\n");
	khoangcach(ngay,stt-1,stt);
	printf("\nSo ngay ban muon nhap them: "); scanf("%d", &n);
	for (int i=stt+1; i<2+n; i++){
		printf("\nnhap ngay thu %d\n", i+1);
		nhap(ngay,i);
	} 
	for (int i=0; i<2+n; i++){
		if (xet(ngay,i)) dem++;
	}
	printf("\nso ngay dau thang va cuoi thang la: %d\n", dem);
	sapxep(ngay,2+n);

	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;

}
