#include <stdio.h>
#include <allegro.h>
#include "mappyal.h"
//#include "mappyal.c"

#define MODE GFX_AUTODETECT
#define WIDTH 1024
#define HEIGHT 640
#define JUMPIT 1600

//timer
volatile long ticks = 0;

void ticker()
{
     ticks++;
}

//srite structure
typedef struct SPRITE
{
        int dir , alive;
        int x , y;
        int width , height;
        int xspeed , yspeed;
        int xdelay , ydelay;
        int xcount , ycount;
        int curframe , maxframe , animdir;
        int framecount , framedelay;
}SPRITE;

//bitmaps and sprites declarations
BITMAP *player_img[3];
SPRITE *player;
BITMAP *buffer;
BITMAP *temp;

//other declarations
int jump = JUMPIT;
int facing = 1;
int oldpx , oldpy;
int i;

void init()
{
     allegro_init();
     install_keyboard();
     install_timer();
     set_color_depth(32);
     set_gfx_mode(MODE , WIDTH , HEIGHT , 0 , 0);
     
     LOCK_VARIABLE(ticks);
     LOCK_FUNCTION(ticker);
     
     install_int_ex(ticker , BPS_TO_TIMER(80));
}

//tile grabber
BITMAP *grabframe(BITMAP *source , int width , int height , int startx , int starty , int columns , int frame)
{
       BITMAP *temp = create_bitmap(width , height);
       int x = startx + (frame % columns) * width;
       int y = starty + (frame / columns) * height;
       blit(source , temp , x , y , 0 , 0 , width , height);
       return (temp);
}

//collision control
int collided(int x , int y)
{
    BLKSTR *blockdata;
    blockdata = MapGetBlock((x / mapblockwidth) , (y / mapblockheight));
    return blockdata->tl;
}

int collidedtop(int x , int y)
{
    BLKSTR *blockdata;
    blockdata = MapGetBlock((x / mapblockwidth) , (y / mapblockheight));
    return blockdata->br;
}

void loadmap()
{
     if(MapLoad("map.fmp"))
                           exit(0);
     buffer = create_bitmap(WIDTH , HEIGHT);
     clear(buffer);
}

void keyinput()
{
     if(key[KEY_RIGHT])
     {
                       facing = 1;
                       player->x += 3;
                       if(++player->framecount > player->framedelay)
                       {
                                               player->framecount = 0;
                                               if(++player->curframe > player->maxframe)
                                                                     player->curframe = 0;
                       }
                       if((player->x + player->width) > mapwidth*mapblockwidth)
                                     player->x = (mapwidth*mapblockwidth - player->width);
     }
     else if(key[KEY_LEFT])
     {
                       facing = 0;
                       player->x -= 3;
                       if(++player->framecount > player->framedelay)
                       {
                                               player->framecount = 0;
                                               if(++player->curframe > player->maxframe)
                                                                     player->curframe = 0;
                       }
                       if(player->x < 0)
                                    player->x = 0;
     }
     else player->curframe = 0;
     
     //jump handling
     if(jump == JUMPIT)
     {
             //gravity code
             if(!collided(player->x + (player->width / 2) , player->y + player->height + 5))
             {
                                    jump = 0;
             }
             if(key[KEY_SPACE])
             {
                               jump = 35;
             }
     }
     else
     {
         player->curframe = 1;
         player->y -= jump / 3;
         jump--;
         if(player->y < 0)
                      player->y = 0;
         if(collidedtop(player->x , player->y))
                                  player->y = oldpy;                         
     }
     if(jump < 0)
     {
             if(collided(player->x + (player->width / 2) , player->y + player->height))
             {
                                   jump = JUMPIT;
                                   while(collided(player->x + (player->width / 2) , player->y + player->height))
                                                            player->y -= 2;
             }
     }
}

void initialize_player()
{
     player = malloc(sizeof(SPRITE));
     player->x = 80;
     player->y = 200;
     player->curframe = 0;
     player->framecount = 0;
     player->framedelay = 11;
     player->maxframe = 2;
     player->width = player_img[0]->w;
     player->height = player_img[0]->h;
}

void update_game()
{
     register int mapxoff , mapyoff;
     //collision detection
     if(!facing)
     {
               if(collided(player->x , player->y + player->height))
                                     player->x = oldpx;                               
     }
     else
     {
               if(collided(player->x +player->width , player->y + player->height))
                                     player->x = oldpx;         
     }
     
     //update the map scroll position
     mapxoff = player->x + (player->width / 2) - (WIDTH / 2) + 10;
     mapyoff = player->y + (player->height / 2) - (HEIGHT / 2) + 10;
     
     //aviod moving beyond the map edges
     if(mapxoff < 0)
                mapxoff = 0;
     if(mapxoff > (mapwidth * mapblockwidth - WIDTH))
                mapxoff = (mapwidth * mapblockwidth - WIDTH);
     if(mapyoff < 0)
                mapyoff = 0;
     if(mapyoff > (mapheight * mapblockheight - HEIGHT))
                mapyoff = (mapheight * mapblockheight - HEIGHT);
                
     //draw the background tiles
     MapDrawBG(buffer , mapxoff , mapyoff , 0 , 0 , WIDTH - 1 , HEIGHT - 1);
     //draw foreground tiles
     MapDrawFG(buffer , mapxoff , mapyoff , 0 , 0 , WIDTH - 1 , HEIGHT - 1 , 0);
     
     //draw player's sprite
     if(facing)
     {
               draw_sprite(buffer , player_img[player->curframe] , (player->x - mapxoff) , (player->y - mapyoff));
     }
     else
     {
               draw_sprite_h_flip(buffer , player_img[player->curframe] , (player->x - mapxoff) , (player->y - mapyoff));
     }
     blit(buffer , screen , 0 , 0 , 0 , 0 , WIDTH - 1 , HEIGHT - 1);
     clear(buffer);
}

void deinit()
{
     for(i = 0 ; i < 3 ; i++)
           destroy_bitmap(player_img[i]);
     destroy_bitmap(buffer);
     free(player);
     MapFreeMem();
     MapFreeMem();
}

main(void)
{
          init();
          
          temp = load_bitmap("mario.bmp", NULL);
          for(i = 0 ; i < 3 ; i++)
          {
                player_img[i] = grabframe(temp , 57 , 72 , 0 , 0 , 3 , i);
          }
          destroy_bitmap(temp);
       first:
          initialize_player();
          
          loadmap();
          
          //main game loop
          while(!key[KEY_ESC])
          {
                    oldpx = player->x;
                    oldpy = player->y;
                    while(ticks > 0)
                    {         
                              keyinput();
                              if(player->y > 550)
                                           goto first;
                              ticks--;
                    }                              
                              update_game();
          }
          deinit();
          allegro_exit();
          return 0;
}
END_OF_MAIN();
