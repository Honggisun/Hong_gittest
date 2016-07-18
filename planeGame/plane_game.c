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
#include "Targetplane.h"
#include "bullet.h"
#include "targetbullet.h"



struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer;
_S_MAP_OBJECT gBackBuffer;
_S_MAP_OBJECT gF22Raptor;
_S_MAP_OBJECT gF22Bullet;
_S_MAP_OBJECT gF22Bullet2;
_S_MAP_OBJECT gTarget;

//게임오브잭트 선언 
_S_Plane gPlayerPlane;
_Target_S_Plane gTargetPlane;
S_BULLET_OBJECT g_bullets[32];
TARGET_S_BULLET_OBJECT g_bullets2[32];


int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	system("clear");
	map_init(&gScreenBuffer);
	map_new(&gScreenBuffer,40,30);

	map_init(&gBackBuffer);
	map_new(&gBackBuffer,40,30);

	map_init(&gF22Raptor);
	map_load(&gF22Raptor,"plane5.dat");

	map_init(&gF22Bullet);
	map_load(&gF22Bullet,"bullet5.dat");
	
	map_init(&gF22Bullet2);
	map_load(&gF22Bullet2,"bullet5.dat");


	map_init(&gTarget);
	map_load(&gTarget,"target5.dat");
	
	Plane_init(&gPlayerPlane,&gF22Raptor,18,25);
	Target_Plane_init(&gTargetPlane,&gTarget,18,3);

	for(int i=0;i< sizeof(g_bullets)/sizeof(S_BULLET_OBJECT); i++)
	{
		bullet_init(&g_bullets[i],0,0,0,&gF22Bullet);
	}
	for(int i=0;i< sizeof(g_bullets2)/sizeof(TARGET_S_BULLET_OBJECT); i++)
	{
		Target_bullet_init(&g_bullets2[i],0,0,0,&gF22Bullet2);
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
			if(ch == 'l') {
				for(int i=0;i<sizeof(g_bullets2)/sizeof(TARGET_S_BULLET_OBJECT);i++) {
					TARGET_S_BULLET_OBJECT *pObj = &g_bullets2[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면...
						Target_bullet_fire(pObj,
								gTargetPlane.m_nXpos,
								gTargetPlane.m_nYpos,10,5.0);
						break;
					}
				}

			


			
			Plane_Apply(&gPlayerPlane,delta_tick,ch);

			Target_Plane_Apply(&gTargetPlane,delta_tick,ch);
			} 
		}
}
for(int i=0;i<sizeof(g_bullets)/sizeof(S_BULLET_OBJECT);i++) {
	S_BULLET_OBJECT *pObj = &g_bullets[i];
	bullet_apply(pObj,delta_tick);
	
for(int i=0;i<sizeof(g_bullets2)/sizeof(TARGET_S_BULLET_OBJECT);i++) {
	TARGET_S_BULLET_OBJECT *pObj = &g_bullets2[i];
	Target_bullet_apply(pObj,delta_tick);
}	
}

//타이밍 계산 
acc_tick += delta_tick;
if(acc_tick > 0.1) {

	map_drawTile(&gBackBuffer,0,0,&gScreenBuffer); //클리어 

	// map_drawTile_trn(&gF22Raptor,xpos,ypos,&gScreenBuffer);//오브잭트 출력 

	Plane_Draw(&gPlayerPlane,&gScreenBuffer); //player

	Target_Plane_Draw(&gTargetPlane,&gScreenBuffer); //target
	for(int i=0;i<sizeof(g_bullets)/sizeof(S_BULLET_OBJECT);i++) {
		S_BULLET_OBJECT *pObj = &g_bullets[i];
		bullet_draw(pObj,&gScreenBuffer);	
	}
	for(int i=0;i<sizeof(g_bullets2)/sizeof(TARGET_S_BULLET_OBJECT);i++) {
		TARGET_S_BULLET_OBJECT *pObj = &g_bullets2[i];
		Target_bullet_draw(pObj,&gScreenBuffer);	
	}



	setColor(0,0);
	gotoxy(0,0);
	puts(" \r\n");
	map_dump(&gScreenBuffer,Default_Tilepalete);
	puts(" \r\n");

	puts("move : w,a,s,d \r");
	puts("quit : q \r");

	acc_tick = 0;
}


}
return 0;

}
