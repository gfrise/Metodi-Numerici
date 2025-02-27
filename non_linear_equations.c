#include<stdio.h>

double f(double x){
    return pow(x,2)-2*x-3; //exp(-x) come generatrice
}

double f1(double x){
    return 2*x-2;
}

double g(double x){
    return x - f(x)/f1(x);
}

int main(){
    int i= 0,scelta;
    double eps = 0.001, x0=0.1, x = 0, den, num, rate, t_rate;
    printf("generatrice (1) o raphson (2):\n");
    scanf("%d",&scelta);
    
    do{
        den=x-x0;
        x0=x;
        if (scelta==1){
            x = f(x0);
        } else if (scelta==2){
            x = g(x0);
        }
        i++;
        num = x-x0;
    } while (fabs(x-x0)>eps);

    rate = fabs(num/den);
    t_rate = fabs(-1/exp(x)); // deriavat di e^-x

    printf("result:%f\n",x);
}