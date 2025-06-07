#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//CONTA LE RIGHE DI UN FILE//
int numrighe(FILE *fp){
    int N=0;
    char c, r='\n';
    while(fscanf(fp,"%c",&c)!=EOF){
      if(c==r){
         N++;
      }
    }
    return N;
}

//CONTA LE COLONNE DI UN FILE//
int numcolonne(FILE *fp){
   int N=0, M=0, cc;
    char c, r='\t', p='\n';
      while(fscanf(fp,"%c",&c)!=EOF){
        if(c==r){
           N++;
       }
       if(c==p){
         M++;
       }
     }
    return (N/M)+1;
}





//ALLOCAZIONE DINAMICA DELLA MEMORIA per un vettore //
double *allocamem1(int N){
	int i;
	double *V;
	V=(double *) malloc(N*sizeof(double));

	return (V);
}

//ALLOCAZIONE DINAMICA DELLA MEMORIA per una matrice rettangolare//
double **allocamem2(int N1, int N2){
	int i;
	double **M;
	M=(double **) malloc(N1*sizeof(double));
	for(i=0;i<N1;i++){
		M[i]=(double *) malloc(N2*sizeof(double));
	}

	return (M);
}

//ALLOCAZIONE DINAMICA DELLA MEMORIA per una matrica quadrata//
double **allocamem(int N){
	int i;
	double **M;
	M=(double **) malloc(N*sizeof(double));
	for(i=0;i<N;i++){
		M[i]=(double *) malloc(N*sizeof(double));
	}

	return (M);
}





//CALCOLO DELLA MEDIA//
double mymedia(int N,  double x[]) {
   
    int i;
    double MEDIA;
    
    MEDIA=0;    
    for(i=0; i<N; i++){  
       MEDIA += x[i];
       }
    MEDIA=(double)MEDIA/N;    
    return MEDIA; 
}
 
 
//CALCOLO DELLA STANDARD DEVIATION//
double mysd(int N,  double x[]) {
   
    int i;
    double MEDIA, STD;
    
    MEDIA=0;
    STD=0;    
    for(i=0; i<N; i++){  
       MEDIA += x[i];
       STD=STD+pow(x[i],2.);
       }
    MEDIA=(double)MEDIA/N;
    STD=(double)STD/N-pow(MEDIA,2.);
    STD=sqrt(STD);    
    return STD; 
}
 
//CALCOLO DEL MINIMO//
double mymin(int N, double x[]) {
   
   int i;
   double MIN;
    
    MIN=x[0];
    for(i=0; i<N; i++) {
       if(x[i]<MIN){
          MIN=x[i];
       }
  }  
  return MIN;
}
 
//CALCOLO DEL MASSIMO//
double mymax(int N,  double x[]) {

   int i;
   double MAX;

   MAX=x[0]; 
   for(i=0; i<N; i++) {
      if(x[i]>MAX){
      MAX=x[i];      
      }   
   } 
   return MAX;
}      	      





//GENERAZIONE DI NUMERI RANDOM//          
double *myrand(int N, int seed, double a, double b){
 
      int i;
      double *Xgen;
      Xgen=(double *) malloc(N*sizeof(double));
 
      srand(seed);
      for(i=0; i<N;i++){
          Xgen[i]=(double) rand()/RAND_MAX;
	  Xgen[i]=a+Xgen[i]*(b-a);
	  }
      return Xgen;	  
}

//GENERAZIONE DI NUMERI RANDOM distribuiti secondo una GAUSS//          
double *myrandgauss(int N, int seed, double m, double s){
 
      #define PIgreco 3.1415926535897932385
      
      int i;
      double x1,x2,gam;
      double *Xgen;
      Xgen=(double *) malloc(N*sizeof(double));
 
      srand(seed);
      for(i=0; i<N;i++){
          x1=(double) rand()/RAND_MAX;
	  if(x1>0){
	     x2=(double) rand()/RAND_MAX;
	     gam=sqrt(-2.*log(x1))*sin(2.*PIgreco*x2);
	     Xgen[i]=(double) sqrt(s)*gam;
	     Xgen[i]=m+Xgen[i];
	  }
	  
          
	  }
      return Xgen;	  
}

