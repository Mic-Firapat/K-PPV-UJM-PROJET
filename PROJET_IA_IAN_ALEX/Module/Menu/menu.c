#include "menu.h"
#include "../Evenement/evenement.h"

extern int WIDTH, HEIGHT;


/*Crée la fenêtre qui va nous servir pour le programme, la remplie par défaut avec le menu principal puis en fonction des event, détermine quel menu sera affiché 

Description des variables :

   - clic -> Entier qui nous permet de déterminer si il y a eu un clic

   - en_cours -> Détermine si le programme est en cours

   - boucle_menu -> Peut prendre 3 valeurs : 1=menu_principal
                                             2=menu_algo
                                             3=menu_option
   - i -> Pour les for

   - x_souris -> contiendra la coord x de la souris

   - y_souris -> contiendra la coord y de la souris

   - menu_precedent -> Permet de réafficher le bon menu lors du retour du menu option

   - mode_algo -> Sert à afficher le mode actuel, par défaut creation

   - tab -> Contient toutes les zones sur lesquels nous pouvons cliquer

*/
void affiche_menu(){
  int clic, en_cours=1, boucle_menu,i, x_souris, y_souris, menu_precedent=0;
  char *mode_algo="creation";
  Zone_clic tab[TAB_MAX];

  for(i=0;i<TAB_MAX;i++){
    tab[i] = creer_zone_val(0,0,0,0);
  }
  
  MLV_create_window("K-PPV","k-ppv",WIDTH, HEIGHT);

  MLV_clear_window(MLV_rgba(102,102,102,255));

  affiche_menu_principal(WIDTH, HEIGHT, tab);
  boucle_menu = 1;

  /*Boucle tant qu'on est dans le programme */
  while(en_cours){
    clic = 0;

    /*On récupère la souris */
    MLV_wait_mouse(&x_souris, &y_souris);

    /*Vérifie si le clique gauche est pressé */
    if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED){
      clic = 1;
    }

    /*Si le clic est à 1, on vérifie où on a cliqué et comment réagir en fonction de */

    if(clic == 1){
      /*On vérifie sur quel menu nous sommes :*/
      switch (boucle_menu)
	{
	  /*Premier cas, le menu principal */
	case 1:
	  /*On vérifie sur quelle case on a cliqué */
	  switch(event_menu(tab, x_souris, y_souris))
	    {
	      /*Si on a cliqué sur lancer l'algo*/
	    case 0:
	      for(i=0;i<TAB_MAX;i++){
		tab[i] = creer_zone_val(0,0,0,0);
	      }
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH,HEIGHT,mode_algo, tab);
	      boucle_menu = 2;
	      clic = 0;
	      break;
	      /*Si on a cliqué sur options*/
	    case 1:
	      for(i=0;i<TAB_MAX;i++){
		tab[i] = creer_zone_val(0,0,0,0);
	      }
	      menu_precedent = 1;
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_option(WIDTH,HEIGHT,tab);
	      boucle_menu = 3;
	      clic = 0;
	      break;
	      /*Si on a cliqué sur quitter*/
	    case 2:
	      clic = 0;
	      en_cours = 0;
	      for(i=0;i<TAB_MAX;i++){
	        free(tab[i]);
	      }
	      MLV_free_window();
	      exit(-1);
	      break;
	      /*Sinon on cliqué sur une zone inutile */
	    default:
	      clic = 0;
	      break;
	    }
	  break;
	  /*Deuxième cas, le menu_algo */
	case 2:
	  /*On vérifie sur quelle case on a cliqué */
	  switch(event_menu(tab, x_souris, y_souris)){
	    /*On a cliqué sur l'engrenage */
	  case 0:
	    for(i=0;i<TAB_MAX;i++){
	      tab[i] = creer_zone_val(0,0,0,0);
	    }
	    menu_precedent = 2;
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_option(WIDTH,HEIGHT,tab);
	    boucle_menu = 3;
	    clic = 0;
	    break;
	    /*On a cliqué sur réinitialiser fenêtre */
	  case 1:
	    for(i=0;i<TAB_MAX;i++){
	      tab[i] = creer_zone_val(0,0,0,0);
	    }
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab);
	    clic = 0;
	    printf("AJOUTER FONCTION AFFICHE POINTS\n");
	    break;
	    /*On a cliqué sur la zone d'affichage */
	  case 2:
	    printf("CLIC ZONE AFFICHAGE, A IMPLEMENTER\n");
	    clic = 0;
	    break;
	    /*On a cliqué pour changer le mode */
	  case 3:
	    if(strcmp(mode_algo, "creation") == 0){
	      mode_algo = "kppv";
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab);
	      clic = 0;
	    }
	    else if(strcmp(mode_algo, "kppv") == 0){
	      mode_algo = "creation";
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab);
	      clic = 0;
	    }
	    else{
	      fprintf(stderr,"ERREUR, un mode incompatible a été renvoyé.\nFATAL ERROR MODE IS NOT OF TYPE CREATE NOR KPPV\n");
	      for(i=0;i<TAB_MAX;i++){
		free(tab[i]);
	      }
	      MLV_free_window();
	      exit(-1);
	    }
	    break;
	    /*On a cliqué sur ajout de point (creation) ou classe (kppv)*/
	  case 4:
	    printf("INTERACTION POINT/CLASSE A INTEGRER\n");
	    clic = 0;
	    break;
	    /*On a cliqué sur ajout de classe */
	  case 5:
	    printf("RAJOUTER L'AJOUT D'UNE CLASSE\n");
	    clic = 0;
	    break;
	    /*On a cliqué sur Voisinage */
	  case 6:
	    printf("LANCE L'AFFICHAGE DU CERCLE DE VOISINAGE\n");
	    clic = 0;
	    break;
	    /*On a cliqué sur Prise de décision */
	  case 7:
	    printf("LANCE LE MODE PRISE DE DECISION\n");
	    clic = 0;
	    break;
	    /*On a cliqué sur sauvegarder */
	  case 8:
	    printf("SAUVEGARDE DANS UN FICHIER LES DONNEES\n");
	    clic = 0;
	    break;
	    /*On a cliqué sur charger */
	  case 9:
	    printf("CHARGE LES DONNEES D'UN FICHIER\n");
	    clic = 0;
	    break;
	    /*Sinon on cliqué sur une zone inutile */
	  default:
	    clic=0;
	    break;
	  }
	  break;
	  /*Troisième cas, le menu_option */
	case 3:
	  /*On vérifie sur quelle case on a cliqué */
	  switch(event_menu(tab, x_souris, y_souris))
	    {
	      /*Si on clique sur 1920x1080 */
	    case 0:
	      WIDTH = 1920;
	      HEIGHT = 1080;
	      MLV_change_window_size(WIDTH, HEIGHT);
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_option(WIDTH,HEIGHT,tab);
	      clic = 0;
	      break;
	      /*Si on clique sur 1280x720 */
	    case 1:
	      WIDTH = 1280;
	      HEIGHT = 720;
	      MLV_change_window_size(WIDTH, HEIGHT);
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_option(WIDTH,HEIGHT,tab);
	      clic = 0;
	      break;
	      /*Si on clique sur 640x480 */
	    case 2:
	      WIDTH = 640;
	      HEIGHT = 480;
	      MLV_change_window_size(WIDTH, HEIGHT);
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_option(WIDTH,HEIGHT,tab);
	      clic = 0;
	      break;
	      /*Si on clique sur retour */
	    case 3:
	      if(menu_precedent == 1){
		for(i=0;i<TAB_MAX;i++){
		  tab[i] = creer_zone_val(0,0,0,0);
		}
		MLV_clear_window(MLV_rgba(102,102,102,255));
		affiche_menu_principal(WIDTH, HEIGHT, tab);
		clic = 0;
		boucle_menu = 1;
	      }
	      else{
		for(i=0;i<TAB_MAX;i++){
		  tab[i] = creer_zone_val(0,0,0,0);
		}
		MLV_clear_window(MLV_rgba(102,102,102,255));
		affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab);
		clic = 0;
		boucle_menu = 2;
	      }
	      break;
	      /*Si on clique sur quitter */
	    case 4:
	      clic = 0;
	      en_cours = 0;
	      for(i=0;i<TAB_MAX;i++){
	        free(tab[i]);
	      }
	      MLV_free_window();
	      exit(-1);
	      break;
	      /*Sinon on cliqué sur une zone inutile */
	    default:
	      clic = 0;
	      break;
	    }
	  break;
	  /*Si nous sommes en dehors d'un menu c'est une erreur */
	default:
	  fprintf(stderr,"ERREUR boucle_menu : Vous n'êtes pas sur un cas possible EXIT\n");
	  /*Penser à free tout ce qui peut l'être */
	  for(i=0;i<TAB_MAX;i++){
	    free(tab[i]);
	  }
	  MLV_free_window();
	  exit(-1);
	  break;
	}
    }
    
  }
  MLV_free_window();
}




