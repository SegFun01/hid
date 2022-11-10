#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double PI = 3.14159265358979323846;


double calcular_hl(double k, double v)
{
   double hl;
   hl=0.0;
   hl = k * pow(v,2) / 19.62;
   return hl;
}

int main(int argc, char *argv[])
{
  double k, v, hl;
  if (argc<2)
  {
    printf("Uso: hl CoeficienteK Velocidad[m/s]\n");
    printf("\nEjemplo:\n ./hl 10.0 2.546\n 3.3038307849\n"); 
  }
  else
  {  
   k=atof(*++argv);
   v=atof(*++argv);
   hl=calcular_hl(k, v);
   printf("%12.10f\n",hl);
  }    
}
