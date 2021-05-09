#ifndef POINT_H
#define POINT_H

#include "../necessaire.h"


typedef struct point {
  float x; /*Entre -1 et 1*/
  float y; /*Entre -1 et 1*/
  int classe;
} Point;

void affiche_points (int n, Point *t, MLV_Color c[], char s[]);
/*Affiche les points*/

void pxtopoint(Point *p, int x, int y);
/*x,y position du clic dans toute la fenêtre
    Change les coordonnees du point pour qu'elles collent avec le clic*/

Point *creer_point();

Point *init_point(float x, float y, int classe);

Coord *coordtopx(Point *p);
/*Renvoie les coordonnées en pixels auquelles on doit afficher le point dans le fenêtre*/

float dist(Point *p1, Point *p2);
/*Renvoie la distance entre deux points avec un flottant qui a donc une valeur maximale de sqrt(8)*/

float distpx(Point *p1, Point *p2);
/*Renvoie la distance entre deux points avec un flottant mais en pixels pour l'affichage du cercle*/

Point *ajout_point_tab(Point *t, Point *p, int *n);
/*Ajoute un point p à la fin du tableau t en allouant la mémoire de manière dynamique. n est la taille du tableau qui est incrémentée automatiquement
SURTOUT PAS INCREMENTER N EN DEHORS DE CETTE FONCTION
Renvoie t*/

Point *retrait_point_tab(Point *t, int *n);
/*Retire le dernier point du tableau t et réalloue la mémoire nécessaire au tableau t
n = taille du tableau avant retrait
Retourne la tableau t ET PAS LE POINT ENLEVE
Décrémente la valeur de n automatiquement
SURTOUT PAS DECREMENTER N EN DEHORS*/

int *k_voisins(Point *t, Point *p, int k, int n);
/*Renvoie un tableaux d'entiers contenant les indices des k-PPV du point p dans le tableau t
le premier élément du tableau correspond à l'indice du voisin le plus éloigné. Utilisé pour tracer le cercle
Si p est déjà dans le tableau t, il est ignoré dans les voisins
n = taille du tableau t (p compris si il s'y trouve)*/

int classe_majoritaire(Point *t, int *voisins,int k, int nbclasses);
/*Renvoie la classe majoritaire des k-voisins
  voisins doit être généré par k_voisins
  Suppose que la classe est entre 1 et nbclasses (inclus)*/
#endif
