#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"fonction.h"
void initialiser_imageBACK(image *imge)
{
imge->ur1="back.png";
imge->img=IMG_Load(imge->ur1);
if(imge->img==NULL)
{
  printf("unable to load background image %s \n",SDL_GetError());
  return ;
}
imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}
void afficher_image(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}
//perso
void initPerso(perso *p)
{
	p->spritesheet=IMG_Load("perso3.png");

	p->position.x=5;
	p->position.y=200;
	p->position.w=1000;
	p->position.h=500;

	p->direction=3;//gauche=2 et droite=1
	p->acceleration=0;
	p->vitesse=0.5;
        p->vitesseV=0;
	p->nb_vie=5;
	p->score=0;
	p->up=0;

	p->posRelative.x=-50;
	p->posRelative.y=0;

	p->posSprite.x=0;
	p->posSprite.y=500;
	p->posSprite.w=166,5;//largeur image/NBC;
	p->posSprite.h=250;//Hauteur image/ NBL;//une ligne correspond aux animations d'une direction
}
void afficherPerso(perso p, SDL_Surface * screen)
{
SDL_BlitSurface(p.spritesheet,&p.posSprite,screen,&p.position);
}
void movePerso (perso *p,Uint32 dt)
{
	double dx;
if(p->acceleration!=0)
{
	dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 

	/*if (p->position.x> 1000)//gauche=2 et droite=1
		p->direction=1;
	if (p->position.x<5)
		p->direction=1;*/
	if (p->direction==1 || p->direction==3 )
                p->position.x+=dx;
	if(p->direction==2 || p->direction==4 )
                p->position.x-=dx;
}
}
void animerPerso (perso * p)
{
	p->posSprite.x +=167;
	if( p->posSprite.x > 1000)//si dernier frame atteint
	{
		p->posSprite.x =0; //(revenir au premier frame)
		p->posSprite.y =(p->direction-1)*250;
		//printf("\n p->posSprite.x=%d",p->posSprite.x );
	}
		
	else    
		p->posSprite.x = p->posSprite.x + p->posSprite.w;//(avancer au frame suivant)

}	
void saut(perso *p,int dt,int posx_absolu, int posy_absolu)
{
double dx;
if(p->up==1|| p->up==2)//saut_vertical
{
	p->vitesse=1;	
   if(p->up==1)//yatla3
{
	if(posy_absolu-190 <= p->position.y-((p->vitesse)*dt))
     		p->position.y-= (p->vitesse)*dt;
	else
		p->position.y=posy_absolu-190;
}
   else if(p->up==2)//yahbat
{
	if(posy_absolu >= p->position.y+((p->vitesse)*dt))
    		 p->position.y+= (p->vitesse)*dt;
	else
		 p->position.y=posy_absolu;       
}

   if(p->position.y<=(posy_absolu-190) && p->up==1)
        p->up=2;
   if(p->position.y>=posy_absolu && p->up==2)
        p->up=0;
}
if(p->up==3)//saut_parabolique
{
		if(p->direction==1 ||p->direction==3)
		{
			p->posRelative.x+=10;
			p->posRelative.y= (-0.04) * p->posRelative.x * p->posRelative.x+100;
		       	p->position.x=p->px + p->posRelative.x+50;
	       		p->position.y=p->py - p->posRelative.y;
		}
		if(p->direction==2 ||p->direction==4)
		{
			p->posRelative.x+=10;
			p->posRelative.y= (-0.04) * p->posRelative.x * p->posRelative.x+100;
		       	p->position.x=p->px - p->posRelative.x-50;
	       		p->position.y=p->py - p->posRelative.y;
		}
}   
}
void liberer(perso p, SDL_Surface * screen)
{
SDL_FreeSurface(p.spritesheet);
}

