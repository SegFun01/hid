# Programas varios de cálculos hidráulicos
# Fecha: noviembre 2022

#! /usr/bin/env python
"""
 Cálculo del factor de fricción de la ecuación de Darcy Weisbach
 utilizando la ecuación de Colebrook-White ó Swamee-Jain
 
"""
import math
import sys

#---> Calcula el area de la tuberia en m2 con diametro en mm        
def area(D):
    a = D * D * math.pi / 4
    return a
    
#---> Calcula la velocidad del flujo a partir del caudal y el area    
def ve(q,a):
    v = q / a
    return v

#---> Calcula el numero de reynolds para la condicion de flujo dada
def reynolds(v,d,vis):
    re = abs( v * d / vis )
    return re

def fCW(k, d, R, tol, ec): # parámetros de entrada ks/D, Re, t
   # primero se calcula f por S-W
   it=0
   Re = pow(abs(R),0.9)
   f1 = 0.25 / ( math.log10(k/d/3.7 + 5.74/Re)**2)
   # print(f"f según Swamee-Jain: {f1:10.9f}")
   if ec=="C":
      # Calcular el factor de f por Colebrook-White
      f1= 0.01
      f=0
      dif = 0.1
      #it=0
      while dif>tol:
         f= ( 1 / ( -2* math.log10(k/d/3.7 + 2.51/(R * math.sqrt(f1) ) ) ))**2
         dif=abs(f1-f)
         f1=f
         it=it+1
         print(f"Iteracion:{it}   factor: {f}")
   else:
      f=f1
   return f


def uso():
    print("")
    print("Cálculo de f de Darcy-Weisbach")
    print("---------------------------------")
    print("python3 f_DW D Ks vi Q ec")
    print("")
    print("D  : diámetro de la tubería en [mm]")
    print("Ks : rugosidad equivalente del material de la tubería en [mm]")
    print("vi : viscosidad del fluido en [m2/s]")
    print("Q  : caudal que fluye en la tubería en [l/s]")
    print("ec : ecuación: C=Colebrook-White, S=Swamee-Jain [C/S] ")
    print("")
    print("ejemplo con D=100mm, Ks=0.0015mm vi=1.007e-6 m2/s, Q=15l/s Ecuación=C")
    print("# python3 f_DW.py 100 0.0015 1.007E-6 15 C")
    print("")
    return

if len(sys.argv) < 2 :  #cuando solo se escribe mgh, imprime el modo de uso y termina
   uso()
   sys.exit()
else:     
   print("Cálculo de la f de Dary-Weisbach")
   print("---")
   d= float(sys.argv[1])/1000.0
   ks= float(sys.argv[2])/1000.0
   vi=float(sys.argv[3])
   q= float(sys.argv[4])/1000.0
   ec=sys.argv[5]
   t= 1.0e-6 
   a= area(d)
   v=ve(q,a)
   r=reynolds(v,d,vi)
   f=fCW(ks,d,r,t,ec)
   print(f"f={f}")

#EOF