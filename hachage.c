#include "hachage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Les fonctions ajoutées sont expliquées dans le hachage.h */

struct annuaire *creer()
{  struct annuaire *an = malloc(sizeof(struct annuaire));
  char nom[50] = "Pas de nom";
  char num[50] = "Pas de num";
  an->ann = malloc(10*sizeof(struct personne));
  for (int i=0; i<=10; i++) {
  an->ann[i] = initial(nom, num);
}
return an;
}

/*
void liberer(struct annuaire *an) {
}
*/

void afficher_personne(struct personne *pers)
{  printf("Nom : %s \t Numéro : %s \n", pers->nom, pers->num);
  if (pers->suiv != pers) {
    struct personne *suivi = pers->suiv;
    afficher_personne(suivi);
  }
}

void afficher_annuaire(struct annuaire *an)
{ printf("Annuaire : \n");
  for (int i=0; i<=10; i++){
    printf("\t Clé numéro %d : \n", i);
    afficher_personne(an->ann[i]);
  }

}

int hachage(char *num)
{ int indice_courant = 0;
  int hash = 5381;
  char chara_courant = num[indice_courant];
  while (chara_courant != '\0') {
      hash = hash*33 + chara_courant;
      indice_courant++;
      chara_courant = num[indice_courant];
  }
  hash = -hash%10;
  return hash;
}

struct personne *initial(char nom[50], char num[50])
{ struct personne *init = malloc(sizeof(struct personne));
  char *nomen = malloc(50);
  nomen = strncpy(nomen, nom, 50);
  char *numen = malloc(50);
  numen = strncpy(numen, num, 50);
  *init->nom = *strncpy(init->nom, nom, 50);
  *init->num = *strncpy(init->num, num, 50);
  init->suiv = init;
  return init;
}

 const char *inserer(struct annuaire *an, const char *nom, const char *numero)
{  //Début : copie les chaînes de charactères passés en arguments
  size_t d_size = sizeof(nom);
  char nomc[d_size];
  strncpy(nomc, nom, d_size);
  nomc[d_size - 1] = '\0';
  size_t d_size2 =  sizeof(numero);
  char numc[d_size2];
  strncpy(numc, numero, d_size2);
  numc[d_size2 - 1] = '\0';
  //Fin : copie des chaînes de charactères passés en arguments
  struct personne *pers = initial(nomc, (char *) numero);
  int *cle = malloc(32);
  *cle = hachage(numc);
  if (strncmp(an->ann[*cle]->nom,"Pas de nom", 50)){
    pers->suiv = an->ann[*cle];
    an->ann[*cle] = pers;
    return "";
  } else {
    an->ann[*cle] = pers;
    return "NULL";

  }
}
/*


const char *rechercher_numero(struct annuaire *an, const char *nom)
{
}


void supprimer(struct annuaire *an, const char *nom)
{
}
*/
