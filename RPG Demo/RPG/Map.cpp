#include "stdafx.h"
#include "Map.h"
//��ʼ����ͼʵ��
cMap* cMap::m_pInstanceMap = nullptr;
cMap::cMap()
{
	//�ӵ�ͼ�����߻�ȡ��ͼ����
	vector<cDataBase*> vec = cDataRuler::getInstance()->getDataRuler("MapDataRuler")->getVecData();
	for (cDataBase* mapData : vec)
	{
		//cMap* map = new cMap();
		//�� cDataBase* ����ת��Ϊ cMapData* ����
		cMapData* pData = static_cast<cMapData*>(mapData);
		//map->initialize(pData);
		//storage
		m_vecMap.push_back(pData);
	}
}


cMap::~cMap()
{
}
//������ҵ�����
cMapData* cMap::getMapByID(const int &mapID)
{
	//������ͼ������
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