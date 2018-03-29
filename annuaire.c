#include <stdlib.h>
#include <stdio.h>
#include "hachage.h"

int main()
{ printf("test \n");
  struct annuaire *an = creer();
  for (uint8_t i=0; i<=10; i++) {
    printf("%c 1 \n", an->ann[i]->nom);
  }
  return 0;
}
