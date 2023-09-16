#pragma once
#ifndef RPG_RPG_DATASTRUCT_H_
#define RPG_RPG_DATASTRUCT_H_

#include "DataBase.h"

class cDataStruct {
    cDataStruct();
    ~cDataStruct() {}
};

struct MapData :public DataBase {
    int  m_iRow, m_iCol, m_iPlayerRow, m_iPlayerCol;
    int m_arrMap[100][100];
};

class cMapDataRuler : public cDataBaseRuler {
public:
    void load();
    //MapData* getMapById(int mapID);
    //获取地图容器
    //CC_GET_SETPRIVATE(vector<MapData*>, VecMap, m_vecMap);

private:
    //vector<MapData*> m_vecMap;
};

class cRoleSelectData :public DataBase {
public:
    cRoleSelectData() {}
    string m_strName, m_strRole{}, m_strGrowth{}, m_strImg{};
    int  m_iAtk{}, m_iDef{}, m_iHP{}, m_iAcount{};
};

class cRoleSelectDataRuler :public cDataBaseRuler {
public:
    void load();
private:
};

class cDataLoad {
public:
    cDataLoad() {}
    ~cDataLoad() {}

    void dataLoad() {}
};

class cNPCData :public DataBase {
public:
    cNPCData() {}

    int iRow{}, iCol{}, iCurentMapID{};
    string strName, strOccupation, strDialogue;
};

class cNPCDataRuler :public cDataBaseRuler
{
public:
    cNPCDataRuler() {}
    ~cNPCDataRuler() {}

    void load();
private:
};

class cGoodsData :public DataBase {
public:
    cGoodsData() { iBagCount = 0, iEquipmentCount = 0; }
    int iBagCount{}, iEquipmentCount{};//背包/容器内用于计数的变量
    int iNPCID{}, iAmount{}, iPrice{}, iAtk{}, iDef{}, iHeal{};
    string strName, strDetail, strTag;
};

class cGoodsDataRuler :public cDataBaseRuler {
public:
    cGoodsDataRuler() {}
    ~cGoodsDataRuler() {}

    void load();
private:
};

class cEnemyData :public DataBase {
public:
    cEnemyData() {}

    int iRow{}, iCol{}, iAtk{}, iDef{}, iHp{}, iCurentMapID{}, iEXPValue{};
    string strName, strImg;
};

class cEnemyDataRuler :public cDataBaseRuler {
public:
    cEnemyDataRuler() {}
    ~cEnemyDataRuler() {}

    void load();
};

class cPetData :public DataBase {
public:
    cPetData() {}
    int iRow{}, iCol{}, iGain{};
    string    strName, strImg;
};

class cPetDataRuler :public cDataBaseRuler {
public:
    cPetDataRuler() {}
    ~cPetDataRuler() {}

    void load();
};

// this class is used to load above of all datas
class cLoad {
public:
    cLoad();
    ~cLoad();

private:

};

#endif // !RPG_RPG_DATASTRUCT_H_