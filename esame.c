#include <stdio.h>
#include <math.h>
#define NMAX 1000

double f(double t, double u) {
    return sin(log(1.26 * t) + u);
}

double taylor(double t, double u, double h) {
    return u + h * f(t, u);
}

void start(double t[], double u[], double h) {
    t[1] = t[0] + h;
    u[1] = taylor(t[0], u[0], h);
    printf("t0 = %.6lf, u0 = %.6lf\n", t[0], u[0]);
    printf("t1 = %.6lf, u1 = %.6lf\n", t[1], u[1]);
}

void ab(double t0, double u0, double tf, double eps, double h) {
    int n = (int)((tf - t0) / h) + 1;
    double t[NMAX], u[NMAX];
    
    t[0] = t0;
    u[0] = u0;
    start(t, u, h);
    
    for (int i = 1; i < n - 1; i++) {
        t[i+1] = t[i] + h;
        double up = u[i] + (h / 2.0) * (3 * f(t[i], u[i]) - f(t[i-1], u[i-1]));
        double temp;
        do {
            temp = up;
            up = u[i] + (h / 2.0) * (f(t[i+1], temp) + f(t[i], u[i]));
        } while (fabs(up - temp) > eps);
        
        u[i+1] = up;
        printf("t%d = %.6lf, u%d = %.6lf\n", i+1, t[i+1], i+1, u[i+1]);
    }
}

int main(){
    double t0 = 1.0, tf = 10.0, u0 = 0.0;
    double h = 0.1, eps = 1e-6;
    ab(t0, u0, tf, eps, h);
}
