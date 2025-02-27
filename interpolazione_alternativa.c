#include<stdio.h>
#define N 100

int main(void){
    double h = 0.125, z=1.03,x[N],y[N],diff[N][N];
    int i,j,m,k;
    for(i=0;i<N;i++){
        x[i]=i*h;
        y[i]=exp(x[i]);
        diff[i][0]=y[i];
    }

    for(m=1;m<N;m++){
        for(i=0;i<N-m;i++){
            diff[i][m]=diff[i+1][m-1]-diff[i][m-1];
        }
    }

    j = (int)((z-x[0])/h);
    double r = (z-x[j])/h;
    int maxm = (N-j-1>j)?j:N-j-1;
    for(m=1;m<=maxm;m++){
        double yx = diff[j][0],coeff=1;
        for(k=1;k<=m;k++){
            coeff*=((r-k+1)/k);
            yx+=coeff*diff[j][k];
        }
        double err = fabs(coeff*diff[j][m]);
        printf("%d %f %f\n",m,yx,err);
    }
}