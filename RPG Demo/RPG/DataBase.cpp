#include "stdafx.h"
#include "DataBase.h"

cDataBaseRuler* cDataBaseRuler::m_pInstanceDataBaseRuler = nullptr;
cDataBaseRuler::cDataBaseRuler() {
}

cDataBaseRuler::~cDataBaseRuler() {
}

void cDataBaseRuler::load() {
}

cDataBaseRuler* cDataBaseRuler::getInstance() {
    if (!m_pInstanceDataBaseRuler) {
        m_pInstanceDataBaseRuler = new cDataBaseRuler();
    }
    return m_pInstanceDataBaseRuler;
}

DataBase* cDataBaseRuler::getDataByID(const int& iID) {
    for (DataBase* pData : m_vecDataBase) {
        if (pData->iID == iID)
            return pData;
    }
    return nullptr;
}

vector<DataBase*> cDataBaseRuler::getVecData() {
    //for (map<string, cDataBaseRuler*>::iterator iter = cDataRuler::getMapDataRuler().begin();)
    return m_vecDataBase;
}
