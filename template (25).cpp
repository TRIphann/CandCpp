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
void add_tail(List &l, int x) {
    if (x == 0) return; // Kh�ng th�m s? 0 v�o danh s�ch
    Node *p = new Node; // T?o m?t Node m?i
    p->val = x;         // G�n gi� tr? cho Node
    p->next = NULL;     // N�t cu?i c�ng tr? t?i NULL

    if (l.head == NULL) {
        l.head = l.tail = p; // N?u danh s�ch r?ng, g�n c? head v� tail l� Node m?i
    } else {
        l.tail->next = p; // N?i n�t m?i v�o cu?i danh s�ch
        l.tail = p;       // C?p nh?t l?i tail
    }
}

void copy(List &l1, List &l2) {
    l2.head = l1.head;  // Tr? head c?a l2 �?n head c?a l1
    l2.tail = l1.tail;  // Tr? tail c?a l2 �?n tail c?a l1
    
    // Bi?n �?i gi� tr? trong danh s�ch l2 m� kh�ng thay �?i �?a ch?
    Node* p = l2.head;
    while (p != NULL) {
        p->val += 1; // Thay �?i gi� tr? m?i n�t, v� d?: t�ng gi� tr? l�n 1
        p = p->next;
    }
}


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
