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
	int infor;
	node *pNext;
}; 

struct List{
	node *pHead;
	node *pTail;
};

node *addNode(int p){
	node *n= new node;
	n->infor=p;
	n->pNext=NULL;
	return n;
}

void Init(List &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
void addTail(List &l, int x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext = p;  
        l.pTail = p;  
	}
}

void addHead(List &l, int x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void inputList(List &l, int n){
	int a;
	for (int i=0; i<n; i++){
		cin >> a;
		addTail(l,a);
	}
}

void addList(List &l, int m){
	int a;
	for (int i=0; i<m; i++){
		cin >> a;
		addHead(l,a);
	}
}

void outputList(List l){
	if (l.pHead==NULL){
		cout << "List is empty";
	}
	else {
		node *p=l.pHead;
		while (p!=NULL){
			cout << p->infor << " ";
			p=p->pNext;
		}
	}
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    cout<<"\nEnter a number: "; int m; cin>>m; // Nhap so luong phan tu them vao dau ds
    cout<<"\nEnter a sequence of "<<m<<" numbers: ";
    addList(L,m); // Nhap 1 day gom m so va them phan tu moi vao dau ds
    cout<<"\nThe updated Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}
