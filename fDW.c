#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double PI = 3.14159265358979323846;

double area(double D)
{
    double a;
    a = D * D * PI / 4;
    return a;
}

double velocidad(double q, double a)
{
    double v; 
    v = q / a;
    return v;
}

double reynolds(double v, double d, double vis)
{
    double re;
    re = abs( v * d / vis );
    return re;
}

double calcular_f(double d, double k, double R)
{
   double f, f1, Re, dif, t;
   int it;
   t=0.00000000001;
   it=0;
   Re = pow(abs(R),0.9);
   f1 = 0.25 / ( pow(log10(k/d/3.7 + 5.74/Re),2) );
   f=0;
   dif = 0.1;
   while (dif > t)
   {
      f= 1.0 /( -2* log10( k/d/3.7 + 2.51/(R * sqrt(f1) ) ) );
      f = pow(f,2);
      dif = f1-f;
      if (dif<0.0){ 
        dif= (-1.0)*dif;
      }
      //printf("Iteracion: %d f: %12.10f f1:%12.10f err: %12.10f \n",++it,f,f1,f-f1);
      f1=f;
   }
   return f;
}

int main(int argc, char *argv[])
{
  double v, R, vi, a, d, q, k, f;
  int e;
  if (argc<2)
  {
    printf("Uso: fDW Diametro[mm] Caudal[l/s] Rugosidad[mm] Viscosidad[m2/s]\n");
    printf("\nEjemplo:\n ./fDW 100 20 0.0015 1.007e-6\n 0.015830756\n"); 
  }
  else
  {  
   d=atof(*++argv);
   q=atof(*++argv);  
   k=atof(*++argv);
   vi=atof(*++argv);
   d=d/1000.0;
   k=k/1000.0;
   q=q/1000.0;
   a=area(d);
   v=velocidad(q,a);
   R=reynolds(v,d,vi);
   f=calcular_f(d, k, R);
   printf("%12.10f\n",f);
  }    
}
