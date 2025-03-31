#include<stdio.h>
#include<math.h>
#define U ((double)rand()/RAND_MAX)

double expo(double lambda){
    return -log(U)/lambda;
}

int poisson(double mu){
    double pb=exp(-mu),acc=pb;
    int n=0;
    while(U>acc){
        pb*=mu/++n;
        acc+=pb;
    }
    return n;
}

double sumUniforms(double mu,double sigma){
    double sum=0.0;
    for(int j=0;j<12;j++) sum+=U;
    return mu+sigma*(sum-6.0);
}

int main(){
    for(int i=0;i<10;i++){
        printf("exp %d:%f\tpoisson %d:%d\tnormal %d:%f\n",
        i+1,expo(1),i+1,poisson(3),i+1,sumUniforms(0,1));
    }
}
