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
#include "alien.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[32];

_S_MAP_OBJECT gPlaneModel;
_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gAlienModel2;

_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gPlasmaModel;

_S_Plane gTestPlaneObject;
_S_ALIEN_OBJECT gTestAlienObject;
_S_BULLET_OBJECT gTestBulletObject[16];
_S_BULLET_OBJECT gTestBulletObject2;


int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,16);
	}
	map_init(&gPlaneModel);
	map_load(&gPlaneModel,"plane5.dat");


	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gPlasmaModel);
	map_load(&gPlasmaModel,"plasma.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet5.dat");

	alien_init(&gTestAlienObject,&gAlienModel);
	bullet_init(&gTestBulletObject2,0,0,0,&gPlasmaModel);


	gTestAlienObject.m_pBullet = &gTestBulletObject2;
		
	gTestAlienObject.m_fXpos = 5;
	gTestAlienObject.m_fYpos = 2;
	gTestAlienObject.m_nFSM = 1;


	system("clear");
	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
			if(ch == 'j') {
				for(int i=0;i<sizeof(gTestBulletObject)/sizeof(_S_BULLET_OBJECT);i++) {
					_S_BULLET_OBJECT *pObj = &gTestBulletObject[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면...
						pObj->pfFire(pObj,
								gTestPlaneObject.m_fXpos,
								gTestPlaneObject.m_fYpos,5,0,-2,10);
						break;
					}

				
			

			gTestAlienObject.pfApply(&gTestAlienObject,delta_tick);
		gTestBulletObject2.pfApply(&gTestBulletObject2,delta_tick);	

	gTestPlaneObject.pfApply(&gTestPlaneObject,delta_tick,ch);
		}
		}
	}
		for(int i=0;i<sizeof(gTestBulletObject)/sizeof(_S_BULLET_OBJECT);i++) {
			_S_BULLET_OBJECT *pObj = &gTestBulletObject[i];
			pObj->pfApply(pObj,delta_tick);

		}

			//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			gTestPlaneObject.pfDraw(&gTestPlaneObject,&gScreenBuf[1]);
			gTestAlienObject.pfDraw(&gTestAlienObject,&gScreenBuf[1]);
			gTestBulletObject2.pfDraw(&gTestBulletObject2,&gScreenBuf[1]);	

			for(int i=0;i<sizeof(&gTestBulletObject)/sizeof(_S_BULLET_OBJECT);i++) {
				_S_BULLET_OBJECT *pObj = &gTestBulletObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);	
			}

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
