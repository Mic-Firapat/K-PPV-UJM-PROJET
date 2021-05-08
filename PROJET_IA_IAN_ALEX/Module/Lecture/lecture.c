#include "lecture.h"

Point *chargement_fichier(char *nom_fichier, int *n, int *nbclasses){
    /*Renvoie le tableau de points t si lecture des données réussie et NULL sinon. Modifie le contenu de l'entier n (nombre de points) et de nbclasses
     Attention, le nom_fichier est le chemin menant au fichier à partir du répertoire de l'exécutable*/
    int dimensions,i;
    /*dimensions ne sert à rien mais si on veut gérer les dimensions plus tard voilà*/
    FILE *fichier = NULL;
    Point *t = NULL;

    /*Ouverture du Fichier*/
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL){
        printf("Ouverture du fichier ratée\n");
        return NULL;
    }

    /*Lecture de la première ligne : nombre de points, dimensions et nombre de classes*/
    if (fscanf(fichier, "%d %d %d\n",n, &dimensions, nbclasses) != 3){
        printf("Lecture de la première ligne (n dimensions nbclasses) ratée\n");
        fclose(fichier);
        return NULL;
    }

    /*Remplissage du tableau de Points*/
    t = malloc(sizeof(Point) * (*n));
    for (i=0; i < *n; i++){
        if (fscanf(fichier, "%d %f %f\n", &(t[i].classe), &(t[i].x), &(t[i].y)) != 3){
            printf("Lecture d'une ligne de données sur un point ratée");
            fclose(fichier);
            return NULL;
        }
    }

    /*Fermeture du fichier et renvoi du tableau*/
    fclose(fichier);
    return t;

}
