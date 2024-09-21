#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for date
struct time {
    int day;
    int month;
    float year;
};

// Struct for employee
struct diemdanh {
    int stt;
    char ten[50];
    char gioi_tinh[50];
    time ngay_sinh;
    char chuc_vu[50];
    char bo_phan[50];
    char sdt[50];
    time ngay_vaoct;
    time ngay_ract;
};

typedef struct diemdanh dd;

// Node structure for linked list
struct Node {
    dd data;
    Node *pNext;
};

// List structure with head and tail
struct List {
    Node *pHead, *pTail;
};

// Function to initialize the list
void Init(List &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// Function to create a new node
Node *creatnode(dd x) {
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Function to add a node to the list
void addnode(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Function to remove the newline character from a string
void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to input date
void nhaptime(time &a, FILE *f1) {
    fscanf(f1, "%d", &a.day);
    fscanf(f1, "%d", &a.month);
    fscanf(f1, "%f\n", &a.year);
}

// Function to input employee information
void thongtin(dd &a, FILE *f1) {
    fscanf(f1, "%d\n", &a.stt);
    fgets(a.ten, sizeof(a.ten), f1);
    remove_newline(a.ten);
    fgets(a.gioi_tinh, sizeof(a.gioi_tinh), f1);
    remove_newline(a.gioi_tinh);
    nhaptime(a.ngay_sinh, f1);
    fgets(a.chuc_vu, sizeof(a.chuc_vu), f1);
    remove_newline(a.chuc_vu);
    fgets(a.bo_phan, sizeof(a.bo_phan), f1);
    remove_newline(a.bo_phan);
    fscanf(f1, "%s\n", a.sdt);
    nhaptime(a.ngay_vaoct, f1);
    nhaptime(a.ngay_ract, f1);
}

// Function to input a list of employees
void nhapthongtin(List &l, int n, FILE *f1) {
    dd a;
    for (int i = 0; i < n; i++) {
        thongtin(a, f1);
        Node *b = creatnode(a);
        addnode(l, b);
    }
}

// Function to output a single employee's information
void xuat1(dd a, FILE *f2) {
    remove_newline(a.ten);
    remove_newline(a.gioi_tinh);
    remove_newline(a.chuc_vu);
    remove_newline(a.bo_phan);
    remove_newline(a.sdt);
    fprintf(f2, "%d  %s\t\t %s  \t    %d %d %.0f\t\t %s    \t\t%s\t\t%s\t\t   %d %d %.0f\t\t\t   %d %d %.0f", a.stt, a.ten, a.gioi_tinh, a.ngay_sinh.day, a.ngay_sinh.month, a.ngay_sinh.year, a.chuc_vu, a.bo_phan, a.sdt, a.ngay_vaoct.day, a.ngay_vaoct.month, a.ngay_vaoct.year, a.ngay_ract.day, a.ngay_ract.month, a.ngay_ract.year);
    fprintf(f2, "\n\n\n");
}

// Function to output the entire list of employees
void xuat(List l, FILE *f2) {
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        xuat1(k->data, f2);
    }
}

// Function to count and output gender distribution
void demgioitinh(List l, FILE *f2) {
    int nam = 0;
    int nu = 0;
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        if (strcmp(k->data.gioi_tinh, "nu") == 0) nu++;
        else if (strcmp(k->data.gioi_tinh, "nam") == 0) nam++;
    }
    fprintf(f2, "Nam: %d,   Nu: %d", nam, nu);
}

// Function to compare dates
int sstime(time a, time b) {
    if (a.year > b.year) return 1;
    else if (a.year < b.year) return -1;
    else {
        if (a.month > b.month) return 1;
        else if (a.month < b.month) return -1;
        else {
            if (a.day > b.day) return 1;
            else if (a.day < b.day) return -1;
            else return 0;
        }
    }
}

// Function to count distinct departments
int dembophan(int n, Node* a) {
    int c = 0;
    Node* current = a;
    Node* b[100];
    while (current != NULL) {
        int dem = 0;
        for (int j = 0; j < c; j++) {
            if (strcmp(current->data.bo_phan, b[j]->data.bo_phan) == 0) {
                dem++;
                break;
            }
        }
        if (dem == 0) {
            b[c] = current;
            c++;
        }
        current = current->pNext;
    }
    return c;
}

// Function to manage and output department heads and staff counts
void quanly(List l, FILE *f2) {
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        int dem = 0;
        if (strcmp(k->data.chuc_vu, "Quan ly") == 0) {
            fprintf(f2, "%s %s bo phan %s", k->data.ten, k->data.chuc_vu, k->data.bo_phan);
            for (Node* j = l.pHead; j != NULL; j = j->pNext) {
                if (strcmp(k->data.bo_phan, j->data.bo_phan) == 0) {
                    dem++;
                }
            }
            fprintf(f2, " So nhan su: %d\n\n", dem);
        }
    }
}

