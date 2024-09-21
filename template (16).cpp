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

void Init(List &l){
	l.pHead=NULL;
	l.pTail=NULL;
}

node *addNode(int n){
	node *p=new node;
	p->infor=n;
	p->pNext=NULL;
	return p;
}

void addHead(List &l, int x){
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

void outputList(List l){
	node *p=l.pHead;
	if (l.pHead==NULL) cout <<"List is empty";
	else {
		while (p!=NULL){
			cout << p->infor << " ";
			p=p->pNext;
		}
	}
}

void outputGreaterThan(List l, int m){
	node *p=l.pHead;
	if (l.pHead==NULL){
		cout << "List is empty";
		return;
	}
	int count=0;
	while (p!=NULL){
		if (p->infor>m){
			cout << p->infor <<" ";
			count ++;
		}
		p=p->pNext;
	}
	if (count ==0) cout << "None";
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


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
