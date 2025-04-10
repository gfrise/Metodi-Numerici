#include <stdio.h>

void calcola_istogramma(double arr[], int n, double min, double max, int nbin) {
    int count[nbin];  
    double dx = (max - min) / nbin;  

    // Inizializza il vettore di conteggio a zero
    for (int i = 0; i < nbin; i++) {
        count[i] = 0;
    }

    // Conta le occorrenze in ciascun bin
    for (int i = 0; i < n; i++) {
        int j = (int)((arr[i] - min) / dx);  // Calcola l'indice del bin per ogni valore
        if (j >= 0 && j < nbin) {  // Verifica che l'indice del bin sia valido
            count[j]++;  // Incrementa il conteggio del bin corrispondente
        }
    }

    // Stampa l'istogramma
    printf("Istogramma:\n");
    for (int i = 0; i < nbin; i++) {
        printf("Bin %d (%.2f - %.2f): ", i + 1, min + i * dx, min + (i + 1) * dx);
        for (int j = 0; j < count[i]; j++) {
            printf("*");
        }
        printf(" (%d occorrenze)\n", count[i]);
    }
}

int main() {
    double arr[] = {1.1, 2.3, 3.5, 4.6, 1.7, 2.9, 3.1, 4.2, 4.9};
    int n = sizeof(arr) / sizeof(arr[0]);
    double min = 1.0;
    double max = 5.0;
    int nbin = 5;

    calcola_istogramma(arr, n, min, max, nbin);

    return 0;
}
