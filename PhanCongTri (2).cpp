#include<iostream>
#include<math.h>

using namespace std;

class Donthuc {
	private:
		int mu;
		float heso;
	public:
		void nhap();
		int getheso();
		int getmu();
		void setmu(int x);
		void setheso(int x);
};

int Donthuc::getheso(){
	return this->heso;
}

void Donthuc::setheso(int x){
	this->heso=x;
}

void Donthuc::setmu(int x){
	this->mu=x;
}

int Donthuc::getmu(){
	return this->mu;
}

void Donthuc::nhap(){
	cout << "nhap mu:";
	cin >> this->mu;
	cout << "nhap heso:";
	cin >> this->heso;
}

struct node{
	Donthuc info;
	node *pNext;
}; 

struct List{
	node *pHead;
	node *pTail;
};

node *addNode(Donthuc p){
	node *n= new node;
	n->info=p;
	n->pNext=NULL;
	return n;
}

void addTail(List &l, Donthuc x){
	node *p=addNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext = p;  
        l.pTail = p;  
	}
}

void nhap(List &l, Donthuc x){
	x.nhap();
	addTail(l,x);
	int a=x.getmu();
	a--;
	while (a>-1){
		float b;
		Donthuc c;
		c.setmu(a);
		cout << "nhap ho so cua x^" << a<<": ";
		cin >> b;
		c.setheso(b);
		addTail(l,c);
		a--;
	}
}

void outputList(List l){
	if (l.pHead==NULL){
		cout << "List is empty";
	}
	else {
		node *p=l.pHead;
		while (p!=NULL){
			if (p->info.getmu()==0) cout << p->info.getheso();
			else if (p->info.getmu()!=0 && p->info.getheso()!=0)	cout << p->info.getheso() << "x^"<<p->info.getmu();
			p=p->pNext;
			if(p!=NULL&&p->info.getheso()!=0) cout << " + "; 
		}
	}
}

float tong(List l, float x){
	node *p=l.pHead;
	int summ=0;
		while (p!=NULL){
			summ=summ+p->info.getheso()*pow(x,p->info.getmu());
			p=p->pNext;
		}
	return summ;	
}

int sosanh(List l, List k){
	float a=5;
	if (tong(l,a)>tong(k,a)) return 1;
	if (tong(l,a)<tong(k,a)) return 2;
	return 3;
}

int main(){
	List l,k;
	l.pHead=NULL;
	l.pTail=NULL;
	Donthuc x;
	nhap(l,x);
	outputList(l);
	cout << endl;
	float n; cout <<"nhap x: "; cin >> n;
	cout << "gia tri da thuc la: " << tong(l,n)<< endl;
	k.pHead=NULL;
	k.pTail=NULL;
	Donthuc z;
	nhap(k,z);
	if (sosanh(l,k)==1) cout << "da thuc thu 1 lon hon";
	if (sosanh(l,k)==2) cout << "da thuc thu 2 lon hon";
	if (sosanh(l,k)==3) cout << "2 da thuc bang nhau";
}

