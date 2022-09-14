#include "stdafx.h"
#include "Clert.h"

// 实现不同场景下调用clert不同的渲染函数

cClert* cClert::m_pInstance = nullptr;
cClert::cClert() {
    m_strName = "Clert";
}

cClert::~cClert() {
}

void cClert::update() {
    if (KEY_DOWN(VK_RETURN)) {
        cDirector::getInstance()->popScene();//退出clert
        cDirector::getInstance()->popScene();//退出sceneMain
    } else if (KEY_DOWN(VK_ESCAPE)) {
        cDirector::getInstance()->popScene();
    }
}

void cClert::render() {
    cout << endl << endl << "				do you wanna go RoleSelect scene?"
        << endl << "				press RETURN to confirm, Esc to cancel.";
}

void cClert::buyingPower() {
    cout << endl << endl << "				you have no authority to buy this" << endl;
}

cClert* cClert::getInstance() {
    if (!m_pInstance) {
        m_pInstance = new cClert();
    }
    return m_pInstance;
}
