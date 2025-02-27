#include<stdio.h>

double spezzata(double a, double h, double l, int n){
    int i;
    l /= 2.;
    for(i=1;i<n;i++){
        l += f(a+i*h);
    }
    return l*h;
}

double simpson(double a, double h, double l, int n){
    int i;
    for(i=1;i<n-1;i+=2){
        l+=4*f(a+i*h)+2*f(a+(i+1)*h);
    }
    l+=f(a+(n-1)*h)*h;
    return l*h/3;
}

double treottavi(double a, double h, double l, int n){
    int i;
    for(i=1;i<n-1;i+=3){
        l+=3*f(a+i*h)+3*f(a+(i+1)*h)+2*f(a+(i+2)*h);
    }
    return l*3*h/8;
}

void iterative_integration(double a, double b, double (*method)(double, double, double, int), const char *method_name, double epsilon) {
    int n = 1000;
    double h = (b - a) / n;
    double l = f(a) + f(b);
    double value, next;

    value = method(a, h, l, n);
    printf("%s: n = %d, value = %.8f\n", method_name, n, value);

    do {
        next = value;
        n *= 2;
        h = (b - a) / n;
        value = method(a, h, l, n);
        printf("%s: n = %d, value = %.8f\n", method_name, n, value);
    } while (fabs(value - next) > epsilon);

    printf("%s Final result: %.8f\n", method_name, value);
}

int main(){
    double a = 0., b = 2.;
    double epsilon = 1e-6;

    printf("\nIterative Spezzata:\n");
    iterative_integration(a, b, spezzata, "Spezzata", epsilon);

    printf("\nIterative Simpson:\n");
    iterative_integration(a, b, simpson, "Simpson", epsilon);

    printf("\nIterative Tre-Ottavi:\n");
    iterative_integration(a, b, treottavi, "Tre-Ottavi", epsilon);

    printf("\nErrore teorico spezzata:\n");
    printf("(b-a)*h^2/12*maxf2\n");

    printf("\nErrore teorico simpson:\n");
    printf("(b-a)*h^4/180*maxf4\n");

    printf("\nErrore teorico treottavi:\n");
    printf("(b-a)*h^4*3/80*maxf4\n");

    printf("\nErrore teorico 24esimi:\n");
    printf("(b-a)*h^6*8/945*maxf6\n");
}
