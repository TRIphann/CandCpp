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
    if (x == 0) return; // Không thêm s? 0 vào danh sách
    Node *p = new Node; // T?o m?t Node m?i
    p->val = x;         // Gán giá tr? cho Node
    p->next = NULL;     // Nút cu?i cùng tr? t?i NULL

    if (l.head == NULL) {
        l.head = l.tail = p; // N?u danh sách r?ng, gán c? head và tail là Node m?i
    } else {
        l.tail->next = p; // N?i nút m?i vào cu?i danh sách
        l.tail = p;       // C?p nh?t l?i tail
    }
}

void copy(List &l1, List &l2) {
    l2.head = l1.head;  // Tr? head c?a l2 ð?n head c?a l1
    l2.tail = l1.tail;  // Tr? tail c?a l2 ð?n tail c?a l1
    
    // Bi?n ð?i giá tr? trong danh sách l2 mà không thay ð?i ð?a ch?
    Node* p = l2.head;
    while (p != NULL) {
        p->val += 1; // Thay ð?i giá tr? m?i nút, ví d?: tãng giá tr? lên 1
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
