#include <stdio.h>
#include <stdbool.h>

bool sont(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int m, n, sum = 0;
    printf("Nhap m va n (m < n): ");
    scanf("%d %d", &m, &n);
    if(m>n) printf("Nhap sai");
    else {
		for (int i = m; i <= n; i++) {
	        if (sont(i)) {
	            sum += i;
	        }
	    }
	    printf("Tong cua cac so nguyen to tu %d den %d la: %d\n", m, n, sum);
}
    return 0;
}
