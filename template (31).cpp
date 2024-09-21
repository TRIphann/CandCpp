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

struct tinh{
	int id;
	string name;
	int pop;
	float area;
};

struct node{
	tinh info;
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

node *addNode(tinh x){
	node *p= new node;
	p->info=x;
	p->pNext=NULL;
	return p;
}

void addTail(List &l, tinh x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=p;
		l.pTail=p;
	}
	else {
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void inputListProvinces(List &l){
	int x; cin >>x;
	for (int i=0; i<x; i++){
		tinh a;
		cin >> a.id;
		cin.ignore();
		getline(cin, a.name);
		cin >> a.pop;
		cin >> a.area; 
		addTail(l,a);
	}
	
}

void outputListProvinces(List l){
	node *p=l.pHead;
	while (p!=NULL){
		cout << p->info.id << "\t" << p->info.name << "\t" << p->info.pop << "\t" << p->info.area << endl;
		p=p->pNext;
	}
}

void outputProvincesMore1MillionPop(List l){
	node *p=l.pHead;
	while (p!=NULL){
		if (p->info.pop>1000){
			cout << p->info.id << "\t" << p->info.name << "\t" << p->info.pop << "\t" << p->info.area << endl;
		}
		p=p->pNext;
	}
}

node *findProMaxArea(List l){
	node *p=l.pHead;
	p=p->pNext;
	node *max=l.pHead;
	while (p!=NULL){
		if (p->info.area>max->info.area) max=p;
		p=p->pNext;
	}
	return max;
}

void outputProvince(tinh p){
	cout << p.id << "\t" << p.name << "\t" << p.pop << "\t" << p.area << endl;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}



