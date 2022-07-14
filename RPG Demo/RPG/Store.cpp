#include "stdafx.h"
#include "Store.h"
#include "NPC.h"
#include "SceneMain.h"

//cStore* cStore::m_pInstance = nullptr;
cStore::cStore() {
	m_strName = "Store";
	m_iState = 0;
	m_pPlayer = new cPlayer();
	//初始化商品数据
	initialize();
}

cStore::~cStore() {
}

//void cStore::getInstance()
//{
//	if (!m_pInstance)
//	{
//		m_pInstance = new cStore();
//	}
//	m_pInstance = nullptr;
//}

void cStore::update() {
	//GET_pCURENTSCENE;
	GET_pSCENEMAIN;
	if (KEY_DOWN(VK_DOWN)) {
		m_iState++;
	} else if (KEY_DOWN(VK_UP))	{
		m_iState--;
	} else if (KEY_DOWN(VK_ESCAPE))	{
		cDirector::getInstance()->popScene();
	} else if (KEY_DOWN(VK_RETURN))	{
		cGoodsData* pData = m_vecItems[m_iState];
		if (pData->iAmount != 0) {
			cEmitter::getInstance()->emitNews("buyGoods",pData);
			//pSceneMain->getPlayer()->buyGoods(pData);
		}
		//sellGoods();
	}
	int itemVecSize = int(m_vecItems.size());
	if (m_iState < 0) {
		m_iState = 0;
	} else if (m_iState >= itemVecSize) {
		m_iState = itemVecSize - 1;
	}
}

void cStore::render() {
	//GET_pCURENTSCENE;
	GET_pSCENEMAIN;
	//玩家属性渲染
	pSceneMain->getPlayer()->propertyRender();
	//商店物品渲染
	cNPC* pNPC = pSceneMain->getNPCRuler()->getNPCByID(pSceneMain->getSurroundPlayer());
	cout << endl << endl <<"\t\t"<< "欢迎来到" << pNPC->getName()<< "的" <<pNPC->getOccupation()<<endl;
		cout << "\tName\t\t" << "Atk\t" << "Heal\t" << "Amount\t" << "Price\t" << "details"<< endl;
	for (int i = 0; i < int(m_vecItems.size()); i++)	{
		cGoodsData* pData = m_vecItems[i];

		if (m_iState == i)
			cout << "-->";
		else
			cout << "   ";
		cout << "\t"
			<<left<<setw(8)<< pData->strName << "\t"
			<< pData->iAtk << "\t"
			<< pData->iHeal << "\t"
			<< pData->iAmount << "\t"
			<< pData->iPrice << "\t"
			<< pData->strDetail << "\t"
			<< endl;

	}
	//玩家背包渲染
	cout << endl << endl << "		It is " << pSceneMain->getPlayer()->getName() << "'s bag."
		<< endl << "\tName\t\t" << "Atk\t" << "Count\t" << "Price\t" << "Details\t" << endl;

	auto bagVector = pSceneMain->getPlayer()->getBag()->getVecBag();
	for (int i = 0; i < int(bagVector.size()); i++)	{
		cout << "\t";
		cGoodsData* pData = bagVector[i];
		cout
			<< left << setw(8) << pData->strName << "\t"
			<< pData->iAtk << "\t"
			<< pData->iBagCount << "\t"
			<< pData->iPrice << "\t"
			<< pData->strDetail << "\t" << endl;
	}
}

//初始化
void cStore::initialize() {
	vector<cDataBase*> vec = cDataRuler::getInstance()->getDataRuler("GoodsDataRuler")->getVecData();
	for (cDataBase* pData : vec) {
		cGoodsData* tempGoods = static_cast<cGoodsData*>(pData);
		m_vecGoods.push_back(tempGoods);
	}
}

vector<cGoodsData*> cStore::getVectorGoods(const int& i) {
	for (cGoodsData* pData : m_vecGoods) {
		if (pData->iNPCID == i) {
			m_vecItems.push_back(pData);
		}
	}
	return m_vecItems;
}

void cStore::initItems(const int& i) {
	for (cGoodsData* pData : m_vecGoods) {
		if (pData->iNPCID == i) {
			m_vecItems.push_back(pData);
		}
	}
}

cGoodsData* cStore::armament(const int& i) {
	for (cGoodsData* data : m_vecGoods) {
		if (data->iID == i) {
			return data;
		}
	}
	return nullptr;
}

//void cStore::sellGoods()
//{
//	for (cGoodsData* pData : m_vecGoods)
//	{
//		if (pData->iID == m_iState+300)
//		{
//			if (0 >= pData->iAmount)
//				return;
//			pData->iAmount--;
//			m_pPlayer->buyGoods(pData);
//		}
//	}
//}
