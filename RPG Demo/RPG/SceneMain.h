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
	GET_SET_PRIVATE(int, MapID, m_iMapID);
	//玩家周围NPC的ID
	GET_SET_PRIVATE(int, SurroundPlayer, m_iSurroundPlayer);
	GET_PRIVATE(cPlayer*, Player, m_pPlayer);
	GET_PRIVATE(cEnemyRuler*, EnemyRuler, m_pEnemyRuler);
	GET_SET_PRIVATE(MapData*, CurentMap, m_pCurentMap);
	GET_PRIVATE(cNPCRuler*, NPCRuler, m_pNPCRuler);
	GET_PRIVATE(cRoleSelectRuler*, RoleSelectRuler, m_pRoleSelectRuler);
	GET_PRIVATE(cStore*, Store, m_pStore);
	GET_PRIVATE(cFireRuler*, FireRuler, m_pFireRuler);
	GET_PRIVATE(cEnemy*, EnemyTemp, m_EnemyTemp);
	//GET_PRIVATE(cNodeRoleSelect*, NodeRoleSelect, m_pNodeRoleSelect);


private:
	//NPC周围是否有玩家
	bool m_bSurroundNPC;
	bool m_bTrainning, m_bEnemyPropertyRender;
	cEnemy* pEnemyData;
	//cFire* fireIns;
	//int m_iSurroundPlayer;
	
	//cStore* m_pStore;
	//static cSceneMain* m_pInstanceSceneMain;
	/*int m_iMapID;
	cPlayer* m_player;
	MapData* m_curentMap;
	vector<cRoleSelect*> m_vecRoleSelect;
	vector<cNPC*> m_vecNPC;*/
};

#endif // !RPG_RPG_SCENEMAIN_H_