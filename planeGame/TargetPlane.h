#ifndef __TARGETPLANE_H__
#define __TARGETPLANE_H__

typedef struct {
	int m_nXpos;
	int m_nYpos;
	_S_MAP_OBJECT *m_pBody;
} _Target_S_Plane;

void Target_Plane_init(_Target_S_Plane *pObj,_S_MAP_OBJECT *pBody,int x,int y);
void Target_Plane_Apply(_Target_S_Plane *pObj,double deltaTick,char key_input);
void Target_Plane_Draw(_Target_S_Plane *pObj, _S_MAP_OBJECT *pBuff);

#endif

