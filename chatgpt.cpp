#include<iostream>
using namespace std;

struct node {
	int info;
	node *pNext;
}; 

struct List {
	node *pHead;
	node *pTail;
};

node* getNode (int x){
	node* p= new node;
	p->info=x;
	p->pNext=NULL;
	return p;
}

void addHead(List &l, int x){
	node *p=getNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}	
	else {
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void addTail(List &l, int x){
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
    node *p = l.pHead;
    while (p != NULL) { 
        cout << p->info << " ";
        p = p->pNext;
    }
}

void insertAfter(List &l, int value, int newVal) {
    node *p = l.pHead;
    while (p != NULL && p->info != value){
        p = p->pNext;
    }

    if (p != NULL) {  
        node *c = getNode(newVal);
        c->pNext = p->pNext;
        p->pNext = c;
        if (p == l.pTail) {  
            l.pTail = c;
        }
    }
}

int main(){
	List l;
	l.pHead=l.pTail=NULL;
	int n,a,b;
	cin >> n;
	while (n!=3){
		cin >> a;
		if (n==1) addTail(l,a);
		else if (n==0) addHead(l,a);
		else if (n==2) {
			cin >> b;
			insertAfter(l, a, b);
		}
		cin >> n;
	} 
	output(l); 
}

