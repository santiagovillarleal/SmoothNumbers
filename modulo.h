#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define TAM_LISTA_INIT 150

#define ERR_USO -1
#define ERR_LIST_PRIM_OVERFLOW -2
#define ERR_ERANGE -3

extern unsigned int es_cuadrado_perfecto(unsigned long long n);
extern unsigned long long int obter_q(unsigned long long n);
extern unsigned int es_primo_fermat(unsigned long long int n); //n impar
extern unsigned int lista_baleira(unsigned long long int *lista);
extern unsigned int esta_en_lista_fact(unsigned long long int n, unsigned long long int *lista_fact);
extern unsigned int es_primo(unsigned long long int n, unsigned long long int *lista_fact);
