#pragma once
#ifndef RPG_RPG_DATASTRUCT_H_
#define RPG_RPG_DATASTRUCT_H_

#include "DataBase.h"

class cDataStruct {
	cDataStruct();
};

class cMapData :public cDataBase {
public:
	int  m_iRow, m_iCol, m_iPlayerRow, m_iPlayerCol;
	int m_arrMap[100][100];
};

class cMapDataRuler : public cDataBaseRuler {
public:
	void load();
	//cMapData* getMapById(int mapID);
	//获取地图容器
	//CC_GET_SETPRIVATE(vector<cMapData*>, VecMap, m_vecMap);

private:
	//vector<cMapData*> m_vecMap;
};

class cRoleSelectData :public cDataBase {
public:
	cRoleSelectData() {}
	string m_strName, m_strRole{}, m_strGrowth{}, m_strImg{};
	int  m_iAtk{}, m_iDef{}, m_iHP{}, m_iAcount{};
};

class cRoleSelectDataRuler : public cDataBaseRuler {
public:
	void load();

	//CC_GET_SETPRIVATE(vector<cRoleSelectData*>, VecPlayer, m_vecPlayer);
private:
	//vector<cRoleSelectData*> m_vecPlayer;
};

class cDataLoad {
public:
	cDataLoad() {}

	void dataLoad() {}
};

class cNPCData :public cDataBase {
public:
	cNPCData() {}

	int iRow{}, iCol{}, iCurentMapID{};
	string strName, strOccupation, strDialogue;
};

class cNPCDataRuler : public cDataBaseRuler
{
public:
	cNPCDataRuler() {}
	~cNPCDataRuler() {}

	void load();

	//CC_GETPRIVATE(vector<cNPCData*>, VecNPC, m_vecNPC);
private:
	//vector<cNPCData*> m_vecNPC;
};

class cGoodsData :public cDataBase {
public:
	cGoodsData() { iBagCount = 0, iEquipmentCount = 0; }
	int iBagCount{}, iEquipmentCount{};//背包/容器内用于计数的变量
	int iNPCID{}, iAmount{}, iPrice{}, iAtk{}, iDef{}, iHeal{};
	string strName, strDetail, strTag;
};

class cGoodsDataRuler : public cDataBaseRuler {
public:
	cGoodsDataRuler() {}
	~cGoodsDataRuler() {}

	void load();

	//CC_GETPRIVATE(vector<cGoodsData*>, VecGoods, m_vecGoods);

private:
	//vector<cGoodsData*> m_vecGoods;
};

class cEnemyData :public cDataBase {
public:
	cEnemyData() {}

	int iRow{}, iCol{}, iAtk{}, iDef{}, iHp{}, iCurentMapID{}, iEXPValue{};
	string strName, strImg;
};

class cEnemyDataRuler : public cDataBaseRuler {
public:
	cEnemyDataRuler() {}

	void load();
};

class cPetData :public cDataBase {
public:
	cPetData() {}
	int iID{}, iRow{}, iCol{}, iGain{};
	string	strName, strImg;
};

class cPetDataRuler : public cDataBaseRuler {
public:
	cPetDataRuler() {}

	void load();
};

//class cEnemyDataRuler : public cDataBaseRuler
//{
//public:
//	cEnemyDataRuler() {}
//
//	void load();
//
//};

class cLoad {
public:
	cLoad();
	~cLoad();

private:

};

#endif // !RPG_RPG_DATASTRUCT_H_