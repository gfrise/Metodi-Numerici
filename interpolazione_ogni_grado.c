#include<stdio.h>

int main(){
    int i, j, n = 10;
    double h = 0.5, z = 1.03, r, coeff, yx, err;
    double x[n], y[n], diff[n];

    // Initialize x and y values
    for (i = 0; i < n; i++) {
        x[i] = i * h;
        y[i] = exp(x[i]);
    }

    // Find the index j and ratio r
    j = (int)((z - x[0]) / h);
    r = (z - x[j]) / h;

    if (j >= 0 && j < n) {
        // Determine the highest polynomial degree achievable
        int max_degree = (n - j - 1 > j) ? j : n - j - 1;
        printf("Maximum achievable polynomial degree: %d\n", max_degree);

        // Loop over all possible polynomial degrees
        for (int m = 1; m <= max_degree; m++) {
            // Initialize differences
            for (i = 0; i < m; i++) {
                diff[i] = y[j + 1 + i] - y[j + i];
            }

            coeff = r;
            yx = y[j] + coeff * diff[0];
            err = fabs(coeff * diff[0]);

            for (i = 2; i <= m; i++) {
                coeff *= (r - i + 1) / i;
                for (int k = 0; k < m - i+1; k++) {
                    diff[k] = diff[k + 1] - diff[k];
                }

                yx += coeff * diff[0];
                err = fabs(coeff * diff[0]);
            }

            // Print results for the current degree
            printf("Degree: %d, Result: %f, Error: %f\n", m, yx, err);
        }
    } else {
        printf("Not enough points\n");
    }
}
