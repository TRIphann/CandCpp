#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu {
    int number;
    char name[50];
    int price; 
};

struct Order {
    int stt;
    int quantity;
}; 

struct Table {
    int id;
    bool state;
    Order order[100];
    int orderCount;
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
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* createnode(Menu x)
{
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void addnode(List &l, Node *p)
{
    if (l.pHead == NULL) l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printMenu(List l) {
	printf("+-----------------------+\n");
	printf("+STT |Ten mon an|So tien+\n");
	printf("+-----------------------+\n");
    Node *p = l.pHead;
    while (p != NULL) {
        printf("+%d   |%s	|$%d	+\n", p->data.number, p->data.name, p->data.price);
        p = p->pNext;
    }
    printf("+-----------------------+\n");
}

void printTable(Table a[], int n){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
        	if (!a[j].state) {
        		printf("\033[31m");
	            if (i == 0 || i == 2) {
	                printf("+-------------+");
	                printf("        ");
	            }
	            if (i == 1) {
	                printf("+    Ban %d    +", a[j].id);
	                printf("        ");
	            }
	            printf("\033[0m");
	        }
	        else {
	        	if (i == 0 || i == 2) {
	                printf("+-------------+"); 
	                printf("        ");
	            }
	            if (i == 1) {
	                printf("+    Ban %d    +", a[j].id);
	                printf("        ");
	            }
			}
        }
        printf("\n");
    }
}

void inputOrder(Table &table, List menuList) {
    int start = 1, ask;
    while (start == 1) {
        Order newOrder;
        printf("Nhap so thu tu mon an: ");
        scanf("%d", &newOrder.stt);
        if (newOrder.stt < 1 || newOrder.stt > 5) {
            printf("Khong co trong Menu\n");
            continue;
        }
        printf("Nhap so luong mon an: ");
        scanf("%d", &newOrder.quantity);
        table.order[table.orderCount++] = newOrder;

        printf("Ban co muon order nua khong, 1 la co, 0 la khong: ");
        scanf("%d", &ask);
        if (!ask) start = 0;
        printf("\n");
    }
}

void bill(Table &table, List menuList) {
	int sum;
	printf("\n");
	printf("hoa don cua ban la:\n");
	printf("+-------------------------------+\n");
	printf("+So sp  |Ten mon an     |So tien+\n");
	printf("+-------------------------------+\n");
	for (int i = 0; i < table.orderCount; i++) {
        int stt = table.order[i].stt;
        Node *p = menuList.pHead;
        while (p != NULL) {
            if (p->data.number == stt) {
                printf("+%d	|%s		|$%d	+\n", table.order[i].quantity, p->data.name, p->data.price * table.order[i].quantity);
                sum=sum+(p->data.price * table.order[i].quantity);
                break;
            }
            p = p->pNext;
        }
    }
    printf("+-------------------------------+\n");
    printf("\nTong tien la: %d", sum);
}

int main() {
    List menuList;
    Init(menuList);

    Table dinner[5] = {
        {1, false, {}, 0},
        {2, false, {}, 0},
        {3, true, {}, 0},
        {4, false, {}, 0},
        {5, false, {}, 0}
    };

    int chooseTable;

    printf("Chon ban ban muon ngoi(1-5)\n");
    printTable(dinner, 5);
    scanf("%d", &chooseTable);

    while (chooseTable < 1 || chooseTable > 5 || !dinner[chooseTable - 1].state) {
    	
        printf("Chon lai ban ban muon ngoi (1-5): ");
        scanf("%d", &chooseTable);
        printf("\n");
    }

    Menu items[5] = {
        {1, "Pasta", 150},
        {2, "Pizza", 200},
        {3, "Burger", 100},
        {4, "Salad", 50},
        {5, "Soup", 70}
    };

    for (int i = 0; i < 5; i++) {
        Node *pNode = createnode(items[i]);
        addnode(menuList, pNode);
    }

    printf("Danh sach thuc don cua nha hang:\n");
    printMenu(menuList);
    printf("\n");

    inputOrder(dinner[chooseTable - 1], menuList);

    bill(dinner[chooseTable - 1], menuList);
}

