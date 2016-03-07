#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct SPRITE
{
        int x , y;
        int width , height;
        int xspeed , yspeed;
        int curframe , maxframe;
        int framecount , framedelay;
}SPRITE;

BITMAP *grabframe(BITMAP *source , int width , int height , int startx , int starty , int columns , int frame)
{
	BITMAP *temp = create_bitmap(width , height);
	int x = startx + (frame % columns) * width;
	int y = starty + (frame / columns) * height;
	blit(source , temp , x , y , 0 , 0 , width , height);
	return (temp);
}

int collide_object(SPRITE *a , SPRITE *b)
{
 	if( ( (a->x + a->width) < b->x) || (a->x > (b->x + b->width)) || ((a->y + a->height) < b->y) || (a->y > (b->y +b->height)))
 			  return 0;
    else 
    
    	
    	 return 1;
}
/*
int collidecrystal(SPRITE *a , SPRITE *b)
{
    if(((a->x + a->width) < b->x) || (a->x > (b->x + b->width)) || ((a->y + a->height) < b->y) || (a->y > (b->y + b->height)))
              return 0;
    else
              return 1;
}
*/
///////////// main function///////////
void init();
void load_bitmaps();
void  load_sounds();
void ticker();
void starting_menu();
void CloseButtonCallback();
void deinit(); 
////////////////////////////////////

/////// inside starting menu//////////
void respond_pos();
void gamea();
void credita();
void helpa();
////////////////////////////////////

//////////////inside help////////////
void credit_scrol();


////////// inside game//////////////////////////////////////////////////////////////////////////////////////////////
void grabbing_frame();
void loadmap();
void initialize();
void time_count();
void keyinput();
void updating_crystals();
void update_game();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////inside grabbibg_frame()////////////////////////////////////////////////////////////////////
BITMAP *grabframe(BITMAP *source , int width , int height , int startx , int starty , int columns , int frame);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////inside initialize///////////////////
void mario_init();
void key_init();
void crystal_init( SPRITE **);
//////////////////////////////////////////

//////inside keyinput/////////
void level_complete();
void game_complete();
void resumea();
int collided(int x , int y);
int collidedtop(int x , int y);
///////////////////////////////////

////////////inside game complete///////////////
void key_posi();

//////////////inside updating_crystals///////////////////
void update_crysss(SPRITE * );

////////////////////////////////////////////////////////

//////////////  update game ////////////////////////////
void collides();
void crystal_posi();

//////////////////////////////////////////////////////

/////////////inside collides/////////////////
int collide_object(SPRITE *a , SPRITE *b);

////////////////////////////////////////////////////


void coin_count();


#endif 
