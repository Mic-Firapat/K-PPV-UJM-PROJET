#include "menu.h"
#include "../Evenement/evenement.h"
#include "../Point/point.h"
#include "../Lecture/lecture.h"
#include "../Sauvegarde/sauvegarde.h"

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

   - k -> variable pour indiquer la valeur de k (WAHOU)

   - test_val_k -> variable qui  servira à tester la valeur de k tapper par l'utilisateur

   - quit -> sert à sortir de la boucle do/while de l'input box

   - n -> nombre de sommet

   - nbclasses -> nombre de classe

   - classe -> variable pour indiquer une classe

   - classe_actuelle -> dernière classe rentrée, classe par défaut lors d'un nouveau clic

   - mode_algo -> Sert à afficher le mode actuel, par défaut creation

   - val_k -> chaîne de caractère qui contiendra la valeur k décidé par l'utilisateur

   - chemin_fichier -> Indique le répertoire des sauvegardes

   - chemin -> chaîne qui une fois assembler à l'aide de chemin_fichier et nom_fichier nous permet d'accèder à nos sauvegardes.

   - nom_fichier -> contient le nom du fichier entrée par l'utilisateur

   - val_classe -> chaîne contenant la valeur classe donnée par l'utilisateur

   - symbole -> Tableau des symboles pour représenter des classes

   - couleur -> Tableau des couleurs pour représenter des classes

   - tab -> Contient toutes les zones sur lesquels nous pouvons cliquer

   - change_val_k -> input_box MLV, sert  lorsque l'on appuie sur k

   - change_chemin -> input_box MLV sert lorsque l'on chercher à accéder à un fichier

   - change_classe -> input_box MLV sert lorsque l'on cherche à donner une classe

   - event -> MLV_event, sert pour savoir si l'on utilisé l'input_box

   - tableau_point -> contient nos données sur les points

   - point_clique -> point qui sera crée lors d'un clique grille

