#include <allegro.h>
#include "mappyal.h"
#include "functions.h"
#include "variables.h"
#include "images.h"
#include "sounds.h"

#define MODE GFX_AUTODETECT
#define WIDTH 1024
#define HEIGHT 640


int main()
{
	init();
	load_sounds();
	load_bitmaps();
	starting_menu();

	deinit();
	allegro_exit();
	return 0;
}
END_OF_MAIN();

void init()
{
	allegro_init();
	install_keyboard();

	install_timer();
	set_color_depth(32);
	set_gfx_mode(MODE , WIDTH , HEIGHT , 0 , 0);
	install_mouse();
	install_sound(DIGI_AUTODETECT , MIDI_NONE , "");

	LOCK_VARIABLE(ticks);
	LOCK_FUNCTION(ticker);
	 srand(time(NULL));

	LOCK_FUNCTION(CloseButtonCallback);
	set_close_button_callback(CloseButtonCallback);

	install_int_ex(ticker , BPS_TO_TIMER(80));
	set_mouse_sprite(arrow);
	set_mouse_sprite_focus(0,0);
	show_mouse(buffer2);

	set_window_title("Platformer");
   
}



void load_sounds()
{
	sample_jump = load_sample("sounds/jump.wav");
	sample_theme=load_sample("sounds/a.wav");
	
	crystal_sound = load_sample("sounds/coin.wav");
	sample_click= load_sample("sounds/click.wav");
	sample_menu=load_sample("sounds/menu.wav");
	sample_resume=load_sample("sounds/b.wav");
}
void load_bitmaps()
{
	temp = load_bitmap("images/mario1.bmp", NULL);
	mare=load_bitmap("images/life.bmp",NULL);
	zero=load_bitmap("images/zero.bmp",NULL);
	one=load_bitmap("images/one.bmp",NULL);
	two=load_bitmap("images/two.bmp",NULL);
	three=load_bitmap("images/three.bmp",NULL);
	four=load_bitmap("images/four.bmp",NULL);
	five=load_bitmap("images/five.bmp",NULL);
	star=load_bitmap("images/star.bmp",NULL);
	six=load_bitmap("images/six.bmp",NULL);
	seven=load_bitmap("images/seven.bmp",NULL);
	
	keyi[0]=load_bitmap("images/keyi.bmp",NULL);
	
	
	temp1 = load_bitmap("images/crystalyellow.bmp", NULL);
	finish= load_bitmap("images/finish.bmp",NULL);
	finish1= load_bitmap("images/finish1.bmp",NULL);
	mar=load_bitmap("images/mar.bmp",NULL);
	menu=load_bitmap("images/menu.bmp",NULL);
	game=load_bitmap("images/game.bmp",NULL);
	//option=load_bitmap("images/option.bmp",NULL);
	credit=load_bitmap("images/credit.bmp",NULL);
	help=load_bitmap("images/help.bmp",NULL);
	exita=load_bitmap("images/exit.bmp",NULL);
	arrow=load_bitmap("images/2.bmp",NULL);
	resume=load_bitmap("images/resume.bmp",NULL);
	
	
	level1=load_bitmap("images/level1.bmp",NULL);
	level2=load_bitmap("images/level2.bmp",NULL);
	
	buffer5=create_bitmap(1024,640);
	a=load_bitmap("images/a.bmp",NULL);
	buffer3 = create_bitmap(1024, 640);
	
	buffer2 = create_bitmap(1024, 640);
	
	
	buffer6=create_bitmap(1024,640);
	cre=load_bitmap("images/cre.bmp",NULL);
		cre1=load_bitmap("images/cre1.bmp",NULL);
	

	arrow1=load_bitmap("images/3.bmp",NULL);
	helping=load_bitmap("images/helping.bmp",NULL);
	keying=load_bitmap("images/keying.bmp",NULL);
	abouting=load_bitmap("images/abouting1.bmp",NULL);
	gaming=load_bitmap("images/gaming.bmp",NULL);
	keyboard=load_bitmap("images/key.bmp",NULL);
	buffer4=create_bitmap(1024,640);	
}

void starting_menu()
{
 	 key_count=0;
 	 key_init();
	stop_sample(sample_menu);
	play_sample(sample_menu,volume,panning,pitch,TRUE);
	while(!closewindow)
	{
	     blit(mar,buffer2,0,0,0,0,mar->w,mar->h);
		masked_blit(menu,buffer2,0,0,0,0,menu->w,menu->h);
		textprintf_ex(buffer2, font, 15, 15, makecol(255,0,0), -1,"THIS GAME HAS BEEN DEVELOPED BY THE '5 BITS' GROUP.");
		respond_pos();

		masked_blit(arrow,buffer2,0,0,mouse_x,mouse_y,arrow->w,arrow->h);
		textprintf_ex(buffer2, font, 15,600, makecol(255,0,0), -1, "COPYRIGHT (C) 2012 HAMRO MARIO DEVEL TEAM.");
		textprintf_ex(buffer2, font, 15,630, makecol(255,0,0), -1, "This game comes ABSOLUTE NO WARRANTY. This if free software and you are not welcomed to redistribute it at any condition.");
		blit(buffer2,screen,0,0,0,0,screen->w,screen->h);
	}				
}

