#include "stdafx.h"
#include "Map.h"
//��ʼ����ͼʵ��
cMap* cMap::m_pInstanceMap = nullptr;
cMap::cMap() {
    //�ӵ�ͼ�����߻�ȡ��ͼ����
    vector<DataBase*> vec = cDataRuler::getInstance()->getDataRuler("MapDataRuler")->getVecData();
    for (DataBase* mapData : vec) {
        //cMap* map = new cMap();
        //�� DataBase* ����ת��Ϊ MapData* ����
        MapData* pData = static_cast<MapData*>(mapData);
        //map->initialize(pData);
        //storage
        m_vecMap.push_back(pData);
    }
}


cMap::~cMap() {
}
//������ҵ�����
MapData* cMap::getMapByID(const int& mapID) {
    //������ͼ������
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