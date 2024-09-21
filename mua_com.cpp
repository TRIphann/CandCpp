#include <iostream>
using namespace std;

struct Node {
    int stt;
    string loaiCom;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}

Node* createNode(int stt, string loaiCom) {
    Node* newNode = new Node;
    newNode->stt = stt;
    newNode->loaiCom = loaiCom;
    newNode->next = NULL;
    return newNode;
}

void addTail(List &l, int stt, string loaiCom) {
    Node* newNode = createNode(stt, loaiCom);
    if (l.head == NULL) {
        l.head = l.tail = newNode;
    } else {
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

void removeHead(List &l) {
    if (l.head != NULL) {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
        if (l.head == NULL) {
            l.tail = NULL;
        }
    }
}

void printList(List &l) {
    if (l.head == NULL) {
        cout << "Tiem qua e, khong co khach nao" << endl;
    } else {
        Node* p = l.head;
        while (p != NULL) {
            cout << p->stt << " " << p->loaiCom << endl;
            p = p->next;
        }
    }
}

int main() {
    List khachHang;
    CreateList(khachHang);
    int stt = 1;
    
    while (true) {
        int t;
        cin >> t;
        
        if (t == -1) { 
            break;
        } else if (t == 0) {
            string loai;
            cin >> loai;
            addTail(khachHang, stt++, loai);
        } else if (t == 1) { 
            removeHead(khachHang);
        }
    }
    
    printList(khachHang);
    return 0;
}
