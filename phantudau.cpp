#include<iostream>
using namespace std;

struct com{
	int stt;
	char com[50];
};

struct node{
	com infor;
	node *pNext;
};

struct List{
	node *pHead;
	node *pTail;
};

node *addNode(com x){
	node *p=new node;
	p->infor=x;
	p->pNext=NULL;
	return p;
}

void addTail(List &l, com x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext = p;  
        l.pTail = p;  
	}
}

void deletel(List &l){
	
}

