#include<stdio.h> 

void NhapMaTran(int a[][100], int m, int n)
{
   for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
      {
         printf("A[%d][%d] = ", i, j);
         scanf("%d", &a[i][j]);
      }
}
}
