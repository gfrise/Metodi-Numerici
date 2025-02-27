#include<stdio.h>

double draw(){
    return (double)rand()/RAND_MAX;
}

double gauss_cos(double r1, double r2){
    return sqrt(-2*log(r1))*cos(2*M_PI*r2);
}

double gauss_sin(double r1, double r2){
    return sqrt(-2*log(r1))*sin(2*M_PI*r2);
}

int main(){
    int i,n=10;
    double b = 10, a = 0.5, x0=a;
    double dx=1, sigma = 1;

    srand(time(0));
    for(i=0;i<n;i=i+2){
        double x1 = x0+i*dx;
        double x2 = x1+dx;
        double T1 = a+b*x1;
        double T2 = a+b*x2;
        double r1 = draw();
        double r2 = draw();
        double g1 = gauss_cos(r1,r2);
        double g2 = gauss_sin(r1,r2);
        double Tg1 = T1+sigma*g1;
        double Tg2 = T2+sigma*g2;
        printf("temperatura in %f:%f\ntemperatura in %f:%f\n",x1,Tg1,x2,Tg2);
    }
}