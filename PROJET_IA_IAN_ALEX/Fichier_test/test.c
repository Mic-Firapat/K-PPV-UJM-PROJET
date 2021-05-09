#include "../Module/Menu/menu.h"
#include "../Module/Point/point.h"
#include "../Module/Zone/zone.h"
#include "../Module/Lecture/lecture.h"
#include "../Module/Sauvegarde/sauvegarde.h"

/*Pour tester tes fonctions sur la struct point */

/*Taille fenêtre*/
int WIDTH=640, HEIGHT=480;

int main(){

  /*TEST POINTS */
  Point *p = creer_point();
  Coord *c;
  Point *pp = creer_point();
  double largeur_grille= WIDTH/2. - WIDTH/100., hauteur_grille= HEIGHT/1.15 - HEIGHT/10.;

  /*TEST ZONE */
  Zone_clic test;
  Coord ori, fin;

  /*TEST LECTURE*/
  char *fichier = "Sauvegardes/fichier_test_1";
  char *blob = "Sauvegardes/blobs.txt";
  Point *t = NULL;
  Point *tb = NULL;
  int nbclasses = 0,n,i, nbclassesb = 0,nb;

  /*TEST SAUVEGARDE*/
  char *sauve = "Sauvegardes/sauv_test";


  /*POINTS */

  printf("-----\nTest sur les Points\n-----\n");

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

  /*ZONE */
  ori.x = 10;
  ori.y = 20;
  fin.x = 50;
  fin.y = 100;
  
  printf("TEST de la struct Zone_clic et de leur allocation mem\n");
  test = creer_zone_val(ori.x,ori.y,fin.x,fin.y);
  affiche_zone(test);
  free(test);

  /*LECTURE */

  printf("----------\nTest Lecture Fichier\n----------\n");

  t = chargement_fichier(fichier, &n, &nbclasses);
  printf("%d %d\n",n,nbclasses);
  
  for (i=0; i < n; i++){
      printf("%d %f %f\n",t[i].classe, t[i].x, t[i].y);
  }

  printf("----------\nTest sauvegarde Fichier\n----------\n");

  sauvegarde_fichier(t, sauve, n, nbclasses);


  /*TEST FICHIER .txt  */

  printf("-----------\nTest lecture fichier blob\n");

  tb = chargement_fichier(blob, &nb, &nbclassesb);

  if(tb != NULL){
    printf("%d %d\n",nb,nbclassesb);
  
    for (i=0; i < nb; i++){
      printf("%d %f %f\n",tb[i].classe, tb[i].x, tb[i].y);
    }
  }


  printf("----------\nTest sauvegarde Fichier\n----------\n");

  sauvegarde_fichier(t, sauve, nb, nbclassesb);


  exit(1);
}
