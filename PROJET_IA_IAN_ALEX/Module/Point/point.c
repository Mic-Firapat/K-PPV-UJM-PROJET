#include "point.h"

void pxtocoord(Point *p,int x, int y){
  /*x,y position du clic dans toute la fenêtre
  Change les coordonnees du point pour qu'elles collent avec le clic*/
  Point p;
  double largeur_grille= WIDTH/2 - WIDTH/100, hauteur_grille= HEIGHT/1.15 - HEIGHT/10;
  x = x - width_ecran / 100;
  y = y - height_ecran / 10;
  p->x = (2. / largeur_grille) * x - 1.
  p->y = (2. / hauteur_grille) * y - 1.
  return p 
}


