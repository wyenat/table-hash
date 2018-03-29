#include "hachage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Les fonctions ajoutées sont expliquées dans le hachage.h */

struct annuaire *creer()
{  struct annuaire *an = malloc(10*sizeof(struct personne));
  for (uint8_t i=0; i<=10; i++) {
    char nom[50] = "Pas de nom";
    char num[50] = "Pas de num";
    an->ann[i] = initial(nom, num);
  }
return an;
}

/*
void liberer(struct annuaire *an) {
}
*/

void afficher_personne(struct personne *pers)
{ printf("COQUIN \n");
  printf("Nom : %s \t Numéro : %s \n", pers->nom, pers->num);
}

int hachage(char *num)
{ int indice_courant = 0;
  uint32_t hash = 5381;
  char chara_courant = num[indice_courant];
  while (chara_courant != '\0') {
      hash = hash*33 + chara_courant;
      indice_courant++;
      chara_courant = num[indice_courant];
  }
  return hash;
}

struct personne *initial(char nom[50], char num[50])
{ //struct personne *init = malloc(sizeof(struct personne));
  char *nomen = malloc(50);
  nomen = strncpy(nomen, nom, 50);
  char *numen = malloc(50);
  numen = strncpy(numen, num, 50);
  printf(" Nomen = %s \n", nomen);
  /*init->nom = nomen;
  init->num = numen;
  init->suiv = init;*/
  struct personne *init = (struct personne *){nomen, numen, init};
  return init;
}

/* const char *inserer(struct annuaire *an, const char *nom, const char *numero)
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
  pers->nom = *nomc;
  pers->num = *numc;
  //Fin : couple (nom, numéro) passé dans personne
  int cle = hachage(nomc)%10;
  an->ann[atoi(numc)] = pers;
} */
/*


const char *rechercher_numero(struct annuaire *an, const char *nom)
{
}


void supprimer(struct annuaire *an, const char *nom)
{
}
*/
