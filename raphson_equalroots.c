#include<stdio.h>

#include <stdio.h>
#include <math.h>

double f(double x) { /*...*/ }

double f1(double x) { /*...*/ }

double f2(double x) { /*...*/ }

double root(double x, double eps, double tol) {
    double y = x + eps;
    int k = 0;
    do {
        y -= f(y) / f1(y);
        k++;
    } while (fabs(f(y) / f1(y)) > tol);
    printf("Root: %f, Iterations: %d\n", y, k);
    return y;
}

int main() {
    double x = 1.5, tol = 1.e-4, y = x;
    int i = 0;

    do {
        y -= f1(y) / f2(y);
        i++;
    } while (fabs(f1(y) / f2(y)) > tol);

    double eps = sqrt(-2 * f(y) / f2(y));

    root(x, -eps, tol);
    root(x, eps, tol);
}