*/
void affiche_menu(){
  int clic, en_cours=1, boucle_menu,i, x_souris, y_souris, menu_precedent=0, k=1, test_val_k = 0, quit = 0,n=0, nbclasses = 0, classe=0, classe_actuelle = 1;
  int *voisins = NULL;
  char *mode_algo="creation", *val_k = NULL, *chemin_fichier = "Sauvegardes/", *chemin = malloc(1 * sizeof(char)), *nom_fichier = NULL, *val_classe = NULL;
  char symbole[CMAX+1]={'o','-','+','*','/','!','?','=',':','.','#','&','@','<','>','\\','%'};
  MLV_Color couleur[CMAX+1] = {MLV_COLOR_WHITE, MLV_COLOR_GREEN, MLV_COLOR_RED, MLV_COLOR_NAVYBLUE, MLV_COLOR_DARKMAGENTA, MLV_COLOR_ORANGE4, MLV_COLOR_SALMON2, MLV_COLOR_BROWN3, MLV_COLOR_WHEAT4, MLV_COLOR_SIENNA1, MLV_COLOR_DARKOLIVEGREEN3, MLV_COLOR_KHAKI2, MLV_COLOR_CHARTREUSE1, MLV_COLOR_AQUAMARINE3, MLV_COLOR_CYAN1, MLV_COLOR_MISTYROSE4, MLV_COLOR_IVORY1};
  Zone_clic tab[TAB_MAX];
  MLV_Input_box *change_val_k, *change_chemin, *change_classe;
  MLV_Event event = MLV_NONE;
  Point *tableau_point = NULL, *point_clique = creer_point();

  /*Init de tab pour définir les zones de clic*/
  for(i=0;i<TAB_MAX;i++){
    tab[i] = creer_zone_val(0,0,0,0);
  }
  /*Init de tableau_point, qui contiendra nos points */

  /*Init val_k */
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
            
	  /*
Premier cas, le menu principal 
          */
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
	      affiche_menu_algo(WIDTH,HEIGHT,mode_algo, tab, k);
	      if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
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

          
	  /*
Deuxième cas, le menu_algo 
          */
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
	    if(n != 0){
	      n = 0;
	      nbclasses = 0;
	      tableau_point = NULL;
	    }
	    for(i=0;i<TAB_MAX;i++){
	      tab[i] = creer_zone_val(0,0,0,0);
	    }
            k = 1;
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	    clic = 0;
	    break;
            
	    /*On a cliqué sur la zone d'affichage */
	  case 2:
            pxtopoint(point_clique,x_souris,y_souris);
            tableau_point = ajout_point_tab(tableau_point, point_clique, &n);
	    tableau_point[n-1].classe = classe_actuelle;
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	    if(n != 0){
	      affiche_points(n, tableau_point, couleur, symbole);
	    }
	    clic = 0;
	    break;
            
	    /*On a cliqué pour changer le mode */
	  case 3:
	    if(strcmp(mode_algo, "creation") == 0){
	      mode_algo = "kppv";
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	      if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
	      clic = 0;
	    }
	    else if(strcmp(mode_algo, "kppv") == 0){
	      mode_algo = "creation";
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	      if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
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
            
	    /*On a cliqué sur suppression de point (creation) ou classe (kppv)*/
	  case 4:
	    if(n == 0){
	      clic = 0;
	      break;
	    }
            if (strcmp(mode_algo,"creation") == 0){
                tableau_point = retrait_point_tab(tableau_point, &n);
                MLV_clear_window(MLV_rgba(102,102,102,255));
                affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
                if(n != 0){
                    affiche_points(n, tableau_point, couleur, symbole);
                }
                clic = 0;
            }
            else {
                printf("CLASSE MODE KPPV\n");
            }
                break;
            
	    /*On a cliqué sur ajout de classe */
	  case 5:
	    if (n == 0){
	      clic = 0;
	      break;
	    }
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    change_classe = MLV_create_input_box (WIDTH/2-WIDTH/4,
						  HEIGHT/2-HEIGHT/5,
						  WIDTH/2,
						  HEIGHT/5,
						  MLV_COLOR_GREEN,
						  MLV_COLOR_GREEN,
						  MLV_COLOR_BLACK,
						  "Entrez la classe du dernier point :");
	    MLV_draw_text_box(10,
			      HEIGHT/10,
			      WIDTH/1.1,
			      HEIGHT/8,
			      "Pour utiliser la boîte, vous devez cliquer dessus.\nAttention : Vous ne quitterez pas ce menu tant qu'une valeur valide ne sera rentrée.\n(Une valeur valide est un entier compris entre 1 et le nombre max de classe : %d)",
			      2,
			      MLV_COLOR_BLACK,
			      MLV_COLOR_GREEN,
			      MLV_COLOR_BLACK,
			      MLV_TEXT_CENTER,
			      MLV_HORIZONTAL_CENTER,
			      MLV_VERTICAL_CENTER,
			      CMAX);
	    MLV_draw_all_input_boxes();
	    MLV_actualise_window();
	    /*boucle tant que l'utilisateur n'entre pas une valeur numérique valide ou ne quitte pas l'input box */
	    do{
	      /*Récupère un evenement */
	      event = MLV_get_event(NULL, NULL, NULL,&val_classe, &change_classe,NULL, NULL, NULL, NULL);

	      /*On le traite seulement si il s'agit d'un evenement input_box */
	      if (event == MLV_INPUT_BOX){
	        classe = atoi(val_classe);
		printf("%d\n",classe);
		if(classe < CMAX && classe >= 1){
                    if (classe > nbclasses){
                        nbclasses = classe;
                    }
		  tableau_point[n-1].classe = classe;
                  classe_actuelle = classe;
		  quit = 1;
		}
		classe = 0;
	      }
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      MLV_draw_text_box(10,
				HEIGHT/10,
				WIDTH/1.1,
				HEIGHT/8,
				"Pour utiliser la boîte, vous devez cliquer dessus.\nAttention : Vous ne quitterez pas ce menu tant qu'une valeur valide ne sera rentrée.\n(Une valeur valide est un entier compris entre 1 et le nombre de classes %d.)",
				2,
				MLV_COLOR_BLACK,
				MLV_COLOR_GREEN,
				MLV_COLOR_BLACK,
				MLV_TEXT_CENTER,
				MLV_HORIZONTAL_CENTER,
				MLV_VERTICAL_CENTER,
				nbclasses);
	      
	      MLV_draw_all_input_boxes();
	      MLV_actualise_window();
	    } while(quit == 0);
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	    if(n != 0){
	      affiche_points(n, tableau_point, couleur, symbole);
	    }
	    clic = 0;
	    quit = 0;
      
	    MLV_free_input_box (change_classe);
	    clic = 0;
	    break;

	    /*On a cliqué sur Voisinage */
	  case 6:
              /*Marche pas encore*/
              voisins = k_voisins(tableau_point, &(tableau_point[n-1]), k, n);
              
              MLV_draw_circle(coordtopx(&(tableau_point[n-1]))->x, coordtopx(&(tableau_point[n-1]))->y,distpx(&(tableau_point[n-1]),&(tableau_point[voisins[0]])), MLV_COLOR_RED );
              MLV_actualise_window();
              clic = 0;
              break;
            
	    /*On a cliqué sur Prise de décision */
	  case 7:
	    printf("LANCE LE MODE PRISE DE DECISION\n");
	    clic = 0;
	    break;

	    /*On a cliqué sur sauvegarder */
	  case 8:
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    change_chemin = MLV_create_input_box (WIDTH/2-WIDTH/4,
						  HEIGHT/2-HEIGHT/5,
						  WIDTH/2,
						  HEIGHT/5,
						  MLV_COLOR_GREEN,
						  MLV_COLOR_GREEN,
						  MLV_COLOR_BLACK,
						  "Nom du fichier:");

	    MLV_draw_text_box(10,
			      10,
			      WIDTH/1.01,
			      HEIGHT/4,
			      "Pour utiliser la boîte, vous devez cliquer dessus.\nVeuillez enter un nom de fichier.\n Essayer de ne pas nommer n'importe comment votre fichier.",
			      2,
			      MLV_COLOR_BLACK,
			      MLV_COLOR_GREEN,
			      MLV_COLOR_BLACK,
			      MLV_TEXT_CENTER,
			      MLV_HORIZONTAL_CENTER,
			      MLV_VERTICAL_CENTER);
	    MLV_draw_all_input_boxes();
	    MLV_actualise_window();

	    /*Boucle tant que l'utilisateur n'a pas rentré de nom d'un fichier valide*/
	    do{
	      /*Récupère un evenement */
	      event = MLV_get_event(NULL, NULL, NULL,&nom_fichier, &change_chemin,NULL, NULL, NULL, NULL);

	      /*On le traite si il s'agit d'un event input_box */
	      if ( event == MLV_INPUT_BOX){
		chemin = realloc(chemin, sizeof(char) * (strlen(nom_fichier) + strlen(chemin_fichier) + 1));
		strcat(chemin, chemin_fichier);
		strcat(chemin, nom_fichier);
		sauvegarde_fichier(tableau_point, chemin, n, nbclasses);
		quit = 1;
	      }
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      MLV_draw_text_box(10,
				10,
				WIDTH/1.01,
				HEIGHT/4,
				"Pour utiliser la boîte, vous devez cliquer dessus.\nVeuillez enter un nom de fichier.\n Essayer de ne pas nommer n'importe comment votre fichier.",
				2,
				MLV_COLOR_BLACK,
				MLV_COLOR_GREEN,
				MLV_COLOR_BLACK,
				MLV_TEXT_CENTER,
				MLV_HORIZONTAL_CENTER,
				MLV_VERTICAL_CENTER);
	      MLV_draw_all_input_boxes();
	      MLV_actualise_window();
	    }while(quit == 0);
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	    if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
	    MLV_free_input_box(change_chemin);
	    chemin[0] = '\0';
	    quit = 0;
	    clic = 0;
	    break;

            
	    /*On a cliqué sur charger */
	  case 9:
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    change_chemin = MLV_create_input_box (WIDTH/2-WIDTH/4,
						  HEIGHT/2-HEIGHT/5,
						  WIDTH/2,
						  HEIGHT/5,
						  MLV_COLOR_GREEN,
						  MLV_COLOR_GREEN,
						  MLV_COLOR_BLACK,
						  "Entrez le nom d'un fichier :");

	    MLV_draw_text_box(10,
			      10,
			      WIDTH/1.01,
			      HEIGHT/4,
			      "Pour utiliser la boîte, vous devez cliquer dessus.\nVeuillez enter un nom de fichier.\n ATTENTION: tant que le nom de fichier ne sera pas valide vous ne quitterez pas cete boîte.\n Les noms de fichier valide sont disponibles dans le répertoire Sauvegardes.",
			      2,
			      MLV_COLOR_BLACK,
			      MLV_COLOR_GREEN,
			      MLV_COLOR_BLACK,
			      MLV_TEXT_CENTER,
			      MLV_HORIZONTAL_CENTER,
			      MLV_VERTICAL_CENTER);
	    MLV_draw_all_input_boxes();
	    MLV_actualise_window();

	    /*Boucle tant que l'utilisateur n'a pas rentré de nom d'un fichier valide*/
	    do{
	      /*Récupère un evenement */
	      event = MLV_get_event(NULL, NULL, NULL,&nom_fichier, &change_chemin,NULL, NULL, NULL, NULL);

	      /*On le traite si il s'agit d'un event input_box */
	      if ( event == MLV_INPUT_BOX){
		chemin = realloc(chemin, sizeof(char) * (strlen(nom_fichier) + strlen(chemin_fichier) + 1));
		strcat(chemin, chemin_fichier);
		strcat(chemin, nom_fichier);
	        tableau_point = chargement_fichier(chemin, &n, &nbclasses);

		if (tableau_point != NULL){
		  quit = 1;
		}
		chemin[0] = '\0';
	      }
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      MLV_draw_text_box(10,
				10,
				WIDTH/1.1,
				HEIGHT/4,
				"Pour utiliser la boîte, vous devez cliquer dessus.\nVeuillez enter un nom de fichier.\n ATTENTION: tant que le nom de fichier ne sera pas valide vous ne quitterez pas cette boîte.\n Les noms de fichier valide sont disponibles dans le répertoire Sauvegardes.",
				2,
				MLV_COLOR_BLACK,
				MLV_COLOR_GREEN,
				MLV_COLOR_BLACK,
				MLV_TEXT_CENTER,
				MLV_HORIZONTAL_CENTER,
				MLV_VERTICAL_CENTER);
	      MLV_draw_all_input_boxes();
	      MLV_actualise_window();
	      
	    }while(quit == 0);
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	    if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
	    chemin[0] = '\0';
	    MLV_free_input_box(change_chemin);
	    quit = 0;
	    clic = 0;
	    break;

	    
	    /*On a cliqué sur flèche du bas */
	  case 10:
	    if(k == 1){
	      clic = 0;
	      break;
	    }
	    else{
	      k--;
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	      if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
	      clic = 0;
	    }
	    break;
	    /*On a cliqué sur flèche du haut */
	  case 11:
	    if(k < n){
	      k++;
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	      if(n != 0){
		affiche_points(n, tableau_point, couleur, symbole);
	      }
	      clic = 0;
	      break;
	    }
	    clic = 0;
	    break;

            
	    /*On a cliqué sur la valeur de k afin de la modifier à une valeur voulue */
	  case 12:
	    if(n == 0){
	      clic = 0;
	      break;
	    }
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    change_val_k = MLV_create_input_box (WIDTH/2-WIDTH/4,
						 HEIGHT/2-HEIGHT/5,
						 WIDTH/2,
						 HEIGHT/5,
						 MLV_COLOR_GREEN,
						 MLV_COLOR_GREEN,
						 MLV_COLOR_BLACK,
						 "Entrez la valeur de k :");
	    MLV_draw_text_box(10,
			      HEIGHT/10,
			      WIDTH/1.1,
			      HEIGHT/8,
			      "Pour utiliser la boîte, vous devez cliquer dessus.\nAttention : Vous ne quitterez pas ce menu tant qu'une valeur valide ne sera rentrée.\n(Une valeur valide est un entier compris entre 1 et le nombre de points %d.)",
			      2,
			      MLV_COLOR_BLACK,
			      MLV_COLOR_GREEN,
			      MLV_COLOR_BLACK,
			      MLV_TEXT_CENTER,
			      MLV_HORIZONTAL_CENTER,
			      MLV_VERTICAL_CENTER,
			      n);
	    MLV_draw_all_input_boxes();
	    MLV_actualise_window();
	    
	    /*boucle tant que l'utilisateur n'entre pas une valeur numérique valide ou ne quitte pas l'input box */
	    do{
	      /*Récupère un evenement */
	      event = MLV_get_event(NULL, NULL, NULL,&val_k, &change_val_k,NULL, NULL, NULL, NULL);

	      /*On le traite seulement si il s'agit d'un evenement input_box */
	      if ( event == MLV_INPUT_BOX){
		test_val_k = atoi(val_k);
		if(test_val_k < n && test_val_k >= 1){
		  k = test_val_k;
		  quit = 1;
		}
		test_val_k = 0;
	      }
	      MLV_clear_window(MLV_rgba(102,102,102,255));
	      MLV_draw_text_box(10,
				HEIGHT/10,
				WIDTH/1.1,
				HEIGHT/8,
				"Pour utiliser la boîte, vous devez cliquer dessus.\nAttention : Vous ne quitterez pas ce menu tant qu'une valeur valide ne sera rentrée.\n(Une valeur valide est un entier compris entre 1 et le nombre de points %d.)",
				2,
				MLV_COLOR_BLACK,
				MLV_COLOR_GREEN,
				MLV_COLOR_BLACK,
				MLV_TEXT_CENTER,
				MLV_HORIZONTAL_CENTER,
				MLV_VERTICAL_CENTER,
				n);
	      
	      MLV_draw_all_input_boxes();
	      MLV_actualise_window();
	    } while(quit == 0);
	    MLV_clear_window(MLV_rgba(102,102,102,255));
	    affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
	    if(n != 0){
	      affiche_points(n, tableau_point, couleur, symbole);
	    }
	    clic = 0;
	    quit = 0;
      
	    MLV_free_input_box (change_val_k);
	    break;

            
	    /*Sinon on cliqué sur une zone inutile */
	  default:
	    clic=0;
	    break;
	  }
	  break;



	  
	  /*
            Troisième cas, le menu_option 
          */
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
		affiche_menu_algo(WIDTH, HEIGHT, mode_algo, tab, k);
		if(n != 0){
		  affiche_points(n, tableau_point, couleur, symbole);
		}
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




