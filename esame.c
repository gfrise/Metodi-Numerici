#include <stdio.h>
#include <math.h>

double f(double t, double u) {
    return sin(log(1.26 * t) + u);
}

void ab(double t0, double u0, double tf, double eps, double h) {
    int n = (int)((tf-t0)/h);
    double t[n], u[n];
    
    t[0] = t0;
    u[0] = u0;
    t[1] = t[0] + h;
    u[1] = u[0]+h*f(t[0],u[0]);
    printf("t0 = %.6lf, u0 = %.6lf\n", t[0], u[0]);
    printf("t1 = %.6lf, u1 = %.6lf\n", t[1], u[1]);    
    
    for (int i=1;i<n;i++) {
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
    ab(1,0,10,1.e-6,0.1);
}
