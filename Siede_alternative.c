#include <stdio.h>

int main() {
    int n,max_iter;
    float tol, omega, sum;
    printf("n, tolleranza, max_iter, omega: ");
    scanf("%d %f %d %f", &n, &tol, &max_iter, &omega);
    float A[n][n], b[n], x[n];
    printf("Matrice A e Vettore b:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
        scanf("%f", &b[i]);
        x[i]=0;
    }
    
    // Metodo di Gauss-Seidel
    for (int iter = 0; iter < max_iter; iter++) {
        float norm = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            // Somma solo sui valori già aggiornati di x (Gauss-Seidel)
            for (int j = 0; j < n; j++) {
                if (i != j) sum += A[i][j] * x[j];
            }
            // Aggiorna x[i] come nel metodo di Gauss-Seidel
            x[i] = (b[i] - sum) / A[i][i];
            
            // Calcola la norma per la convergenza durante la stessa iterazione
            norm += (b[i] - A[i][i] * x[i]) * (b[i] - A[i][i] * x[i]);
        }
        if (norm < tol) break; // Se la norma è inferiore alla tolleranza, termina
    }
    
    printf("Soluzione:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }
}
