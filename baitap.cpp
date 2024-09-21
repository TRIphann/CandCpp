#include <stdio.h>

struct Node{
	int hs;
	int sm;
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
	Node *p= new Node;
	p->sm=sm; p->hs=hs;
	p->pNext = NULL;
	return p;
}
void addnode(List &l, Node *p)
{
	if (l.pHead == NULL) 
	l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void nhap(List &l)
{
	int x, n;
	do {
	printf("Nhap bac da thuc:");
	scanf("%d",&n);}
	while (n<0);
	for (int i=n; i >=0 ; i--)
	{
		printf("Nhap he so x^%d:",i); scanf("%d",&x);
		Node *p=creatnode(x,i);
		addnode(l,p);	
	}
}

void xuat(List l)
{
	for (Node *k=l.pHead; k!=NULL; k=k->pNext)
	{
		
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
    	if (k->hs==0) printf("");
	}
}
int main()
{
	List L1,L2;
	Init (L1);
	Init(L2);
	printf("Nhap vao da thuc 1:\n"); nhap(L1);
	printf("Nhap vao da thuc 2:\n"); nhap(L2);
	printf("Da thuc 1 la:"); xuat(L1);
	printf("\n");
	printf("Da thuc 2 la:"); xuat(L2);
}


