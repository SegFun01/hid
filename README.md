# hid
## Programas de cálculo sobre mecánica de fluidos e hidráulica
Escritos en C y en python
----
Programas de cálculos hidráulicos escritos en C, para funcionar con argumentos de entrada y devuelve los valores en unidades del SI (Sistema Internacional de Medidas).   El objetivo es poder ser usados en línea de comando a través del su uso en scripts de bash.

* fDW : obtiene el valor del factor de fricción de la ecuación de Darcy-Weisbach a partir del diámetro de la tubería en [mm], el caudal en [l/s], la rugosidad en [mm] y la viscosidad en [m2/s]
* hf : calcular las pérdidas de carga en [m] a partir del diámetro, longitud y rugosidad de la tubería en [mm], [m] y [mm] respectivamente; y el factor de fricción de la ecuación de Darcy Weisbach
* hl : calcular las perdidas locales de carga a partir de los datos de coeficiente de pérdidas y velocidad de flujo en una tubería
* vmax : calcular de la velocidad máxima de flujo en una tubería a partir de la carga topográfica disponible, diámetro, longitud, rugosidad, coeficiente de pérdidas locales y viscosidad del flujo.
