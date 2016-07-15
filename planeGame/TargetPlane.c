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

#include "Targetplane.h"

void Target_Plane_init(_Target_S_Plane *pObj,_S_MAP_OBJECT *pBody,int x,int y)
{
	pObj->m_pBody = pBody;
	pObj->m_nYpos = y;
	pObj->m_nXpos = x;

}

void Target_Plane_Apply(_Target_S_Plane *pObj,double deltaTick,char key_input)
{
	switch(key_input)
	{
		case 'b':
		pObj->m_nXpos -= 1;
		break;
		case 'm':
		pObj->m_nXpos += 1;
		break;
		case 'h':
		pObj->m_nYpos -= 1;
		break;
		case 'n':
		pObj->m_nYpos += 1;
		break;
	}
	
}


void Target_Plane_Draw(_Target_S_Plane *pObj, _S_MAP_OBJECT *pBuff)
{
	map_drawTile_trn(pObj->m_pBody,pObj->m_nXpos,pObj->m_nYpos,pBuff);
}

