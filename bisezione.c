#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 2;  
}

double bisezione(double a, double b, double tol, int max_iter) {
    double c;
    int iter = 0;

    if (f(a) * f(b) >= 0) {
        printf("Errore: f(a) e f(b) devono avere segni opposti.\n");
        return NAN;
    }

    while (((b - a) / 2.0 > tol) && (iter < max_iter)) {
        c = (a + b) / 2.0;

        if (fabs(f(c)) < tol)
            return c;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iter++;
    }

    if (iter >= max_iter)
        printf("Attenzione: raggiunto massimo numero di iterazioni.\n");

    return (a + b) / 2.0;
}

int main() {
    double a = 0, b = 2, tol = 1e-6;
    int max_iter = 100;

    double zero = bisezione(a, b, tol, max_iter);
    printf("Zero trovato: %.8f\n", zero);
    return 0;
}
