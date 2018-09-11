#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERR_USO -1
#define TRUE 1
#define FALSE 0

void uso(char *prog)
{
  printf("Uso: %s <N>\n", prog);
}

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

unsigned int es_primo(unsigned long long int n) //n impar
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

int main(int argc, char *argv[])
{
  unsigned long long int n = 0;
  unsigned int res = TRUE;
  if (argc != 2)
  {
    uso(argv[0]);
    exit(ERR_USO);
  }
  n = (unsigned long long int)atoll(argv[1]);
  if (!(n%2)) //n par
  {
    if (n!=2) res = FALSE;
    printf("%llu = 2*%llu\n",n,n/2);
  }
  else
  {
    res = es_primo(n);
  }
  printf("%llu é primo? %s\n",n,res?"Si":"Non");

  //printf("n=%llu, q=%llu\n",n,q);
  return 0;
}
