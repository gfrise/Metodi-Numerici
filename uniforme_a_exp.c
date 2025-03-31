#include<stdio.h>
#include<math.h>

double expRand(double lambda){ // o 1/tau 
    return -log((double)rand()/RAND_MAX)/lambda;
}

int main() {
    for(int i=0;i<50;i++){
        printf("evento %d: %.4f\n",i,expRand(1.0));
    }
}
