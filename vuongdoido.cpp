#include<stdio.h>

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		if (i==0){
			printf("*");
		}
		else if (i==1){
			printf("**");
		}
		else if (i==(n-1)){
			for (int j=0; j<n; j++) printf("*");
			break;
		}
		else {
			for (int z=0; z<i+1; z++){
				if (z==0 || z==(i)){
					printf("*");
				}
				else printf(" ");
			}
		}
		printf("\n");
	}

}
