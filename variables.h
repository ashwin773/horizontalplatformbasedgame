#ifndef VARIABLES_H
#define VARIABLES_H


//////////  for timer  function/////////////////////////////
volatile long ticks = 0;
volatile int closewindow = FALSE;
///////////////////////////////////////////////////////////


/////////// for mouse buttons////////////////////
extern volatile int mouse_x;
extern volatile int mouse_y;
extern volatile int mouse_b;
/////////////////////////////////////////////////

//////////// static variables////////////////////
////////  for coin count
static int coin=0;
////////  for time count
static int timea=24100;
////////  map count
static int map_no=1;
//////// life count
static int life=2;
//////////////////////////////////////////////

//////////////////////////////////////
//other declarations
int facing1 = 1;
int facing2= 1;
int oldpx;
int  oldpy;

int i;
int j;
int jump;
///////////////////////////////
int crystals[51];
SAMPLE *crystal_sound;

////////// for sounds///////////
int panning = 128;
int pitch = 1000;
int volume = 500;
////////////////////////////

static int key_count=0;
static int random=0;
static int keyi_x;
static int keyi_y;


static int arrow1_x=511;
static int arrow1_y=255;

int cre_y=0;



#endif 
