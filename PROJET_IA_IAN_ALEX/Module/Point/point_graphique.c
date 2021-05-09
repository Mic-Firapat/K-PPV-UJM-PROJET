#include "point.h"


void affiche_points (int n, Point *t, MLV_Color c[], char s[]){
  int i;
  Coord *af_pt;
  
  for(i=0;i<n;i++){
    if(t[i].classe != 0){
      af_pt = coordtopx(&(t[i]));
      MLV_draw_text(af_pt->x,
		    af_pt->y,
		    "%c",
		    c[t[i].classe],
		    s[t[i].classe]);
    }
  }

  MLV_update_window();
}
