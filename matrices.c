#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int leggi_matrice(FILE *file, int matrice[MAX_SIZE][MAX_SIZE], int *n, int *m) {
    fscanf(file, "%d %d", n, m);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(file, "%d", &matrice[i][j]);
        }
    }
    return 1;
}

int prodotto_matrici(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                     int C[MAX_SIZE][MAX_SIZE], int n, int m, int p) {
    if (m != p) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 1;
}

int è_simmetrica(int matrice[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrice[i][j] != matrice[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

void scrivi_risultato(FILE *file, int matrice[MAX_SIZE][MAX_SIZE], int n, int m, int simmetrica) {
    fprintf(file, "Matrice risultante:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrice[i][j]);
        }
        fprintf(file, "\n");
    }
    if (simmetrica) {
        fprintf(file, "La matrice risultante è simmetrica.\n");
    } else {
        fprintf(file, "La matrice risultante non è simmetrica.\n");
    }
}

int main() {
    FILE *file_in1, *file_in2, *file_out;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int n1, m1, n2, m2;

    file_in1 = fopen("matrice1.txt", "r");
    if (file_in1 == NULL) {
        printf("Errore nell'aprire il file 'matrice1.txt'.\n");
        return 1;
    }

    if (!leggi_matrice(file_in1, A, &n1, &m1)) {
        fclose(file_in1);
        return 1;
    }
    fclose(file_in1);

    file_in2 = fopen("matrice2.txt", "r");
    if (file_in2 == NULL) {
        printf("Errore nell'aprire il file 'matrice2.txt'.\n");
        return 1;
    }

    if (!leggi_matrice(file_in2, B, &n2, &m2)) {
        fclose(file_in2);
        return 1;
    }
    fclose(file_in2);

    if (m1 != n2) {
        printf("Le matrici non possono essere moltiplicate (m1 != n2).\n");
        return 1;
    }

    if (!prodotto_matrici(A, B, C, n1, m1, m2)) {
        return 1;
    }

    int simmetrica = è_simmetrica(C, n1);

    file_out = fopen("risultato.txt", "w");
    if (file_out == NULL) {
        printf("Errore nell'aprire il file 'risultato.txt'.\n");
        return 1;
    }

    scrivi_risultato(file_out, C, n1, m2, simmetrica);

    fclose(file_out);

    printf("Il risultato è stato scritto in 'risultato.txt'.\n");

    return 0;
}
