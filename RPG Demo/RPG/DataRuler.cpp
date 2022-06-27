#include "stdafx.h"
#include "DataRuler.h"

cDataRuler* cDataRuler::m_pInstance = nullptr;
cDataRuler::cDataRuler()
{
	//��ʼ��ָ��
	//m_pMapDataRuler = new cMapDataRuler();
	//m_pRoleSelectDataRuler = new cRoleSelectDataRuler();
	//m_pNPCDataRuler = new cNPCDataRuler();
	//m_pGoodsDataRuler = new cGoodsDataRuler();

	////���ݼ���
	//m_pMapDataRuler->load();
	//m_pRoleSelectDataRuler->load();
	//m_pNPCDataRuler->load();
	//m_pGoodsDataRuler->load();


}


void cDataRuler::addDataRuler(string dataRulerName, cDataBaseRuler* dataRuler)
{
	//����ָ�� ���������Զ�ת��Ϊ����ָ��
	if (dataRulerName.empty() || !dataRuler)
	{
		return;
	}
	m_mapDataRuler[dataRulerName] = dataRuler;
}

//ͨ���洢��map������DataRuler�����ֻ�ȡ��Ӧ������ָ��
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
	//ֻ��Ҫ new һ��
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
