#include <stdio.h>


int main ()
{
  int i, nb, test;
  test =  0;
  printf ("Entrez un nombre entier : ");
  if (scanf ("%d", &nb) != 1)
    return -1;

  for (i = 2; i < nb; i++)
    if (nb % i == 0)
      test = 1;
  if (!test)
    printf ("%d est un nombre premier\n", nb);
  else
    printf ("%d n'est pas nombre premier\n", nb);
  return 0;
}
