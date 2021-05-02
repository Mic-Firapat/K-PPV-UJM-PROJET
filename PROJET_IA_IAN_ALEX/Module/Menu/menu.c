#include "menu.h"


/*Crée la fenêtre qui va nous servir pour le programme, la remplie par défaut avec le menu principal puis en fonction des event, détermine quel menu sera affiché */
void affiche_menu(){
  int width=640, height=480;
  char *mode_algo="creation";

  MLV_create_window("K-PPV","k-ppv",width, height);

  MLV_clear_window(MLV_rgba(102,102,102,255));

  affiche_menu_algo(width,height,mode_algo);
  
  MLV_wait_seconds(5);

  MLV_free_window();
}




