#pragma once
#ifndef RPG_RPG_NODEROLESELECT_H_
#define RPG_RPG_NODEROLESELECT_H_

#include "Node.h"

class cNodeRoleSelect :public cNode {
public:
    cNodeRoleSelect();
    ~cNodeRoleSelect();
    void update();
    void render();
    int roleselArrowState{};
    //vector<cRoleSelectData*> getVecPlayer();
    GET_PRIVATE(vector<cRoleSelectData*>, VecPlayer, roleContainer);
};

#endif // !RPG_RPG_NODEROLESELECT_H_