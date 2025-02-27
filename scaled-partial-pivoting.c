#include<stdio.h>

int main(){
int n,i,j,k,maxRow;
double maxVal,scale,inv,temp;

printf("Inserire il numero di variabili (n): \n");
scanf("%d",&n);

double A[n][n+1],X[n];

printf("Inserire i coefficienti della matrice aumentata (A):\n");
for (i=0;i<n;i++) {
    for (j=0;j<=n;j++) {
        scanf("%lf",&A[i][j]);
    }
}

// Normalizzazione di ogni riga
for (i=0;i<n;i++){
    double maxCol = fabs(A[i][i]);
    for (j=0;j<n;j++){
        if (fabs(A[i][j]) > maxCol) {
            maxCol = fabs(A[i][j]);
        }
    }
    scale = 1.0/maxCol;
    for (j=0;j<=n;j++) {
        A[i][j]*=scale;
    }
}

// Trova la riga pivotale e riordina
for (i = 0; i < n; i++) {
    maxRow = i;
    maxVal = fabs(A[i][i]);
    for (k = i + 1; k < n; k++) {
        if (fabs(A[k][i]) > maxVal) {
            maxRow = k;
            maxVal = fabs(A[k][i]);
        }
    }

    // Scambia le righe se necessario
    if (maxRow != i) {
        for (j = 0; j <= n; j++) {
            temp = A[i][j];
            A[i][j] = A[maxRow][j];
            A[maxRow][j] = temp;
        }
    }

    // Elimina i termini sotto la diagonale
    inv = 1.0 / A[i][i];
    for (k = i + 1; k < n; k++) {
        scale = inv * A[k][i];
        for (j = i; j <= n; j++) {
            A[k][j] -= scale * A[i][j];
        }
    }
}

// Sostituzione all'indietro
for (i = n - 1; i >= 0; i--) {
    X[i] = A[i][n];
    for (j = i + 1; j < n; j++) {
        X[i] -= A[i][j] * X[j];
    }
    X[i] /= A[i][i];
}

printf("Soluzione del sistema:\n");
for (i = 0; i < n; i++) {
    printf("X%d = %.6lf\n", i + 1, X[i]);
}
}