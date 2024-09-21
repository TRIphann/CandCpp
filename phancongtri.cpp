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

typedef struct Node {
    Acc data;
    struct Node* pNext;
} Node;

typedef struct {
    Node* pHead;
    Node* pTail;
} List;

void Init(List* l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

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

void addnode(List *l, Node *p) {
    if (l->pHead == NULL)
        l->pHead = l->pTail = p;
    else {
        l->pTail->pNext = p;
        l->pTail = p;
    }
}

Node* creatnode(Acc x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->pNext = NULL;
    return p;
}

void inputNew(char *a, char *b) {
    int n = 0;
    char c[50];
    printf("Nhap thong tin voi dieu kien sau: Ten dang nhap phai co it nhat 5 ky tu. Mat khau phai co it nhat 8 ky tu va chua it nhat mot chu cai viet hoa, mot chu cai viet thuong va mot chu so. Nguoi dung phai nhap lai mat khau de xac nhan. Gioi han so lan thu dang nhap la 3 lan.\n");
    printf("Enter account: ");
    scanf("%s", a);
    printf("Enter password: ");
    scanf("%s", b);
    printf("Enter password again: ");
    scanf("%s", c);

    size_t length1 = strlen(a);
    size_t length2 = strlen(b);

    while (n < 2) {
        if (length1 < 5 || length2 < 8 || !capital(b) || !lowercase(b) || !digit(b) || strcmp(b, c) != 0) {
            printf("Nhap lai:\n");
            printf("Enter account: ");
            scanf("%s", a);
            printf("Enter password: ");
            scanf("%s", b);
            printf("Enter password again: ");
            scanf("%s", c);
            n++;
        } else
            n = 4;
    }
    if (n == 3)
        printf("Ban da nhap qua 3 lan, ban khong duoc nhap nua. ");
}

void thongtin(Acc &a, FILE *f1) {
    fscanf(f1, "%d\n", &a.stt);
    fgets(a.account, sizeof(a.account), f1);
    fgets(a.password, sizeof(a.password), f1);
    a.password[strcspn(a.password, "\n")] = '\0';
}

void nhapthongtin(List *l, int n, FILE *f1) {
    Acc a;
    for (int i = 0; i < n; i++) {
        thongtin(a, f1);
        Node* b = creatnode(a);
        addnode(l, b);
    }
}

void printList(List *l) {
    Node* current = l->pHead;
    while (current != NULL) {
        printf("STT: %d\n", current->data.stt);
        printf("Account: %s\n", current->data.account);
        printf("Password: %s\n\n", current->data.password);
        current = current->pNext;
    }
}

bool comparePassword(List *l, char *password) {
    Node* current = l->pHead;
    while (current != NULL) {
        if (strcmp(current->data.password, password) == 0) {
            return true; 
        }
        current = current->pNext;
    }
    return false; 
}

int main() {
    List l;
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
    nhapthongtin(&l, n, f1);
    fclose(f1);
    inputNew(acc,pass);
    if (comparePassword(&l, pass)) {
        printf("Mat khau da ton tai trong danh sach.\n");
    } else {
        printf("Mat khau khong ton tai trong danh sach.\n");
    }

    return 0;
}