void respond_pos()
{	   
	if(mouse_x>=53 && mouse_x<=254)
	{
		if(mouse_y>=86 &&mouse_y<=160)
		{
			blit(game,buffer2,0,0,60,79,game->w,game->h);
			if(mouse_b==1)
			{
				stop_sample(sample_menu);
				play_sample(sample_click,volume,panning,pitch,FALSE);
				gamea();
				stop_sample(sample_theme);

			}

		}
	} 	

	if(mouse_x>=749 && mouse_x<=951)
	{
		if(mouse_y>=86 &&mouse_y<=160)
		{
			blit(help,buffer2,0,0,756,79,help->w,help->h);
			if(mouse_b==1)
			{
				play_sample(sample_click,volume,panning,pitch,FALSE);
				helpa();
			}
		}
	} 

	if(mouse_x>=49 && mouse_x<=251)
	{
		if(mouse_y>=500 &&mouse_y<=576)
		{
			blit(credit,buffer2,0,0,56,493,credit->w,credit->h);
			if(mouse_b==1)
			{
				play_sample(sample_click,volume,panning,pitch,FALSE);
				credita();
				cre_y=0;
			}

		}
	} 	
	if(mouse_x>=749 && mouse_x<=951)
	{
		if(mouse_y>=500 &&mouse_y<=576)
		{
			blit(exita,buffer2,0,0,752,493,exita->w,exita->h);
			if(mouse_b==1)
			{
				play_sample(sample_click,volume,panning,pitch,FALSE);

				rest(800);
				deinit();
				exit (0);
			//	allegro_exit();
				
			}
		}
	} 	
}

/////////////////////////////////////////////////////////////////////////////////

void credita()
{
 	 		  
 	 		  while(!key[KEY_Z])
 	 		  {	
			  					rest(10);
			  					credit_scrol();
			   				   blit(cre1,buffer6,0,0,0,0,cre1->w,cre1->h);
			   				    masked_blit(cre,buffer6,0,0,0,cre_y--,cre->w,cre->h);
			   				   blit(buffer6,screen,0,0,0,0,screen->w,screen->h);
			   				  
			 } 
}
void credit_scrol()
{
 	 cre_y-=0.1;
 	 if(cre_y<=-1920)
 	 cre_y=640;
}

void helpa()
{
 	 		
 	 		while(!key[KEY_SPACE])
 	 		{		
							
			 	masked_blit(helping,buffer4,0,0,0,0,helping->w,helping->h);
			 	masked_blit(abouting,buffer4,0,0,250,200,abouting->w,abouting->h);
				masked_blit(keying,buffer4,0,0,250,400,keying->w,keying->h);
			    masked_blit(arrow,buffer4,0,0,arrow1_x,arrow1_y,arrow->w,arrow->h);
			    if(key[KEY_DOWN])
				{
			    				 arrow1_y=450;
		     	 }
		 	    if(key[KEY_UP])
				{
			    				 arrow1_y=255;
			    		 	
			    				 
		     	 }	    
				   if(key[KEY_ENTER] && arrow1_y==450)
	    	     {
				    			
	  			  			  while(!key[KEY_Z])
 	  						  {
			    				 				  blit(keyboard,buffer4,0,0,0,0,keyboard->w,keyboard->h);
			    				 				  blit(buffer4,screen,0,0,0,0,screen->w,screen->h);
	  						  }
					}	 
					 if(key[KEY_ENTER] && arrow1_y==255)
	    	     {
				    			
	  			  			  while(!key[KEY_Z])
 	  						  {
			    				 				  blit(gaming,buffer4,0,0,0,0,gaming->w,gaming->h);
			    				 				  blit(buffer4,screen,0,0,0,0,screen->w,screen->h);
	  						  }
					}	 
	    	 
				  blit(buffer4,screen,0,0,0,0,screen->w,screen->h);
			  }
}

void gamea()
{	random=rand()%4;
	grabbing_frame();    




	for(i=1;i<=50;i++)
	{ 
		crystals[i]=TRUE;
	}			 			 
	loadmap();
	first:
		  if(map_no==1)
		   timea=24100;
	
		   else
		   timea=65000;
		   
	initialize();
	
	

	play_sample(sample_theme,volume,panning,pitch,TRUE);
	
	while(!key[KEY_ESC])
	{

						timea--;
						if(timea==0)
						{
						 			stop_sample(sample_theme);
						 				if(life>0)
 										  life--;
							goto first;	
							}  
		oldpx = player->x;
		oldpy = player->y;
		while(ticks > 0)
		{         
		
			keyinput();
			updating_crystals();
			
			if(map_no==1)
			{
				if(player->y > 550 )
				{
			 
				 			stop_sample(sample_theme);
					if(life>0)
					{
							  		life--;
										timea=24100;
					
						goto first;
					}

					else
					{
						stop_sample(sample_theme);
						stop_sample(sample_jump);
						deinit();
						allegro_message("GAMEOVER!");
						allegro_exit();
					}
				}
			}
			if(map_no==2)
			{
				if(player->y >= 1195 )
				{
					stop_sample(sample_theme);
					if(life>0 )
					{
					 		 
							   life--;
							   timea=65000;
							 
						goto first;
					}
					else
					{
						stop_sample(sample_theme);
						stop_sample(sample_jump);
						deinit();
						allegro_message("GAMEOVER!");
						allegro_exit();
					}
				}
			}		   
			ticks--;
		}                              
		update_game();
	}
	coin=0;
	life=2;
	
	play_sample(sample_menu,volume,panning,pitch,TRUE);
}

void resumea()
{
 	 	play_sample(sample_resume,volume,panning,pitch,TRUE);
	while(!key[KEY_Q])
	{
	 				  
		mouse_needs_poll(); //masked_blit(resume , buffer , 0 , 0 , 0 , 0 , resume->w , resume->h);
		masked_blit(resume , screen , 0 , 0 , 0 , 0 , screen->w, screen->h);
		if(key[KEY_ESC])
		{
		 				stop_sample(sample_resume);
			starting_menu();
		}
	}
	stop_sample(sample_resume);
	play_sample(sample_theme,volume,panning,pitch,TRUE);
}




void loadmap()
{
	if(map_no==1)
	{
		if(MapLoad("map.fmp"))
		exit(0);
		buffer = create_bitmap(WIDTH , HEIGHT);
		clear(buffer);
	}
	if(map_no==2)
	{
		if(MapLoad("newmap.fmp"))
		exit(0);
		buffer = create_bitmap(WIDTH , HEIGHT);
		clear(buffer);
	}	 
	
}

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


void time_count()
{

	
}

