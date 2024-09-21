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
		addTail(l,c);
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

node *findMiddle(List l){
	node *p=l.pHead;
	int count=1;
	while (p!=NULL){
		count ++;
		p=p->pNext;
	}
	count--;
	int counts=1;
	node *q=l.pHead;
	while(counts != (count/2+1)) {
		counts ++;
		q=q->pNext;
	}
	return q;
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

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
