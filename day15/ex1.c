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
#include "../mapEditor/map.h"

#include "plane.h"
#include "bullet.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];
_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;
_S_Plane gPlayerObject;
_S_BULLET_OBJECT gTestBullet;

int main()
{
	system("clear");

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,30);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane5.dat");


	map_init(&gBulletModel);
	map_load(&gBulletModel,"plasma.dat");


	Plane_init(&gPlayerObject,&gPlayerModel,17,24);
	bullet_init(&gTestBullet,0,0,0,&gBulletModel);

	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간입력	
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("Good bye~ \r");
			}
			else if (ch == 'j') {
				
				double bullet_pos_x = 0;	 //총알 시작위치
				double bullet_pos_y = 0;	

				double target_pos_x = gPlayerObject.m_fXpos;
				double target_pos_y = gPlayerObject.m_fYpos;
				
				double vx = target_pos_x - bullet_pos_x;
				double vy = target_pos_y - bullet_pos_y;
				double dist = sqrt(vx*vx+vy*vy);
				vx /= dist;
				vy /= dist;
				

				gTestBullet.pfFire(&gTestBullet,bullet_pos_x,bullet_pos_y,10,vx,vy,10);
			}

			gPlayerObject.pfApply(&gPlayerObject,delta_tick,ch);
		}

		gTestBullet.pfApply(&gTestBullet,delta_tick);

		//타이밍계산
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);

			gPlayerObject.pfDraw(&gPlayerObject,&gScreenBuf[1]);
			gTestBullet.pfDraw(&gTestBullet,&gScreenBuf[1]);	

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}
	}

	return 0;
}


