#include<stdio.h>
#define MEAN 5
#define N 1000
#define SIGMA 2

double draw(){
    return (double)rand()/RAND_MAX;
}

int main(){
    double x[N];
    int i = 0;

    while (i<N){
        double r1 = 12*draw()-6;
        double r2 = sqrt(2*M_PI)*draw();
        if (exp(-0.5*r1*r1)>=r2){
            x[i++]=MEAN+SIGMA*r1;
        }
    }
}