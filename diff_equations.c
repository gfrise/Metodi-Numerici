#include<stdio.h>
#include<math.h>

double f(double x,double y){
    return cos(5*x)+y;
}

double taylor(double x,double y,int i,double h){
    double dx=i*h, f0=f(x,y);
    double f1=-5*sin(5*x)+f0;
    double f2=-25*cos(5*x)+f1;
    double f3=125*sin(5*x)+f2;
    double f4=625*cos(5*x)+f3;
    return y+dx*f0+pow(dx,2)*f1/2+pow(dx,3)*f2/6+pow(dx,4)*f3/24+pow(dx,5)*f4/120;
}

void start(double x[],double y[],double x0,double y0,double h){
    x[0]=x0; y[0]=y0;
    for(int i=1;i<4;i++){
        x[i]=x0+i*h;
        y[i]=taylor(x0,y0,i,h);
        printf("%d\t%f\t%f\n",i,x[i],y[i]);
    }
}

double ab(double x0,double y0,double h,double xf,double eps){
    int n=(int)((xf-x0)/h);
    double x[5],y[5];
    start(x,y,x0,y0,h);
    for(int i=4;i<=n;i++){
        x[4]=x[3]+h;
        y[4]=y[3]+h*(55*f(x[3],y[3])-59*f(x[2],y[2])
        +37*f(x[1],y[1])-9*f(x[0],y[0]))/24;
        double err=1;
        while(err>eps){
            double ws=y[3]+h*(9*f(x[4],y[4])+19*f(x[3],y[3])
                 -5*f(x[2],y[2])+f(x[1],y[1]))/24;
            err=fabs(y[4]-ws);
            y[4]=ws;
        }
        printf("%d\t%f\t%f\n",i,x[4],y[4]);
        for(int j=0;j<4;j++){
            x[j]=x[j+1];
            y[j]=y[j+1];
        }
    }
    return y[3];
}

int main(){
    double x0=0,y0=0,xf=3.5,h=0.05,eps=1e-2,s1,s2,s3;
    printf("h = %f, eps = %f\n", h, eps);
    s1 = ab(x0, y0, h, xf, eps);
    eps /= 10;
    printf("\nNuovo eps: %le\n", eps);
    printf("\nCon h = %.2lf, eps = %le\n", h, eps);
    s2 = ab(x0, y0, h, xf, eps);
    printf("\nDifferenza (stesso h, eps differente): %le\n", fabs(s2 - s1));
    h = 0.25;
    printf("\nCon h = %.2lf, eps = %le\n", h, eps);
    s3 = ab(x0, y0, h, xf, eps);
    printf("\nDifferenza (stesso eps, h differente): %le\n", fabs(s3 - s2));
}
