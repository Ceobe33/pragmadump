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
//	//将容器内每个元素依次赋值给 pNPC  //遍历
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
	//获取存储NPC数据的容器
	vector<cDataBase*> vecNPCData = cDataRuler::getInstance()->getDataRuler("NPCDataRuler")->getVecData();
	for (cDataBase* pNPC : vecNPCData)
	{
		cNPC* pNpc = new cNPC();
		//将父类的 cDataBase* 型转换为 cNPCData* 型
		cNPCData* pData = static_cast<cNPCData*>(pNPC);
		//将NPC数据文件初始化
		pNpc->initialize(pData);
		//将每个初始化的NPC装进NPC容器
		m_vecNPC.push_back(pNpc);
	}

}

cNPC* cNPCRuler::render(const int& r, const int& c, const int& i)
{
	//将容器内每个元素依次赋值给 pNPC  //遍历
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
//	//将容器内每个元素依次赋值给 pNPC  //遍历
//	for (cNPCData* pNPC : m_vecNPC)
//	{
//		if (pNPC->iID == r)
//		{
//			return pNPC;
//		}
//	}
//	return nullptr;
//}
