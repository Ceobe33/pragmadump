#include "stdafx.h"
#include "Map.h"
//初始化地图实例
cMap* cMap::m_pInstanceMap = nullptr;
cMap::cMap()
{
	//从地图管理者获取地图容器
	vector<cDataBase*> vec = cDataRuler::getInstance()->getDataRuler("MapDataRuler")->getVecData();
	for (cDataBase* mapData : vec)
	{
		//cMap* map = new cMap();
		//从 cDataBase* 类型转换为 cMapData* 类型
		cMapData* pData = static_cast<cMapData*>(mapData);
		//map->initialize(pData);
		//storage
		m_vecMap.push_back(pData);
	}
}


cMap::~cMap()
{
}
//传入玩家的行列
cMapData* cMap::getMapByID(const int &mapID)
{
	//遍历地图的容器
	for (cMapData* mapData: m_vecMap)
	{
		if (mapData->iID == mapID)
		{
			return mapData;
		}
	}
	return nullptr;
	
}

cMap* cMap::getInstance()
{
	if (!m_pInstanceMap)
	{
		m_pInstanceMap = new cMap();
	}
	return m_pInstanceMap;
}

//void cMap::initialize(cMapData* data)
//{
//	m_iID = data->iID;
//	m_iRow = data->m_iRow;
//	m_iCol = data->m_iCol;
//	m_iPlayerRow = data->m_iPlayerRow;
//	m_iPlayerRow = data->m_iPlayerCol;
//}

//cMapRuler::cMapRuler()
//{
//	vector<cDataBase*> vec = cDataRuler::getInstance()->getDataRuler("MapDataRuler")->getDataVector();
//	for (cDataBase* mapData : vec)
//	{
//		cMap* map = new cMap();
//		cMapData* pData = static_cast<cMapData*>(mapData);
//		map->initialize(pData);
//		m_vecMap.push_back(map);
//	}
//}
//
//cMapRuler::~cMapRuler()
//{
//}