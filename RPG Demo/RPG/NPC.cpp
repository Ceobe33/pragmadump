#include "stdafx.h"
#include "NPC.h"

cNPC::cNPC()
{
	
}


cNPC::~cNPC()
{
}

void cNPC::update()
{

}

//
//cNPC* cNPC::render(const int& r, const int& c, const int& i)
//{
//	GET_pCURENTSCENE;
//	//��������ÿ��Ԫ�����θ�ֵ�� pNPC  //����
//	for (cNPC* pNPC : pCurentScene->getNPCRuler()->getVecNPC())
//	{
//		if (pNPC->m_iRow == r && pNPC->m_iCol == c && pNPC->m_iCurentMapID == i)
//		{
//			return pNPC;
//		}
//	}
//	return nullptr;
//}
void cNPC::initialize(cNPCData* data)
{
	m_iID = data->iID;
	m_iRow = data->iRow;
	m_iCol = data->iCol;
	m_iCurentMapID = data->iCurentMapID;
	m_strName = data->strName;
	m_strOccupation = data->strOccupation;
	m_strDialogue = data->strDialogue;
}

cNPC* cNPCRuler::getNPCByID(const int& i)
{
	//GET_pCURENTSCENE;
	//GET_pSCENEMAIN;
	for (cNPC* pData : m_vecNPC)
	{
		if (pData->getID() == i)
		{
			return pData;
		}
	}
	
	return nullptr;
}

cNPCRuler::cNPCRuler()
{
	//m_pNPC = new cNPC();
	storage();
}


void cNPCRuler::storage()
{
	//��ȡ�洢NPC���ݵ�����
	vector<cDataBase*> vecNPCData = cDataRuler::getInstance()->getDataRuler("NPCDataRuler")->getVecData();
	for (cDataBase* pNPC : vecNPCData)
	{
		cNPC* pNpc = new cNPC();
		//������� cDataBase* ��ת��Ϊ cNPCData* ��
		cNPCData* pData = static_cast<cNPCData*>(pNPC);
		//��NPC�����ļ���ʼ��
		pNpc->initialize(pData);
		//��ÿ����ʼ����NPCװ��NPC����
		m_vecNPC.push_back(pNpc);
	}

}

cNPC* cNPCRuler::render(const int& r, const int& c, const int& i)
{
	//��������ÿ��Ԫ�����θ�ֵ�� pNPC  //����
	for (cNPC* pNPC :m_vecNPC)
	{
		if (pNPC->getRow() == r && pNPC->getCol() == c && pNPC->getCurentMapID() == i)
		{
			return pNPC;
		}
	}
	return nullptr;
}

//
//
//cNPCData* cNPC::dialogue(const int& r)
//{
//	//��������ÿ��Ԫ�����θ�ֵ�� pNPC  //����
//	for (cNPCData* pNPC : m_vecNPC)
//	{
//		if (pNPC->iID == r)
//		{
//			return pNPC;
//		}
//	}
//	return nullptr;
//}
