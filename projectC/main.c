//  main.c
//  Created by Mario Loera Lozano on 10/20/14.
//  EL2310 C project Boild Algorithm
//  Copyright (c) 2014 kth. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>


/* Defines with parameters */
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800
#define NR_BOIDS 500
#define FPS 50

#include "boid.h" //definitions of structure, functions
struct boid b[NR_BOIDS];//array of boild
struct boid *bp=&b[0];//pointer to acces the array

/* Data types */
typedef struct _pixel{
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 alpha;} pixel;

/* Function declarations */
int render_screen(SDL_Surface* screen);
void update_boids(void);
void clean_up(SDL_Surface* screen);
void read_mouse(SDL_Event* event);
void put_pixel(SDL_Surface* screen,int x,int y,pixel* p);
void clear_screen(SDL_Surface* screen);
void render_boids(void);

/* Main function */
int main(int argc,char** argv)
{
  write_parameters();//cretete text file for velocit parametes and gains
  SDL_Surface* screen;
  SDL_Event event;
  int done;
  Uint32 old_time,current_time;

  /* Initialise screen */
  if(SDL_Init(SDL_INIT_VIDEO)!=0) {
    fprintf(stderr,"Failed to Open Screen\n");
    return -1;
  }
  screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,8,SDL_DOUBLEBUF|SDL_SWSURFACE|SDL_ANYFORMAT);
  if(screen == NULL) {
    fprintf(stderr,"Failed to set video mode: %s\n",SDL_GetError());
    return -1;
  }

  /* Set up boids Random x[0:1024], y[0:800]*/
  int i;
  for(i=0;i<NR_BOIDS;i++){
      b[i].pos.x=rand()%SCREEN_WIDTH;
      b[i].pos.y=rand()%SCREEN_HEIGHT;
      b[i].pos.z=rand()%SCREEN_HEIGHT;

      b[i].vel.x=0;
      b[i].vel.y=0;
      b[i].vel.z=0;

      b[i].v_cen.x=0;
      b[i].v_cen.y=0;
      b[i].v_cen.z=0;

      b[i].v_rep.x=0;
      b[i].v_rep.y=0;
      b[i].v_rep.z=0;

      b[i].v_coh.x=0;
      b[i].v_coh.y=0;
      b[i].v_coh.z=0;

      b[i].v_tar.x=0;
      b[i].v_tar.y=0;
      b[i].v_tar.z=0;
  }
  
  /* Event loop */
  done = 0;
  current_time = SDL_GetTicks();
  old_time = current_time;
  while(!done) {

    if(!SDL_PollEvent(&event)) {
      switch(event.type) {
      case SDL_KEYDOWN:
        if(event.key.keysym.sym == SDLK_ESCAPE) {
          done = 1;
          break;
        }
      case SDL_QUIT:
        done = 1;
        break;
      case SDL_MOUSEMOTION:
        read_mouse(&event);
      }
    }
    current_time = SDL_GetTicks();
    if(((current_time-old_time)%(1000/FPS))==0) {
      old_time = current_time;
      update_boids();
      render_screen(screen);
    }
  }
  
  /* Clean up */
  clean_up(screen);
  return 0;
}

