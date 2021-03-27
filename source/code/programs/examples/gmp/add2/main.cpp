#include <stdio.h>          /* for printf */
#include <gmp.h>
 
int main(int argc, char *argv[])
{
  mpz_t a, b;                       /* working numbers */
  if (argc<3)
    {                   /* not enough words */
    printf("Please supply two numbers to add.\n");
    return 1;
  }
  mpz_init_set_str (a, argv[1], 10);    /* Assume decimal integers */
  mpz_init_set_str (b, argv[2], 10);    /* Assume decimal integers */
  mpz_add (a, a, b);            /* a=a+b */

  printf("%s + %s => %s\n", argv[1], argv[2], mpz_get_str (NULL, 10, a));
  return 0;
}