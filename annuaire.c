#include <stdlib.h>
#include <stdio.h>
#include "hachage.h"

int main()
{ printf("test \n");
  char nom[50] = "Papa";
  char num[50] = "0012";
  printf("%lu \n", sizeof(nom));
  struct personne *pers = initial(nom, num);
  printf("Hihih");
  afficher_personne(pers);
  struct annuaire *an = creer();
  for (uint8_t i=0; i<=10; i++) {
    printf("%s 1 \n", an->ann[i]->nom);
  }
  return 0;
}
