#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void bubble_sort_int(int *arr, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--) 
            if (arr[j-1] > arr[j]) {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
}

void bubble_sort_double(double *arr, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--) 
            if (arr[j-1] > arr[j]) {
                double tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
}

double dev_std_sample(double *arr, int n) {
    double sum = 0, mean = 0;
    for (int i = 0; i < n; i++) mean += arr[i];
    mean /= n;
    for (int i = 0; i < n; i++) sum += (arr[i] - mean) * (arr[i] - mean);
    return sqrt(sum / (n - 1));
}

double dev_std_population(double *arr, int n) {
    double sum = 0, mean = 0;
    for (int i = 0; i < n; i++) mean += arr[i];
    mean /= n;
    for (int i = 0; i < n; i++) sum += (arr[i] - mean) * (arr[i] - mean);
    return sqrt(sum / n);
}

double dev_std_sample_int(int *arr, int n) {
    double sum = 0, mean = 0;
    for (int i = 0; i < n; i++) mean += arr[i];
    mean /= n;
    for (int i = 0; i < n; i++) sum += (arr[i] - mean) * (arr[i] - mean);
    return sqrt(sum / (n - 1));
}

double dev_std_population_int(int *arr, int n) {
    double sum = 0, mean = 0;
    for (int i = 0; i < n; i++) mean += arr[i];
    mean /= n;
    for (int i = 0; i < n; i++) sum += (arr[i] - mean) * (arr[i] - mean);
    return sqrt(sum / n);
}

void shuffle_int(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % (n - i); // Genera un numero casuale nel range da 0 a n-i-1
        int temp = arr[i];
        arr[i] = arr[i + r]; // Scambia l'elemento i con l'elemento i+r
        arr[i + r] = temp;    // Scambia l'elemento i+r con il valore temporaneo
    }
}

void shuffle_double(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % (n - i); // Genera un numero casuale nel range da 0 a n-i-1
        double temp = arr[i];
        arr[i] = arr[i + r]; // Scambia l'elemento i con l'elemento i+r
        arr[i + r] = temp;    // Scambia l'elemento i+r con il valore temporaneo
    }
}

int main() {
    int n = 20;
    int min_int = 10, max_int = 50;
    double min_d = 0.0, max_d = 5.0;

    int v_int[n];
    double v_double[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        v_int[i] = rand() % (max_int - min_int + 1) + min_int;
        v_double[i] = ((double)rand() / RAND_MAX) * (max_d - min_d) + min_d;
    }

    shuffle_int(v_int, n);
    shuffle_double(v_double, n);

    bubble_sort_int(v_int, n);
    bubble_sort_double(v_double, n);

    double ds_sample_int = dev_std_sample_int(v_int, n);
    double ds_pop_int = dev_std_population_int(v_int, n);
    double ds_sample_dbl = dev_std_sample(v_double, n);
    double ds_pop_dbl = dev_std_population(v_double, n);

    FILE *f = fopen("output.txt", "w");
    if (!f) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    fprintf(f, "Vettore Interi Ordinato:\n");
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", v_int[i]);

    fprintf(f, "\nDev. Std Campionaria: %.4f\n", ds_sample_int);
    fprintf(f, "Dev. Std Popolazione: %.4f\n", ds_pop_int);

    fprintf(f, "\nVettore Double Ordinato:\n");
    for (int i = 0; i < n; i++)
        fprintf(f, "%.4f ", v_double[i]);

    fprintf(f, "\nDev. Std Campionaria: %.4f\n", ds_sample_dbl);
    fprintf(f, "Dev. Std Popolazione: %.4f\n", ds_pop_dbl);

    fclose(f);

    printf("Dev. Std Interi (Camp.): %.4f | (Pop.): %.4f\n", ds_sample_int, ds_pop_int);
    printf("Dev. Std Double (Camp.): %.4f | (Pop.): %.4f\n", ds_sample_dbl, ds_pop_dbl);
    printf("Dati salvati in 'output.txt'.\n");

    return 0;
}
