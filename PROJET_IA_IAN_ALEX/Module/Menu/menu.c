#include "menu.h"


/*Crée la fenêtre qui va nous servir pour le programme, la remplie par défaut avec le menu principal puis en fonction des event, détermine quel menu sera affiché */
void affiche_menu(){
  char *mode_algo="creation";

  MLV_create_window("K-PPV","k-ppv",WIDTH, HEIGHT);

  MLV_clear_window(MLV_rgba(102,102,102,255));

  affiche_menu_principal(WIDTH, HEIGHT);
  
  MLV_wait_seconds(5);
  
  MLV_clear_window(MLV_rgba(102,102,102,255));

  affiche_menu_algo(WIDTH,HEIGHT,mode_algo);
  
  MLV_wait_seconds(5);

  MLV_clear_window(MLV_rgba(102,102,102,255));

  affiche_menu_option(WIDTH, HEIGHT);

  MLV_wait_seconds(5);

  MLV_free_window();
}




