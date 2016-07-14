#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "plane.h"
#include "bullet.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer;
_S_MAP_OBJECT gBackBuffer;
_S_MAP_OBJECT gF22Raptor;
_S_MAP_OBJECT gF22Bullet;
_S_MAP_OBJECT gTarget;
//게임오브잭트 선언 
_S_Plane gPlayerPlane;
_S_Plane gTargetPlane;
S_BULLET_OBJECT g_bullets[32];

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	system("clear");
	map_init(&gScreenBuffer);
	map_new(&gScreenBuffer,60,20);

	map_init(&gBackBuffer);
	map_new(&gBackBuffer,60,20);

	map_init(&gF22Raptor);
	map_load(&gF22Raptor,"plane3.dat");

	map_init(&gF22Bullet);
	map_load(&gF22Bullet,"bullet4.dat");

	map_init(&gTarget);
	map_load(&gTarget,"target2.dat");


	Plane_init(&gTargetPlane,&gTarget,50,5);
	Plane_init(&gPlayerPlane,&gF22Raptor,5,5);

	for(int i=0;i< sizeof(g_bullets)/sizeof(S_BULLET_OBJECT); i++)
	{
		bullet_init(&g_bullets[i],0,0,0,&gF22Bullet);
	}

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
			for(int i=0;i<sizeof(g_bullets)/sizeof(S_BULLET_OBJECT);i++) {
				S_BULLET_OBJECT *pObj = &g_bullets[i];
				if(pObj->m_nFSM == 0) { //슬립상태라면...
					bullet_fire(pObj,
							gPlayerPlane.m_nXpos,
							gPlayerPlane.m_nYpos,10,5.0);
					break;
				}
			}

		
		Plane_Apply(&gPlayerPlane,delta_tick,ch);

	}
	else if(ch == 'l') {
		for(int i=0;i<sizeof(g_bullets)/sizeof(S_BULLET_OBJECT);i++) {
			S_BULLET_OBJECT *pObj = &g_bullets[i];
			if(pObj->m_nFSM == 0) { //슬립상태라면...
				Target_bullet_fire(pObj,
						gTargetPlane.m_nXpos,
						gTargetPlane.m_nYpos,10,5.0);
				break;
			}
		}

	
	Target_Plane_Apply(&gTargetPlane,delta_tick,ch);
	}
}


for(int i=0;i<sizeof(g_bullets)/sizeof(S_BULLET_OBJECT);i++) {
	S_BULLET_OBJECT *pObj = &g_bullets[i];
	bullet_apply(pObj,delta_tick);
}	

//타이밍 계산 
acc_tick += delta_tick;
if(acc_tick > 0.1) {

	map_drawTile(&gBackBuffer,0,0,&gScreenBuffer); //클리어 

	// map_drawTile_trn(&gF22Raptor,xpos,ypos,&gScreenBuffer);//오브잭트 출력 

	Plane_Draw(&gPlayerPlane,&gScreenBuffer); //player

	Plane_Draw(&gTargetPlane,&gScreenBuffer); //target
	for(int i=0;i<sizeof(g_bullets)/sizeof(S_BULLET_OBJECT);i++) {
		S_BULLET_OBJECT *pObj = &g_bullets[i];
		bullet_draw(pObj,&gScreenBuffer);	
	}


	gotoxy(0,0);
	puts("------------------------------------------------------------\r");
	map_dump(&gScreenBuffer,Default_Tilepalete);
	puts("------------------------------------------------------------\r");

	puts("move : w,a,s,d \r");
	puts("quit : q \r");

	acc_tick = 0;
}


}
return 0;

}
