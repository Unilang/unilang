/**
   @brief     General implementation of an LCG with GMP.@EOL
   @Keywords  none
   @Std       C89

              General implementation of an LCG (Linear Congruential
              Generator) utilizing the simplest of algorithms, but
              making use of GMP to avoid overflow.

              GMP can be a powerful tool allowing the algorithm
              designer to focus on the algorithm in the early phases
              of algorithm design, and avoid the the vulgarities of
              machine arithmetic during this "deep thought" phase of
              development.  The designer is then free, after getting
              the algorithm to work, to focus on efficiency issues.

              Imagine for a moment that we had just discovered the
              LCG, and wanted to explore the algorithm.  Yes, several
              ways exist to implement specialized LCGs with 32-bit
              signed arithmetic; however, GMP allows us to use a
              straight forward algorithm right out of the gate.  We
              could test our new algorithm out without being forced to
              set down and think about how to implement the thing in
              32-bit arithmetic.  When we were done testing, we could
              then work on an optimal 32-bit implementation and use
              our GMP prototype to verify that our new and improved
              32-bit algorithm actually was correct.
*/

#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <gmp.h>                /* GNU GMP Library       */

int main (void) {
  int               i;          /* Loop variable                 */
  mpz_t             randNumMPZ; /* For intermediate computations */
  unsigned long int randNumINT; /* For final computation results */

  /* Set the constants for the minimal standard LCG */
  const unsigned int M = 2147483647;
  const unsigned int A = 16807;
  const unsigned int B = 0;
  const unsigned int S = 1;

  /* Set initial seed */
  mpz_init_set_ui(randNumMPZ, S);

  printf( "10 numbers from LCG(%d, %d, %d, %d):\n", M, A, B, S);
  for ( i = 0; i < 10; i++ ) {
    /* Compute: randNumMPZ = (A*randNumMPZ+C)%M */
    mpz_mul_si(randNumMPZ, randNumMPZ, A);
    mpz_add_ui(randNumMPZ, randNumMPZ, B);
    randNumINT = (unsigned long int)mpz_mod_ui(randNumMPZ, randNumMPZ, M);
    printf( "%12lu\n", randNumINT);
  } /* end for */

  return 0;
} /* end func: main */