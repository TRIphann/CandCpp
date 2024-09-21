/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}

//###INSERT CODE HERE -

Node *addNode(int n){
    Node *p = new Node;
    p->val = n;
    p->next = NULL;
    return p;
}

void add_tail(List &l, int n){
    Node *p = addNode(n);
    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void addHead(List &l, int x){
	Node *p=addNode(x);
	if (l.head==NULL){
		l.head=l.tail=p;
	}
	else {
		p->next=l.head;
		l.head=p;
	}
}

void add(List &l, int n){
	int a;
	for (int i=0; i<n; i++){
		cin >> a;
		addHead(l,a);
	}
} 

void inputList(List &l, int n){
    int c;
    for (int i = 0; i < n; i++){
        cin >> c;
        add_tail(l, c);
    }
}

void outputList(List &l){
    Node *p = l.head;
    if (l.head == NULL){
        cout << "List is empty";
        return;
    } else {
        while (p != NULL){
            cout << p->val << " ";
            p = p->next;
        }
    }
}

void copy (List l,List &k){
	if (l.head==NULL) return;
	Node *p=l.head;
	while (p!=NULL){
		int x=p->val;
		add_tail(k,x);
		p=p->next;
	}
}

//END your code 

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.head, *q = l2.head;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    return 0;
}
