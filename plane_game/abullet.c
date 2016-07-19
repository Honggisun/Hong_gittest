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

#include "abullet.h"

void abullet_apply(_A_BULLET_OBJECT *pObj,double deltaTick)
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
				pObj->m_fYpos += deltaTick * (pObj->m_fSpeed * pObj->m_fvy);
				pObj->m_fXpos += deltaTick * (pObj->m_fSpeed * pObj->m_fvx);
			}
			break;
	}
}

void abullet_draw(_A_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf)
{
	switch(pObj->m_nFSM) {
		case 0:
			break;
		case 1:
			map_drawTile_trn(pObj->m_pBody,
					(int)(pObj->m_fXpos + pObj->m_fCenterX),
					(int)(pObj->m_fYpos + pObj->m_fCenterY),
					pMapBuf);
			break;
	}
}

void abullet_fire(_A_BULLET_OBJECT *pObj,
int x,int y,double speed,double vx, double vy,
double lifeLimit)
{
	pObj->m_nFSM = 1;
	pObj->m_nStep = 0;
	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;
	pObj->m_fvx = vx;
	pObj->m_fvy = vy;
	pObj->m_fSpeed = speed;
	pObj->m_fLifeLimit = lifeLimit;

}

void abullet_init(_A_BULLET_OBJECT *pObj,
double x,double y,double speed,
_S_MAP_OBJECT *pBody)
{
	pObj->m_nFSM = 0;
	pObj->m_nStep = 0;
	pObj->m_fSpeed = speed;
	pObj->m_fXpos = 0;
	pObj->m_fYpos = 0;
	pObj->m_pBody = pBody;
	pObj->m_fCenterX = 0 - (pBody->m_header.m_nWidth/2);//중심점
	pObj->m_fCenterY = 0 - (pBody->m_header.m_nHeight/2);
	pObj->pfApply = abullet_apply;
	pObj->pfDraw = abullet_draw;
	pObj->pfFire = abullet_fire;

}