void level_complete()
{
 	 stop_sample(sample_resume);
 	 play_sample(sample_resume,volume,panning,pitch,TRUE);
 	     if(map_no==1)
 	     {
		  		 
 		  			   blit(level1,buffer3,0,0,0,0,level1->w,level1->h);
 					    blit(buffer3,screen,0,0,0,0,screen->w,screen->h);
	 					rest(4500);
			}
			if(map_no==2)
			{
				 
			 			   blit(level2,buffer3,0,0,0,0,level2->w,level2->h);
			 			     blit(buffer3,screen,0,0,0,0,screen->w,screen->h);	
							 rest(5000);
				game_complete();
			 }
}

void game_complete()
{
 	 				
 						 while(!key[KEY_ESC])
 						 {					
						 			
						  					 blit(a,buffer5,0,0,0,0,a->w,a->h);
											 	 blit(buffer5,screen,0,0,0,0,screen->w,screen->h);
												  if(key[KEY_ESC])
												  {
												   				  allegro_exit();
												 }
												  if(key[KEY_ENTER])
												  {
		   								 		   					map_no=1;
		   								 		   					coin=0;
											   						life=2;
																			  stop_sample(sample_resume);
												  							  starting_menu();
														 } 							  
						  }
}	




void keyinput()
{
	if((player->x >4735 && map_no==1) || (key[KEY_U] && map_no==1))
	{
	 	stop_sample(sample_theme);		 
	 	level_complete();
		stop_sample(sample_resume);		 
	 		map_no++;
		
		rest(240);
		loadmap();
		player->x=30;
		timea=65000;
		play_sample(sample_theme,volume,panning,pitch,TRUE);

	}
	if(map_no==2 && player->x>=13440 && player->x<=13565 && key[KEY_UP] && key_count==1  )
	{
	 			 stop_sample(sample_theme);
	 			 level_complete();
	 			 stop_sample(sample_resume);
	 			
	 } 
	 
	 
	
	if(key[KEY_P])
	{
				   			   stop_sample(sample_theme); 
			
			
		resumea();
  		stop_sample(sample_resume);
	}

	if(key[KEY_RIGHT])
	{		

		facing1 = 1;
		player->x += player->xspeed;
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
		facing1 = 0;
		player->x -= player->xspeed;
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
	if(jump == 1600)
	{
		//gravity code
		if(!collided(player->x + (player->width / 2) , player->y + player->height + 5))
		{
			jump = 0;
		}
	
		if(key[KEY_X])
		{
			jump = 35;
			play_sample(sample_jump , volume , panning , pitch , FALSE);
		}
	}
	else
	{
		player->curframe = 1;
		player->y -= jump / player->yspeed;
		jump--;

		if(player->y <= 0)
		{
			player->y = 0;
			player->xspeed = 4;
		}
		else
			player->xspeed = 3;
		if(collidedtop(player->x + (player->width / 2) , player->y))
		{
			player->y = oldpy + 2;
			jump = 0;
		}                         
	}
	if(jump < 0)
	{
		if(collided(player->x + (player->width / 2) , player->y + player->height))
		{
			jump = 1600;
			
			while(collided(player->x + (player->width / 2) , player->y + player->height))
			player->y -= 2;
		}
	}
}




void update_game()
{
	register int mapxoff , mapyoff;
	//collision detection
	if(!facing1)
	{
		if(collided(player->x , player->y + player->height))
		player->x = oldpx;                               
	}
	else
	{
		if(collided(player->x +player->width , player->y + player->height))
		player->x = oldpx;         
	}
	


	collides();

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

	//draw crystal sprite
	crystal_posi();
	key_posi();
	
	if(map_no==1)
	{
	 			draw_sprite(buffer , finish , 4735- mapxoff , 409- mapyoff);
		draw_sprite(buffer , crystal_img1[crystal1->curframe] , crystal1->x - mapxoff , crystal1->y - mapyoff);
		draw_sprite(buffer , crystal_img2[crystal2->curframe] , crystal2->x - mapxoff , crystal2->y - mapyoff);
		draw_sprite(buffer , crystal_img3[crystal3->curframe] , crystal3->x - mapxoff , crystal3->y - mapyoff);
		draw_sprite(buffer , crystal_img4[crystal4->curframe] , crystal4->x - mapxoff , crystal4->y - mapyoff);
		draw_sprite(buffer , crystal_img5[crystal5->curframe] , crystal5->x - mapxoff , crystal5->y - mapyoff);
		draw_sprite(buffer , crystal_img6[crystal6->curframe] , crystal6->x - mapxoff , crystal6->y - mapyoff);
		draw_sprite(buffer , crystal_img7[crystal7->curframe] , crystal7->x - mapxoff , crystal7->y - mapyoff);
		draw_sprite(buffer , crystal_img8[crystal8->curframe] , crystal8->x - mapxoff , crystal8->y - mapyoff);
		draw_sprite(buffer , crystal_img9[crystal9->curframe] , crystal9->x - mapxoff , crystal9->y - mapyoff);
		draw_sprite(buffer , crystal_img10[crystal10->curframe] , crystal10->x - mapxoff , crystal10->y - mapyoff);
		draw_sprite(buffer , crystal_img11[crystal11->curframe] , crystal11->x - mapxoff , crystal11->y - mapyoff);
		draw_sprite(buffer , crystal_img12[crystal12->curframe] , crystal12->x - mapxoff , crystal12->y - mapyoff);
		draw_sprite(buffer , crystal_img13[crystal13->curframe] , crystal13->x - mapxoff , crystal13->y - mapyoff);
		draw_sprite(buffer , crystal_img14[crystal14->curframe] , crystal14->x - mapxoff , crystal14->y - mapyoff);
		draw_sprite(buffer , crystal_img15[crystal15->curframe] , crystal15->x - mapxoff , crystal15->y - mapyoff);
		draw_sprite(buffer , crystal_img16[crystal16->curframe] , crystal16->x - mapxoff , crystal16->y - mapyoff);
		draw_sprite(buffer , crystal_img17[crystal17->curframe] , crystal17->x - mapxoff , crystal17->y - mapyoff);
		draw_sprite(buffer , crystal_img18[crystal18->curframe] , crystal18->x - mapxoff , crystal18->y - mapyoff);
		draw_sprite(buffer , crystal_img19[crystal19->curframe] , crystal19->x - mapxoff , crystal19->y - mapyoff);
		draw_sprite(buffer , crystal_img20[crystal20->curframe] , crystal20->x - mapxoff , crystal20->y - mapyoff);
		draw_sprite(buffer , crystal_img21[crystal21->curframe] , crystal21->x - mapxoff , crystal21->y - mapyoff);
		draw_sprite(buffer , crystal_img22[crystal22->curframe] , crystal22->x - mapxoff , crystal22->y - mapyoff);
		draw_sprite(buffer , crystal_img23[crystal23->curframe] , crystal23->x - mapxoff , crystal23->y - mapyoff);
		draw_sprite(buffer , crystal_img24[crystal24->curframe] , crystal24->x - mapxoff , crystal24->y - mapyoff);
		draw_sprite(buffer , crystal_img25[crystal25->curframe] , crystal25->x - mapxoff , crystal25->y - mapyoff);
	
	}

	if(map_no==2)
	{
	 				 			 
				  				draw_sprite(buffer , keyi[key_sprite->curframe] , key_sprite->x-mapxoff , key_sprite->y-mapyoff);
					
				  	draw_sprite(buffer , finish1 , 13200- mapxoff , 660- mapyoff);
		draw_sprite(buffer , crystal_img26[crystal26->curframe] , crystal26->x - mapxoff , crystal26->y - mapyoff);
		draw_sprite(buffer , crystal_img27[crystal27->curframe] , crystal27->x - mapxoff , crystal27->y - mapyoff);
		draw_sprite(buffer , crystal_img28[crystal28->curframe] , crystal28->x - mapxoff , crystal28->y - mapyoff);
		draw_sprite(buffer , crystal_img29[crystal29->curframe] , crystal29->x - mapxoff , crystal29->y - mapyoff);
		draw_sprite(buffer , crystal_img30[crystal30->curframe] , crystal30->x - mapxoff , crystal30->y - mapyoff);
		draw_sprite(buffer , crystal_img31[crystal31->curframe] , crystal31->x - mapxoff , crystal31->y - mapyoff);
		draw_sprite(buffer , crystal_img32[crystal32->curframe] , crystal32->x - mapxoff , crystal32->y - mapyoff);
		draw_sprite(buffer , crystal_img33[crystal33->curframe] , crystal33->x - mapxoff , crystal33->y - mapyoff);
		draw_sprite(buffer , crystal_img34[crystal34->curframe] , crystal34->x - mapxoff , crystal34->y - mapyoff);
		draw_sprite(buffer , crystal_img35[crystal35->curframe] , crystal35->x - mapxoff , crystal35->y - mapyoff);
		draw_sprite(buffer , crystal_img36[crystal36->curframe] , crystal36->x - mapxoff , crystal36->y - mapyoff);
		draw_sprite(buffer , crystal_img37[crystal37->curframe] , crystal37->x - mapxoff , crystal37->y - mapyoff);
		draw_sprite(buffer , crystal_img38[crystal38->curframe] , crystal38->x - mapxoff , crystal38->y - mapyoff);
		draw_sprite(buffer , crystal_img39[crystal39->curframe] , crystal39->x - mapxoff , crystal39->y - mapyoff);
		draw_sprite(buffer , crystal_img40[crystal40->curframe] , crystal40->x - mapxoff , crystal40->y - mapyoff);
		draw_sprite(buffer , crystal_img41[crystal41->curframe] , crystal41->x - mapxoff , crystal41->y - mapyoff);
		draw_sprite(buffer , crystal_img42[crystal42->curframe] , crystal42->x - mapxoff , crystal42->y - mapyoff);
		draw_sprite(buffer , crystal_img43[crystal43->curframe] , crystal43->x - mapxoff , crystal43->y - mapyoff);
		draw_sprite(buffer , crystal_img44[crystal44->curframe] , crystal44->x - mapxoff , crystal44->y - mapyoff);
		draw_sprite(buffer , crystal_img45[crystal45->curframe] , crystal45->x - mapxoff , crystal45->y - mapyoff);
		draw_sprite(buffer , crystal_img46[crystal46->curframe] , crystal46->x - mapxoff , crystal46->y - mapyoff);
		draw_sprite(buffer , crystal_img47[crystal47->curframe] , crystal47->x - mapxoff , crystal47->y - mapyoff);
		draw_sprite(buffer , crystal_img48[crystal48->curframe] , crystal48->x - mapxoff , crystal48->y - mapyoff);
		draw_sprite(buffer , crystal_img49[crystal49->curframe] , crystal49->x - mapxoff , crystal49->y - mapyoff);
		draw_sprite(buffer , crystal_img50[crystal50->curframe] , crystal50->x - mapxoff , crystal50->y - mapyoff);
	}///draw player's sprite///draw player's sprite
	
	if(facing1)
	{
		draw_sprite(buffer , player_img[player->curframe] , (player->x - mapxoff) , (player->y - mapyoff));
	}
	else
	{
		draw_sprite_h_flip(buffer , player_img[player->curframe] , (player->x - mapxoff), (player->y - mapyoff));
	}
	
	

	 masked_blit(mare,buffer,0,0,0,0,mare->w,mare->h);
	 if(life==0)
	 {
	  		masked_blit(zero,buffer,0,0,40,0,zero->w,zero->h);
	}		
	if(life==1)
	{
 		masked_blit(one,buffer,0,0,40,0,one->w,one->h);
	}
	if(life==2)
	{
	 		   masked_blit(two,buffer,0,0,40,0,two->w,two->h);
    }			   
	if(life==3)
	{
	 		   masked_blit(three,buffer,0,0,40,0,three->w,three->h);
    }
    if(life==4)
    {
		  masked_blit(four,buffer,0,0,40,0,four->w,four->h);
	 }
	   if(life==5)
    {
		  masked_blit(five,buffer,0,0,40,0,five->w,five->h);
	 }
	 if(life==6)
	 {
	  			masked_blit(six,buffer,0,0,40,0,six->w,six->h);
	}
	if(life==7)
	{
	 		   masked_blit(seven,buffer,0,0,40,0,seven->w,seven->h);
     } 
	 masked_blit(star,buffer,0,0,22,2,star->w,star->h);
     //textprintf_ex(buffer, font, 200,200, makecol(255,255,0), -1, " %d",random);
	textprintf_ex(buffer, font, 800,0, makecol(255,255,0), -1, "COINS COLLECTED %d/50",coin);
	if(key_count==1)
	{
	 				textprintf_ex(buffer, font, 470,610, makecol(0,255,0), -1, "the key has been collected");
	}
	textprintf_ex(buffer, font, 750,610, makecol(0,255,0), -1, "DEVELOPED BY : 5 BITS GROUP");
	textprintf_ex(buffer, font, 512,0, makecol(0,255,0), -1, "TIME = %d",timea/160);
	textprintf_ex(buffer, font, 0,610, makecol(0,255,0), -1, "Press P to pause the game");
	
	blit(buffer , screen , 0 , 0 , 0 , 0 , WIDTH - 1 , HEIGHT - 1);
	clear(buffer);
}

void key_posi()
{
 	 		   if(random==1)
 	 		   {
			   				key_sprite->x=587;
			   				key_sprite->y=55;
				}
				if(random==2)
				{
				 			 key_sprite->x=5897;
				 			 	key_sprite->y=364;
				 }
				 if(random==3)
				 {
				  			 key_sprite->x=2110;
				  			  	key_sprite->y=414;
				 }
				 if(random==0) 
				 {
				  			   key_sprite->x=10377;
							  	key_sprite->y=598;
				 }	
}		   

void crystal_posi()
{
	if(map_no==1)
	{


		crystal1->x = 330;
		crystal1->y = 175;

		crystal2->x=400;
		crystal2->y=175;

		crystal3->x=460;
		crystal3->y=175;

		crystal4->x=520;
		crystal4->y=175;
		crystal5->x=1200;
		crystal5->y=85;
		crystal6->x=1300;
		crystal6->y=85;
		crystal7->x=1400;
		crystal7->y=85;
		crystal8->x=1235;
		crystal8->y=405;
		crystal9->x=1300;
		crystal9->y=370;      
		crystal10->x=1379;
		crystal10->y=405;
		crystal11->x=1942;
		crystal11->y=466;
		crystal12->x=2121;
		crystal12->y=397;
		crystal13->x=2311;
		crystal13->y=466; 
		crystal14->x=3200;
		crystal14->y=379; 
		crystal15->x=3200;
		crystal15->y=291; 
		crystal16->x=3330;
		crystal16->y=379; 
		crystal17->x=3330;
		crystal17->y=291; 
		crystal18->x=3460;
		crystal18->y=379; 
		crystal19->x=3460;
		crystal19->y=291;
		crystal20->x= 3330;
		crystal20->y=30;
		crystal21->x=3852 ;
		crystal21->y= 83;
		crystal22->x=3938 ;
		crystal22->y= 150;
		crystal23->x= 4024;
		crystal23->y= 83;
		crystal24->x=4500 ;
		crystal24->y=380 ;
		crystal25->x= 4580;
		crystal25->y= 380;
	}	 
	////////////////////////////
	if(map_no==2)
	{
		crystal26->x = 517;
		crystal26->y = 213;

		crystal27->x=661;
		crystal27->y=213;

		crystal28->x=1645;
		crystal28->y=429;

		crystal29->x=1965;
		crystal29->y=569;

		crystal30->x=2685;
		crystal30->y=945;

		crystal31->x=3053;
		crystal31->y=945;

		crystal32->x=3753;
		crystal32->y=669;

		crystal33->x=4309;
		crystal33->y=977;

		crystal34->x=4461;
		crystal34->y=893;      

		crystal35->x=4613;
		crystal35->y=765;

		crystal36->x=5831;
		crystal36->y=313;

		crystal37->x=6283;
		crystal37->y=969;

		crystal38->x=7019;
		crystal38->y=1029; 

		crystal39->x=7307;
		crystal39->y=473; 

		crystal40->x=7431;
		crystal40->y=861; 

		crystal41->x=9318;
		crystal41->y=1009; 

		crystal42->x=10182;
		crystal42->y=841; 

		crystal43->x=10546;
		crystal43->y=841; 

		crystal44->x=10362;
		crystal44->y=669;

		crystal45->x= 11414;
		crystal45->y=349;

		crystal46->x=11782 ;
		crystal46->y= 697;

		crystal47->x=12366 ;
		crystal47->y= 645;

		crystal48->x= 12366;
		crystal48->y= 789;

		crystal49->x=13266 ;
		crystal49->y=1017 ;

		crystal50->x= 1268;
		crystal50->y= 509;
	}
		   
}
void collides()
{	
	if(map_no==1)
	{
	 			 
		if(collide_object(player , crystal1))
		{
			if(crystals[1])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img1[i] , makecol(255 , 0 , 255));
			crystals[1] = FALSE;						  
		}

		if(collide_object(player , crystal2))
		{
			if(crystals[2])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img2[i] , makecol(255 , 0 , 255));
			crystals[2] = FALSE;						  
		}
		if(collide_object(player , crystal3))
		{
			if(crystals[3])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img3[i] , makecol(255 , 0 , 255));
			crystals[3] = FALSE;						  
		}
		if(collide_object(player , crystal4))
		{
			if(crystals[4])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();				 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img4[i] , makecol(255 , 0 , 255));
			crystals[4] = FALSE;			

		}
		if(collide_object(player , crystal5))
		{
			if(crystals[5])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
				for(i=0;i<8;i++)
				clear_to_color(crystal_img5[i] , makecol(255 , 0 , 255));
				crystals[5] = FALSE;						  
		}
		if(collide_object(player , crystal6))
		{
			if(crystals[6])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
				for(i=0;i<8;i++)
				clear_to_color(crystal_img6[i] , makecol(255 , 0 , 255));
				crystals[6] = FALSE;						  
		}

		if(collide_object(player , crystal7))
		{
			if(crystals[7])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img7[i] , makecol(255 , 0 , 255));
			crystals[7] = FALSE;						  
		}

		if(collide_object(player , crystal8))
		{
			if(crystals[8])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img8[i] , makecol(255 , 0 , 255));
			crystals[8] = FALSE;						  
		}
		if(collide_object(player , crystal9))
		{
			if(crystals[9])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();				 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img9[i] , makecol(255 , 0 , 255));
			crystals[9]= FALSE;			

		}
		if(collide_object(player , crystal10))
		{
			if(crystals[10])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img10[i] , makecol(255 , 0 , 255));
			crystals[10] = FALSE;						  
		}
		if(collide_object(player , crystal11))
		{
			if(crystals[11])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}  				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img11[i] , makecol(255 , 0 , 255));
			crystals[11] = FALSE;						  
		}

		if(collide_object(player , crystal12))
		{
			if(crystals[12])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img12[i] , makecol(255 , 0 , 255));
			crystals[12] = FALSE;						  
		}
		if(collide_object(player , crystal13))
		{
			if(crystals[13])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img13[i] , makecol(255 , 0 , 255));
			crystals[13] = FALSE;						  
		}
		if(collide_object(player , crystal14))
		{
			if(crystals[14])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();				 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img14[i] , makecol(255 , 0 , 255));
			crystals[14] = FALSE;			

		}
		if(collide_object(player , crystal15))
		{
			if(crystals[15])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img15[i] , makecol(255 , 0 , 255));
			crystals[15] = FALSE;						  
		}
		if(collide_object(player , crystal16))
		{
			if(crystals[16])
			{
			play_sample(crystal_sound , volume , panning , pitch , FALSE);
			coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img16[i] , makecol(255 , 0 , 255));
			crystals[16] = FALSE;						  
		}

		if(collide_object(player , crystal17))
		{
			if(crystals[17])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}
			for(i=0;i<8;i++)
			clear_to_color(crystal_img17[i] , makecol(255 , 0 , 255));
			crystals[17] = FALSE;						  
		}
		if(collide_object(player , crystal18))
		{
			if(crystals[18])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img18[i] , makecol(255 , 0 , 255));
			crystals[18]= FALSE;						  
		}
		if(collide_object(player , crystal19))
		{
			if(crystals[19])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();	 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img19[i] , makecol(255 , 0 , 255));
			crystals[19] = FALSE;			
		}

		if(collide_object(player , crystal20))
		{
			if(crystals[20])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img20[i] , makecol(255 , 0 , 255));
			crystals[20]= FALSE;						  
		}

		if(collide_object(player , crystal21))
		{
			if(crystals[21])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img21[i] , makecol(255 , 0 , 255));
			crystals[21] = FALSE;						  
		}

		if(collide_object(player , crystal22))
		{
			if(crystals[22])
			{	
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img22[i] , makecol(255 , 0 , 255));
			crystals[22] = FALSE;						  
		}
		if(collide_object(player , crystal23))
		{
			if(crystals[23])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img23[i] , makecol(255 , 0 , 255));
			crystals[23] = FALSE;						  
		}
		if(collide_object(player , crystal24))
		{
			if(crystals[24])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();		 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img24[i] , makecol(255 , 0 , 255));
			crystals[24]= FALSE;			
		}

		if(collide_object(player , crystal25))
		{
			if(crystals[25])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img25[i] , makecol(255 , 0 , 255));
			crystals[25]= FALSE;						  
		}
		
		
		
		
	}

	if(map_no==2)
	{
 	 			 if(collide_object(player , key_sprite) && coin>=40)
			 {
			  	 key_count=1;
			
			clear_to_color(keyi[0] , makecol(255 , 0 , 255));
			//crystals[26] = FALSE;	
			}
	
		if(collide_object(player , crystal26))
		{
			if(crystals[26])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img26[i] , makecol(255 , 0 , 255));
			crystals[26] = FALSE;						  
		}

		if(collide_object(player , crystal27))
		{
			if(crystals[27])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img27[i] , makecol(255 , 0 , 255));
			crystals[27] = FALSE;						  
		}
		if(collide_object(player , crystal28))
		{
			if(crystals[28])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img28[i] , makecol(255 , 0 , 255));
			crystals[28] = FALSE;						  
		}
		if(collide_object(player , crystal29))
		{
			if(crystals[29])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();				 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img29[i] , makecol(255 , 0 , 255));
			crystals[29] = FALSE;			

		}
		if(collide_object(player , crystal30))
		{
			if(crystals[30])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img30[i] , makecol(255 , 0 , 255));
			crystals[30] = FALSE;						  
		}
		if(collide_object(player , crystal31))
		{
			if(crystals[31])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img31[i] , makecol(255 , 0 , 255));
			crystals[31] = FALSE;						  
			}

		if(collide_object(player , crystal32))
		{
			if(crystals[32])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img32[i] , makecol(255 , 0 , 255));
			crystals[32] = FALSE;						  
		}

		if(collide_object(player , crystal33))
		{
			if(crystals[33])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}	 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img33[i] , makecol(255 , 0 , 255));
			crystals[33] = FALSE;						  
		}
		if(collide_object(player , crystal34))
		{
			if(crystals[34])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();				 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img34[i] , makecol(255 , 0 , 255));
			crystals[34]= FALSE;			

		}
		if(collide_object(player , crystal35))
		{
			if(crystals[35])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img35[i] , makecol(255 , 0 , 255));
			crystals[35] = FALSE;						  
		}

		if(collide_object(player , crystal36))
		{
			if(crystals[36])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}  				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img36[i] , makecol(255 , 0 , 255));
			crystals[36] = FALSE;						  
		}

		if(collide_object(player , crystal37))
		{
			if(crystals[37])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img37[i] , makecol(255 , 0 , 255));
			crystals[37] = FALSE;						  
		}
		if(collide_object(player , crystal38))
		{
			if(crystals[38])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img38[i] , makecol(255 , 0 , 255));
			crystals[38] = FALSE;						  
		}

		if(collide_object(player , crystal39))
		{
			if(crystals[39])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();				 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img39[i] , makecol(255 , 0 , 255));
			crystals[39] = FALSE;			

		}
		if(collide_object(player , crystal40))
		{
			if(crystals[40])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img40[i] , makecol(255 , 0 , 255));
			crystals[40] = FALSE;						  
		}
		if(collide_object(player , crystal41))
		{
			if(crystals[41])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img41[i] , makecol(255 , 0 , 255));
			crystals[41] = FALSE;						  
		}

		if(collide_object(player , crystal42))
		{
			if(crystals[42])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			}
			for(i=0;i<8;i++)
			clear_to_color(crystal_img42[i] , makecol(255 , 0 , 255));
			crystals[42] = FALSE;						  
		}
		if(collide_object(player , crystal43))
		{
			if(crystals[43])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img43[i] , makecol(255 , 0 , 255));
			crystals[43]= FALSE;						  
		}
		if(collide_object(player , crystal44))
		{
			if(crystals[44])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();	 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img44[i] , makecol(255 , 0 , 255));
			crystals[44] = FALSE;			

		}
		if(collide_object(player , crystal45))
		{
			if(crystals[45])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img45[i] , makecol(255 , 0 , 255));
			crystals[45]= FALSE;						  
		}
		if(collide_object(player , crystal46))
		{
			if(crystals[46])
			{
			play_sample(crystal_sound , volume , panning , pitch , FALSE);
			coin_count();
			}				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img46[i] , makecol(255 , 0 , 255));
			crystals[46] = FALSE;						  
		}

		if(collide_object(player , crystal47))
		{
			if(crystals[47])
			{	
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img47[i] , makecol(255 , 0 , 255));
			crystals[47] = FALSE;						  
		}
		if(collide_object(player , crystal48))
		{
			if(crystals[48])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img48[i] , makecol(255 , 0 , 255));
			crystals[48] = FALSE;						  
		}
		if(collide_object(player , crystal49))
		{
			if(crystals[49])
			{				
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();		 
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img49[i] , makecol(255 , 0 , 255));
			crystals[49]= FALSE;			

		}
		if(collide_object(player , crystal50))
		{
			if(crystals[50])
			{
				play_sample(crystal_sound , volume , panning , pitch , FALSE);
				coin_count();
			} 				 
			for(i=0;i<8;i++)
			clear_to_color(crystal_img50[i] , makecol(255 , 0 , 255));
			crystals[50]= FALSE;						  
		}
	}
	 
}


