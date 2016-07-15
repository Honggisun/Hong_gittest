#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine/engine2d.h"
#include "../mapeditor/map.h"
#include "bullet.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer[2];
_S_MAP_OBJECT gBulletModel;
S_BULLET_OBJECT gBulletObject;

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuffer[i]);
		map_new(&gScreenBuffer[i],80,40);
	}
	map_init(&gBulletModel);
	map_load(&gBulletModel,"plasma.dat");
	bullet_init(&gBulletObject,0,0,0,&gBulletModel);

	system("clear");	

	double target_x,target_y;
	double center_x,center_y;
	double moon_x,moon_y;
	center_x = 40;
	center_y = 20;
	target_x = 40;
	target_y = 25;
	moon_x = 40;
	moon_y = 15;

	double angle = 0;
	
	while(bLoop) {
		//타이밍처리/////////////////////////////////////
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간입력/////////////////////////////////////	
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("Good bye~ \r");
			}
		}
		////////////////////////////////////////////////
		
		//apply 위치 ...////////////////////////////////
		angle += (delta_tick * 45);
		double tx,ty;
		double rad = angle/180.0 * 3.141592;
		tx = (target_x - center_x) * cos(rad) - (target_y - center_y) * sin(rad);
		ty = (target_x - center_x) * sin(rad) + (target_y - center_y) * cos(rad);
		tx += center_x;
		ty += center_y;
		/////moon
		double bad = angle/180.0 * 3.141592;
			angle += (delta_tick * 20);
		double mx,my;
		mx = (tx - moon_x) * cos(bad) - target_x(ty - moon_y) * sin(bad); //타겟 돌아가는 위치 문 위치
		my = (tx - moon_x) * sin(bad) + target_y(ty - moon_y) * cos(bad);
		mx += moon_x;
		my += moon_y;
		
		//타이밍계산///////////////////////////////////
		acc_tick += delta_tick;
		if(acc_tick > 0.01) {
			//puts("tick...\r");
			map_drawTile(&gScreenBuffer[0],0,0,&gScreenBuffer[1]);
			map_PutTile(&gScreenBuffer[1],tx,ty,2);
			map_PutTile(&gScreenBuffer[1],mx,my,3);
		
			map_PutTile(&gScreenBuffer[1],center_x,center_y,5);
			map_PutTile(&gScreenBuffer[1],target_x,target_y,1);
			map_PutTile(&gScreenBuffer[1],moon_x,moon_y,6);
					
			gotoxy(0,0);
			map_dump(&gScreenBuffer[1],Default_Tilepalete);
			acc_tick = 0;
		}
	}

	return 0;
}


