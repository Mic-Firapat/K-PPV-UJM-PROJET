#include "point.h"

extern int WIDTH;
extern int HEIGHT;

void pxtopoint(Point *p,int x, int y){
  /*x,y position du clic dans toute la fenêtre
    Change les coordonnees du point pour qu'elles collent avec le clic*/
  double largeur_grille= WIDTH/2. - WIDTH/100., hauteur_grille= HEIGHT/1.15 - HEIGHT/10.;
  x = x - WIDTH / 100;
  y = y - HEIGHT / 10;
  p->x = (2. / largeur_grille) * x - 1.;
  p->y = (2. / hauteur_grille) * y - 1.;
}

Point * creer_point(){
    Point *p = malloc(sizeof(Point));
    return p;
}

Point *init_point(float x, float y, int classe){
    Point *p = creer_point();
    p->x = x;
    p->y = y;
    p->classe = classe;
    return p;
}

Coord *coordtopx(Point *p){
/*Renvoie les coordonnées en pixels auquelles on doit afficher le point dans le fenêtre*/
    Coord *c = malloc(sizeof(Coord));
    double largeur_grille= WIDTH/2. - WIDTH/100., hauteur_grille= HEIGHT/1.15 - HEIGHT/10.;
    c->x = (p->x + 1) * (largeur_grille / 2.) + WIDTH / 100;
    c->y = (p->y + 1) * (hauteur_grille / 2.) + HEIGHT / 10;
    return c;
}

float dist(Point *p1, Point *p2){
    /*Renvoie la distance entre deux points avec un flottant qui a donc une valeur maximale de sqrt(8)*/
    return sqrt( pow(p2->x - p1->x,2) + pow(p2->y - p1->y,2));
}

float distpx(Point *p1, Point *p2){
    /*Renvoie la distance entre deux points avec un flottant mais en pixels pour l'affichage du cercle*/
    Coord *c1 = coordtopx(p1);
    Coord *c2 = coordtopx(p2);
    return sqrt( pow(c2->x - c1->x,2) + pow(c2->y - c1->y, 2));
}

