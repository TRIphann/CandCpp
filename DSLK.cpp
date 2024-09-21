#include <stdio.h>

struct Node{
	int sm;
	int hs;
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
Node *creatnode(int hs, int sm)
{
	Node *p=new Node;
	p->hs=hs;
	p->sm=sm;
	p->pNext = NULL;
	return p;
}
void addnode(List &l3, Node *p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void nhap(List &l)
{
	int x,n;
	do {
	printf("Nhap bac da thuc:");
	scanf("%d",&n);}
	while (n<0);
	for (int i=n; i >=0 ; i--)
	{
		printf("Nhap he so x^%d:",i);
		scanf("%d",&x);
		Node *p= creatnode(x,i);
		addnode(l,p);	
	}
}

void cong(List &l, List l1, List l2)
{
	Node *p = new Node;
	Node *q = new Node;
	if (l1.pHead->sm > l2.pHead->sm)
	{
		l=l1;
		p=l2.pHead;
	}
	else
	{
		l=l2;
		p=l1.pHead;
	}
	q=l.pHead;
	while (q->sm > p->sm) q = q->pNext;
	while (q!=NULL){
	q->hs=q->hs+p->hs;
	p=p->pNext;
	q=q->pNext;}
	
}
void xuat(List l)
{
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	{
		if (k->hs > 0 ) 
		{
			if (k->hs==1)
			{
				if (k->sm==0) printf("+1");
				else if (k->sm==1 )printf("+x");
				else printf("+x^%d",k->sm);
			}
			else
			{
				if (k->sm==0) printf("+%d",k->hs);
				else if (k->sm==1 )printf("+%dx",k->hs);
				else printf("+%dx^%d",k->hs,k->sm);
			}
		}
		if (k->hs <0)
		{
			if (k->hs==-1)
			{
				if (k->sm==0) printf("-1");
				else if (k->sm==1 )printf("x");
				else printf("-x^%d",k->sm);
			}
			else
			{
				if (k->sm==0) printf("%d",k->hs);
				else if (k->sm==1 )printf("%dx",k->hs);
				else printf("%dx^%d",k->hs,k->sm);
			}
		
    	}
    	if (k->hs==0) printf("");
	}
}
int main()
{
	List D,D1,D2;
	Init (D1);
	Init(D2);
	Init(D);
	printf("Nhap vao da thuc D1:\n"); nhap(D1);
	printf("Nhap vao da thuc D2:\n"); nhap(D2);
	printf("Da thuc D1 la:"); xuat(D1);
	printf("\n");
	printf("Da thuc D2 la:"); xuat(D2);
	cong(D,D1,D2);
	printf("\n");
	xuat(D);
}



