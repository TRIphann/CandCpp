/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct node {
	int info;
	node *left, *right;
};

typedef node *Tree;


node* getNode(int x){
	node* p= new node;
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}



void NLR(Tree T){
	if (!T) return; 
	cout <<T->info <<" ";
	NLR(T->left);
	NLR(T->right);
}

void inputTree(Tree &T){
	int n; cin >>n;
	for (int i=0; i<n; i++){
		int a; cin >>a;
		insertTree(T,a);
	}
}

void LRN(Tree T){
	if (!T) return; 
	LRN(T->left);
	LRN(T->right);
	cout <<T->info <<" ";
} 

void LNR(Tree T){
	if (!T) return; 
	LNR(T->left);
	cout <<T->info <<" ";
	LNR(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
