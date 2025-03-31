#include<stdio.h>
#include<math.h>

#define H 0.000005
#define TF 5.5
#define EPS 1e-6
#define N ((int)(TF/H))

double f(double t,double x) {
    return cos(5*t)+x;
}

double taylor(double t0,double x0,int i){
    double h = H;
    double f0 = f(t0,x0);
    double f1 = -5*sin(5*t0)+f0;
    double f2 = -25*cos(5*t0)+f1;
    double f3 = 125*sin(5*t0)+f2;
    double f4 = 625*cos(5*t0)+f3;
    return x0+i*h*f0+pow(i*h,2)*f1/2+pow(i*h,3)*f2/6+pow(i*h,4)*f3/24+pow(i*h,5)*f4/120;
}

void initialize(double t[],double x[]){
    for(int i=0;i<4;i++){
        t[i] = i*H;
        x[i] = taylor(0,0,i);
    }
}

void predictor_corrector(double t[],double x[]){
    for (int i=4;i<= N;i++){
        t[4]=t[3]+H;
        x[4]=x[3]+H*(55*f(t[3],x[3])-59*f(t[2],x[2])+37*f(t[1],x[1])-9*f(t[0],x[0]))/24;

        double x_new;
        do {
            x_new = x[4];
            x[4]=x[3]+H*(9*f(t[4],x_new)+19*f(t[3],x[3])-5*f(t[2],x[2])+f(t[1],x[1]))/24;
        } while (fabs(x[4]-x_new)>EPS);
        
        printf("t = %.2lf, x = %.6lf\n",t[4],x[4]);

        for (int j=0;j<4;j++){
            t[j]=t[j+1];
            x[j]=x[j+1];
        }
    }
}

int main(){
    double t[5],x[5];
    initialize(t,x);
    predictor_corrector(t,x);
}
