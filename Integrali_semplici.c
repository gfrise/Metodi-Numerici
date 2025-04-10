#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x) {
    return x*x*x;
}

double rettangoli(double a, double b, int n) {
    double h = (b - a) / n, s = 0;
    for (int i = 0; i < n; i++) s += f(a + i * h);
    return h * s;
}

double punto_medio(double a, double b, int n) {
    double h = (b - a) / n, s = 0;
    for (int i = 0; i < n; i++) s += f(a + (i + 0.5) * h);
    return h * s;
}

double trapezi(double a, double b, int n) {
    double h = (b - a) / n, s = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++){
        s += f(a + i * h);
    }
    return h*s;
}

double montecarlo(double a, double b, int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        double x = a + (b - a) * ((double)rand() / RAND_MAX);
        s += f(x);
    }
    return (b - a) * s / n;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 100000;
    srand(time(NULL));

    printf("Rettangoli:   %.8f\n", rettangoli(a, b, n));
    printf("Punto medio:  %.8f\n", punto_medio(a, b, n));
    printf("Trapezi:      %.8f\n", trapezi(a, b, n));
    printf("Monte Carlo:  %.8f\n", montecarlo(a, b, n));
}
