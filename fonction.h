#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 500
#define SCREEN_W 1000
typedef struct
{
  char *ur1;
  SDL_Rect pos_img_affiche;
  SDL_Rect pos_img_ecran;
  SDL_Surface *img;
}image;

typedef struct perso
{
SDL_Surface *spritesheet;
SDL_Rect position;//ecran
SDL_Rect posSprite;
SDL_Rect posRelative;
int px,py;
double vitesse,acceleration,vitesseV;
Uint32 dt;
int direction;
int nb_vie;
int score;
int up;
}perso;
//background
void initialiser_imageBACK(image *imge);
void afficher_image(SDL_Surface *screen,image imge);
void liberer_image(image imge);
//personage		
void initPerso(perso *p);		
void afficherPerso(perso p, SDL_Surface * screen);		
void movePerso (perso *p,Uint32 dt);	
void animerPerso (perso * p);	
void saut(perso *p,int dt,int posx_absolu, int posy_absolu);	
void liberer(perso p, SDL_Surface * screen);
#endif
