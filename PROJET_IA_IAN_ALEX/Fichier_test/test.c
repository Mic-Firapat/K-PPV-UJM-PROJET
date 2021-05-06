#include "../Module/Menu/menu.h"
#include "../Module/Point/point.h"

/*Pour tester tes fonctions sur la struct point */

int main(){

    Point *p = creer_point();
    Coord *c;
    Point *pp = creer_point();
    double largeur_grille= WIDTH/2. - WIDTH/100., hauteur_grille= HEIGHT/1.15 - HEIGHT/10.;
    pxtopoint(pp, WIDTH/100 + 3 * largeur_grille/4. , HEIGHT/1.15);
    p->x = -0.5;
    p->y = 1;
    p->classe = 666;
    c = coordtopx(p);
    printf("%f\n%f\n%d\n",pp->x,pp->y,p->classe);
    printf("-----\n%d\n%f\n",WIDTH/100 + (WIDTH/2 - WIDTH/100)/2, HEIGHT/1.15);
    printf("%d\n%d\n",c->x,c->y);
    printf("%f\n",dist(p,pp));
    printf("%f\n",sqrt(8));
    exit(1);
}
