#include "menu.h"

/*Imprime l'engrenage dans la case dessiner à la postion attendue */
void dessine_engrenage(int taille, int pos_x, int pos_y, Zone_clic tab[]){
  MLV_Image * image = MLV_load_image("./Module/Image/gear.png");

  MLV_draw_rectangle(pos_x,
		     pos_y,
		     taille+2,
		     taille+2,
		     MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(pos_x+1,
			    pos_y+1,
			    taille,
			    taille,
    			    MLV_COLOR_DARKSLATEGREY);

  MLV_resize_image_with_proportions(image,taille*1.5, taille*1.5);
  
  MLV_draw_image(image,pos_x-(pos_x/110),(pos_y/2));

  tab[0] = creer_zone_val(pos_x, pos_y, pos_x+(taille+2),pos_y+(taille+2));
  
}


/*Ajoute le bouton réinitialise fenêtre */
void reinitialise_fenetre(int w, int h, Zone_clic tab[]){
  
  MLV_draw_text_box(w - (w/3.5),
		    h/100,
		    w/4.5,
		    h/20,
		    "Réinitialiser fenêtre",
		    3,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLDENROD,
		    MLV_COLOR_DARKSLATEGREY,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER);

  tab[1] = creer_zone_val(w - (w/3.5), h/100, (w - (w/3.5) + w/4.5), (h/100 + h/20));
  
}

/*Ajoute la cellule valeur de k */
void valk(int w, int h, Zone_clic tab[], int k){
  MLV_Image *fh = MLV_load_image("./Module/Image/fleche_haut.png");
  MLV_Image *fb = MLV_load_image("./Module/Image/fleche_bas.png");

  MLV_draw_text_box((w/2)-(w/3.8),
			    h/100,
			    w/4.5,
			    h/20,
			    "Valeur de k : %d",
			    3,
			    MLV_COLOR_BLACK,
			    MLV_COLOR_GOLDENROD,
			    MLV_COLOR_DARKSLATEGREY,
			    MLV_TEXT_CENTER,
			    MLV_HORIZONTAL_CENTER,
			    MLV_VERTICAL_CENTER,
			    k);

  /*Je rajoute la possibilité de choisir son k*/

  tab[12] = creer_zone_val((w/2)-(w/3.8),h/100,(w/2)-(w/3.8)+w/4.5,h/100+h/20);

  /*Rajoute les flèches pour changer la valeur de k */

  /*Flèche du bas */
  MLV_draw_rectangle((w/2)-(w/3.3),
		     h/100,
		     w/30+2,
		     w/30+2,
		     MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle((w/2)-(w/3.3)+1,
			    h/100+1,
			    w/30,
			    w/30,
    			    MLV_COLOR_DARKSLATEGREY);

  MLV_resize_image_with_proportions(fb,w/40, w/40);
  
  MLV_draw_image(fb,(w/2)-(w/3.3)+(w/150),((h/100))+(w/30+2)/10);

  tab[10] = creer_zone_val((w/2)-(w/3.3),h/100,(w/2)-(w/3.3)+(w/30+2),h/100+(w/30+2));

  /*Flèche du haut */

  MLV_draw_rectangle((w/2)-(w/25),
		     h/100,
		     w/30+2,
		     w/30+2,
		     MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle((w/2)-(w/25)+1,
			    h/100+1,
			    w/30,
			    w/30,
    			    MLV_COLOR_DARKSLATEGREY);

  MLV_resize_image_with_proportions(fh,w/40, w/40);
  MLV_draw_image(fh,(w/2)-(w/25)+(w/150),(h/100)+(w/30+2)/10);

  tab[11] = creer_zone_val((w/2)-(w/25),h/100,(w/2)-(w/25)+(w/30+2),h/100+(w/30+2));
  
}


/*Ajoute la zone d'affichage (la grille) */
void zone_affichage(int w, int h, Zone_clic tab[]){
  int x=w/100, y=h/10 ,width=w/2, height=h/1.15;

  
  MLV_draw_rectangle(x-1,
		     y-1,
		     width+2,
		     height+2,
		     MLV_COLOR_WHITE);

  MLV_draw_filled_rectangle(x,
			    y,
			    width,
			    height,
			    MLV_COLOR_BLACK);

  MLV_draw_line(x+(width/2),
		y,
		x+(width/2),
		height+y,
		MLV_COLOR_WHITE);

  MLV_draw_line(x,
		y+(height/2),
		x+width,
		y+(height/2),
		MLV_COLOR_WHITE);

  tab[2] = creer_zone_val(x,y,x+width,y+height);
}


/*Ajoute le bouton pour changer le mode  */
void changement_mode(int w, int h, char * mode, Zone_clic tab[]){
  
  MLV_draw_text_box(w/100,
		    h/100,
		    w/5.5,
		    h/20,
		    "Mode : %s",
		    3,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLDENROD,
		    MLV_COLOR_DARKSLATEGREY,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER,
		    mode);

  tab[3] = creer_zone_val(w/100,h/100,(w/100+w/5.5),(h/100+h/20));
  
}

/*Ajoute le bouton d'ajout de point ou classe*/
void bouton_point(int w, int h, char * action, Zone_clic tab[]){

  MLV_draw_text_box((w/2)+w/50,
		    h/10,
		    w/5,
		    h/13,
		    "Cliquez ici pour:\n %s",
		    3,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLDENROD,
		    MLV_COLOR_DARKSLATEGREY,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER,
		    action);
  
  tab[4] = creer_zone_val((w/2)+w/50, h/10, w/5 +(w/2)+w/50, h/10 + h/13);
}

/*Ajoute le bouton ajout de classe */
void ajout_classe(int w, int h, Zone_clic tab[]){
  
  MLV_draw_text_box((w/2)+w/50,
		    h/5,
		    w/3.5,
		    h/13,
		    "Ajoutez la classe\n du point manuellement",
		    3,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLDENROD,
		    MLV_COLOR_DARKSLATEGREY,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER);

  tab[5] = creer_zone_val((w/2)+w/50, h/5,(w/2)+w/50 + w/3.5, h/5+ h/13);
}

/*Ajoute l'onglet des options d'affichage */
void options_affichage(int w, int h, Zone_clic tab[]){
  int taille_x=0, taille_y=0;

  MLV_draw_rectangle(w/2+w/50-1,
		     h/3.2-1,
		     w/2.1+2,
		     h/2+2,
		     MLV_COLOR_WHITE);
  
  MLV_draw_filled_rectangle(w/2+w/50,
			    h/3.2,
			    w/2.1,
			    h/2,
			    MLV_COLOR_BLACK);

  MLV_get_size_of_text("Options d'affichage",
		       &taille_x,
		       &taille_y);
  
  MLV_draw_text((w/1.5),
	        h/3,
		"Options d'affichage",
		MLV_COLOR_GOLDENROD);
  
  MLV_draw_rectangle((w/2+w/50)+h/100,
		     h/2.25,
		     w/30,
		     w/30,
		     MLV_COLOR_WHITESMOKE);

  tab[6] = creer_zone_val((w/2+w/50)+h/100,h/2.25,(w/2+w/50)+h/100+w/30,h/2.25+w/30);
  
  MLV_draw_text((w/2+w/50)+w/20,
		h/2.25+(w/30)/2,
		"Voisinage",
		MLV_COLOR_GOLDENROD);
  
  MLV_draw_rectangle((w/2+w/50)+h/100,
		     h/1.9,
		     w/30,
		     w/30,
		     MLV_COLOR_WHITESMOKE);

  tab[7] = creer_zone_val((w/2+w/50)+h/100,h/1.9,(w/2+w/50)+h/100+w/30,h/1.9+w/30);

  MLV_draw_text((w/2+w/50)+w/20,
		h/1.9+(w/30)/2,
		"Prise de décision",
		MLV_COLOR_GOLDENROD);
  
}

/*Ajoute les deux boutons liés aux sauvegardes */
void sauvegarde(int w, int h, Zone_clic tab[]){

  MLV_draw_text_box(w-(w/2.2),
		    h/1.1,
		    w/2.5,
		    h/15,
		    "Sauvegarder les données actuelles",
		    5,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLDENROD,
		    MLV_COLOR_DARKSLATEGREY,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER);

  tab[8] = creer_zone_val(w-(w/2.2), h/1.1,w-(w/2.2)+w/2.5, h/1.1+h/15);

  MLV_draw_text_box(w-(w/2.2),
		    h/1.2,
		    w/2.5,
		    h/15,
		    "Charger les données d'un fichier",
		    5,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLDENROD,
		    MLV_COLOR_DARKSLATEGREY,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER);

  tab[9] = creer_zone_val(w-(w/2.2),h/1.2,w-(w/2.2)+w/2.5,h/1.2+h/15);
}

/*Affiche le menu complet */
void affiche_menu_algo(int w, int h, char * m, Zone_clic tab[], int k){

  reinitialise_fenetre(w,h, tab);

  if(strcmp(m, "creation") == 0){
    changement_mode(w,h,m, tab);
    bouton_point(w,h,"Placer un point", tab);
    ajout_classe(w,h, tab);
  }
  else if(strcmp(m, "kppv") == 0){
    changement_mode(w,h,m, tab);
    bouton_point(w,h,"Classer un point", tab);
  }
  else{
    fprintf(stderr,"ERREUR, un mode incompatible a été renvoyé.\nFATAL ERROR MODE IS NOT OF TYPE CREATE NOR KPPV\n");
    MLV_free_window();
    exit(-1);
  }

  valk(w,h,tab,k);
  zone_affichage(w,h, tab);
  options_affichage(w,h, tab);
  sauvegarde(w,h,tab);

  dessine_engrenage(w/40,(w - (w/3.5)-w/40-h/100),h/100, tab);
  
  MLV_actualise_window();

}
