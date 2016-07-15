#ifndef __TARGETBULLET_H__
#define __TARGETBULLET_H__

typedef struct {
	int m_nFSM;
	int m_nStep;
	double m_fXpos;
	double m_fYpos;
	double m_fSpeed;
	double m_faccLifeTime; //현재 생존시간
	double m_fLifeLimit; //수명

	_S_MAP_OBJECT *m_pBody;

} TARGET_S_BULLET_OBJECT;

void Target_bullet_init(TARGET_S_BULLET_OBJECT *pObj,double x,double y,double speed,_S_MAP_OBJECT *pBody);
void Target_bullet_apply(TARGET_S_BULLET_OBJECT *pObj,double deltaTick);
void Target_bullet_draw(TARGET_S_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf);
void Target_bullet_fire(TARGET_S_BULLET_OBJECT *pObj,int x,int y,double speed,double lifeLimit);
#endif
