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
    l.pHead = NULL;
    l.pTail = NULL;
}

node *addNode(int n){
    node *p = new node;
    p->info = n;
    p->pNext = NULL;
    return p;
}

void addTail(List &l, int n){
    node *p = addNode(n);
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void addTaill(List &l, node *p){
    if (l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void inputList(List &l, int n){
    int c;
    for (int i = 0; i < n; i++){
        cin >> c;
        addTail(l, c);
    }
}

void outputList(List &l){
    node *p = l.pHead;
    if (l.pHead == NULL){
        cout << "List is empty";
        return;
    } else {
        while (p != NULL){
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

void concate(List &l1,List &l2){
	if (l1.pHead==NULL) {
		l1.pHead = l2.pHead;
        l1.pTail = l2.pTail;
		return;
	}
	if (l2.pHead==NULL) return;
	
	node *p=l2.pHead;
	while (p!=NULL){
		addTaill(l1,p);
		p=p->pNext;
	}
}

int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