void update_boids(void)
{
    int i,j;//counters for loops
    double dist=0;
    double * param=read_parameters();//pointer to acces the parameters
       double k_centre= * param;
       double k_repulsion= * (param+1);
       double k_cohesion= * (param+2);
       double k_target= * (param+3);
       double v_max= * (param+4);
       double REPULSION_DISTANCE= * (param+5);

    //p_average
    p_average.x=0;
    p_average.y=0;
    p_average.z=0;
    for(i=0;i<NR_BOIDS;i++){
        p_average.x+=b[i].pos.x;
        p_average.y+=b[i].pos.y;
        p_average.z+=b[i].pos.z;
    }
    p_average.x/=NR_BOIDS;
    p_average.y/=NR_BOIDS;
    p_average.z/=NR_BOIDS;

    //v_average
    v_average.x=0;
    v_average.y=0;
    v_average.z=0;
    for(i=0;i<NR_BOIDS;i++){
        v_average.x+=b[i].vel.x;
        v_average.y+=b[i].vel.y;
        v_average.z+=b[i].vel.z;
    }
    v_average.x/=NR_BOIDS;
    v_average.y/=NR_BOIDS;
    v_average.z/=NR_BOIDS;

    //cohesion velocit
    for(i=0;i<NR_BOIDS;i++){
        b[i].v_coh.x=v_average.x-b[i].vel.x;
        b[i].v_coh.y=v_average.y-b[i].vel.y;
        b[i].v_coh.z=v_average.z-b[i].vel.z;
    }

    //restet repulsion velocity
    for(i=0;i<NR_BOIDS-1;i++){
        b[i].v_rep.x=0;
        b[i].v_rep.y=0;
        b[i].v_rep.z=0;
    }
    //new repulsion velocity
    int n=1;
    for(i=0;i<NR_BOIDS-1;i++){
         for(j=n;j<NR_BOIDS;j++){
             //fprintf(stderr,"i=%d,j=%d\n",i,j);
             //calculate diference
             dif.x=b[i].pos.x-b[j].pos.x;
             dif.y=b[i].pos.y-b[j].pos.y;
             dif.z=b[i].pos.z-b[j].pos.z;
             //distance, no neet to get square root
             dist=dif.x*dif.x+dif.y*dif.y+dif.z*dif.z;
             //upadte repulsion velocity
             if (dist<REPULSION_DISTANCE*REPULSION_DISTANCE){
                 b[i].v_rep.x+=dif.x;
                 b[j].v_rep.x-=dif.x;
                 b[i].v_rep.y+=dif.y;
                 b[j].v_rep.y-=dif.y;
                 b[i].v_rep.z+=dif.z;
                 b[j].v_rep.z-=dif.z;
             }
         }
         n++;
    }

    //Centering velocity
     for(i=0;i<NR_BOIDS;i++){
         b[i].v_cen.x=p_average.x-b[i].pos.x;
         b[i].v_cen.y=p_average.y-b[i].pos.y;
         b[i].v_cen.z=p_average.z-b[i].pos.z;
     }

    //Target velocity    k_target= * (param+3)
    for(i=0;i<NR_BOIDS;i++){
        b[i].v_tar.x=p_target.x-b[i].pos.x;
        b[i].v_tar.y=p_target.y-b[i].pos.y;
        b[i].v_tar.z=p_target.z-b[i].pos.z;
    }
    //total velocity & clamp
    for(i=0;i<NR_BOIDS;i++){
        b[i].vel.x+=k_target*b[i].v_tar.x+k_centre*b[i].v_cen.x+k_cohesion*b[i].v_coh.x+k_repulsion*b[i].v_rep.x;
        b[i].vel.y+=k_target*b[i].v_tar.y+k_centre*b[i].v_cen.y+k_cohesion*b[i].v_coh.y+k_repulsion*b[i].v_rep.y;
        b[i].vel.z+=k_target*b[i].v_tar.z+k_centre*b[i].v_cen.z+k_cohesion*b[i].v_coh.z+k_repulsion*b[i].v_rep.z;

        b[i].vel.x=clamp_double(b[i].vel.x,-1*v_max,v_max);
        b[i].vel.y=clamp_double(b[i].vel.y,-1*v_max,v_max);
        b[i].vel.z=clamp_double(b[i].vel.z,-1*v_max,v_max);
    }

    //position update & cast
    for(i=0;i<NR_BOIDS;i++){
        b[i].pos.x+=b[i].vel.x;
        b[i].pos.y+=b[i].vel.y;
        b[i].pos.z+=b[i].vel.z;

        b[i].pos.x=clamp_double(b[i].pos.x,1,SCREEN_WIDTH-1);
        b[i].pos.y=clamp_double(b[i].pos.y,1,SCREEN_HEIGHT-1);
        b[i].pos.z=clamp_double(b[i].pos.z,5,SCREEN_HEIGHT-1);
    }
}

int render_screen(SDL_Surface* screen)
{
  int i;
  double x,y,z;
  pixel pixel_white;
  pixel_white.r = (Uint8)0xff;
  pixel_white.g = (Uint8)0xff;
  pixel_white.b = (Uint8)0xff;
  pixel_white.alpha = (Uint8)128;


  SDL_LockSurface(screen);
  /* Do your rendering here */

  /* For instance, to draw a single pixel (replace with actual rendering code): */

  for(i=0;i<NR_BOIDS;i++){
      int x=b[i].pos.x;
      int y=b[i].pos.y;

      x=clamp_int(x,0,SCREEN_WIDTH);
      y=clamp_int(y,0,SCREEN_HEIGHT);

      put_pixel(screen, x,y, &pixel_white);
  }
  /*----------------------*/
  SDL_UnlockSurface(screen);

  /* Flip buffers */
  SDL_Flip(screen);
  clear_screen(screen);

  return 0;
}

void read_mouse(SDL_Event* event){
  //fprintf(stderr,"%d,%d\n",event->motion.x,event->motion.y);

    p_target.x=event->motion.x;
    p_target.y=event->motion.y;
    //p_target.z=0;
}

void put_pixel(SDL_Surface* screen,int x,int y,pixel* p)
{
  Uint32* p_screen = (Uint32*)screen->pixels;
  p_screen += y*screen->w+x;
  *p_screen = SDL_MapRGBA(screen->format,p->r,p->g,p->b,p->alpha);  
}

void clear_screen(SDL_Surface* screen)
{
  Uint32 p = SDL_MapRGBA(screen->format,0x00,0x00,0x00,0xff);
  if(SDL_FillRect(screen,NULL,p)) {
    fprintf(stderr,"Failed to clear screen\n");
  }
}

void clean_up(SDL_Surface* screen)
{
  /* Clean up stuff you have allocated */
  SDL_FreeSurface(screen);
  SDL_Quit();
}
