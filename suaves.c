#include <malloc.h>
#include <errno.h>
#include "modulo.h"
#include <sys/time.h>

void uso(char *prog)
{
  printf("%s <N>\n", prog);
}

void limpar_lista_fact(unsigned long long int *lista)
{
  for (int k=0;lista[k]&&(k<TAM_LISTA_INIT);k++) lista[k]=0;
}

void imprimir_lista_fact(unsigned long long int *lista)
{
  unsigned int i=0;
  if (lista_baleira(lista))
  {
    printf("Lista baleira.\n");
    return;
  }
  printf("%llu",lista[0]);
  for (i=1;lista[i]&&(i<TAM_LISTA_INIT);i++) printf(",%llu",lista[i]);
  printf("\n");
}

void fact(unsigned long long int n, unsigned long long int *lista_fact)
{
  unsigned int tam_act_lista=0;
  unsigned long long j = n, i = 2;

  limpar_lista_fact(lista_fact);

  do
  {
    if ((!(j%i))&&(es_primo(i, lista_fact))) //j divisor de i && i primo //MUI EFICIENTE
    //if ((!(j%i))&&(es_primo_fermat(i))) //j divisor de i && i primo //MUI EFICIENTE
    {
      j /= i;
      lista_fact[tam_act_lista++]=i;
      //printf("%llu\n",i);
      if (tam_act_lista==TAM_LISTA_INIT)
      {
        printf("ERROR: vai desbordar a lista de primos.\n");
        exit(ERR_LIST_PRIM_OVERFLOW);
      }
      //i = 2;
    }
    else
    {
      i++;
    }
  }
  while (j != 1);
}

unsigned int p_suave(unsigned long long int *lista_fact)
{
  unsigned int i=0, p=0;
  if (lista_baleira(lista_fact))
  {
    printf("p_suave: Lista baleira.\n");
    return p;
  }
  for (i=0;lista_fact[i]&&(i<TAM_LISTA_INIT);i++)
  {
    if (lista_fact[i]>p) p=lista_fact[i];
  }
  return p;
}

unsigned long long obter_num(char *num_str)
{
  unsigned long long int n = 0;
  //n = (unsigned long long int)atoll(num_str);
  n = (unsigned long long int)strtoull(num_str, NULL, 10);
  if (errno == ERANGE)
  {
    printf("%s non válido: fóra de rango.\n", num_str);
    exit(ERR_ERANGE);
  }
  return n;
}

long long int obter_tmstmp_msegundos(struct timeval t)
{
  gettimeofday(&t, NULL);
  return t.tv_sec*1000LL + t.tv_usec/1000;
}


int main(int argc, char *argv[])
{
  unsigned long long int p = 0, n = 0, *lista_fact=NULL;
  struct timeval t_tempo;
  long long int t_ini_msec = 0, t_fin_msec = 0, t_tot_msec = 0;

  if (argc != 2)
  {
    uso(argv[0]);
    return ERR_USO;
  }
  n = obter_num(argv[1]);
  lista_fact = (unsigned long long int *)malloc(TAM_LISTA_INIT*sizeof(unsigned long long int));
  t_ini_msec = obter_tmstmp_msegundos(t_tempo);
  fact(n, lista_fact);
  p=p_suave(lista_fact);
  t_fin_msec = obter_tmstmp_msegundos(t_tempo);
  t_tot_msec = t_fin_msec - t_ini_msec;
  imprimir_lista_fact(lista_fact);
  printf("%llu é %llu-suave.\n", n, p);
  printf("Tempo: %lli ms\n", t_tot_msec);
  free(lista_fact);
  return 0;
}

