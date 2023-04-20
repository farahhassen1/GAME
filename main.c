#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"fonction.h"
int main(int argc, char *args[])
{
SDL_Surface *screen;
image IMAGE,IMAGE_BTN1,IMAGE_BTN2,IMAGE_BTN3,IMAGE_BTN4,IMAGE_BTN5,IMAGE_BTN6,IMAGE1,IMAGE2,LOGO;
image IMAGE_BTNR,IMAGE_BTNVUP,IMAGE_BTNVDOWN,IMAGE_BTNF,IMAGE_BTNN;
image IMAGE_BTNR1,IMAGE_BTNVUP1,IMAGE_BTNVDOWN1,IMAGE_BTNF1,IMAGE_BTNN1;
animation Backg;
Mix_Music *music;
Mix_Chunk *mus,*motion;
texte txte;
SDL_Event event;
int boucle=1;
int detect=0,detect1=0;
int choix=1;
int volume=128;
int Mode=0;
int posinit;
perso p;
Uint32 dt,t_prev;
screen=SDL_SetVideoMode(1000,500,32,SDL_HWSURFACE|SDL_SRCALPHA);
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("could not initialize : %s \n",SDL_GetError());
return-1;
}
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
mus=Mix_LoadWAV("mus.wav");
motion=Mix_LoadWAV("motion.wav");
initialiser_imageBACK(&IMAGE);//init background menu
initialiser_imageBACKOP(&IMAGE1);//init background option
initialiser_imageBACKPLAY(&IMAGE2);//init background play
//init bouton
initialiser_imageBOUTON1(&IMAGE_BTN1);
initialiser_imageBOUTON2(&IMAGE_BTN2);
initialiser_imageBOUTON3(&IMAGE_BTN3);
initialiser_imageBOUTON4(&IMAGE_BTN4);
initialiser_imageBOUTON5(&IMAGE_BTN5);
initialiser_imageBOUTON6(&IMAGE_BTN6);
initialiser_imageBOUTONR(&IMAGE_BTNR);
initialiser_imageBOUTONVUP(&IMAGE_BTNVUP);
initialiser_imageBOUTONVDOWN(&IMAGE_BTNVDOWN);
initialiser_imageBOUTONF(&IMAGE_BTNF);
initialiser_imageBOUTONN(&IMAGE_BTNN);
initialiser_imageBOUTONR1(&IMAGE_BTNR1);
initialiser_imageBOUTONVUP1(&IMAGE_BTNVUP1);
initialiser_imageBOUTONVDOWN1(&IMAGE_BTNVDOWN1);
initialiser_imageBOUTONF1(&IMAGE_BTNF1);
initialiser_imageBOUTONN1(&IMAGE_BTNN1);
initialiser_audio(music);
initPerso(&p);
initialiser_imageBACKp(&IMAGE2);
while(boucle)
{
t_prev=SDL_GetTicks();
if(choix==1)//afficher menu if choix=1
{
		
	afficher_imageBMP(screen,IMAGE);
	//afficher_texte(screen,txte);
	if (detect==0)
	{
	afficher_imageBTN(screen,IMAGE_BTN1);
	afficher_imageBTN(screen,IMAGE_BTN2);
	afficher_imageBTN(screen,IMAGE_BTN3);
	}
	else if(detect==1)
	{
	afficher_imageBTN(screen,IMAGE_BTN4);//motion play
	afficher_imageBTN(screen,IMAGE_BTN2);
	afficher_imageBTN(screen,IMAGE_BTN3);
	}
	else if(detect==2)
	{
	afficher_imageBTN(screen,IMAGE_BTN1);//motion option
	afficher_imageBTN(screen,IMAGE_BTN5);
	afficher_imageBTN(screen,IMAGE_BTN3);
	}
	else if(detect==3)
	{
	afficher_imageBTN(screen,IMAGE_BTN1);//motion quitter
	afficher_imageBTN(screen,IMAGE_BTN2);
	afficher_imageBTN(screen,IMAGE_BTN6);
	}
}
if(choix==2)// aficher play if choix=2
{
	//afficher_imageBMP(screen,IMAGE2);
	afficher_image(screen,IMAGE2);
	afficherPerso(p,screen);
	 
}
if(choix==3)//afficher options if choix=3
{
	afficher_imageBMP(screen,IMAGE1);
	if(detect1==0)
	{
		afficher_imageBTN(screen,IMAGE_BTNR);
		afficher_imageBTN(screen,IMAGE_BTNVUP);
		afficher_imageBTN(screen,IMAGE_BTNVDOWN);
		afficher_imageBTN(screen,IMAGE_BTNF);
		afficher_imageBTN(screen,IMAGE_BTNN);
	}
	else if(detect1==1)
	{
		afficher_imageBTN(screen,IMAGE_BTNR1);//motion return menu
		afficher_imageBTN(screen,IMAGE_BTNVUP);
		afficher_imageBTN(screen,IMAGE_BTNVDOWN);
		afficher_imageBTN(screen,IMAGE_BTNF);
		afficher_imageBTN(screen,IMAGE_BTNN);
	}
	else if(detect1==2)
	{
		afficher_imageBTN(screen,IMAGE_BTNR);//motion volume up
		afficher_imageBTN(screen,IMAGE_BTNVUP1);
		afficher_imageBTN(screen,IMAGE_BTNVDOWN);
		afficher_imageBTN(screen,IMAGE_BTNF);
		afficher_imageBTN(screen,IMAGE_BTNN);
	}
	else if(detect1==3)
	{
		afficher_imageBTN(screen,IMAGE_BTNR);//motion volume down
		afficher_imageBTN(screen,IMAGE_BTNVUP);
		afficher_imageBTN(screen,IMAGE_BTNVDOWN1);
		afficher_imageBTN(screen,IMAGE_BTNF);
		afficher_imageBTN(screen,IMAGE_BTNN);
	}
	else if(detect1==4)
	{
		afficher_imageBTN(screen,IMAGE_BTNR);//motion boutton full screen
		afficher_imageBTN(screen,IMAGE_BTNVUP);
		afficher_imageBTN(screen,IMAGE_BTNVDOWN);
		afficher_imageBTN(screen,IMAGE_BTNF1);
		afficher_imageBTN(screen,IMAGE_BTNN);
	}
	else if(detect1==5)
	{
		afficher_imageBTN(screen,IMAGE_BTNR);//motion boutton normall screen
		afficher_imageBTN(screen,IMAGE_BTNVUP);
		afficher_imageBTN(screen,IMAGE_BTNVDOWN);
		afficher_imageBTN(screen,IMAGE_BTNF);
		afficher_imageBTN(screen,IMAGE_BTNN1);
	}
}
 while(SDL_PollEvent(&event))
 {
		    switch(event.type)
		    {
		       case SDL_MOUSEMOTION:
			if(choix==1)
			{
				  if(event.motion.y<=280 && event.motion.y>=230 &&(event.motion.x<=800 && event.motion.x>=600))//play
				   {
					Mix_PlayChannel(-1,motion,0);
					detect=1;
				   }
				  else if(event.motion.y<=380 && event.motion.y>=330 &&(event.motion.x<=800 && event.motion.x>=600))//option
				   { 
					Mix_PlayChannel(-1,motion,0);
					detect=2;
				   }
				  else if(event.motion.y<=470 && event.motion.y>=420 &&(event.motion.x<=800 && event.motion.x>=600))//quitter
				   {
					Mix_PlayChannel(-1,motion,0);
					detect=3;
				   }
				else
				   {
					detect=0;
				   }	
			}
			if(choix==3)
			{
				if(event.motion.y<=70 && event.motion.y>=0&&(event.motion.x<=70 && event.motion.x>=0))//retour au menu
				   {
					Mix_PlayChannel(-1,motion,0);
					detect1=1;
				   }
				else if(event.motion.y<=200 && event.motion.y>=160&&(event.motion.x<=460 && event.motion.x>=400))//augmentation volume
				{
					Mix_PlayChannel(-1,motion,0);
					detect1=2;
				}
				else if(event.motion.y<=200 && event.motion.y>=170&&(event.motion.x<=220 && event.motion.x>=185))//diminution volume
				{
					Mix_PlayChannel(-1,motion,0);
					detect1=3;
				}
				else if(event.motion.y<=320 && event.motion.y>=280&&(event.motion.x<=480 && event.motion.x>=400))//full
				{
					Mix_PlayChannel(-1,motion,0);
					detect1=4;
				}
				else if(event.motion.y<=320 && event.motion.y>=280&&(event.motion.x<=280 && event.motion.x>=200))//normal
				{
					Mix_PlayChannel(-1,motion,0);
					detect1=5;
				}	
				else
				{
					detect1=0;
				}
			}
		       break;
		      case SDL_MOUSEBUTTONDOWN:
			if(choix==1)//menu
			{
				if((event.button.button==SDL_BUTTON_LEFT)&& (event.motion.y<=280 && event.motion.y>=230 &&(event.motion.x<=800 && event.motion.x>=600)))
				  {
			 	       Mix_PlayChannel(-1,mus,0);
				       choix=2;
				  }
				if( (event.button.button==SDL_BUTTON_LEFT)&&(event.motion.y<=380 && event.motion.y>=330 &&(event.motion.x<=800 && event.motion.x>=600)))
				  {	
				      Mix_PlayChannel(-1,mus,0);
				      choix=3;
				  }
				if((event.button.button==SDL_BUTTON_LEFT) && (event.motion.y<=470 && event.motion.y>=420 &&(event.motion.x<=800 && event.motion.x>=600)))
				{
					Mix_PlayChannel(-1,mus,0);
					boucle=0;
				}
			}
			if(choix==3)//option
			{
				if((event.button.button==SDL_BUTTON_LEFT) &&(event.motion.y<=70 && event.motion.y>=0&&(event.motion.x<=70 && event.motion.x>=0)))
				   {
					detect1=1;
					choix=1;

				   }
				else if((event.button.button==SDL_BUTTON_LEFT) && event.motion.y<=200 && event.motion.y>=160&&(event.motion.x<=460 && event.motion.x>=400))
				{
					Mix_PlayChannel(-1,mus,0);
 					volume+=30;
					setMusicVolume(volume);
				}
				else if((event.button.button==SDL_BUTTON_LEFT) && event.motion.y<=200 && event.motion.y>=170&&(event.motion.x<=220 && event.motion.x>=185))
				{
					Mix_PlayChannel(-1,mus,0);
					volume-=30;
                                        setMusicVolume(volume);
				}
				else if(event.motion.y<=320 && event.motion.y>=280&&(event.motion.x<=480 && event.motion.x>=400))
				{
					Mix_PlayChannel(-1,mus,0);
					SetFull(screen,&Mode);
				}
				else if(event.motion.y<=320 && event.motion.y>=280&&(event.motion.x<=280 && event.motion.x>=200))
				{
					Mix_PlayChannel(-1,mus,0);
					SetNorm(screen,&Mode);
				}
				else
				{
					detect1=0;
				}
				SaveScreenMode(screen,&Mode);
			}
		         break;
			case SDL_KEYDOWN:
			if(event.key.keysym.sym==SDLK_ESCAPE)
				boucle=0;
			if(choix==1)
			{
				if(event.key.keysym.sym==SDLK_p)
				{
					choix=2;
				}
				else if(event.key.keysym.sym==SDLK_o)
				{
					choix=3;
				}
				else
				{
					choix=1;
				}
				
			}
			else if(choix==3)
			{
				if(event.key.keysym.sym==SDLK_F3)
				{
					volume+=50;
					setMusicVolume(volume);
				}
				if(event.key.keysym.sym==SDLK_F2)
				{
					volume-=50;
                                        setMusicVolume(volume);
				}
				if(event.key.keysym.sym==SDLK_LEFT)
				{
					choix=1;
				}
				if(event.key.keysym.sym==SDLK_f)
				{
					SetFull(screen,&Mode);
				}
				if(event.key.keysym.sym==SDLK_n)
				{
					SetNorm(screen,&Mode);
				}
			}
			else if(choix==0)
			{
				if(event.key.keysym.sym==SDLK_SPACE)
				{
					choix=1;
				}
				
			}
			else if(choix==2)
			{
				/*if(event.key.keysym.sym==SDLK_LEFT)
				{
					choix=1;
				}*/
				//case SDL_KEYDOWN:
				if(event.key.keysym.sym==SDLK_SPACE)//saut_parabolique
				{
					posinit=p.position.y;
					p.up=3;
				}
				if(event.key.keysym.sym==SDLK_LEFT)//gauche=2
				{
					p.direction=2;
					 p.acceleration +=  0.001; 
				}
				if(event.key.keysym.sym==SDLK_RIGHT)//droit=1
				{
					p.direction=1;
				         p.acceleration +=  0.001; 
					
				}
				if(event.key.keysym.sym==SDLK_ESCAPE)
					boucle=0;
				if(event.key.keysym.sym ==SDLK_UP && p.up==0)//saut_vertical
				{
				    posinit=p.position.y;
				    p.up=1;
				}
 			}
			
      		         break;
				case SDL_KEYUP:
				if(choix==2)
				{
				    switch (event.key.keysym.sym)
				    {
				        case SDLK_RIGHT:
					    p.vitesse=0.5;
					    p.acceleration=0;
				            p.direction=3; 
				            break;
				        case SDLK_LEFT:
					    p.vitesse=0.5;
					    p.acceleration=0;
				            p.direction=4;
				}
				            break;
				    }
    			 case SDL_QUIT:
      				boucle=0;
      		          break;
   }
			p.acceleration -=0.00001;
			if (p.acceleration<0 ) p.acceleration=0;
			if (p.acceleration>2) p.acceleration=2;				
			//SDL_Delay(20);
			if(p.up==1|| p.up==2)//saut vertical
        		{
				
            		        saut(&p,dt,p.position.x,posinit);
			
                        }
			if(p.up==3)//saut parabolique
			{
				p.px=p.position.x;
				p.py=p.position.y;
				while(p.posRelative.x>=-50 && p.posRelative.x<50)
				{
					SDL_Delay(10);
					saut(&p,dt,p.position.x,posinit);
					afficher_image(screen,IMAGE2);
					afficherPerso(p,screen);
					SDL_Flip(screen);
				}
					p.posRelative.x=-50;
					p.posRelative.y=0;
					p.up=0;
			}
	 movePerso (&p,dt);
	 animerPerso (&p);
	dt=SDL_GetTicks()-t_prev;	
   SDL_Flip(screen);

}
}
liberer_image(IMAGE);
liberer_image(IMAGE1);
//liberer_image(LOGO);
liberer_image(IMAGE_BTN1);
liberer_image(IMAGE_BTN2);
liberer_image(IMAGE_BTN3);
liberer_image(IMAGE_BTN4);
liberer_image(IMAGE_BTN5);
liberer_image(IMAGE_BTN6);
liberer_image(IMAGE_BTNR);
liberer_image(IMAGE_BTNVUP);
liberer_image(IMAGE_BTNVDOWN);
liberer_image(IMAGE_BTNF);
liberer_image(IMAGE_BTNN);
liberer_image(IMAGE_BTNR1);
liberer_image(IMAGE_BTNVUP1);
liberer_image(IMAGE_BTNVDOWN1);
liberer_image(IMAGE_BTNF1);
liberer_image(IMAGE_BTNN1);
Mix_HaltMusic();
liberer_musique(music);
liberer_musiquebref(mus);
liberer_musiquebref(motion);
liberer_texte(txte);
libererA(&Backg);
liberer(p,screen);
liberer_image(IMAGE2);
SDL_Quit();
return 0;
}
