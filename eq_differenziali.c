#include<stdio.h>

double f_(double x, double w){return x+pow(w,2);}
double w_(double r, double h){return pow(r*h,2)/2+pow(r*h,5)/20;}

int main(){
    double xf = 1.6, h = 0.2, eps = 1e-8;
    int n = (int)(xf/h),i,j;
    double x[4],w[4],f[4];

    for(i=0;i<4;i++){
        x[i]=i*h;
        w[i]=w_(i,h);
        f[i]=f_(x[i],w[i]);
        printf("x%d=%.1f w%d=%.5f\n",i,x[i],i,w[i]);
    }

    for(i=4;i<=n;i++){
        double x_new = x[3]+h;
        double w_new=w[3]+h*(55*f[3]-59*f[2]+37*f[1]-9*f[0])/24, w_old;
        do {
            w_old = w_new;
            double f_new=f_(x_new,w_old);
            w_new = w[3]+h*(9*f_new+19*f[3]-5*f[2]+f[1])/24;
        } while (fabs(w_new-w_old)>eps);

        printf("x%d=%.1f w%d=%.5f\n",i,x_new,i,w_new);

        for(j=0;j<3;j++){
            x[j]=x[j+1];
            w[j]=w[j+1];
            f[j]=f[j+1];
        }
        x[3]=x_new;
        w[3]=w_new;
        f[3]=f_(x_new,w_new);
    }
}