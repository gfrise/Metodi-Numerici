#include<stdio.h>
#include<math.h>

int poisson(double mu){
    double u=rand()/(double)RAND_MAX;
    double pb=exp(-mu),acc=p;
    int n =0;
    while(u>acc){
        pb*=mu/++n;
        acc+=pb;
    }
    return n;
}

int main(){
    for(int i=0;i<10;i++)
    printf("evento %d: %d\n",i+1,poisson(3));
}
