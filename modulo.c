#include "modulo.h"

#define ERR_USO -1
#define TRUE 1
#define FALSE 0

unsigned int es_cuadrado_perfecto(unsigned long long n)
{
  unsigned long long int raiz_n = 0;
  raiz_n = (unsigned long long int)sqrtl(n*1.0);
  return (raiz_n*raiz_n-n==0);
}


//q tal que q^2>=n && (q-1)^2<n
//EQUIV (q-1)^2<n<=q^2
//EQUIV q-1<sqrt(n)<=q
//EQUIV q>=sqrt(n)>q-1
unsigned long long int obter_q(unsigned long long n)
{
  unsigned long long int raiz_n = 0, q = 0;
  raiz_n = (unsigned long long int)sqrtl(n*1.0);
  q= (!(n-raiz_n*raiz_n))?raiz_n:(raiz_n+1);
/*
  if ((q*q>=n)&&((q-1)*(q-1)<n))
  {
    printf("n=%llu, q=%llu BEN\n",n,q);
  }
  else
  {
    printf("MAL:\n");
    printf("%llu^2 %s %llu\n",raiz_n,(q*q>=n)?">=":"<", n);
    printf("%llu^2 %s %llu\n",raiz_n-1, (q-1)*(q-1)<n?"<":">=",n);
  }
*/
  return q;
}

unsigned int es_primo_fermat(unsigned long long int n) //n impar
{
  unsigned long long int q = 0, m = 0, x_2 = 0, x = 0, lim_sup_bucle = 0, fact1 = 0, fact2 = 0;
  unsigned int res = TRUE;
  lim_sup_bucle = (n+1)/2;

  if (!(n%2)) lim_sup_bucle++;
  q = obter_q(n);

  for (m=q; m<lim_sup_bucle;m++)
  {
    x_2 = m*m-n;
    if (es_cuadrado_perfecto(x_2))
    {
      x = (unsigned long long int)sqrtl(x_2*1.0);
      res = FALSE;
      fact1 = m+x;
      fact2 = m-x;
      printf("%llu = %llu*%llu\n",n,fact2,fact1);
      break;
    }
  }
  return res;
}

unsigned int lista_baleira(unsigned long long int *lista)
{
  return ((!lista)||!(lista[0]));
}

unsigned int esta_en_lista_fact(unsigned long long int n, unsigned long long int *lista_fact)
{
  if (lista_baleira(lista_fact)) return FALSE;
  for (unsigned int i=0;lista_fact[i]&&(i<TAM_LISTA_INIT);i++)
  {
    if (lista_fact[i]==n) return TRUE;
  }
  return FALSE;
}

unsigned int es_primo(unsigned long long int n, unsigned long long int *lista_fact)
{
  unsigned long long int i = 0, lim_criba = 0;
  if (esta_en_lista_fact(n, lista_fact)) return TRUE;
  lim_criba = (unsigned long long int)sqrtl(n * 1.0);
  for (i = 2; i<lim_criba;i++)
  {
    if (!(n%i))
    {
      return FALSE;
    }
  }
  return TRUE;
}

