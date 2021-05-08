
#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "../necessaire.h"
#include "../Point/point.h"

void sauvegarde_fichier(Point *t, char *nom_fichier, int n, int nbclasses);
/*Sauvegarde les données dans un fichier nom_fichier.
  Attention ! Ecrase le contenu de nom_fichier si il existe déjà et le crée sinon
  n = nombre de points du tableau de Points t
  nbclasses = nombre de classes de points possibles
  nom_fichier doit être le chemin du fichier depuis l'executable. De préférence on enregistre dans le dossier Sauvegardes/
*/


#endif

