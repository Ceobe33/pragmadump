#include "stdafx.h"
#include "NodeRoleSelect.h"

cNodeRoleSelect::cNodeRoleSelect() {
    //m_strName = "RoleSelect";
    nodeName = "NodeRoleSelect";
    vector<DataBase*> vecData = cDataRuler::getInstance()->getDataRuler("RoleSelectDataRuler")->getVecData();
    for (DataBase* pBase : vecData) {
        //cRoleSelect* pRole = new cRoleSelect();
        cRoleSelectData* pData = static_cast<cRoleSelectData*>(pBase);
        //pRole->initialize(pData);
        roleContainer.push_back(pData);
    }
}

cNodeRoleSelect::~cNodeRoleSelect() {
}

void cNodeRoleSelect::update() {
    if (KEY_DOWN(VK_DOWN)) {
        roleselArrowState++;
    } else if (KEY_DOWN(VK_UP)) {
        roleselArrowState--;
    }

    if (roleselArrowState < 0) {
        roleselArrowState = 0;
    } else if (int(roleContainer.size()) - ONE < roleselArrowState) {
        roleselArrowState = roleContainer.size() - ONE;
    } else if (KEY_DOWN(VK_RETURN)) {
        //cDirector::getInstance()->pushScene(this);
        //cDirector::getInstance()->replaceScene(new cSceneMain());//setState(1);
    } else if (KEY_DOWN(VK_ESCAPE)) {
        cDirector::getInstance()->popScene();
    }
}

void cNodeRoleSelect::render() {
    cout << "\tName\t" << "Role\t\t" << "Atk\t" << "Def\t" << "Growth\t" << "Img\t" << endl;
    for (int i = 0; i < int(roleContainer.size()); i++) {
        if (i == roleselArrowState) {
            cout << "->";
        } else {
            cout << "  ";
        }
        cRoleSelectData* role = roleContainer[i];
        cout
            << "\t"
            << role->m_strName << "\t"
            << role->m_strRole << "\t\t"
            << role->m_iAtk << "\t"
            << role->m_iDef << "\t"
            << role->m_strGrowth << "\t"
            << role->m_strImg << endl;
    }
}
