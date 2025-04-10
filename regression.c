#include <stdio.h>
#include <stdlib.h>

void linear_regression(double *x, double *y, int n, double *m, double *b) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    *b = (sum_y - *m * sum_x) / n;
}

int main() {
    int n = 5; 
    double x[] = {1, 2, 3, 4, 5}; 
    double y[] = {2, 4, 5, 4, 5}; 

    double m, b; 
    linear_regression(x, y, n, &m, &b);

    printf("Equazione della retta di regressione: y = %.2fx + %.2f\n", m, b);

    for (int i = 0; i < n; i++) {
        double y_pred = m * x[i] + b;
        printf("Punto (%f, %f) -> Predetto: %f\n", x[i], y[i], y_pred);
    }

    return 0;
}
