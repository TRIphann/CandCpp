#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SanPham {
    char TenSP[50];
    int NamSX;
    float Gia;
    struct SanPham* next;
};


struct SanPham* nhap_danh_sach(int n) {
    struct SanPham* danh_sach = NULL;
    for (int i = 0; i < n; i++) {
        struct SanPham* new_san_pham = (struct SanPham*)malloc(sizeof(struct SanPham));
        printf("Nhap tên san pham: ");
        scanf("%s", new_san_pham->TenSP);
        printf("Nhap nam san xuat: ");
        scanf("%d", &new_san_pham->NamSX);
        printf("Nhap gia ban: ");
        scanf("%f", &new_san_pham->Gia);
        new_san_pham->next = danh_sach;
        danh_sach = new_san_pham;
    }
    return danh_sach;
}


void xuat_danh_sach(struct SanPham* danh_sach) {
    struct SanPham* current = danh_sach;
    while (current != NULL) {
        printf("Tên san pham: %s\n", current->TenSP);
        printf("Nãm san xuat: %d\n", current->NamSX);
        printf("Giá bán: %.2f\n", current->Gia);
        printf("--------------------\n");
        current = current->next;
    }
}


void sap_xep_theo_ten(struct SanPham* danh_sach) {

    struct SanPham *current, *index;
    char tempTenSP[50];
    int tempNamSX;
    float tempGia;

    for (current = danh_sach; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (strcmp(current->TenSP, index->TenSP) > 0) {
                strcpy(tempTenSP, current->TenSP);
                strcpy(current->TenSP, index->TenSP);
                strcpy(index->TenSP, tempTenSP);

                tempNamSX = current->NamSX;
                current->NamSX = index->NamSX;
                index->NamSX = tempNamSX;

                tempGia = current->Gia;
                current->Gia = index->Gia;
                index->Gia = tempGia;
            }
        }
    }
}

// Hàm ð? t?m ki?m s?n ph?m theo tên
void tim_kiem(struct SanPham* danh_sach, char* ten_sp) {
    struct SanPham* current = danh_sach;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->TenSP, ten_sp) == 0) {
            printf("Tên san pham: %s\n", current->TenSP);
            printf("Nãm san xuat: %d\n", current->NamSX);
            printf("Giá bán: %.2f\n", current->Gia);
            printf("--------------------\n");
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Không tim thay san pham có tên %s\n", ten_sp);
    }
}

int main() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);

    struct SanPham* danh_sach = nhap_danh_sach(n);

    printf("\nDanh sách san pham vua nhap:\n");
    xuat_danh_sach(danh_sach);

    sap_xep_theo_ten(danh_sach);
    printf("\nDanh sách san pham sau khi sap xep theo tên:\n");
    xuat_danh_sach(danh_sach);

    char ten_sp[50];
    printf("\nNhap tên san pham can tim kiem: ");
    scanf("%s", ten_sp);
    printf("\nKet qua tim kiem:\n");
    tim_kiem(danh_sach, ten_sp);

    return 0;
}

