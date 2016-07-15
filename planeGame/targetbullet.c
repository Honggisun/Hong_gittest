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

#include "bullet.h"

void Target_bullet_init(TARGET_S_BULLET_OBJECT *pObj,
double x,double y,double speed,
_S_MAP_OBJECT *pBody)
{
	pObj->m_nFSM = 0;
	pObj->m_nStep = 0;
	pObj->m_fSpeed = speed;
	pObj->m_fXpos = x;
	pObj->m_fYpos = y;
	pObj->m_pBody = pBody;

}

void Target_bullet_apply(TARGET_S_BULLET_OBJECT *pObj,double deltaTick)
{
	switch(pObj->m_nFSM) {
		case 0:
			break;
		case 1:
			if(pObj->m_nStep == 0) {
				pObj->m_nStep++;
				pObj->m_faccLifeTime = 0;
			}
			else {
				pObj->m_faccLifeTime += deltaTick;
				if(pObj->m_faccLifeTime > pObj->m_fLifeLimit) {
					pObj->m_nStep = 0;
					pObj->m_nFSM = 0;
				}
				pObj->m_fYpos -= deltaTick *pObj->m_fSpeed; //총알 방향
			}
			break;
	}
}

void Target_bullet_draw(TARGET_S_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf)
{
	switch(pObj->m_nFSM) {
		case 0:
			break;
		case 1:
			map_drawTile_trn(pObj->m_pBody,
					(int)pObj->m_fXpos,
					(int)pObj->m_fYpos,
					pMapBuf);
			break;
	}
}
void Target_bullet_fire(TARGET_S_BULLET_OBJECT *pObj,int x,int y,double speed,double lifeLimit)
{
	pObj->m_nStep = 0;
	pObj->m_nFSM = 1;
	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;
	pObj->m_fSpeed = speed;
	pObj->m_fLifeLimit = lifeLimit;

}

