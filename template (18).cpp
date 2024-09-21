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

struct node{
	int info;
	node *pNext;
};

struct List{
	node *pHead;
	node *pTail;
};

void Init(List &l){
	l.pHead=NULL;
	l.pTail=NULL;
}

node *addNode(int n){
	node *p=new node;
	p->info=n;
	p->pNext=NULL;
	return p;
}

void addTail(List &l, int n){
	node *p=addNode(n);
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
	if (l.pHead==NULL){
		cout << "List is empty";
		return ;
	}
	else {
		while (p!=NULL){
			cout << p->info <<" ";
			p=p->pNext;
		}
	}
}

node *findElement(List l,int n){
	node *p = l.pHead;
    int count = 1; 
    while (p!=NULL&&count!=n){
        p = p->pNext;
        count++;
    }
    
    if (p == NULL) {
        cout << "The index is invalid";
    }
    return p;
}


int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}