//GENERAZIONE DI NUMERI RANDOM distribuiti secondo una EXP//          
double *myrandexp(int N, int seed, double EXP){
 
      int i;
      double x1,x2,gam;
      double *Xgen;
      Xgen=(double *) malloc(N*sizeof(double));
 
      srand(seed);
      for(i=0; i<N;i++){
          Xgen[i]=(double) rand()/RAND_MAX;
	  Xgen[i]=-pow(EXP,-1)*log(Xgen[i]);         
	  }
      return Xgen;	  
}

//GENERAZIONE DI UN ISTOGRAMMA//
void istogramma(int N, double *X, double xmin, double xmax, int nbin){
      int i,j;

      int num[nbin+1];
      double z[nbin+1],numnorm[nbin+1];
 
      /*faccio la griglia ed inizializzo num*/
      double step;
      double area;
      step=(double) (xmax-xmin)/nbin;
      printf("La larghezza di ciascun bin e': %lf \n",step);
      
      /*inizializzo*/
      z[0]=xmin;
      area=0.;
      num[0]=0.;
      numnorm[0]=0.;
      for(j=0;j<=nbin;j++){
	  z[j]=xmin+step*j;
          num[j]=0;
          numnorm[j]=0.;
	 }			  

      /*riempio la griglia*/
      int p;
      for(i=0;i<N;i++){
          p=(double)(X[i]-xmin)/step;
          num[p]=num[p]+1;
	 }

      /*istogramma normalizzato*/
      area=0;
      for(j=0;j<=nbin;j++){
	  area=area+step*num[j];
	 }
      for(j=0;j<=nbin;j++){
          numnorm[j]=(double)num[j]/area;
         }
	 
      FILE *fp222222;
      fp222222=fopen("istogramma.dat","w");
      for(j=0;j<=nbin;j++){
         fprintf(fp222222,"%lf %d %lf \n", z[j], num[j], numnorm[j]); 
      }
      fclose(fp222222);
}

//CORRELAZIONE//
double mycorr(int N, double *x, double *y){

     double mean1,mean2,sd1,sd2,corr;
     double *z;
     z=(double *) malloc(N*sizeof(double));
     int i;

     mean1=mymedia(N,x);
     mean2=mymedia(N,y);

     for(i=0;i<N;i++){
	 z[i]=pow(x[i],2);
        }
     sd1=sqrt(mymedia(N,z)-pow(mean1,2));

     for(i=0;i<N;i++){
	 z[i]=pow(y[i],2);
        }
     sd2=sqrt(mymedia(N,z)-pow(mean2,2));

     for(i=0;i<N;i++){
	 z[i]=x[i]*y[i];
        }
     corr=(mymedia(N,z)-mean1*mean2)/(sd1*sd2);

     return corr;
}



//POPOLAMENTO RANDOM DI UNA MATRICE SIMMETRICA//
double **matrice(int N, int seed, double a, double b){
	int i,j;
	double **M;
	/*M=(double **)malloc(N*sizeof(double));
	for(i=0;i<N;i++){
		M[i]=(double *)malloc(N*sizeof(double));
	}*/
	M=allocamem(N);
	
        srand(seed);
	for(i=0;i<N;i++){
	   for(j=i;j<N;j++){
		M[i][j]=(double)rand()/RAND_MAX;
		M[i][j]=a+M[i][j]*(b-a);
		M[j][i]=M[i][j];
		}
	}
	
	return (M);
}

//PRODOTTO TRA MATRICI//
double **prod(int N,double **A,double**B){
	int i,j,k;
	double **C;
	/*C=(double **)malloc(N*sizeof(double));
	for(i=0;i<N;i++){
		C[i]=(double *)malloc(N*sizeof(double));
	}*/
	C=allocamem(N);
	
	for(i=0;i<N;i++){
	for(j=0;j<N;j++){
	   C[i][j]=0;
		for(k=0;k<N;k++){
                    C[i][j]=C[i][j]+A[i][k]*B[k][j];	
	            }
		}
	}		

	return (C);	
	}
	
	
	
		
	
