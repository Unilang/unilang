#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "getch.hpp"

t_key keys[] = {
  {"[A", K_UP},
  {"[B", K_DOWN},
  {"[D", K_LEFT},
  {"[C", K_RIGHT},
  {NULL, K_UNK},
};

int     main()
{
  int       key;

  ch_init();
  while ((key = ch_get(keys)) != K_BACK)
    {
      printf("%d\n", key);
    }
  ch_end();
  return (EXIT_SUCCESS);
}