#include "menu.h"




void affiche_1920(int w, int h){
int x=0, int y=0;
  MLV_get_size_of_adapted_text_box("1920x1080",
5,
&x,
&y);
     MLV_draw_adapted_text_box((w/2)-(x/2),
h/100,
"1920x1080",
5,
MLV_COLOR_BLACK,
MLV_COLOR_GOLDENROD,
MLV_COLOR_DARKSLATEGREY,
MLV_TEXT_CENTER);

}

void affiche_1280(int w, int h){
int x=0, int y=0;
  MLV_get_size_of_adapted_text_box("1280x720",
5,
&x,
&y);
     MLV_draw_adapted_text_box((w/2)-(x/2),
h/2,
"1280x720",
5,
MLV_COLOR_BLACK,
MLV_COLOR_GOLDENROD,
MLV_COLOR_DARKSLATEGREY,
MLV_TEXT_CENTER);

}

void affiche_640(int w, int h){
int x=0, int y=0;
  MLV_get_size_of_adapted_text_box("640x480",
5,
&x,
&y);
     MLV_draw_adapted_text_box((w/2)-(x/2),
h/1.2,
"640x480",
5,
MLV_COLOR_BLACK,
MLV_COLOR_GOLDENROD,
MLV_COLOR_DARKSLATEGREY,
MLV_TEXT_CENTER);

}

void affiche_menu_option(int w, int h){

    affiche_1920(w,h);

    affiche_1280(w,h);

    affiche_640(w,h);

     MLV_actualise_window();
}
