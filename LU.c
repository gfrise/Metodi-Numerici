#include <stdio.h>

int main() {
    int n;
    printf("Dimensione matrice: ");
    scanf("%d", &n);

    float A[n][n], L[n][n], U[n][n];

    // Input matrice A e inizializzazione L, U
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
            L[i][j] = U[i][j] = 0;
        }

    // Decomposizione LU
    for(int i=0;i<n;i++){
        L[i][i]=1;
        for(int j=i;j<n;j++){
            float s=0;
            for(int k=0;k<i;k++)s+=L[i][k]*U[k][j];
            U[i][j]=A[i][j]-s;
            if(j>i){
                s=0;
                for(int k=0;k<i;k++)s+=L[j][k]*U[k][i];
                L[j][i]=(A[j][i]-s)/U[i][i];
            }
        }
    }

    printf("\nL:\n");
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < n; j++)
            printf("%6.2f ", L[i][j]);
    printf("\nU:\n");
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < n; j++)
            printf("%6.2f ", U[i][j]);
}
