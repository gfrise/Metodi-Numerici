#include<stdio.h>

int main(){
    double mu = 0.0, sigma = 1.0;
    int i,j,n=100;

    for(i=0;i<n;i++){
        double sum = 0.0;
        for(j=0;j<12;j++){
            sum+=(double)rand()/RAND_MAX;
        }
        double rg=mu+sigma*(sum-6.0);
        printf("Evento %d:%.4f\n",i+1,rg);
    }
}