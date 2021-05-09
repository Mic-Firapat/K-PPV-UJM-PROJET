#include "sauvegarde.h"

void sauvegarde_fichier(Point *t, char *nom_fichier, int n, int nbclasses){
    FILE *fichier = NULL;
    int i;
    /*Ouverture du fichier*/
    fichier = fopen(nom_fichier, "w+");
    if (fichier == NULL){
      fprintf(stderr,"Impossible d'ouvrir %s\n",nom_fichier);
    }
    else {
        /*Ecriture dans le fichier*/
        fprintf(fichier,"%d %d %d\n",n, 2 , nbclasses);
        for (i=0; i < n; i++){
            fprintf(fichier,"%d %f %f\n", t[i].classe, t[i].x, t[i].y);
        }
        fclose(fichier);
    }
    
}
