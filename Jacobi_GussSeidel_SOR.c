#include <stdio.h>
#include <math.h>
int main(){
    int n, max_iter, i, j, iter, method;
    double tol, omega = 1.0;
    scanf("%d", &n);
    double A[n][n], b[n], x[n], x_old[n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) scanf("%lf", &A[i][j]);
        scanf("%lf", &b[i]);
        x[i] = 0.0;
    }
    scanf("%lf %d %d", &tol, &max_iter, &method);
    if(method == 2) scanf("%lf", &omega);
    for(iter = 0; iter < max_iter; iter++){
        if(method == 0) for(i = 0; i < n; i++) x_old[i] = x[i];
        for(i = 0; i < n; i++){
            double sum = 0;
            for(j = 0; j < n; j++) if(i != j) sum += A[i][j] * (method == 0 ? x_old[j] : x[j]);
            double newx = (b[i] - sum) / A[i][i];
            if(method == 2) newx = (1 - omega) * x[i] + omega * newx;
            x[i] = newx;
        }
        double rnorm = 0;
        for(i = 0; i < n; i++){
            double r = b[i];
            for(j = 0; j < n; j++) r -= A[i][j] * x[j];
            rnorm += r * r;
        }
        if(rnorm < tol * tol) break;
    }
    for(i = 0; i < n; i++) printf("x[%d] = %lf\n", i, x[i]);
    return 0;
}
