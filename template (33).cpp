/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -

void init(DList &l){
	l.pHead=NULL;
	l.pTail=NULL;
} 

DNode *addNode(int x){
	DNode *p=new DNode;
	p->info=x;
	p->pNext=NULL;
	p->pPrev=NULL;
	return p;
}

void addTail(DList &l, int a){
	DNode *p=addNode(a);
	if (l.pHead==NULL) {
		l.pHead=p;
		l.pTail=p; 
		return;
	}
	p->pPrev=l.pTail;
	l.pTail->pNext=p;
	l.pTail=p;
	
}

void createList(DList &l){
	int a;
	cin >> a;
	while (a!=-1) {
		addTail(l,a);
		cin >> a;
	}
}

void  printList(DList &l){
	DNode *p=l.pHead;
	if (l.pHead==NULL) {
		cout << "List is empty";
		return ;
	}
	while (p!=NULL){
		cout << p->info << " ";
		p=p->pNext;
	}
}

void addHead(DList &l, int a){
	DNode *p=addNode(a);
	if (l.pHead==NULL){
		l.pHead=p;
		l.pTail=p; 
		return;
	}
	p->pNext=l.pHead;
	l.pHead->pPrev=p;
	l.pHead=p;
}

int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
