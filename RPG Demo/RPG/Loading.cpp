#include "stdafx.h"
#include "Loading.h"
#include"map.h"

cLoading* cLoading::m_pInstanceLoading = nullptr;
cLoading::cLoading() {
    m_strName = "Loading";
}

cLoading::~cLoading() {
}

void cLoading::update() {
}

void cLoading::render() {
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl
        << endl << endl << "                          Loading..." << endl
        << endl;
    int a = 100;
    for (int i = 0; i < 33; i++) {
        switch (i) {
            case 5:
                // the size_type convert is to solve the warning C4244
                a -= int(a * 0.9);
                break;
            case 20:
                a -= int(a * 0.05);
                break;
            case 30:
                a -= int(a * 0.04);
                break;
            case 32:
                a -= int(a * 0.01);
                break;
        }

        Sleep(a);
        cout << "¡ö";
    }
    system("cls");
    cDirector::getInstance()->popScene();
    //    cDirector::getInstance()->popScene();

        /*cSceneMain* pSceneMain = static_cast<cSceneMain*>(cDirector::getInstance()->getScene());
        pSceneMain->setCurentMap(cMap::getInstance()->getMapByID(nextMapId));
        pSceneMain ->getPlayer()->surroundPlayer(eWall);

        if (405 == pSceneMain->getSurroundPlayer())
            pSceneMain->getPlayer()->setPosition
            (pSceneMain->getPlayer()->getBackupTrainRow(), pSceneMain->getPlayer()->getBackupTrainCol());
            */
}

cLoading* cLoading::getInstance() {
    if (!m_pInstanceLoading) {
        m_pInstanceLoading = new cLoading();
    }
    return m_pInstanceLoading;
}