#include <stdlib.h>
#include <stdio.h>
#include "hachage.h"

int main()
{ struct annuaire *an = creer();
  afficher_annuaire(an);
  inserer(an,"Vivien", "0125");
  return 0;
}
