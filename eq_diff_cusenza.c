#include<stdio.h>
#include<math.h>

double f(double t, double x){
	return cos(5*t)+x;
}

double f1(double t, double x){
	return -5*sin(5*t)+f(t,x);
}

double f2(double t, double x){
	return -25*cos(5*t)+f1(t,x);
}

double f3(double t, double x){
	return 125*sin(5*x)+f2(t,x);
}

double f4(double t, double x){
	return 625*cos(5*x)+f3(t,x);
}

double metIn(double t0, double x0, int i, double h){
	return (x0+(i*h*f(x0,t0))+(pow(i,2)*pow(h,2)*f1(x0,t0))/2+(pow(i,3)*pow(h,3)*f2(t0,x0))/6+(pow(i,4)*pow(h,4)*f3(x0,t0))/24+(pow(i,5)*pow(h,5)*f4(x0,t0))/120);
}

double restart(double t0, double x0, double t[], double x[], double h, FILE *fp){
        int i;

        t[0]=t0;
        x[0]=x0;
        for(i=1;i<4;i++){
                t[i]=t0+i*h;
                x[i]=metIn(x0,t0,i,h);
                fprintf(fp,"%d\t%.2lf\t%.8lf\n", i,t[i],x[i]);
        }
}

void ab(double t[], double x[], double h, int n, double eps, double *pred, FILE *fp){
	int i, j;
	double ws, err;

        for(i=4;i<n+1;i++){
                t[4]=t[3]+h;
                x[4]=x[3]+h*(55*f(t[3],x[3])-59*f(t[2],x[2])+37*f(t[1],x[1])-9*f(t[0],x[0]))/24;
                *pred=x[4];

                err=1;
                while(err>eps){
                        ws=x[3]+h*(9*f(t[4],x[4])+19*f(t[3],x[3])-5*f(t[2],x[2])+f(t[1],x[1]))/24;
                        err=fabs(x[4]-ws);
                        x[4]=ws;
                }
                fprintf(fp,"%d\t%.2lf\t%.8lf\n", i,t[4],x[4]);

                for(j=0;j<4;j++){
                        t[j]=t[j+1];
                        x[j]=x[j+1];
                }
        }
}

int main(){
	double t0=0, x0=0, h=0.05, tf=3.5,  eps=1e-2, err, t[5], x[5], pred;
	int n=(int)((tf-t0)/h), i;

	FILE *fp;
	fp=fopen("e4_CusenzaFrancesco.txt","w");

	fprintf(fp,"DIFFERENTIAL EQUATIONS\n\ni.\nCon h = %.2lf, eps = %le\ni\tt\tx\n", h,eps);
	restart(t0,x0,t,x,h,fp);
	ab(t,x,h,n,eps,&pred,fp);
	double s1=x[4];

	fprintf(fp,"\n\nii.\nERRORE 1: %le\n", fabs(pred-x[4]));
	i=2;
	while(pred-x[4]<eps){
		eps/=10;
		i++;
	}
	fprintf(fp,"Nuova eps: %le\n", eps);

	fprintf(fp,"\n\nCon h = %.2lf, eps = %le\ni\tt\tx\n", h,eps);
	restart(t0,x0,t,x,h,fp);
	ab(t,x,h,n,eps,&pred,fp);
	double s2=x[4], err2=fabs(pred-x[4]);
	fprintf(fp,"\nERRORE 2: %le\n", err2);
	fprintf(fp,"\nDifferenza con il primo (stesso h ma eps differente):\n%le\n", fabs(s2-s1));

	h=0.25;
	n=(int)((tf-t0)/h);
	fprintf(fp,"\n\niii.\nCon h = %.2lf, eps = %le\ni\tt\tx\n", h,eps);
	restart(t0,x0,t,x,h,fp);
        ab(t,x,h,n,eps,&pred,fp);
        double s3=x[4], err3=fabs(pred-x[4]);
	fprintf(fp,"\n\nERRORE 3: %le\nRapporto tra ERR2 ed ERR 3: %le\n", err3, (err2/err3));
	fprintf(fp,"\nDifferenza con il secondo (stesso eps ma h differente):\n%le\n\nCome si può notare aumentando il passo h la precisione globale diminuisce, perchè l'errore di troncamento locale aumenta. Contrariamente, se si dovesse scegliere un passo troppo piccolo aumenterebbero il numero di iterazioni e ciò porterebbe all'accumulazione di errori di arrotondamento (non e' il nostro caso). E' piu' opportuno nel nostro caso utilizzare un valore di h = 0.05, difatti riporta un errore di 4 ordini inferiore.", fabs(s3-s2));
}

