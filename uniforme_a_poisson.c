#include<stdio.h>

int poissonRandom(double mu){
    double u = (double)rand()/RAND_MAX;
    double prob = exp(-mu);
    double cumulative = prob;
    int n = 0;

    while (u>cumulative){
        n++;
        prob*=mu/n;
        cumulative+=prob;
    }
    return n;
}

int main(){
    double mu = 3;
    int i,n=10;
    for(i=0;i<n;i++){
        printf("evento %d:%d\n",i+1,poissonRandom(mu));
    }
}