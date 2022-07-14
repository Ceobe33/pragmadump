#pragma once
#include "Node.h"

class cNodeRoleSelect:public cNode
{
public:
	cNodeRoleSelect();
	~cNodeRoleSelect();
	void update();
	void render();	
	GET_SET_PRIVATE(int, State, m_iState);
	//vector<cRoleSelectData*> getVecPlayer();
	GET_PRIVATE(vector<cRoleSelectData*>, VecPlayer, m_vecPlayer);
};

