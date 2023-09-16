#include "stdafx.h"
#include "RoleSelect.h"
#include "SceneMain.h"
#include "Emitter.h"

cRoleSelect::cRoleSelect() {
}

void cRoleSelect::initialize(cRoleSelectData* data) {
    m_strName = data->m_strName;
    m_strRole = data->m_strRole;
    m_strGrowth = data->m_strGrowth;
    m_strImg = data->m_strImg;
    m_iAtk = data->m_iAtk;
    m_iDef = data->m_iDef;
    m_iHP = data->m_iHP;
    m_iAcount = data->m_iAcount;
}

void cRoleSelect::render(cRoleSelect* role) {
    cout
        << "\t"
        << role->m_strName << "\t"
        << left << setw(10) << role->m_strRole    //left:左对齐  setw（15）设置输出宽度为15
        << role->m_iAtk << "\t"
        << role->m_iDef << "\t"
        << role->m_strGrowth << "\t"
        << role->m_strImg << "\t"
        << role->m_iAcount << endl;
}

cRoleSelect* cRoleSelect::getDataByID(const int &i) {
    GET_pSCENEMAIN;
    for (cRoleSelect* pData : pSceneMain->getRoleSelectRuler()->roleContainer)    {
        if (pData->m_iID == i) {
            return pData;
        }
    }
    return nullptr;
}

cRoleSelectRuler::cRoleSelectRuler() {
    m_strName = "RoleSelectRuler";
    roleselArrowState = 0;
    selectedRole = new cRoleSelect();
    //将数据文件存储
    storage();
}

void cRoleSelectRuler::update() {
    Sleep(70);
    if (KEY_DOWN(VK_DOWN)) {
        roleselArrowState++;
    } else if (KEY_DOWN(VK_UP)) {
        roleselArrowState--;
    }

    int playerVecSize = int(roleContainer.size());
    if (0 > roleselArrowState) {
        roleselArrowState = 0;
    } else if (playerVecSize - 1 < roleselArrowState) {
        roleselArrowState = playerVecSize - 1;
    } else if (KEY_DOWN(VK_RETURN))    {
        //获取选角色的数据
        cRoleSelectData* pData = static_cast<cRoleSelectData*>(cDataRuler::getInstance()->getDataRuler("RoleSelectDataRuler")->getDataByID(roleselArrowState + 100));
        cSceneMain* pGameScene = new cSceneMain();
        pGameScene->getPlayer()->initialize(pData);
        cDirector::getInstance()->pushScene(pGameScene);
        //cEmitter::getInstance()->registerNews("curentPlayer", bind(&cRoleSelect::getVecPlayer()[roleselArrowState], this, placeholders::_1));
    } else if (KEY_DOWN(VK_ESCAPE))    {
        cDirector::getInstance()->popScene();
    }
}

void cRoleSelectRuler::render() {
    cout << "\tName\t" << left << setw(10) << "Role" << "Atk\t" << "Def\t" << "Growth\t" << "Img\t" << "Acount\t" << endl;
    for (int i = 0; i < int(roleContainer.size()); i++) {
        if (i == roleselArrowState) {
            cout << "-->";
        } else {
            cout << "   ";
        }
        selectedRole->render(roleContainer[i]);
    }
}

void cRoleSelectRuler::storage() {
    vector<DataBase*> vecData = cDataRuler::getInstance()->getDataRuler("RoleSelectDataRuler")->getVecData();
    for (DataBase* pBase : vecData) {
        cRoleSelect* pRole = new cRoleSelect();
        cRoleSelectData* pData = static_cast<cRoleSelectData*>(pBase);
        pRole->initialize(pData);
        roleContainer.push_back(pRole);
    }
}