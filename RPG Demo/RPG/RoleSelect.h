#pragma once
#include "DataStruct.h"
class cRoleSelect {//:public cSceneBase
public:
	cRoleSelect();
	//void update();
	void render(cRoleSelect* role);
	//void getData();
	void initialize(cRoleSelectData* data);
	cRoleSelect* getDataByID(const int &i);

	//API
	//GET_SET_PRIVATE(int, State, roleselArrowState);
	//vector<cRoleSelectData*> getVecPlayer();
	//GET_PRIVATE(vector<cRoleSelectData*>, VecPlayer, roleContainer);

private:

	string m_strName, m_strRole, m_strGrowth, m_strImg;
	// "{}" is to solve the warninig C26495
	int m_iID{}, m_iAtk{}, m_iDef{}, m_iHP{}, m_iAcount{};

	//static cRoleSelect* m_pInstanceRoleSelect;
	//int roleselArrowState;
	//int m_iID, m_iRow,m_iAtk,m_iDef;
	//string m_strRole, m_strName, m_strGrowth, m_strImg;
	//vector<cRoleSelectData*> roleContainer;
};

class cRoleSelectRuler :public cSceneBase {
public:
	cRoleSelectRuler();
	~cRoleSelectRuler() {}
	void update();
	void render();
	void storage();

	int roleselArrowState{};
	vector<cRoleSelect*> roleContainer;
	cRoleSelect* selectedRole;
private:
	//cRoleSelect* selectedRole;
	//vector<cRoleSelect*> roleContainer;
};
