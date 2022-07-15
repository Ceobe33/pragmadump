#include "stdafx.h"
#include "DataStruct.h"

cDataStruct::cDataStruct() {
}

void cRoleSelectDataRuler::load() {
	fstream loadFile("data/100_characters.txt");
	if (loadFile) {
		getline(loadFile, string());
		int iRowAmount;
		loadFile >> iRowAmount;
		for (int i = 0; i < iRowAmount; i++) {
			cRoleSelectData* data = new cRoleSelectData();
			loadFile 
				>> data->iID >> data->m_strName
				>> data->m_strRole >> data->m_iAtk >> data->m_iDef
				>> data->m_iHP>> data->m_strGrowth >> data->m_strImg >> data->m_iAcount;
			m_vecDataBase.push_back(data);
		}
		int a = 0;
	}
}
//
//MapData* cMapDataRuler::getMapById(int mapID) {
//	for (int i = 0; i < m_vecMap.size(); i++) {
//		if (m_vecMap[i]->m_mapID == mapID) {
//			return m_vecMap[i];
//		}
//	}
//	return nullptr;
//}

void cMapDataRuler::load() {
	fstream loadFile("data/200_map.txt");
	if (loadFile) {
		getline(loadFile, string());
		int mapAmount;
		loadFile >> mapAmount;
		for (int i = 0; i < mapAmount; i++) {
			MapData* data = new MapData();
			loadFile >> data->iID >> data->m_iRow >> data->m_iCol >> data->m_iPlayerRow >> data->m_iPlayerCol;
			for (int p = 0; p < data->m_iRow; p++) {
				for (int q = 0; q < data->m_iCol; q++) {
					loadFile >> data->m_arrMap[p][q];
					/*if (m_arrMap[p][q] >= 500 && m_arrMap[p][q] < 600) {
					}*/
				}
			}
			m_vecDataBase.push_back(data);
		}
	}
	int a = 0;
}

void cGoodsDataRuler::load() {
	fstream loadFile("data/300_goods.txt");
	if (loadFile) {
		getline(loadFile, string());
		int iRowAmount;
		loadFile >> iRowAmount;
		for (int i = 0; i < iRowAmount; i++) {
			cGoodsData* data = new cGoodsData();
			loadFile
				>> data->iID >> data->strName >> data->iAtk >> data->iHeal
				>> data->iNPCID >> data->iAmount >> data->iPrice >> data->strTag>>data->iDef>>data->strDetail;
			m_vecDataBase.push_back(data);
		}
	}
	int a = 0;
}

void cNPCDataRuler::load() {
	fstream loadFile("data/400_npc.txt");
	if (loadFile) {
		getline(loadFile, string());
		int iRowAmount;
		loadFile >> iRowAmount;
		for (int i = 0; i < iRowAmount; i++) {
			cNPCData* data = new cNPCData();
			loadFile
				>> data->iID >> data->strName >> data->strOccupation
				>> data->iRow >> data->iCol >> data->iCurentMapID >> data->strDialogue;
			m_vecDataBase.push_back(data);
		}
	}
	int a = 0;
}

void cEnemyDataRuler::load() {
	fstream loadFile("data/500_enemy.txt");
	if (loadFile) {
		getline(loadFile, string());
		int iRowAmount;
		loadFile >> iRowAmount;
		for (int i = 0; i < iRowAmount; i++) {
			cEnemyData* data = new cEnemyData();
			loadFile
				>> data->iID >> data->strName >> data->iRow >> data->iCol >> data->iAtk >> data->iDef >> data->iHp>> data->strImg
				/*>> data->iRow >> data->iCol*/ >> data->iCurentMapID >> data->iEXPValue;
			m_vecDataBase.push_back(data);
		}
	}
	int a = 0;
}

void cPetDataRuler::load() {
	fstream loadFile("data/600_pet.txt");
	if (loadFile) {
		getline(loadFile, string());
		int iRowAmount;
		loadFile >> iRowAmount;
		for (int i = 0; i < iRowAmount; i++) {
			cPetData* data = new cPetData();
			loadFile
				>> data->iID >> data->strName >> data->iRow >> data->iCol >> data->strImg >> data->iGain;
			m_vecDataBase.push_back(data);
		}
	}
}

// proxy class, to load the game data. Only running once at the game beginning
cLoad::cLoad() {
	cMapDataRuler* pMapDataRuler = new cMapDataRuler();
	pMapDataRuler->load();
	cDataRuler::getInstance()->addDataRuler("MapDataRuler", pMapDataRuler);

	cRoleSelectDataRuler* pRoleSelectDataRuler = new cRoleSelectDataRuler();
	pRoleSelectDataRuler->load();
	cDataRuler::getInstance()->addDataRuler("RoleSelectDataRuler", pRoleSelectDataRuler);

	cNPCDataRuler* pNPCDataRuler = new cNPCDataRuler();
	pNPCDataRuler->load();
	cDataRuler::getInstance()->addDataRuler("NPCDataRuler", pNPCDataRuler);

	cGoodsDataRuler* pGoodsDataRuler = new cGoodsDataRuler();
	pGoodsDataRuler->load();
	cDataRuler::getInstance()->addDataRuler("GoodsDataRuler", pGoodsDataRuler);

	cEnemyDataRuler* pEnemyDataRuler = new cEnemyDataRuler();
	pEnemyDataRuler->load();
	cDataRuler::getInstance()->addDataRuler("EnemyDataRuler", pEnemyDataRuler);

	cPetDataRuler* pPetDataRuler = new cPetDataRuler();
	pPetDataRuler->load();
	cDataRuler::getInstance()->addDataRuler("PetsDataRuler", pPetDataRuler);
}

cLoad::~cLoad() {
}