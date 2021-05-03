#include "menu.h"


/*Affiche le titre */
void affiche_titre(int w, int h, int *px,int *py, MLV_Font *font){
  char *titre = "K-PPV";

  MLV_get_size_of_text_with_font(titre,
				 px,
				 py,
				 font);
  
  MLV_draw_text_with_font((w/2)-(*px/2),
			  (h/ECART_HAUT),
			  titre,
			  font,
			  MLV_COLOR_GOLDENROD);
  printf("%d\n",*py);
  *py+= h/ECART_HAUT;
  printf("%d\n",*py);
}

/*Affiche le bouton pour lancer l'algo KPPV */
void affiche_start(int w, int h, int *px, int *py, MLV_Font *font){
  char *lance = "Lancer l'algo";
  int sauv = *py;

  MLV_get_size_of_adapted_text_box_with_font(lance,
					     font,
					     5,
					     px,
					     py);

  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      lance,
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);
  printf("%d %d\n",*py, sauv);
  *py += sauv + h/ECART_INTER;
  printf("%d %d\n",*py, sauv);
}

/*Affiche le bouton options */
void affiche_options(int w, int h, int *px, int *py, MLV_Font *font){
  char *options = "Options";
  int sauv = *py;

  MLV_get_size_of_adapted_text_box_with_font(options,
					     font,
					     5,
					     px,
					     py);

  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      options,
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);
  printf("%d %d\n",*py, sauv);
  *py += sauv + h/ECART_INTER;
  printf("%d %d\n",*py, sauv);
  
}

/*Affiche le bouton quitter */
void affiche_quitter(int w, int h, int *px, int *py, MLV_Font *font){
  char *quitter = "Quitter";
  int sauv = *py;

  MLV_get_size_of_adapted_text_box_with_font(quitter,
					     font,
					     5,
					     px,
					     py);

  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      quitter,
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);
  printf("%d %d\n",*py, sauv);				     
  *py += sauv;
  printf("%d %d\n",*py, sauv);
}

/*Assemble le menu principal */
void menu_principal(int w, int h){
  MLV_Font *police = MLV_load_font("Module/Habillage/Police/Knights-Quests.ttf",
				  w/18);
  int placement_y=0, placement_x=0;

  affiche_titre(w, h, &placement_x, &placement_y, police);
  
  affiche_start(w, h, &placement_x, &placement_y, police);
  
  affiche_options(w, h, &placement_x, &placement_y, police);
  
  affiche_quitter(w, h, &placement_x, &placement_y, police);
  
  MLV_actualise_window();
  MLV_free_font(police);
}
