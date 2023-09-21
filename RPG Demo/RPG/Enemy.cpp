#include "stdafx.h"
#include "Enemy.h"

cEnemy::cEnemy() 
{
    death = false;
}

void cEnemy::update() {
    //GET_pCURENTSCENE;
    //GET_pSCENEMAIN;
    //for (cEnemyData* pData : m_vecEnemy)
    //{
    //    int playerRow = pCurentScene->getPlayer()->getRow();
    //    int playerCol = pCurentScene->getPlayer()->getCol();
    //    if (
    //        pData->iRow - 1 == playerRow && pData->iCol - 1 == playerCol ||
    //        pData->iRow - 1 == playerRow && pData->iCol + 1 == playerCol ||
    //        pData->iRow - 1 == playerRow && pData->iCol == playerCol ||
    //        pData->iRow + 1 == playerRow && pData->iCol - 1 == playerCol ||
    //        pData->iRow + 1 == playerRow && pData->iCol + 1 == playerCol ||
    //        pData->iRow + 1 == playerRow && pData->iCol == playerCol ||
    //        pData->iRow == playerRow && pData->iCol - 1 == playerCol ||
    //        pData->iRow == playerRow && pData->iCol + 1 == playerCol ||
    //        pData->iRow == playerRow && pData->iCol == playerCol)
    //    {

    //    }
    //    if (pData->iRow == playerRow && pData->iCol == playerCol)
    //    {
    //        delete pData;
    //    }
    //}

}

void cEnemy::initialize(cEnemyData* enemy) {
    m_iID = enemy->iID,
        m_iRow = enemy->iRow,
        m_iCol = enemy->iCol,
        m_iAtk = enemy->iAtk,
        m_iDef = enemy->iDef,
        hp = enemy->iHp,
        m_iCurentMapID = enemy->iCurentMapID,
        m_iEXPValue = enemy->iEXPValue,
        m_strName = enemy->strName,
        m_strImg = enemy->strImg;
}

cEnemyRuler::cEnemyRuler() {
    //m_pEnemy = new cEnemy();
    storage();
}

cEnemyRuler::~cEnemyRuler() {
}

void cEnemyRuler::render(cEnemy* enemy) {
    //m_pEnemy->render(enemy);
    cout << "\tName\t" << "Atk\t" << "Def\t" << "HP\t" << "Img\t" << "EPXValue\t" << endl;
    for (cEnemy* pData : m_vecEnemy) {
        if (pData->getID() == enemy->getID()) {
            cout
                << "\t"
                << enemy->getName() << "\t"
                << enemy->getAtk() << "\t"
                << enemy->getDef() << "\t"
                << enemy->hp << "\t"
                << enemy->getImg() << "\t"
                << enemy->getEXPValue()
                << endl;
            enemy->hp = enemy->hp - 100;
            if (enemy->hp < 0)
                enemy->hp = 0;
        }
    }
}

cEnemy* cEnemyRuler::render(const size_t& r, const size_t& c, const size_t& i) {
    for (cEnemy* pData : m_vecEnemy) {
        if (pData->getRow() == r && pData->getCol() == c && pData->getCurentMapID() == i) {
            return pData;
        }
    }
    return nullptr;
}

cEnemy* cEnemyRuler::getSingleEnemy(const int& enemyID) {
    //GET_pSCENEMAIN;
    //GET_pCURENTSCENE;
    for (cEnemy* pData : m_vecEnemy) {
        if (pData->getID() == enemyID) {
            return pData;
        }
    }
    return nullptr;
}

void cEnemyRuler::storage() {
    //获取map容器里的vector<DataBase*>
    vector<DataBase*> vec = cDataRuler::getInstance()->getDataRuler("EnemyDataRuler")->getVecData();
    for (DataBase* pData : vec) {
        cEnemy* enemyData = new cEnemy();
        //将cDataBase*类型的数据转换为cEnemy*类型
        cEnemyData* enemy = static_cast<cEnemyData*>(pData);
        enemyData->initialize(enemy);
        m_vecEnemy.push_back(enemyData);
    }

}

cEnemy* cEnemyRuler::killed() {
    cEnemy* pData = new cEnemy();
    for (int i = 0; i < int(m_vecEnemy.size()); i++) {
        if (m_vecEnemy[i]->hp == 0) {
            pData = m_vecEnemy[i];
            m_vecEnemy.erase(m_vecEnemy.begin() + i);
            pData->death = true;
            return pData;
        }
    }
    return 0;
}
