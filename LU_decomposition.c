#include<stdio.h>

void luDecomposition(double A[MAX][MAX], double L[MAX][MAX], double U[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Costruzione di U e calcolo dei valori diagonali di L
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // Costruzione di L
        for (int k = i; k < n; k++) {
            if (i == k) 
                L[i][i] = 1; // Elementi diagonali di L sono 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

void forwardSubstitution(double L[MAX][MAX], double b[MAX], double y[MAX], int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }
}

void backwardSubstitution(double U[MAX][MAX], double y[MAX], double x[MAX], int n) {
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
}

int main() {
    int n;
    double A[MAX][MAX], L[MAX][MAX] = {0}, U[MAX][MAX] = {0};
    double b[MAX], y[MAX], x[MAX];

    printf("Inserisci la dimensione della matrice: "); // Input dimensione della matrice
    scanf("%d", &n);
    
    printf("Inserisci la matrice A (%dx%d):\n", n, n); // Input matrice A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Inserisci il vettore b (%d elementi):\n", n); // Input vettore b
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    luDecomposition(A, L, U, n); // Decomposizione LU

    printf("\nMatrice L:\n"); // Output di L e U
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.2lf ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrice U:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.2lf ", U[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    forwardSubstitution(L, b, y, n); // Risoluzione tramite forward e backward substitution
    backwardSubstitution(U, y, x, n);

    printf("Soluzione del sistema:\n");
    for (int i = 0; i < n; i++) {
        printf("X%d = %.6lf\n", i + 1, x[i]);
    }

    return 0;
}
