#ifndef RPG_RPG_SCENEMAIN_H_
#define RPG_RPG_SCENEMAIN_H_	

#include "Player.h"
#include "DataStruct.h"
#include "NPC.h"
#include "RoleSelect.h"
#include "Enemy.h"
#include "NPC.h"
#include "Store.h"
#include "PetStore.h"
#include "Fire.h"


//#include "NodeRoleSelect.h"

class cSceneMain :public cSceneBase
{
public:
	cSceneMain();
	void update();
	void render();
	bool collide();
	//void setPosition(int r, int c);
	//cNPCData* collideNPC();
	//static cSceneMain* getInstance();
	
	
	//API
	CC_GET_SET_PRIVATE(int, MapID, m_iMapID);
	//�����ΧNPC��ID
	CC_GET_SET_PRIVATE(int, SurroundPlayer, m_iSurroundPlayer);
	CC_GET_PRIVATE(cPlayer*, Player, m_pPlayer);
	CC_GET_PRIVATE(cEnemyRuler*, EnemyRuler, m_pEnemyRuler);
	CC_GET_SET_PRIVATE(cMapData*, CurentMap, m_pCurentMap);
	CC_GET_PRIVATE(cNPCRuler*, NPCRuler, m_pNPCRuler);
	CC_GET_PRIVATE(cRoleSelectRuler*, RoleSelectRuler, m_pRoleSelectRuler);
	CC_GET_PRIVATE(cStore*, Store, m_pStore);
	CC_GET_PRIVATE(cFireRuler*, FireRuler, m_pFireRuler);
	CC_GET_PRIVATE(cEnemy*, EnemyTemp, m_EnemyTemp);
	//CC_GET_PRIVATE(cNodeRoleSelect*, NodeRoleSelect, m_pNodeRoleSelect);


private:
	//NPC��Χ�Ƿ������
	bool m_bSurroundNPC;
	bool m_bTrainning, m_bEnemyPropertyRender;
	cEnemy* pEnemyData;
	//cFire* m_pFire;
	//int m_iSurroundPlayer;
	
	//cStore* m_pStore;
	//static cSceneMain* m_pInstanceSceneMain;
	/*int m_iMapID;
	cPlayer* m_player;
	cMapData* m_curentMap;
	vector<cRoleSelect*> m_vecRoleSelect;
	vector<cNPC*> m_vecNPC;*/
};

#endif // !RPG_RPG_SCENEMAIN_H_