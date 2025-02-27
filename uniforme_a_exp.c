#include<stdio.h>

double exponentialRandom(double lambda){
    double u = (double)rand()/RAND_MAX;
    return -log(u)/lambda;
}

int main(){
    double lambda = 1.0; // o 1/tau;
    int n = 50;

    printf("dist exp lambda = %.2f\n",lambda);
    for(int i =0;i<n;i++){
        printf("evento %d: %.4f\n",i+1,exponentialRandom(lambda));
    }
}