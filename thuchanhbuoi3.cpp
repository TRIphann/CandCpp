#include<stdio.h>
#include<string>

struct Menu {
	char name[50];
	int price; 
};

struct Order {
	Menu dish;
	int quantity;
}; 

struct Node{
	Menu data;
	Node *pNext;
};

struct List{
	Node *pHead, *pTail;
};
void Init(List &l)
{
	l.pHead= NULL;
	l.pTail= NULL;
}
Node *creatnode(Menu x)
{
	Node *p=new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addnode(List &l, Node *p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

int main (){
	List menuList;
    Init(menuList);

    Menu items[5] = {
        {"Pasta", 150},
        {"Pizza", 200},
        {"Burger", 100},
        {"Salad", 50},
        {"Soup", 70}
    };

    for (int i = 0; i < 5; i++) {
        Node *pNode = createnode(items[i]);
        addnode(menuList, pNode);
    }

    printf("Danh sach thuc don cua nha hang:\n");
    printMenu(menuList);

	printf("Danh sach thuc don cua nha hang");
	
} 
