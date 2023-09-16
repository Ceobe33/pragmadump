#include "Bag.h"
#include "stdafx.h"

cBag::cBag()
    :bagArrowState(0) {
    m_strName = "Bag";
}

void cBag::update() {
    int bagSize = m_vecBag.size();
    if (KEY_DOWN(VK_ESCAPE)) {
        cDirector::getInstance()->popScene();
    } else if (KEY_DOWN(VK_DOWN)) {
        if (bagArrowState < bagSize - 1)
            bagArrowState++;
    } else if (KEY_DOWN(VK_UP)) {
        if (bagArrowState > 0)
            bagArrowState--;
    } else if (KEY_DOWN(VK_RETURN)) {
        for (int i = 0; i < bagSize; i++) {
            if (i == bagArrowState) {
                //GET_pCURENTSCENE;
                GET_pSCENEMAIN;
                //传相应装备ID给store 来装备到物品容器
                cGoodsData* pData = pSceneMain->getStore()->armament(m_vecBag[i]->iID);
                //将相应物品加到物品栏
                //pSceneMain->getPlayer()->getEquipment()->addEquipment(pData);
                //将相应物品属性加成到玩家
                pSceneMain->getPlayer()->bonus("in", pData);
                //if (pData->strTag == "arms")
                //{
                //    pSceneMain->getPlayer()->getEquipment()->addEquipment(pData);
                //}
                //else if (pData->strTag == "edible")
                //{
                //    pSceneMain->getPlayer()->useItem(pData);
                //}
                //装备加成
                //pSceneMain->getPlayer()->bonus("in",pData);

                if (m_vecBag[i]->iBagCount <= 0) {
                    deleteGoods(m_vecBag[i]->strName);
                    //m_vecBag.erase(m_vecBag.begin() + i);
                    bagArrowState = 0;
                    system("cls");
                }
                break;
            }
        }
    }
}

void cBag::render() {
    //GET_pCURENTSCENE;
    GET_pSCENEMAIN;
    //玩家属性显示
    pSceneMain->getPlayer()->propertyRender();
    //背包物品显示
    cout << endl << endl << "        It is " << pSceneMain->getPlayer()->getName() << "'s bag."
        << endl << "\tName\t\t" << "Atk\t" << "Heal\t" << "Count\t" << "Price\t" << "Details\t" << endl;
    for (int i = 0; i < int(m_vecBag.size()); i++) {
        if (i == bagArrowState)
            cout << "-->\t";
        else
            cout << "   \t";
        cGoodsData* pData = m_vecBag[i];
        cout
            << left << setw(8) << pData->strName << "\t"
            << pData->iAtk << "\t"
            << pData->iHeal << "\t"
            << pData->iBagCount << "\t"
            << pData->iPrice << "\t"
            << pData->strDetail << "\t" << endl;

    }
    //装备物品显示
    cout << endl << endl << "        It is " << m_strName << "'s equipment."
        << endl << "\tName\t\t" << "Atk\t" << "Count\t" << "Price\t" << "Details\t" << endl;
    int equipmentContainerSize = int(pSceneMain->getPlayer()->getEquipment()->getVecEquipment().size());
    for (int i = 0; i < equipmentContainerSize; i++) {
        cout << "\t";
        cGoodsData* pData = pSceneMain->getPlayer()->getEquipment()->getVecEquipment()[i];
        cout
            << left << setw(8) << pData->strName << "\t"
            << pData->iAtk << "\t"
            //<< pData->iHeal << "\t"
            << pData->iEquipmentCount << "\t"
            << pData->iPrice << "\t"
            << pData->strDetail << "\t" << endl;
    }
}

cGoodsData* cBag::takeGoods(string name) {
    for (cGoodsData* pData : m_vecBag) {
        if (pData->strName == name)
            return pData;
    }
    return nullptr;
}

void cBag::deleteGoods(string name) {
    for (int i = 0; i < int(m_vecBag.size()); i++) {
        if (m_vecBag[i]->strName == name) {
            m_vecBag.erase(m_vecBag.begin() + i);
            return;
        }
    }
}

void cBag::addGoods(cGoodsData* goods) {
    if (goods->iAmount > 0)
        goods->iAmount--;
    goods->iBagCount++;
    for (cGoodsData* pData : m_vecBag) {
        if (goods->iID == pData->iID) {
            return;
        }
    }
    m_vecBag.push_back(goods);
}

//
//void cBag::unload(cGoodsData* pData)
//{
//    pData->iBagCount++;
//    for (cGoodsData* pData : m_vecBag)
//    {
//        if (pData->iAmount > 0)
//        {
//            return;
//        }
//    }
//    m_vecBag.push_back(pData);
//}

vector<cGoodsData*> cBag::getVecBag() {
    return m_vecBag;
}
