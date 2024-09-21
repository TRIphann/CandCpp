#include<iostream>
using namespace std;

struct com {
	int stt;
	char com[50];
};

struct node {
	com info[50];
	node *pNext;
}; 

struct List {
	node *pHead;
	node *pTail;
};

node* getNode (com x){
	node* p= new node;
	p->info=x;
	p->pNext=NULL;
	return p;
}

void deleteHead(List &l){
	if (l.pHead.info!='0') l.pHead.info='0';
	node *p=l.pHead;
	while (p->info!='0'){
		p=p->pNext;
	}
	if (p==NULL) l.pHead.info='0';
	
}

void addTail(List &l, char x){
	node *p=getNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext = p;  
        l.pTail = p;  
	}
}

void output(List l){
    int dem=0;
    
}



int main(){
	List l;
	l.pHead=l.pTail=NULL;
	int n;
	char com[50];
	cin >> n;
	while (n!=-1){
		cin >> com;
		if (n==0) {
			addHead(l,com);
		}
		if (n==1){
			deleteHead(l);
		}
	}
	output(l); 
}
