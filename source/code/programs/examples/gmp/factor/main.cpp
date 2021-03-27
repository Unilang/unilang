/**
   @brief     Really dumb prime factor finder GMP example.@EOL
   @Keywords  none
   @Std       C89

              This program is intended to find the largest prime
              smaller than the SQRT of the given number.  The algorithm
              is the one most people try in grade school -- i.e. we test
              all odd numbers less than the SQRT for divisibility!  This
              program makes a good benchmark if the status printing is
              removed.
              
*/

#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <gmp.h>                /* GNU GMP Library       */

// 6005662386412099
// 600566238641209
// 3107418240490043721350750035888567930037346022842727545720161948823206440518081504556346829671723286782437916272838033415471073108501919548529007337724822783525742386454014691736602477652346609

int main(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  mpz_t m, n, p, k;
  int i,j;

  // Get the number to play with
  if(argc < 2) {
    printf("No argument provided, using built in number\n");
    mpz_init_set_str(m, "6005662386412099", 10);
  } else {
    mpz_init_set_str(m, argv[1], 10);
  }

  // Output the number we are working on
  printf("        m: ");
  mpz_out_str(stdout, 10, m);
  printf("\n");

  // Check for 2|m
  if(mpz_divisible_ui_p(m, 2)) {
    printf("FOUND p|m: 2\n");
    exit(1);
  }

  // Compute k=SQRT(M)
  mpz_init(k);
  mpz_sqrt(k, m);
  gmp_printf("  SQRT(m): %Zd\n", k);

  // 2|SQRT(M) => p=SQRT(M)+5, else p=SQRT(M)+4
  mpz_init(p);
  if(mpz_divisible_ui_p(k, 2)) {
    mpz_add_ui(p, k, 5);
  } else {
    mpz_add_ui(p, k, 4);
  }

  // Move DOWN from SQRT(m) by two looking for something that | m
  mpz_init(n);
  for(i=0,j=0;1 || i<10000000;i++) {
    // Subtract 2, and test for |.
    mpz_sub_ui(p, p, 2);
    if(mpz_divisible_p(m, p)) {
      gmp_printf("FOUND p|m: %Zd\n", p);
      if(mpz_cmp_ui(p, 1) == 0)
        printf("m was prime!\n");
      exit(1);
    }
    // Print status every 100K tests
    j++;
    if(j>100000) {
      j=0;
      mpz_sub(n, k, p);
      gmp_printf("  CHECKED: %Zd\n", n);
    }
  }


  // If we got here, then we didn't find the value..
  printf("No Factors Found\n");
  exit(0);

  return 0;
}