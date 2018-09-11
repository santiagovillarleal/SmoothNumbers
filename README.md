# SmoothNumbers
Programa feito en C para calcular o nivel de suavidade dun enteiro.
De momento o enteiro non pode ser maior que 2^63-1

Información números suaves/lisos:
https://es.wikipedia.org/wiki/N%C3%BAmero_liso

Referencia: Velocidade actual de factorización de 2^63-2: 27234 ms.

Compilación suaves.c:

gcc -Wall modulo.h modulo.c suaves.c -o suaves -lm

Compilación fact_fermat.c:

gcc -Wall modulo.h modulo.c fact_fermat.c -o fact_fermat -lm
