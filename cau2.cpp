#include <stdio.h>

void sapxep(int a[], int n){
	for (int i=0; i<n; i++){
		for (int j=n; j>i; j--){
			if (a[i]<a[j]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
} 

int main(){
	int arr[100],b,k;
	printf("so phan tu cua mang: "); scanf("%d", &b);
	printf("nhap k: "); scanf("%d", &k);
	if (k>b-1) printf ("Loi! So k lon hon so phan tu trong mang");
	else {
		printf("nhap mang: ");
		for (int i=0; i<b; i++){
			scanf("%d", &arr[i]);
		}
		sapxep(arr,b);
		printf("%d", arr[k-1]);
	}
}
