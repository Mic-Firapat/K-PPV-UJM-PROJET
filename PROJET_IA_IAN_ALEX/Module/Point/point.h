#ifndef POINT_H
#define POINT_H

#include "../necessaire.h"


typedef struct point {
  float x; /*Entre -1 et 1*/
  float y; /*Entre -1 et 1*/
  int classe;
} Point;


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

void affiche_points(int n, Point *t, MLV_Color c[], char s[]);
    
#endif
