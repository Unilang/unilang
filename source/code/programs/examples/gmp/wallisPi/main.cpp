/**
   @brief     Approximate Pi via a beautiful, but inefficient, formula.@EOL
   @Keywords  none
   @Std       C89

              This program computes pi, quite inefficiently, using a
              wonderful Wallis formula (Wells 1986).  This is a great
              example of a beautiful formula leading to a horribly
              inefficient algorithm. :) Still, the point is to
              demonstrate GMP, not good mathematical algorithm design.
              Take a look at gmp-chudnovsky.c at the GMP site (last
              known URL: http://www.swox.com/gmp/pi-with-gmp.html) for
              a much more robust way to compute pi to many digits.


              Our formula:

              $$ %% Begin TeX/LaTeX
              \frac{\pi}{4} = 
              \prod_{n=1}^\infty\left[\frac{(2n)^2}{(2n-1)(2n+1)}\right] = 
              \prod_{n=1}^\infty\left[\frac{4\cdot n^2}{4n^2-1}\right] = 
              \frac{1\cdot2}{1\cdot3}\frac{4\cdot4}{3\cdot5}\frac{6\cdot6}{5\cdot7}\cdots
              $$ %% End TeX/LaTeX
   
              Mathematica Notation
              In[1]:= 2*Product[4*n^2/(4*n^2 - 1), {n, 1, Infinity}]
              Out[1]= Pi
*/

#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <gmp.h>                /* GNU GMP Library       */

int main(void) {
  mpz_t t, b;
  mpf_t p, tf, bf;
  int n;
  mpz_t n2, n2m1, n2p1;

  // Set up our floating point numbers
   mpf_set_default_prec(1000);
   mpf_init(p);
   mpf_init(tf);
   mpf_init(bf);

  // Compute the top and bottom of the fraction
  mpz_init_set_si(t,     1);
  mpz_init_set_si(b,     1);
  mpz_init_set_si(n2,    0);
  mpz_init_set_si(n2m1, -1);
  mpz_init_set_si(n2p1,  1);
  for(n=1; n<1000; n++) {
    mpz_add_ui(n2,   n2,   2); // 2*n
    mpz_add_ui(n2m1, n2m1, 2); // 2*n-1
    mpz_add_ui(n2p1, n2p1, 2); // 2*n+1
    mpz_mul(t, t, n2);
    mpz_mul(t, t, n2);
    mpz_mul(b, b, n2m1);
    mpz_mul(b, b, n2p1);
  } /* end for */

  // Compute the fraction value
   mpz_mul_ui(t, t, 2);
   mpf_set_z(tf, t);
   mpf_set_z(bf, b);
   mpf_div(p, tf, bf);

   printf("aprox pi: ");
   mpf_out_str(NULL, 10, 20, p);
   printf("\n");

   /* Print out a few digits of the real thing */
   mpf_set_str(p, "3.14159265358979323846264338327950288419716939937510582097494459230", 10);
   printf("real  pi: ");
   mpf_out_str(NULL, 10, 20, p);
   printf("\n");

   return 0;
} /* end func main */