#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "boild.h" //definitions of structure, functions

/* Defines with parameters */
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800
#define NR_BOIDS 50
#define FPS 50

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
      b[i].pos.x=rand()%1024;
      b[i].pos.y=rand()%800;
      b[i].vel.x=0;
      b[i].vel.y=0;
      b[i].v_upd.cen=0;
      b[i].v_upd.rep=0;
      b[i].v_upd.coh=0;
      b[i].v_upd.tar=0;
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

void clean_up(SDL_Surface* screen)
{
  /* Clean up stuff you have allocated */
  SDL_FreeSurface(screen);
  SDL_Quit();
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
  put_pixel(screen, b[i].pos.x,b[i].pos.y, &pixel_white);
  }

  /*----------------------*/
  SDL_UnlockSurface(screen);
  
  /* Flip buffers */
  SDL_Flip(screen);
  clear_screen(screen);

  return 0;
}

void update_boids(void)
{
    double * param=read_parameters();//pointer to acces the parameters
        //* param    = k_centre
        //* (param+1)= k_repulsion
        //* (param+2)= k_cohesion
        //* (param+3)= k_target
        //* (param+4)= V_MAX
        //* (param+5)= REPULSION_DISTANCE
}

void read_mouse(SDL_Event* event){
  //fprintf(stderr,"%d,%d\n",event->motion.x,event->motion.y);
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
