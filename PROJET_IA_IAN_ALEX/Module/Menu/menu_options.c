#include "menu.h"

/*Affiche resolution */
void affiche_resolution(int w, int h, int *px,int *py, MLV_Font *font){
  char *res = "Résolution";

  MLV_get_size_of_text_with_font(res,
				 px,
				 py,
				 font);
  
  MLV_draw_text_with_font((w/2)-(*px/2),
			  (h/ECART_HAUT)-*(py),
			  res,
			  font,
			  MLV_COLOR_GOLDENROD);
  *py+= h/ECART_HAUT-*(py);
}

/*Affiche le bouton resol 1920x1080 */
void affiche_1920(int w, int h, int *px, int *py, MLV_Font *font, Zone_clic tab[]){
  int sauv = *py;
  MLV_get_size_of_adapted_text_box_with_font("1920x1080",
					     font,
					     5,
					     px,
					     py);
  
  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      "1920x1080",
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);

  tab[0] = creer_zone_val((w/2)-(*px/2),sauv+(*py),(w/2)+(*px/2),sauv+(*py)*2);
  *py += sauv + h/50;

}

/*Affiche le bouton resol 1280x720 */
void affiche_1280(int w, int h, int *px, int *py, MLV_Font *font, Zone_clic tab[]){
  int sauv = *py;
  MLV_get_size_of_adapted_text_box_with_font("1280x720",
					     font,
					     5,
					     px,
					     py);
  
  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      "1280x720",
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);
  
  tab[1] = creer_zone_val((w/2)-(*px/2),sauv+(*py),(w/2)+(*px/2),sauv+(*py)*2);
  *py += sauv + h/50;

}

/*Affiche le bouton resol 640x480 */
void affiche_640(int w, int h, int *px, int *py, MLV_Font *font, Zone_clic tab[]){
  int sauv = *py;
 
  MLV_get_size_of_adapted_text_box_with_font("640x480",
					     font,
					     5,
					     px,
					     py);
  
  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      "640x480",
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);

  tab[2] = creer_zone_val((w/2)-(*px/2),sauv+(*py),(w/2)+(*px/2),sauv+(*py)*2);
  *py += sauv + h/50;

}

/*Affiche le bouton retour */
void affiche_retour(int w, int h, int *px, int *py, MLV_Font *font, Zone_clic tab[]){
  char *retour = "Retour";
  int sauv = *py;

  MLV_get_size_of_adapted_text_box_with_font(retour,
					     font,
					     5,
					     px,
					     py);

  MLV_draw_adapted_text_box_with_font((w/2)-(*px/2),
				      sauv+(*py),
				      retour,
				      font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_GOLDENROD,
				      MLV_COLOR_DARKSLATEGREY,
				      MLV_TEXT_CENTER);

  tab[3] = creer_zone_val((w/2)-(*px/2),sauv+(*py),(w/2)+(*px/2),sauv+(*py)*2);
  *py += sauv + h/50;
  
}

/*Affiche le bouton quitter */
void affiche_quitter_option(int w, int h, int *px, int *py, MLV_Font *font, Zone_clic tab[]){
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

  tab[4] = creer_zone_val((w/2)-(*px/2),sauv+(*py),(w/2)+(*px/2),sauv+(*py)*2);
  *py += sauv + h/50;
}

/*Affiche l'ensemble du menu option */
void affiche_menu_option(int w, int h, Zone_clic tab[]){
  MLV_Font *police = MLV_load_font("Module/Habillage/Police/Knights-Quests.ttf",
				   w/20);
  int placement_y=0, placement_x=0;

  affiche_resolution(w, h, &placement_x, &placement_y, police);

  affiche_1920(w,h,&placement_x, &placement_y,police, tab);

  affiche_1280(w,h,&placement_x, &placement_y,police, tab);

  affiche_640(w,h,&placement_x, &placement_y,police, tab);

  affiche_retour(w,h,&placement_x,&placement_y,police, tab);

  affiche_quitter_option(w, h,  &placement_x, &placement_y, police, tab);

  MLV_actualise_window();
  MLV_free_font(police);
}
