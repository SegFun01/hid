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

double perimetro(double D)
{
    double p;
    p = D * PI;
    return p;
}

double radioHidraulico(double D)
{
    double p,r,a;
    p = D * PI;
    a = D * D * PI / 4;
    r = a / p;  
    return r;
}

double calcular_Qmax(double n, double a, double r, double s)
{
  double q;
  q = 1 / n * a * pow(r, (2.0/3.0)) * pow(s,(0.5));  
  return q;
}

double calcula_theta(double d, double q, double n, double s)
{
  double li, ls, AR23, dif, m, error,f;
  int it;
  li = 0;
  ls = PI * 2;
  error=0.00001;
  dif=1.0;
  it=1;
  AR23 = q * n / pow(s,0.5);
  //printf("AR23:%f q:%f n:%f s:%f\n",AR23,q,n,s);
  while ( (dif>error) && (it<50) )
  {
      m = (li+ls)/2.0;
      f= ( d*d/8.0*(m-sin(m)) ) * pow( ( d/4.0*(1-sin(m)/m) ), 2.0/3.0 );
      dif= f - AR23;
      //printf("theta:%f AR23:%f dif:%f it:%d \n",m,f,dif,it);
      if (dif<0.0)
      {
        li=m;
        dif=(-1)*dif;
      }
      else
      {
        ls=m;
      }
      it++;
      //printf("AR23:%f li:%f ls:%f m:%f f:%f dif:%f it:%f\n",AR23,li,ls,m,f,dif,it);
  }
  return m;
}

int main(int argc, char *argv[])
{
  double d,l,c1,c2,n,q,qmax,s,y,theta,a,r;
  if (argc<2)
  {
    printf("Uso: yn D L Zi Zf n Q\n");
    printf("\nEjemplo:\n ./yn 100 500 120 70 0.009 15\n 57.336524 [mm]\n"); 
  }
  else
  {  
   d=atof(*++argv);
   l=atof(*++argv);
   c1=atof(*++argv);
   c2=atof(*++argv);
   n=atof(*++argv);
   q=atof(*++argv);
   d=d/1000.0;
   q=q/1000.0;
   s = (c1-c2)/l;
   a=area(d);
   r=radioHidraulico(d);
   qmax=calcular_Qmax(n, a, r, s);
   //printf("d:%f l:%f z1:%f z2:%f n:%f q:%f s:%f a:%f r:%f qm:%f\n",d,l,c1,c2,n,q,s,a,r,qmax);
   //printf("qm:%f q:%f\n",qmax,q);
   if (qmax < q)
   {
      printf("-1\n");
   }
   else
   {
      theta = calcula_theta(d, q, n, s); 
      //printf("%f\n",cos(theta/2));
      y = d/2 * ( 1 - cos(theta/2));
      printf("%f [mm]\n",y*1000.0);
   }   
  }    
}

//EOF
