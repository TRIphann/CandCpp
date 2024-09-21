#include<stdio.h>

struct Ten{
	int stt;
	char ten[50];
};

struct Node{
	Ten data;
	Node *pNext;
};

struct List{
	Node *pHead, *pTail;
};

void init(List &l){
	l.pHead=NULL;
	l.pTail=NULL;
}

Node *creatNode(Ten a){
	Node *p = new Node;
	p->data=a;
	p->pNext=NULL;
	return p;
}

void addNode(List &l, Node *p){
	if (l.pHead==NULL) l.pHead= l.pTail =p;
	else {
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void nhapTen(List l, Ten &a){
	printf("nhap stt: "); scanf("%d", &a.stt);
	printf("nhap ten: "); scanf("%s", &a.ten);
}

void nhap(List &l, int n){
	Ten a;
	for (int i=0; i<n; i++){
		nhapTen(l,a);
		Node *newNode=creatNode(a);
		addNode(l,newNode);	
	}
}

void xuat(List l, int n){
	for (Node *k=l.pHead; k!=NULL; k=k->pNext){
		printf("%d  %s", k->data.stt, k->data.ten);
		printf("\n");
	}
	
}

int main(){
	List l;
	init(l);
	int n;
	printf("Nhap so luong: "); scanf("%d", &n);
	nhap(l,n);
	printf("\n");
	xuat(l,n);
}