//SCAMBIO DI ELEMENTI//	
double *swap(double a, double b){

     double *scambia;
     scambia=(double *) malloc(2*sizeof(double));

     double temp;
     temp=a;
     a=b;
     b=temp;
     scambia[0]=a;
     scambia[1]=b;
     
     return scambia;
     }
     



//METODO DEI RETTANGOLI (in)//	
double rettangoli (double a, double b, int m, double (*f)(double)){
	double I,x,h=(b-a)/(double)m;
	printf("la larghezza di ciascun bin e': %lf \n",h);
	I=0.;
	int i;
	  for(i=0;i<m;i++){
		x=a+(h*i);
		I+=(*f)(x);
		}
	return I*h;
}

//METODO DEL PUNTO DI MEZZO//	
double midpoint (double a, double b, int m, double (*f)(double)){
	double I,x,h=(b-a)/(double)m;
	printf("la larghezza di ciascun bin e': %lf \n",h);
	I=0.;
	int i;
	  for(i=0;i<m;i++){
		x=a+(h*i)+(0.500*h);
		I+=(*f)(x);
		}
	return I*h;
}

//METODO DEI TRAPEZI//	
double trapezi (double a, double b, int m, double (*f)(double)){
	double I,x1,x2,h=(b-a)/(double)m;
	printf("la larghezza di ciascun bin e': %lf \n",h);
	I=0.;
	int i;
	 
	  for(i=0;i<m;i++){
		x1=a+(h*i);
		x2=a+h*(i+1);
		I+=(*f)(x1)+(*f)(x2);
		}
	return I=(double)I*h/2.;
}


//FUNZIONE//	
   double funz(double x, double p){

   return pow(x,p);
   /*return exp(- p x);*/
}


//METODO DEI RETTANGOLI (in)//	
//Questa funzione svolge l’integrale di una funzione f(x) in cui ho anche un parametro p//
//Esempi: x^p, exp(- p x), …//
double myrettangoli (double a, double b, int m){
	double I,x,h=(b-a)/(double)m;
	printf("la larghezza di ciascun bin e': %lf \n",h);

        double p;
        printf("Inserisci il parametro della funzione \n");
        scanf("%lf",&p);
        
        I=0.;
	int i;
	  for(i=0;i<m;i++){
		x=a+(h*i);
		I+=(*funz)(x,p);
		}
	return I*h;
}

//METODO DEL PUNTO DI MEZZO//	
//Questa funzione svolge l’integrale di una funzione f(x) in cui ho anche un parametro p//
//Esempi: x^p, exp(- p x), …//
double mymidpoint (double a, double b, int m){
	double I,x,h=(b-a)/(double)m;
	printf("la larghezza di ciascun bin e': %lf \n",h);

	double p;
        printf("Inserisci il parametro della funzione \n");
        scanf("%lf",&p);
        
        I=0.;
	int i;
	  for(i=0;i<m;i++){
		x=a+(h*i)+(0.500*h);
		I+=(*funz)(x,p);
		}
	return I*h;
}

//METODO DEI TRAPEZI//	
//Questa funzione svolge l’integrale di una funzione f(x) in cui ho anche un parametro p//
//Esempi: x^p, exp(- p x), …//
double mytrapezi (double a, double b, int m){
	double I,x1,x2,h=(b-a)/(double)m;
	printf("la larghezza di ciascun bin e': %lf \n",h);
	I=0.;
	int i;
	 
	double p;
        printf("Inserisci il parametro della funzione \n");
        scanf("%lf",&p);
        
	  for(i=0;i<m;i++){
		x1=a+(h*i);
		x2=a+h*(i+1);
		I+=(*funz)(x1,p)+(*funz)(x2,p);
		}
	return I=(double)I*h/2.;
}


