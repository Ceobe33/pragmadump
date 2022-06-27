#pragma once
#include "DataStruct.h"
class cRoleSelect//:public cSceneBase
{
public:
	cRoleSelect();
	//void update();
	void render(cRoleSelect* role);
	//void getData();
	void initialize(cRoleSelectData* data);
	cRoleSelect* getDataByID(const int &i);

	//API
	//CC_GET_SET_PRIVATE(int, State, m_iState);
	//vector<cRoleSelectData*> getVecPlayer();
	//CC_GET_PRIVATE(vector<cRoleSelectData*>, VecPlayer, m_vecPlayer);

private:

	string m_strName, m_strRole, m_strGrowth, m_strImg;
	int m_iID, m_iAtk, m_iDef, m_iHP, m_iAcount;
	//static cRoleSelect* m_pInstanceRoleSelect;
	//int m_iState;
	//int m_iID, m_iRow,m_iAtk,m_iDef;
	//string m_strRole, m_strName, m_strGrowth, m_strImg;
	//vector<cRoleSelectData*> m_vecPlayer;
};

class cRoleSelectRuler :public cSceneBase
{
public:
	cRoleSelectRuler();
	~cRoleSelectRuler();
	void update();
	void render();
	void storage();


	CC_GET_SET_PRIVATE(int, State, m_iState);
	CC_GET_SET_PRIVATE(vector<cRoleSelect*>, VecPlayer, m_vecPlayer);
	CC_GET_SET_PRIVATE(cRoleSelect*, RoleSelect, m_pRoleSelect);
private:
	//cRoleSelect* m_pRoleSelect;
	//vector<cRoleSelect*> m_vecPlayer;
};
