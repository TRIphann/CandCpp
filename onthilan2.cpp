#include<stdio.h>

struct ten{
	int stt;
	char ten[50];
};

struct Node{
	ten data;
	Node *pNext;
};

struct List{
	Node *pHead, *pTail;
};

void init(List &l){
	l.pHead=NULL;
	l.pTail=NULL;
}

Node *creatNode(ten a){
	Node *p=new Node;
	p->data=a;
	p->pNext=NULL;
	return p;
}

void addNode(List &l, Node *a){
	if (l.pHead==NULL) l.pHead = l.pTail =a;
	else {
		l.pTail->pNext=a;
		l.pTail=a;
	}
}

void nhapTen(ten a){
	printf("stt: "); scanf("%d", &a.stt);
	printf("ten: "); fgets(a.ten, sizeof(a.ten), stdin);
}

void nhap(List &l, int n){
	ten a;
	for (int i=0; i<n; i++){
		nhapTen(a);
		Node *p= creatNode(a);
		addNode(l,p);
	}
}

void xuat(List l){
	for (Node *k=l.pHead; k!=NULL; k=k->pNext){
		printf("%d %s     ", k->data.stt,k->data.ten);
	}
}

int main(){
	List l;
	init(l);
	int n;
	printf("nhap so luong: "); scanf("%d", &n);
	nhap(l,n);
	xuat(l);
}
