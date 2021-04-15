# R2D2 automatizado

_Programa para dar vida a un R2D2 con sonido, luces, movimiento y melodías_

Link de YouTube cons instrucciones de montaje, programación y funcionamiento :  https://youtu.be/6vW1G448bJM


![R2D2](https://github.com/OscarCalero/R2D2_animado/blob/main/R2D2.png?raw=true)

## Que es...
Mediante un procesador ATmega168 o ATmega328p podemos hacer que nuestro R2D2 hable, emita luces, gire y ande. También puede reproducir melodías pre-grabadas, y todo ello desde un mando a distancia. Una vez programado, se le pueden cambiar los códigos de los mándos y las melodias por puerto serie.

Podemos utilizar solo el sonido y hacer una caja de música, CON o SIN luz, u otra figura que deseemos. Y prodríamos optar por ponerle solo el servo o completarlo con los dos motores.


## Instrucciones...

Referiros al video para ver como se fabrica, pero aquí teneis algunas nociones para programarlo por el puerto serie.

Las instrucciones 'song' y 'end' nos permiten grabar una melodía.

En un ATmega328 puedes enviar los códigos de 10 en 10 (o incluso más), pero en ATmega168 de 5 en 5 por su falta de memoria dinámica.

Este es un ejemplo, donde con 'song1' le decimos al sistema que introducimos la melodía 1 y con 'end' le comunicamos que hemos terminado.

```
song1 T49 5R156 4D12 T0 5L1081 4D101 end 
```

Las instrucciones 'altON' y 'altOFF', activan y desactivan respectivamente por el serial, los códigos RF secundarios introducidos. Ejemplo para activar:
```
altON
```
Y para desactivar:
```
altOFF
```

La instrucción RF nos permite introducir el código del mando para hacer funcionar el R2D2 a distancia.
Este ejemplo asocia el código RF XXXXXX al registro 0 (movimiento de cabeza y sonido de R2D2)
```
rf0 XXXXXX 
```

Estos son los registros disponibles:
```
rf0 - Sonido R2D2
rf1 - Rueda Izquierda
rf2 - Rueda derecha
rf3 - Ambas ruedas
rf4 - Melodía 1
rf5 - Melodía 2
rf6 - Melodía 3
```

Y para la versión de procesador ATmega 328p:
```
rf7 – Melodía 4
rf8 – Activación/Desactivación de códigos secundarios
rf9 - Sonido R2D2 2 (código secundario)
rf10 - Rueda Izquierda 2 (código secundario)
rf11 - Rueda derecha 2 (código secundario)
rf12 - Ambas ruedas 2 (código secundario)
rf13 - Melodía 1 (código secundario)
rf14 - Melodía 2 (código secundario)
rf15 - Melodía 3 (código secundario)
rf16 - Melodía 4 (código secundario)
```

## Como crear una melodía:
songX  = Inicio de meloria, donde X es la melodía de 1 a 4

TX = Tiempo de silencio después las notas siguientes, donde X es un número de 0 a 5500 ( mS ) –redondeado-

XYZ = nota donde X = octava de 0 a 9, Y = letra que representa la nota según descripción abajo y Z es la duración de la nota de 1 a 4004  (mS) –redondeado-

end  = Finalización de melodía

Ejemplo:
```
song1 T49 5R156 4D12 T0 5L1081 4D101 end 
```

### Codificación de notas
```
D = Do
d = Do#
R = Re
r = Re#
M = Mi
F = Fa
f = Fa#
S = Sol
s = Sol#
L = La
l = La#
I = Si
```

### Redondeo de los tempos
Los 'tempos' de silencio serán redondeados, entre 5 y 20 mS, y los 'tempos' de las notas a estos 20 valores en mS:
```
49	
62 Semi-fusa
79	
99	
125 Fusa
158	
198	
250 Semi-corchea
315	
397
500 Corchea
630	
794	
1001 Negra
1261	
1589	
2002 Blanca
2522	
3178	
4004 Redonda
```

### Que ocupa una melodía?
1 byte cada nota

2 byte por cada cambio de silencio

1 byte cada cambio de octava

1 byte al final de melodía

### Espacio en bytes para las melodías
Lo prodrás ver en el código, y puedes cambiar la posición de inicio de los punteros de memoria, para dar más capacidad de bytes a una melodía u otra. Pero antes que grabar el programa en el ATmega, porque no es modificable por puerto serie.

Ejemplo del ATmega328p:
```
// 952 byte para melodias
const byte punteroEE_M1 = 72; // dirección melodía 1 (238 bytes)
const int punteroEE_M2 = 310; // dirección melodía 2 (238 bytes)
const int punteroEE_M3 = 548; // dirección melodía 3 (238 bytes)
const int punteroEE_M4 = 786; // dirección melodía 4 (238 bytes)
```

### Disfruta...

Oscar


