#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Acc {
	int stt;
	char account;
	char password;
};

struct Node{
	Acc data;
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

Node *creatnode(Acc x) {
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

void input(Acc &a, FILE *f1){
	fscanf(f1, "%s", &a.account);
	fscanf(f1, "%s", &a.password);
}

void inputAcc(Acc a, List &l, int stt, char *acc, char *pass){
	scanf("%s", &acc);
	scanf("%s", &pass);
}

int main(){
	List l;
	Acc a;
	int n;
	char acc,pass;
	FILE *f1;
	f1=fopen("Mat_khau.txt","r");
	fscanf(f1,"%d",&n);
	Init(l);
	input(a,f1);
	inputAcc(a,l,n,&acc,&pass);
	printf("%s\n%s", acc,pass);
}
