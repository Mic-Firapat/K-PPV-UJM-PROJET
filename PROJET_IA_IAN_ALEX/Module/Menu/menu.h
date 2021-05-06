
#ifndef MENU_H
#define MENU_H
#define ECART_HAUT 10
#define ECART_INTER 8
#include "../necessaire.h"

/*Fonction qui gère l'affichage du menu */
void affiche_menu();

/*Fonction qui affiche le menu principal */
void affiche_menu_principal(int w, int h);

/*Fonction qui affiche le menu pour manipuler l'algo */
void affiche_menu_algo(int w, int h, char * m);

/*Fonction qui affiche le menu d'option */
void affiche_menu_option(int w, int h);



#endif
