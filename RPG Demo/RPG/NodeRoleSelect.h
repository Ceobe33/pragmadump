#pragma once
#include "Node.h"

class cNodeRoleSelect:public cNode
{
public:
	cNodeRoleSelect();
	~cNodeRoleSelect();
	void update();
	void render();	
	CC_GET_SET_PRIVATE(int, State, m_iState);
	//vector<cRoleSelectData*> getVecPlayer();
	CC_GET_PRIVATE(vector<cRoleSelectData*>, VecPlayer, m_vecPlayer);
};

