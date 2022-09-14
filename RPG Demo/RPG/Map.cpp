#include "stdafx.h"
#include "Map.h"
//初始化地图实例
cMap* cMap::m_pInstanceMap = nullptr;
cMap::cMap() {
    //从地图管理者获取地图容器
    vector<DataBase*> vec = cDataRuler::getInstance()->getDataRuler("MapDataRuler")->getVecData();
    for (DataBase* mapData : vec) {
        //cMap* map = new cMap();
        //从 DataBase* 类型转换为 MapData* 类型
        MapData* pData = static_cast<MapData*>(mapData);
        //map->initialize(pData);
        //storage
        m_vecMap.push_back(pData);
    }
}


cMap::~cMap() {
}
//传入玩家的行列
MapData* cMap::getMapByID(const int& mapID) {
    //遍历地图的容器
    for (MapData* mapData : m_vecMap) {
        if (mapData->iID == mapID) {
            return mapData;
        }
    }
    return nullptr;

}

cMap* cMap::getInstance() {
    if (!m_pInstanceMap) {
        m_pInstanceMap = new cMap();
    }
    return m_pInstanceMap;
}

//void cMap::initialize(MapData* data)
//{
//	m_iID = data->iID;
//	m_iRow = data->m_iRow;
//	m_iCol = data->m_iCol;
//	m_iPlayerRow = data->m_iPlayerRow;
//	m_iPlayerRow = data->m_iPlayerCol;
//}

//cMapRuler::cMapRuler()
//{
//	vector<DataBase*> vec = cDataRuler::getInstance()->getDataRuler("MapDataRuler")->getDataVector();
//	for (DataBase* mapData : vec)
//	{
//		cMap* map = new cMap();
//		MapData* pData = static_cast<MapData*>(mapData);
//		map->initialize(pData);
//		m_vecMap.push_back(map);
//	}
//}
//
//cMapRuler::~cMapRuler()
//{
//}