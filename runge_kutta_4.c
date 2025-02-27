#include<stdio.h>

double f(double x, double y){return cos(5*x)+y};

int main(){
    double x =0, y =0, h=0.001, xf=3.5;
    while ((x+h)<xf){
        double k1 = h*f(x,y);
        double k2 = h*f(x+h/2,y+k1/2);
        double k3 = h*f(x+h/2,y+k2/2);
        double k4 = h*f(x+h,y+k3);
        y+=(k1+2*k2+2*k3+k4)/6;
        x+=h;
        printf("%.4f\t%.6f\n",x,y);
    }
}