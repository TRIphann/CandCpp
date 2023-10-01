// Viết chương trình hiển thị ra màn hình số tiền phải trả cho 
//1 cuộc gọi  điện thoại N giây. Biết rằng cước gọi tính theo 
//mỗi block là xđ, và 1  block bằng 6 giây. Các giá trị x, N nhập từ bàn phím.
#include <stdio.h>

int main() {
	float x, N;
	printf ("thoi gian goi dien thoai (s): ");
	scanf ("%f", &N);
	printf ("gia tien moi block :");
	scanf ("%f", &x);
	if (x==0) {
		printf ("so tien phai tra :0");
	}
	else { printf ("so tien phai tra : %.1f ", (N/6)*x);	}
}