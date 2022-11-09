# Programas varios de cálculos hidráulicos
# Fecha: noviembre 2022

#! /usr/bin/env python
"""
 Cálculo del tirante en canal abierto
 Determinar primero si es canal abierto o presión

  >> Condición 1: debe tener carga = 0 en el nudo de atrás
"""
import math
import sys

def calcula_theta():
  li = 0
  ls = math.pi * 2
  error=0.00001
  dif=1.0
  it=0
  AR23 = q * n / math.pow(s,0.5)
  print(f"AR23={AR23:7.4f}")
  print("  Theta    AR23   dif    Iter")
  while abs(dif)>error and it<50:
      m = (li+ls)/2
      f= ( d**2/8* ( m-math.sin(m) ) ) * math.pow( ( d/4*(1-math.sin(m) /m) ), (2/3) )
      dif= f - AR23
      if dif<0:
        li=m
      else:
        ls=m
      it=it+1
      print(f"{m:7.4} {f:7.4f} {dif:7.4f} {it}")
  return m

def uso():
    print("")
    print("Cálculo de tirante en tubo simple")
    print("---------------------------------")
    print("python3 tirante D L Zi Zf n Q")
    print("")
    print("D es el diámetro de la tubería en [mm]")
    print("L es la longitud de la tubería en [m]")
    print("Zi es la cota topográfica inicial de la tubería en [m] ")
    print("Zf es la cota topográfica final de la tubería en [m] ")
    print("n valor de la n de manning para pérdidas [adim] ")
    print("Q caudal que fluye en la tubería en [l/s]")
    print("")
    return

if len(sys.argv) < 2 :   #cuando solo se escribe mgh, imprime el modo de uso y termina
   uso()
   sys.exit()
else:     
   print("Determinar si es canal abierto o presión")
   print("---")
   d= float(sys.argv[1])/1000.0
   l= float(sys.argv[2])
   c1=float(sys.argv[3])
   c2=float(sys.argv[4])
   n= float(sys.argv[5])
   q= float(sys.argv[6])/1000.0
   print("---")
   a= math.pi * (d)**2 / 4
   p= math.pi * d
   r = a / p
   h= c1 - c2
   s = h / l

   qmax= 1 / n * a * math.pow(r, (2/3)) * math.pow(s,(1/2))  

   print(f"Caudal máximo:{qmax*1000:7.4f} [l/s]")
   if qmax < (q):
      print("El tubo funciona a presión")
   else:
      print("El tubo está a canal abierto...")
      print("Calculando tirante...")
      print("---")
      theta = calcula_theta() 
      y = d/2 * ( 1 - math.cos(theta/2))
      print(f"Tirante: {y*1000:7.4f} [mm]")


#EOF