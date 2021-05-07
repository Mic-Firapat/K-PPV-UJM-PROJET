#include "../necessaire.h"
#include "../Zone/zone.h"


int event_menu(Zone_clic tab[], int px, int py){
  int i;

  for(i=0;i<TAB_MAX;i++){
    if(tab[i]->origine.x == 0 && tab[i]->origine.y == 0 && tab[i]->final.x == 0 && tab[i]->final.y == 0){
      break;
    }
    else{
      if((tab[i]->origine.x <= px && tab[i]->origine.y <= py) &&(tab[i]->final.x >= px && tab[i]->final.y >= py) ){
	return i;
      }	     
    }
  }

  return -1;
}
