/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct node {
	int info;
	node *pNext;
}; 

struct List {
	node *pHead;
	node *pTail;
};

node* addNode (int x){
	node* p= new node;
	p->info=x;
	p->pNext=NULL;
	return p;
}

void addTail(List &l, int x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void inputList(List &l, int n){
	int c;
	for (int i=0; i<n; i++){
		cin >> c;
		addHead(l,c);
	}
}

void outputList(List &l){
	node *p=l.pHead;
	while (p!=NULL){
		cout << p->info << " ";
		p=p->pNext;
	}
	if(l.pHead==NULL) cout << "List is empty" ;
}

void moveLastToFront(List &l){
	if (l.pHead==NULL || l.pHead==l.pTail) {
		return;
	}
	node *p=NULL;
    node *c=l.pHead;
    while (c->pNext!=NULL) {
        p=c;
        c=c->pNext;
    }
    p->pNext=NULL; 
    l.pTail=p;     

    c->pNext=l.pHead;  
    l.pHead=c;   
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
