#include "death_handler.h"

int main() {
  Debug::DeathHandler dh;
  int* p = NULL;
  *p = 0;
  return 0;
}