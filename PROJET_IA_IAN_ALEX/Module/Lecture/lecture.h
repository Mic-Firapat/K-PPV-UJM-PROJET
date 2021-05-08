#ifndef LECTURE_H
#define LECTURE_H

#include "../necessaire.h"
#include "../Point/point.h"

Point *chargement_fichier(char *nom_fichier, int *n, int *nbclasses);
/*Renvoie le tableau de points t si lecture des données réussie et NULL sinon. 
Modifie le contenu de l'entier n (nombre de points) et de l'entier nbclasses
Attention, le nom_fichier est le chemin menant au fichier à partir du répertoire de l'exécutable*/

#endif