void deinit()
{
	for(i = 0 ; i < 3 ; i++)
	destroy_bitmap(player_img[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img1[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img2[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img3[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img4[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img5[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img6[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img7[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img8[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img9[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img10[i]);
	for(i = 0 ; i < 3 ; i++)
	destroy_bitmap(crystal_img11[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img12[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img13[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img14[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img15[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img16[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img17[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img18[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img19[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img20[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img21[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img22[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img23[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img24[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img25[i]);	

	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img26[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img27[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img28[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img29[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img30[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img31[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img32[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img33[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img34[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img35[i]);
	for(i = 0 ; i < 3 ; i++)
	destroy_bitmap(crystal_img36[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img37[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img38[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img39[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img40[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img41[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img42[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img43[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img44[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img45[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img46[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img47[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img48[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img49[i]);
	for(i = 0 ; i < 8 ; i++)
	destroy_bitmap(crystal_img50[i]);
	


	destroy_bitmap(buffer);
	destroy_sample(sample_jump);
	destroy_sample(sample_theme);
	destroy_sample(crystal_sound);
	free(player);

	free(crystal1);
	free(crystal2);
	free(crystal3);
	free(crystal4);
	free(crystal5);
	free(crystal6);
	free(crystal7);
	free(crystal8);
	free(crystal9);
	free(crystal10);
	free(crystal11);
	free(crystal12);
	free(crystal13);
	free(crystal14);
	free(crystal15);
	free(crystal16);
	free(crystal17);
	free(crystal18);
	free(crystal19);
	free(crystal20);
	free(crystal21);
	free(crystal22);
	free(crystal23);
	free(crystal24);
	free(crystal25);
	free(crystal26);
	free(crystal27);
	free(crystal28);
	free(crystal29);
	free(crystal30);
	free(crystal31);
	free(crystal32);
	free(crystal33);
	free(crystal34);
	free(crystal35);
	free(crystal36);
	free(crystal37);
	free(crystal38);
	free(crystal39);
	free(crystal40);
	free(crystal41);
	free(crystal42);
	free(crystal43);
	free(crystal44);
	free(crystal45);
	free(crystal46);
	free(crystal47);
	free(crystal48);
	free(crystal49);
	free(crystal50);
	//  free(enemy);
	MapFreeMem();
	MapFreeMem();
	void remove_joystick();
}

void grabbing_frame()
{
	for(i = 0 ; i < 3 ; i++)
	{
		player_img[i] = grabframe(temp , 57 , 72 , 0 , 0 , 3 , i);
	}
	//destroy_bitmap(temp);
	
	

	for(i = 0 ; i < 8 ; i++)
	crystal_img1[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img2[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img3[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img4[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img5[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img6[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img7[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img8[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img9[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img10[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);


	for(i = 0 ; i < 8 ; i++)
	crystal_img11[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img12[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img13[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img14[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img15[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img16[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img17[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img18[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img19[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img20[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img21[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img22[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img23[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img24[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img25[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img26[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img27[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img28[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img29[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img30[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img31[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img32[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img33[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img34[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img35[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);


	for(i = 0 ; i < 8 ; i++)
	crystal_img36[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img37[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img38[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);
	//  destroy_bitmap(temp1);

	for(i = 0 ; i < 8 ; i++)
	crystal_img39[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img40[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img41[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img42[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img43[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img44[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img45[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img46[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img47[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img48[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img49[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);

	for(i = 0 ; i < 8 ; i++)
	crystal_img50[i] = grabframe(temp1 , 31 , 31 , 0 , 0 , 8 , i);


}

void updating_crystals()
{	
	update_crysss(crystal1);
	update_crysss(crystal2);
	update_crysss(crystal3);
	update_crysss(crystal4);
	update_crysss(crystal5);
	update_crysss(crystal6);
	update_crysss(crystal7);
	update_crysss(crystal8);
	update_crysss(crystal9);
	update_crysss(crystal10);
	update_crysss(crystal11);
	update_crysss(crystal12);
	update_crysss(crystal13);
	update_crysss(crystal14);
	update_crysss(crystal15);
	update_crysss(crystal16);
	update_crysss(crystal17);
	update_crysss(crystal18);
	update_crysss(crystal19);
	update_crysss(crystal20);
	update_crysss(crystal21);
	update_crysss(crystal22);
	update_crysss(crystal23);
	update_crysss(crystal24);
	update_crysss(crystal25);
	update_crysss(crystal26);
	update_crysss(crystal27);
	update_crysss(crystal28);
	update_crysss(crystal29);
	update_crysss(crystal30);
	update_crysss(crystal31);
	update_crysss(crystal32);
	update_crysss(crystal33);
	update_crysss(crystal34);
	update_crysss(crystal35);
	update_crysss(crystal36);
	update_crysss(crystal37);
	update_crysss(crystal38);
	update_crysss(crystal39);
	update_crysss(crystal40);
	update_crysss(crystal41);
	update_crysss(crystal42);
	update_crysss(crystal43);
	update_crysss(crystal44);
	update_crysss(crystal45);
	update_crysss(crystal46);
	update_crysss(crystal47);
	update_crysss(crystal48);
	update_crysss(crystal49);
	update_crysss(crystal50);
}      

void initialize()
{
	//initialize player
	mario_init();
	
	

	crystal_init(&crystal1);  
	crystal_init(&crystal2);
	crystal_init(&crystal3);
	crystal_init(&crystal4);
	crystal_init(&crystal5);
	crystal_init(&crystal6);
	crystal_init(&crystal7);
	crystal_init(&crystal8);
	crystal_init(&crystal9);
	crystal_init(&crystal10);
	crystal_init(&crystal11);
	crystal_init(&crystal12);
	crystal_init(&crystal13);
	crystal_init(&crystal14);
	crystal_init(&crystal15);
	crystal_init(&crystal16);
	crystal_init(&crystal17);
	crystal_init(&crystal18);
	crystal_init(&crystal19);
	crystal_init(&crystal20);
	crystal_init(&crystal21);
	crystal_init(&crystal22);
	crystal_init(&crystal23);
	crystal_init(&crystal24);
	crystal_init(&crystal25);

	crystal_init(&crystal26);  
	crystal_init(&crystal27);
	crystal_init(&crystal28);
	crystal_init(&crystal29);
	crystal_init(&crystal30);
	crystal_init(&crystal31);
	crystal_init(&crystal32);
	crystal_init(&crystal33);
	crystal_init(&crystal34);
	crystal_init(&crystal35);
	crystal_init(&crystal36);
	crystal_init(&crystal37);
	crystal_init(&crystal38);
	crystal_init(&crystal39);
	crystal_init(&crystal40);
	crystal_init(&crystal41);
	crystal_init(&crystal42);
	crystal_init(&crystal43);
	crystal_init(&crystal44);
	crystal_init(&crystal45);
	crystal_init(&crystal46);
	crystal_init(&crystal47);
	crystal_init(&crystal48);
	crystal_init(&crystal49);
	crystal_init(&crystal50);


}
void mario_init()
{
	player = malloc(sizeof(SPRITE));
	player->x = 80;
	player->y = 200;
	player->curframe = 0;
	player->framecount = 0;
	player->framedelay = 10;
	player->maxframe = 2;
	player->width = player_img[0]->w;
	player->height = player_img[0]->h;
	player->xspeed = 3;
	player->yspeed = 3;
}

void key_init()
{
	key_sprite = malloc(sizeof(SPRITE));
	//player->x = 80;
	//player->y = 200;
	key_sprite->curframe = 0;
	//player->framecount = 0;
	//player->framedelay = 10;
	//player->maxframe = 2;
	key_sprite->width = keyi[0]->w;
	key_sprite->height = keyi[0]->h;
	//player->xspeed = 3;
	//player->yspeed = 3;
}




	
 	 


void crystal_init(SPRITE **crystal)
{
	crystal[0]  = (SPRITE *)malloc(sizeof(SPRITE));
	SPRITE *cryst = *crystal;
	cryst->curframe = 0;

	cryst->framecount = 0;
	cryst->framedelay = 5;
	cryst->maxframe = 7;
	cryst->width = crystal_img1[0]->w;
	cryst->height = crystal_img1[0]->h;

}

void update_crysss( SPRITE *crys)
{
	if(++crys->framecount > crys->framedelay)
	{
		crys->framecount = 0;
		if(++crys->curframe > crys->maxframe)
			crys->curframe = 0;
	}

}


void ticker()
{
	ticks++;
}

void CloseButtonCallback()
{
	closewindow = TRUE;
}

void coin_count()
{
	coin++;
	if(coin==10 ||coin==20 || coin==30 || coin==40||coin ==50)
		life++;
 	 	 		
}
