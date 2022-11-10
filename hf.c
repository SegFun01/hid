#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double PI = 3.14159265358979323846;


double calcular_hf(double f, double d, double v, double L)
{
   double hf;
   hf=0.0;
   hf = f * pow(v,2) * L / 19.62 / d;
   return hf;
}

int main(int argc, char *argv[])
{
  double L, f, d, v, hf;
  if (argc<2)
  {
    printf("Uso: hf Diametro[mm] Longitud[m] Velocidad[m/s] factor\n");
    printf("\nEjemplo:\n ./hf 100 1000 2.546 0.015830756\n 52.3021390213\n"); 
  }
  else
  {  
   d=atof(*++argv);
   L=atof(*++argv);  
   v=atof(*++argv);
   f=atof(*++argv);
   d=d/1000.0;
   hf=calcular_hf(f, d, v, L);
   printf("%12.10f\n",hf);
  }    
}
