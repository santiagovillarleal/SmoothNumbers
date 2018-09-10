#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void uso(char *prog)
{
  printf("%s <N>\n", prog);
}

int es_primo(unsigned int n)
{
  unsigned int i = 0;
  for (i = 2; i<n;i++)
  {
    if (!(n%i))
    {
      return FALSE;
    }
  }
  return TRUE;
}


unsigned int p_suave(unsigned long long n)
{
  unsigned int i = 2, p=0, prim=TRUE;
  unsigned long long j = n;
  do
  {
    if (es_primo(i))
    {
      if (!(j%i)) //j divisor de i
      {
        j /= i;
        if (prim)
        {
          printf("%u", i);
          prim=FALSE;
        }
        else
        {
          printf(",%u", i);
        }
        if (i>p) p=i;
        i = 2;
      }
      else
      {
        i++;
      }
    }
    else
    {
      i++;
    }
  }
  while (j != 1);
  printf("\n");
  return p;
}

int main(int argc, char *argv[])
{
  unsigned int p=0;
  unsigned long long n = 0;
  if (argc != 2)
  {
    uso(argv[0]);
    return -1;
  }
  n = atoll(argv[1]);
  printf("n=%llu\n",n);
  p=p_suave(n);
  printf("%llu é %u-suave.\n", n, p);

  return 0;
}

