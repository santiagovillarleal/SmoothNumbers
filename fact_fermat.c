#include "modulo.h"

void uso(char *prog)
{
  printf("Uso: %s <N>\n", prog);
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
    res = es_primo_fermat(n);
  }
  printf("%llu é primo? %s\n",n,res?"Si":"Non");

  //printf("n=%llu, q=%llu\n",n,q);
  return 0;
}
