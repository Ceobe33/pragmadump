#include "stdafx.h"
#include "PetStore.h"

cPetStore::cPetStore() {
    m_strName = "Pet";
    arrowState = 0;
    storage();
    //initialize();
}

//cPetStore::cPetStore()
//{
//    m_strName = "Store";
//    arrowState = 0;
//    m_pPlayer = new cPlayer();
//    //初始化商品数据
//}

cPetStore::~cPetStore() {
}

void cPetStore::update() {
    //GET_pCURENTSCENE;
    GET_pSCENEMAIN;
    if (KEY_DOWN(VK_DOWN)) {
        arrowState++;
    }
    else if (KEY_DOWN(VK_UP)) {
        arrowState--;
    }
    else if (KEY_DOWN(VK_ESCAPE)) {
        cDirector::getInstance()->popScene();
    }
    else if (KEY_DOWN(VK_RETURN)) {
        pSceneMain->getPlayer()->havePet = true;
        if (m_vecPets.size()) {
            cPetData* pData = m_vecPets[arrowState];
        }
        //cEmitter::getInstance()->emitNews("buyGoods", pData);
        //pSceneMain->getPlayer()->buyGoods(pData);
        m_vecPets.clear();
    }
    int petVecSize = int(m_vecPets.size());
    if (arrowState < 0)
        arrowState = 0;
    else if (arrowState >= petVecSize)
        arrowState = petVecSize - 1;
}

void cPetStore::render() {
    // GET_pCURENTSCENE;
    GET_pSCENEMAIN;
    // 玩家属性渲染
    pSceneMain->getPlayer()->propertyRender();
    // 商店物品渲染
    cNPC* pNPC = pSceneMain->getNPCRuler()->getNPCByID(pSceneMain->getSurroundPlayer());
    cout << endl << endl << "\t\t" << "欢迎来到" << pNPC->getName() << "的" << pNPC->getOccupation() << endl;
    cout << "\tName\t\t" << "Img\t" << "Gain\t" << endl;
    for (int i = 0; i < int(m_vecPets.size()); i++) {
        cPetData* data = m_vecPets[i];

        if (arrowState == i)
            cout << "-->";
        else
            cout << "   ";
        cout << "\t"
            << left << setw(8) << data->strName << "\t"
            << data->strImg << "\t"
            << data->iGain << "\t"
            << endl;
    }
    // 玩家背包渲染
    //cout << endl << endl << "        It is " << pSceneMain->getPlayer()->getName() << "'s bag."
    //    << endl << "\tName\t\t" << "Atk\t" << "Count\t" << "Price\t" << "Details\t" << endl;
    //for (int i = 0; i < pSceneMain->getPlayer()->getBag()->getVecBag().size(); i++)
    //{

    //    cout << "\t";
    //    cGoodsData* pData = pSceneMain->getPlayer()->getBag()->getVecBag()[i];
    //    cout
    //        << left << setw(8) << pData->strName << "\t"
    //        << pData->iAtk << "\t"
    //        << pData->iBagCount << "\t"
    //        << pData->iPrice << "\t"
    //        << pData->strDetail << "\t" << endl;
    //}
}

// bag content initialize
void cPetStore::storage() {
    vector<DataBase*> vec = cDataRuler::getInstance()->getDataRuler("PetsDataRuler")->getVecData();
    for (DataBase* data : vec) {
        cPetData* pet = static_cast<cPetData*>(data);
        m_vecPets.push_back(pet);
    }
}

void cPetStore::init(cPetData* pData) {
    assert(pData != nullptr);

    iID = pData->iID;
    iRow = pData->iRow;
    iCol = pData->iCol;
    iGain = pData->iGain;
    strName = pData->strName;
    strImg = pData->strImg;
}

//vector<cPetData*> cPetStore::getVectorPets(const int& i) {
//    for (cPetData* pData : m_vecPets) {
//        if (pData->iID == i) {
//            m_vecItems.push_back(pData);
//        }
//    }
//    return m_vecItems;
//}

//void cPetStore::initItems(const int& i) {
//    for (cGoodsData* pData : m_vecGoods) {
//        if (pData->iNPCID == i) {
//            m_vecItems.push_back(pData);
//        }
//    }
//}
//
//cPetData* cPetStore::armament(const int& i) {
//    for (cGoodsData* vec : m_vecGoods) {
//        if (vec->iID == i) {
//            return vec;
//        }
//    }
//}