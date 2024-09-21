

#include <iostream>
using namespace std;


struct node
{
    int info;
    node *pNext;
};
struct Stack
{
    node *pHead; 
	node *pTail;
};

void Init(Stack &s){
	s.pHead=NULL;
	s.pTail=NULL;
}

node *addNode(int x){
	node *p=new node;
	p->info=x;
	p->pNext=NULL;
	return p; 
}

void Push(Stack &s, int x){
    node *p = addNode(x);
    if (s.pHead == NULL) {
        s.pHead = s.pTail = p;
    } else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

void DecimaltoBinary1(int n,Stack &S){
	if (n==0&&S.pHead==NULL) {
		Push(S,0);
		return;
	}
	if (n==0) return ;
	Push(S,n%2);
	DecimaltoBinary1(n/2,S);
}

void printStack(Stack &l){
    node *p = l.pHead;
    
        while (p != NULL){
            cout << p->info;
            p = p->pNext;
        }
    
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

