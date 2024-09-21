#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int stt;
    char account[50];
    char password[50];
} Acc;

struct Node{
	Acc data;
	Node *pNext;
};

Node *creatnode(Acc x)
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

void Init(List* l) {
    l->head = NULL;
    l->tail = NULL;
}

struct List{
Node *pHead, *pTail;
};

bool capital(const char *str) {
    while (*str) {
        if (isupper(*str)) {
            return true;
        }
        str++;
    }
    return false;
}

bool lowercase(const char *str) {
    while (*str) {
        if (islower(*str)) {
            return true;
        }
        str++;
    }
    return false;
}

bool digit(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return true;
        }
        str++;
    }
    return false;
}

void inputNew(char *a, char *b){
	int n=0;
	char c[50];
	printf("Nhap thong tin voi dieu kien sau: Ten dang nhap phai co it nhat 5 ky tu. Mat khau phai co it nhat 8 ky tu va chua it nhat mot chu cai viet hoa, mot chu cai viet thuong va mot chu so. Nguoi dung phai nhap lai mat khau de xac nhan. Gioi han so lan thu dang nhap la 3 lan.\n");
	printf("Enter account: ");
    scanf("%s", a);
    printf("Enter password: ");
    scanf("%s", b);
    printf("Enter password again: ");
    scanf("%s", &c);
    
    size_t length1 = strlen(a);
    size_t length2 = strlen(b);
    
    while(n<2){
    	if (length1<5 || length2<8 || !capital(b) || !lowercase(b) || !digit(b) || strcmp(b,c)!=0 ){
    		printf("Nhap lai:\n");
    		printf("Enter account: ");
		    scanf("%s", a);
		    printf("Enter password: ");
		    scanf("%s", b);
		    printf("Enter password again: ");
    		scanf("%s", &c);
		    n++;
		}
		else n=4;
	}
	if (n==3) printf("Ban da nhap qua 3 lan, ban khong duoc nhap nua. ");
}

void addToList(List* l, Acc a) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->acc = a;
    newNode->next = NULL;
    if (l->head == NULL) {
        l->head = newNode;
        l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

void printList(List* l) {
    Node* current = l->head;
    while (current != NULL) {
        printf("STT: %d\n", current->acc.stt);
        printf("Account: %s\n", current->acc.account);
        printf("Password: %s\n\n", current->acc.password);
        current = current->next;
    }
}

void thongtin(Acc &a, FILE *f1) {
	fscanf(f1, "%d\n", &a.stt);
	fgets(a.account, sizeof(a.account), f1);
	fgets(a.password, sizeof(a.password), f1);
}

void nhapthongtin(List &l ,int n, FILE *f1){
	Acc a;
	for (int i=0; i<n; i++){
	thongtin(a,f1);
	Node *b= creatnode(a);
	addnode(l,b);
	}
}

int main() {
    List l;
    Acc a;
    int n;
    char acc[50], pass[50];
    FILE *f1;
    f1 = fopen("Mat_khau.txt", "r");
    if (f1 == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    Init(&l);
    fscanf(f1, "%d", &n);
    input(&l, f1);
//    printf("%d\n",n); 
    printList(&l);  
    
    fclose(f1);
    return 0;
}

