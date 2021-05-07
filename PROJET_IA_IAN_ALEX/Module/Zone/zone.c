
#include <stdlib.h>
#include <stdio.h>
#include "zone.h"


Zone_clic creer_zone_val(int xo, int yo, int xf, int yf){
  Zone_clic newz = malloc (1 * sizeof(Zone_clic));
  newz->origine.x = xo;
  newz->origine.y = yo;
  newz->final.x = xf;
  newz->final.y = yf;

  return newz;
}


void affiche_zone(Zone_clic z){
  printf("Ox -> %d\nOy -> %d\nFx -> %d\nFy -> %d\n\n",z->origine.x,z->origine.y,z->final.x,z->final.y);
}
