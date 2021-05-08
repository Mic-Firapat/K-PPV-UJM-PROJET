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

Point *ajout_point_tab(Point *t, Point *p, int *n){
    (*n)++;
    t = realloc(t, sizeof(Point) * (*n));
    t[(*n)-1] = *p;
    return t;
}

Point *retrait_point_tab(Point *t, int *n){
    if (n==0){
        return NULL;
    }
    (*n)--;
    t = realloc(t, sizeof(Point) * (*n));
    return t;
}


float *distances(Point *t, Point *p, int n){
    /*Fonction pas dans le .h*/
    /*Renvoie un tableau de flottant contenant les distances entres les points.
      Par exemple d[0] = dist(t[0],p)
    Fonction utilisée dans k_voisins()*/
    float *d = malloc(sizeof(float) * n);
    int i;

    for (i=0; i < n; i++){
        d[i] = dist( &(t[i]), p);
    }

    return d;
}


int *k_voisins(Point *t, Point *p, int k, int n){
    /*Ne surtout pas appeler avec un tableau de point vide ou un k inférieur à 1*/

    float *d = distances(t,p,n);
    int *voisins = malloc(sizeof(int) * (k+1));
    int i,j,taille_voisins = 0, imax=0;
    float dmax =  -1;
    for (i = 0; i < n ; i++){
        if (taille_voisins < k && d[i] != dist(p,p)){
            voisins[taille_voisins+1] = i;
            taille_voisins++;
            if (dmax < d[i]){
                dmax = d[i];
                imax = i+1;
            }
        }
        else {
            if (d[i] != dist(p,p)){
                if (dmax > d[i]){
                    voisins[imax] = i;
                    dmax = -1;
                    for (j = 1; j < k +1; j++){
                        if (dmax < d[voisins[j]]){
                            dmax = d[voisins[j]];
                            imax = j+1;
                        }
                    }
                }
            }
        }
    }
    voisins[0]=voisins[imax];
    return voisins;
}

int classe_majoritaire(Point *t, int *voisins, int k, int nbclasses){
    int *c = malloc(sizeof(int) * (nbclasses + 1));
    int i,cmax= 0,classe = 1;
    for (i = 1; i < nbclasses + 1; i++){
        c[i] = 0;
    }
    for (i=1;i < k+1; i++){
        c[t[voisins[i]].classe] = c[t[voisins[i]].classe];
    }
    for (i = 1; i < nbclasses + 1; i++){
        if (c[i] > cmax){
            cmax = c[i];
            classe = i;
        }
    }
    return classe;
}
