# hid
## Programas de cálculo sobre mecánica de fluidos e hidráulica
Escritos en C y en python
----
Programas para cálculos hidráulicos escritos en C, para funcionar con argumentos de entrada y devuelve los valores en unidades del SI (Sistema Internacional de Medidas).   El objetivo es poder ser usados en línea de comando y construir programas que los combinen en un bash script.

* fDW : obtiene el valor del factor de fricción de la ecuación de Darcy-Weisbach a partir del diámetro de la tubería en [mm], el caudal en [l/s], la rugosidad en [mm] y la viscosidad en [m2/s]
* hf : calcular las pérdidas de carga en [m] a partir del diámetro, longitud y rugosidad de la tubería en [mm], [m] y [mm] respectivamente; y el factor de fricción de la ecuación de Darcy Weisbach
* hl : calcular las perdidas locales de carga a partir de los datos de coeficiente de pérdidas y velocidad de flujo en una tubería
* vmax : calcular de la velocidad máxima de flujo en una tubería a partir de la carga topográfica disponible, diámetro, longitud, rugosidad, coeficiente de pérdidas locales y viscosidad del flujo.
----
Programas para cálculos hidráulicos escritos en python, para funcionar con argumentos de entrada y devuelve los valores en unidades del SI (Sistema Internacional de Medidas).   El objetivo es poder ser agrupadas como funciones de librería o módulo y construir programas que los combinen o usen.  Tambien pueden ser usados tal cual.
* fDW.py : obtiene el valor del factor de fricción de la ecuación de Darcy-Weisbach a partir del diámetro de la tubería en [mm], el caudal en [l/s], la rugosidad en [mm] y la viscosidad en [m2/s]
* tirante.py : calcular el tirante normal en un flujo en una tubería simple a partir de una altura topográfica (pendiente), diámetro, longitud y rugosidad de la tubería y el caudal a trasegar.

