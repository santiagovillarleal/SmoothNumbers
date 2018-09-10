#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define TAM_LISTA_INIT 150
#define ERR_USO -1
#define ERR_LIST_PRIM_OVERFLOW -2
#define ERR_ERANGE -3

void uso(char *prog)
{
  printf("%s <N>\n", prog);
}

unsigned int lista_baleira(unsigned int *lista)
{
  return ((!lista)||!(lista[0]));
}

unsigned int esta_en_lista_primos(unsigned int n, unsigned int *lista_primos)
{
  if (lista_baleira(lista_primos)) return FALSE;
  for (int i=0;lista_primos[i]&&(i<TAM_LISTA_INIT);i++)
  {
    if (lista_primos[i]==n) return TRUE;
  }
  return FALSE;
}

unsigned int es_primo(unsigned int n, unsigned int *lista_primos)
{
  unsigned int i = 0;
  if (esta_en_lista_primos(n, lista_primos)) return TRUE;
  for (i = 2; i<n;i++)
  {
    if (!(n%i))
    {
      return FALSE;
    }
  }
  return TRUE;
}

void limpar_lista_primos(unsigned int *lista)
{
  for (int k=0;k<TAM_LISTA_INIT;k++) lista[k]=0x00000000;
}

void imprimir_lista_primos(unsigned int *lista)
{
  unsigned int i=0;
  if (lista_baleira(lista))
  {
    printf("Lista baleira.\n");
    return;
  }
  printf("%u",lista[0]);
  for (i=1;lista[i]&&(i<TAM_LISTA_INIT);i++) printf(",%u",lista[i]);
  printf("\n");
}

unsigned int *fact(unsigned long long n)
{
  unsigned int i = 2, *lista_primos = NULL, tam_act_lista=0;
  unsigned long long j = n;

  lista_primos = (unsigned int *)malloc(TAM_LISTA_INIT*sizeof(unsigned int));
  limpar_lista_primos(lista_primos);

  do
  {
    if ((!(j%i))&&(es_primo(i, lista_primos))) //j divisor de i && i primo //MUI EFICIENTE
    {
      j /= i;
      lista_primos[tam_act_lista++]=i;
      printf("%d\n",i);
      if (tam_act_lista==TAM_LISTA_INIT)
      {
        printf("ERROR: vai desbordar a lista de primos.\n");
        exit(ERR_LIST_PRIM_OVERFLOW);
      }
      i = 2;
    }
    else
    {
      i++;
    }
  }
  while (j != 1);
  return lista_primos;
}

unsigned int p_suave(unsigned int *lista_primos)
{
  unsigned int i=0, p=0;
  if (lista_baleira(lista_primos))
  {
    printf("p_suave: Lista baleira.\n");
    return p;
  }
  for (i=0;lista_primos[i]&&(i<TAM_LISTA_INIT);i++)
  {
    if (lista_primos[i]>p) p=lista_primos[i];
  }
  return p;
}

unsigned long long obter_num(char *num_str)
{
  unsigned long long n = 0;
  n = (unsigned long long)atoll(num_str);
  if (errno == ERANGE)
  {
    printf("%s non válido: fóra de rango.\n", num_str);
    exit(ERR_ERANGE);
  }
  return n;
}

int main(int argc, char *argv[])
{
  unsigned int p=0, *lista_primos=NULL;
  unsigned long long n = 0;

  if (argc != 2)
  {
    uso(argv[0]);
    return ERR_USO;
  }
  n = obter_num(argv[1]);
  lista_primos=fact(n);
  imprimir_lista_primos(lista_primos);
  p=p_suave(lista_primos);
  free(lista_primos);
  printf("%llu é %u-suave.\n", n, p);

  return 0;
}