// Function to output general information
void thongtinchung(List l, int n, FILE *f2) {
    int dem = 0;
    fprintf(f2, "GIOI TINH: \n");
    demgioitinh(l, f2);
    fprintf(f2, "\n\n");

    fprintf(f2, "TUOI: \n");
    int tong = 0;
    float tbc = 0;
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        tong = tong + (2024 - k->data.ngay_sinh.year);
    }
    tbc = (float) tong / n;
    fprintf(f2, "Trung binh: %.2f\nNguoi lon tuoi nhat: ", tbc);
    time maxa = l.pHead->data.ngay_sinh;
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        if (sstime((k->data.ngay_sinh), maxa) < 0) {
            maxa = k->data.ngay_sinh;
        }
    }
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        if ((maxa.day == k->data.ngay_sinh.day) && (maxa.month == k->data.ngay_sinh.month) && (maxa.year == k->data.ngay_sinh.year)) {
            fprintf(f2, "%s", k->data.ten);
            for (Node *j = k->pNext; j != NULL; j = j->pNext) {
                if ((maxa.day == j->data.ngay_sinh.day) && (maxa.month == j->data.ngay_sinh.month) && (maxa.year == j->data.ngay_sinh.year)) {
                    fprintf(f2, ", %s", j->data.ten);
                }
            }
            fprintf(f2, ": %.0f\n", (2024 - maxa.year));
            break;
        }
    }
    fprintf(f2, "Nguoi nho tuoi nhat: ");
    time min = l.pHead->data.ngay_sinh;
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        if (sstime((k->data.ngay_sinh), min) > 0) {
            min = k->data.ngay_sinh;
        }
    }
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        if ((min.day == k->data.ngay_sinh.day) && (min.month == k->data.ngay_sinh.month) && (min.year == k->data.ngay_sinh.year)) {
            fprintf(f2, "%s", k->data.ten);
            for (Node *j = k->pNext; j != NULL; j = j->pNext) {
                if ((min.day == j->data.ngay_sinh.day) && (min.month == j->data.ngay_sinh.month) && (min.year == j->data.ngay_sinh.year)) {
                    fprintf(f2, ", %s", j->data.ten);
                }
            }
            fprintf(f2, ": %.0f\n", (2024 - min.year));
            break;
        }
    }
    fprintf(f2, "\n\n");
    fprintf(f2, "BO PHAN: %d\n\n", dembophan(n, l.pHead));
    fprintf(f2, "Quan ly cua cac bo phan: \n\n");
    quanly(l, f2);
}

// Function to handle the menu options
void menu(List &l) {
    int choice;
    FILE *f1 = fopen("input.txt", "r");
    FILE *f2 = fopen("output.txt", "w");

    if (f1 == NULL) {
        printf("Cannot open input file.\n");
        return;
    }
    if (f2 == NULL) {
        printf("Cannot open output file.\n");
        return;
    }

    fscanf(f1, "%d\n", &choice);

    while (true) {
        printf("Choose an option:\n");
        printf("1. Input information\n");
        printf("2. Output information\n");
        printf("3. Output gender distribution\n");
        printf("4. Output department and staff\n");
        printf("5. Output general information\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int n;
                fscanf(f1, "%d\n", &n);
                nhapthongtin(l, n, f1);
                break;
            case 2:
                xuat(l, f2);
                break;
            case 3:
                demgioitinh(l, f2);
                break;
            case 4:
                quanly(l, f2);
                break;
            case 5:
                int m;
                fscanf(f1, "%d\n", &m);
                thongtinchung(l, m, f2);
                break;
            case 0:
                fclose(f1);
                fclose(f2);
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main function
int main() {
    List l;
    Init(l);
    menu(l);
    return 0;
}

