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

double reynolds(double q, double d, double vis)
{
    double re;
    re = abs(4 * q / PI / d / vis );
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

double calculaM(double d, double k, double R, double L, double f)
{
 double mf, ml, m;
 mf = 8 / pow(PI,2) / 9.81 * f * L / pow(d,5);
 ml = 8 / pow(PI,2) / 9.81 * k / pow(d,4);
 m = mf + ml;
 return m;
}

double calculaQ(double H, double M)
{
 double Q;
 Q =  pow(H/M,0.5);
 return Q;
}

double calculaD(double Q, double v)
{
 double D;
 D =  pow(4*Q/v/PI,0.5);
 return D;
}

int main(int argc, char *argv[])
{
  double v, R, L, vi, a, d, q, k, f , M , H, Q ;
  int e;
  if (argc<2)
  {
    printf("Uso: distub Caudal[l/s] Carga[m] Longitud[m] Rugosidad[mm] kL[ad] Viscosidad[m2/s]\n");
    printf("\nEjemplo:\n ./distub 200 30 1250 0.0015 4 1.007e-6\n "); 
  }
  else
  {  
   Q=atof(*++argv);
   H=atof(*++argv);
   L=atof(*++argv);  
   ks=atof(*++argv);
   kL=atof(*++argv);
   vi=atof(*++argv);
   Q=Q/1000.0;
   ks=ks/1000.0;
   d=0.5;
   do {
      R=reynolds(Q,d,vi);
      f=calcular_f(d, ks, R);
      M = calculaM(d, ks, R, L, f);
      q = calculaQ(H, M);
      a = area(d);
      v = velocidad(q, a);
      d = calculaD(q, v);
   }   
   while (dif<tol); 
   printf("%12.10f\n",f);
  }    
}