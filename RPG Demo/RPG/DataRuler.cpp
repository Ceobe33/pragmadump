#include "stdafx.h"
#include "DataRuler.h"

cDataRuler* cDataRuler::m_pInstance = nullptr;
cDataRuler::cDataRuler()
{
	//初始化指针
	//m_pMapDataRuler = new cMapDataRuler();
	//m_pRoleSelectDataRuler = new cRoleSelectDataRuler();
	//m_pNPCDataRuler = new cNPCDataRuler();
	//m_pGoodsDataRuler = new cGoodsDataRuler();

	////数据加载
	//m_pMapDataRuler->load();
	//m_pRoleSelectDataRuler->load();
	//m_pNPCDataRuler->load();
	//m_pGoodsDataRuler->load();


}


void cDataRuler::addDataRuler(string dataRulerName, cDataBaseRuler* dataRuler)
{
	//子类指针 传到这里自动转化为父类指针
	if (dataRulerName.empty() || !dataRuler)
	{
		return;
	}
	m_mapDataRuler[dataRulerName] = dataRuler;
}

//通过存储在map容器的DataRuler的名字获取相应管理者指针
cDataBaseRuler* cDataRuler::getDataRuler(string dataRulerName)
{
	//for(map<string,cDataBaseRuler*>::iterator it = dataRuler.begin(); it!=)
	if (dataRulerName.empty())
	{
		return nullptr;
	}
	return m_mapDataRuler[dataRulerName];
}


cDataRuler* cDataRuler::getInstance()
{
	//只需要 new 一次
	if (!m_pInstance)
	{
		m_pInstance = new cDataRuler();
	}
	return m_pInstance;
}
//
//map<string, cDataBaseRuler*> cDataRuler::getMapDataRuler()
//{
//	return m_mapDataRuler;
//}
