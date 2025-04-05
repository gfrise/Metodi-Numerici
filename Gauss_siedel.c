#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    double e, max_error, error;
    
    scanf("%d %lf", &n, &e);

    double A[n][n], b[n], x[n], x_old[n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%lf", &A[i][j]);
        scanf("%lf", &b[i]);
        x[i] = x_old[i] = 0.0;
    }

    do {
        max_error = 0.0;
        for (i = 0; i < n; i++) {
            double sum = b[i];
            for (j = 0; j < n; j++) if (j != i) sum -= A[i][j] * x[j];
            x[i] = sum / A[i][i];
            error = fabs(x[i] - x_old[i]);
            if (error > max_error) max_error = error;
            x_old[i] = x[i];
        }

        for (i = 0; i < n; i++) printf("%0.4f\t", x[i]);
        printf("\n");
    } while (max_error > e);

    for (i = 0; i < n; i++) printf("x[%d] = %0.3f\n", i + 1, x[i]);
}
