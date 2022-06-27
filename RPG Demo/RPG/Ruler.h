#pragma once
//#include "stdafx.h"
#include "SceneMain.h"
#include "RoleSelect.h"
#include "NPC.h"
#include "Map.h"
#include "Loading.h"

class cRuler
{
public:
	void update();
	void render();
	void solveFrameProblem();
	static cRuler* getInstance();

	CC_GET_SET_PRIVATE(int, State, m_iState);
	CC_GET_SET_PRIVATE(cSceneMain*, SceneMain, m_pSceneMain);
	//CC_GET_SET_PRIVATE(cRoleSelect*, RoleSelect, m_pRoleSelect);
	//CC_GET_SET_PRIVATE(cNPC*, NPC, m_pNPC);
	//CC_GET_SET_PRIVATE(cMap*, Map, m_pMap);
	//CC_GET_PRIVATE(cLoading*, Loading, m_pLoading);

	

private:

	cRuler();
	/*int m_iState;
	cSceneMain* m_pSceneMain;
	cRoleSelect* m_pRoleSelect;
	cNPC* m_pNPC;
	cMap* m_pMaRuler;
	cLoading* m_pLoading;*/
	static cRuler* m_pInstanceRuler;
};

