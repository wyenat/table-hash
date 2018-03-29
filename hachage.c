#include "hachage.h"
#include <stdio.h>
#include <stdlib.h>

struct annuaire *creer()
{ struct personne vide;
  vide.nom = "Pas de Nom";
  vide.num = "Pas de Num";
  vide.suiv = &vide;
  struct annuaire *an = malloc(10*sizeof(struct personne));
  for (uint8_t i=0; i<=10; i++) {
    an->ann[i] = &vide;
  }
return an;
}

/*
void liberer(struct annuaire *an) {
}
*/

int hachage(char *num)
{ int indice_courant = 0;
  uint32_t hash = 5381;
  char chara_courant = num[indice_courant];
  while (chara_courant != '\0') {
      hash = hash*33 + atoi(chara_courant);
      indice_courant++;
      chara_courant = num[indice_courant];
  }
  return hash;
}

struct personne *initial(char *nom, char *num)
{ struct personne *init = malloc(2 * sizeof(char) + sizeof(struct personne));
  char nomen = malloc(char[sizeof(nom)]);
}

const char *inserer(struct annuaire *an, const char *nom, const char *numero)
{ struct personne *pers = malloc(sizeof(struct personne));
  //Début : copie les chaînes de charactères passés en arguments
  size_t d_size = sizeof(nom);
  char nomc[d_size];
  strncpy(nomc, nom, d_size);
  nomc[d_size - 1] = '\0';
  size_t d_size2 =  sizeof(numero);
  char numc[d_size2];
  numc[d_size2 - 1] = '\0';
  //Fin : copie des chaînes de charactères passés en arguments
  //Début : couple (nom, numéro) passé dans personne
  pers->nom = nomc;
  pers->num = numc;
  //Fin : couple (nom, numéro) passé dans personne
  an->ann[atoi(numc)] = pers;
}
/*


const char *rechercher_numero(struct annuaire *an, const char *nom)
{
}


void supprimer(struct annuaire *an, const char *nom)
{
}
*/
