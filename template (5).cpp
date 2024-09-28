/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE


struct node{
	char info;
	node *pNext;
}; 

struct List {
	node *pHead;
	node *pTail;
};

void init(List &l){
	l.pHead=NULL;
	l.pTail=NULL;
}

node *addNode(char c){
	node *p=new node;
	p->info=c;
	p->pNext=NULL;
	return p;
}

void addHead(List &l, char x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=p;
		l.pTail=p; 
		return;
	}
	
	else {
		p->pNext=l.pHead;
		l.pHead=p;
	}
	
}

void addTail(List &l, char c){
	node *p=addNode(c);
	if (l.pHead==NULL){
		l.pHead=p;
		l.pTail=p;
		return;
	}
	else {
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void deleteHead(List &l){
	node *p=l.pHead;
	l.pHead=l.pHead->pNext;
	delete p;
}


void deleteTail(List &l){
	node *p=l.pHead;
	while (p->pNext==l.pTail) p=p->pNext;
	l.pTail=p;
	l.pTail->pNext=NULL; 
	delete p;
}

void input(List &l){
	int c; cin >>c;
	for (int i=0; i<c; i++){
		char a; char b;
		cin >> a >>b;
		if (a=='+'){
			char d; cin >> d;
			if (b=='H') addHead(l,d);
			else addTail(l,d);
		}
		else {
			int e; cin >> e;
			if (b='H') deleteHead(l);
			else deleteTail(l);
		}
	}
}

void in(List &l){
	node *p=l.pHead;
	while (p!=NULL){
		cout << p->info << " ";
		p=p->pNext;
	}
}

int main(){
	List l;
	init (l);
	input(l);
	in(l);
}
