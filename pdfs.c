#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void esponenziale(double *x, int n, double lambda) {
    for (int i = 0; i < n; i++) {
        double u = (double)rand() / RAND_MAX;
        x[i] = -log(1.0 - u) / lambda;
    }
}

void normale_boxmuller(double *x, int n, double mu, double sigma) {
    for (int i = 0; i < n; i++) {
        double u1 = (double)rand() / RAND_MAX;
        double u2 = (double)rand() / RAND_MAX;
        double z = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);
        x[i] = mu + sigma * z;
    }
}

int main() {
    int n = 10;
    double lambda = 1.0;
    double mu = 0.0, sigma = 1.0;
    double x_exp[n], x_norm[n];

    srand(time(NULL));

    esponenziale(x_exp, n, lambda);
    normale_boxmuller(x_norm, n, mu, sigma);

    printf("Distribuzione Esponenziale (lambda = %.1f):\n", lambda);
    for (int i = 0; i < n; i++) {
        printf("%.5f ", x_exp[i]);
    }

    printf("\n\nDistribuzione Normale (mu = %.1f, sigma = %.1f):\n", mu, sigma);
    for (int i = 0; i < n; i++) {
        printf("%.5f ", x_norm[i]);
    }

    printf("\n");
    return 0;
}
