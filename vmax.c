#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double PI = 3.14159265358979323846;

double v_bigMamma(double D, double h, double L, double k, double vi)
{
   double ve, a, b, c, d;
   a= (-1)*sqrt(8*9.81*h*D/L);
   b= k/D/3.7;
   c= 2.51 * vi * sqrt(L) / sqrt(19.62*pow(D,3)*h);
   d= log10(b+c);
   ve= a * d;
  return ve;
}


double calcular_vmax(double d, double h, double L, double ks, double kl, double vi)
{
   double ve, hi, ht, hl, dif, t;
   hi=h;
   int it;
   dif = 1.0;
   t=0.000001;
   it=0;
   while (dif > t)
   {
      ve = v_bigMamma(d,hi,L,ks,vi);
      hl = kl * ve * ve / 19.62;
      ht = hi + hl;
      dif = ht - h;
      if (dif<0.0){ 
        dif= (-1.0)*dif;
      }
      //printf("Iteracion: %d v: %12.10f hi:%12.10f ht:%12.10f err: %12.10f \n",++it,ve,hi,ht,ht-h);
      hi=h-hl;
   }
   return ve;
}

int main(int argc, char *argv[])
{
  double vmax, vi, d, L, ks, kl, h;
  if (argc<2)
  {
    printf("Uso: vmax D[mm] H[m] L[m] Ks, KL, Viscosidad[m2/s]\n");
    printf("\nEjemplo:\n ./vmax 100 20 500 0.0015 10 1.007e-6\n 2.1104010108\n"); 
  }
  else
  {  
   d=atof(*++argv);
   h=atof(*++argv);  
   L=atof(*++argv);
   ks=atof(*++argv);
   kl=atof(*++argv);
   vi=atof(*++argv);
   d=d/1000.0;
   ks=ks/1000.0;
   vmax=calcular_vmax(d, h, L, ks, kl, vi);
   printf("%12.10f\n",vmax);
  }    
}
