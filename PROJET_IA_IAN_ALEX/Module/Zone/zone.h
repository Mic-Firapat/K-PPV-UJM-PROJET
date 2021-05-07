#ifndef H_ZONE
#define H_ZONE

#include "../necessaire.h"

typedef struct zone_clic {
  Coord origine;
  Coord final;
} * Zone_clic;


Zone_clic creer_zone_val(int xo, int yo, int xf, int yf);

void affiche_zone(Zone_clic z);

#endif
