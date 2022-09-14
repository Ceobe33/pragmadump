#include "stdafx.h"
#include "Clert.h"

// ʵ�ֲ�ͬ�����µ���clert��ͬ����Ⱦ����

cClert* cClert::m_pInstance = nullptr;
cClert::cClert() {
    m_strName = "Clert";
}

cClert::~cClert() {
}

void cClert::update() {
    if (KEY_DOWN(VK_RETURN)) {
        cDirector::getInstance()->popScene();//�˳�clert
        cDirector::getInstance()->popScene();//�˳�sceneMain
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
