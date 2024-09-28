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

void insertTree(Tree &T, int x){
if (T == NULL) {
        T = getNode(x);
    } else {
        if (x < T->info)
            insertTree(T->left, x);
        else if (x > T->info)
            insertTree(T->right, x);
    }
}
void inputTree(Tree &T){
	 int x;
    while (true) {
        cin >> x;
        if (x < 0) break;
        insertTree(T, x);
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
//	cout<<"\nNLR: "; NLR(T);
//	cout<<"\nLRN: "; LRN(T);
//	cout<<"\nLNR: "; LNR(T);

//	cout<<"\nLeaf nodes: "; listLeafs(T);
//	cout<<"\nInternal nodes: "; listInternalNodes(T,0);
//	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
//	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
