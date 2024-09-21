

#include <iostream>
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

node* getNode (int x){
	node* p= new node;
	p->info=x;
	p->pNext=NULL;
	return p;
}

void addHead(List &l, int x){
	node *p=getNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}	
	else {
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void addTail(List &l, int x){
	node *p=getNode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else {
		l.pTail->pNext = p;  
        l.pTail = p;  
	}
}

void output(List l){
    if (l.pHead == NULL) {
		cout << "blank";
	}
	else {
		node *p = l.pHead;
    while (p != NULL) { 
        cout << p->info << " ";
        p = p->pNext;
    }	
	}
	
}

void deletee(List &l, int a) {
    node *p = l.pHead;
    node *q=NULL;
    if (p==NULL) return; 
    if (p->info == a) {
        l.pHead = p->pNext;
        if (l.pHead == NULL) {
            l.pTail = NULL;
        }
        delete p;
        return;
    }
    
    while (p!=NULL&&p->info!=a){
		q=p;
		p=p->pNext;
	}
	
	if (p==NULL) return;
	if (p==l.pTail){
		l.pTail=q;
	} 
	q->pNext=p->pNext;
	p->pNext=NULL;
	delete p;
}

void xoadau(List &l){
	if (l.pHead == NULL) {
		return ;
	}
	else{
		node *p = l.pHead;
		l.pHead = l.pHead->pNext; 
		delete p;
		if (l.pHead == NULL) {
	        l.pTail = NULL;
    }
	}
	
}

void themsau(List &l, int a, int b) {
    node *p = l.pHead;
    while (p != NULL && p->info != a){
        p = p->pNext;
    }
    
    if (p==NULL){
    	addHead(l,b);
    	return;
	} 

    if (p != NULL) {  
        node *c = getNode(b);
        c->pNext = p->pNext;
        p->pNext = c;
        
        if (p == l.pTail) {  
            l.pTail = c;
        }
    }
}

void deleteall(List &l, int a){
	node *p = l.pHead;
	node *k= l.pHead;
    node *q=NULL;
    if (p==NULL) return; 
     while (p != nullptr && p->info == a) {
        node* t = p;
        p = p->pNext;
        delete t;
    }
    
    l.pHead=p;
	
	if (l.pHead == nullptr) {
        l.pTail = nullptr;
        return;
    } 
    
    q = l.pHead;
    while (q != nullptr && q->pNext != nullptr) {
        if (q->pNext->info == a) {
            node* t = q->pNext;
            q->pNext = t->pNext;
            if (t == l.pTail) {
                l.pTail = q;
            }
            delete t;
        } else {
            q = q->pNext;
        }
    }
}

int main(){
	List l;
	l.pHead=l.pTail=NULL;
	int n,a,b;
	cin >> n;
	while (n!=6){
		if (n==5) xoadau(l);
		else {
			cin >> a;
			if (n==1) addTail(l,a);
			
			else if (n==0) addHead(l,a);
			
			else if (n==2) {
				cin >> b;
				themsau(l,a,b); 
			}
			
			else if (n==3) {
				
				deletee(l, a);
			}
			else {
				deleteall(l,a);
			}
		}
		
		cin >> n;
	} 
	output(l); 
}
