#include "stdafx.h"
#include "PetStore.h"

cPetStore::cPetStore() {
	m_strName = "Pet";
	m_iState = 0;
	storage();
	//initialize();
}

//cPetStore::cPetStore()
//{
//	m_strName = "Store";
//	m_iState = 0;
//	m_pPlayer = new cPlayer();
//	//初始化商品数据
//}

cPetStore::~cPetStore() {
}

void cPetStore::update() {
	//GET_pCURENTSCENE;
	GET_pSCENEMAIN;
	if (KEY_DOWN(VK_DOWN)) {
		m_iState++;
	}
	else if (KEY_DOWN(VK_UP)) {
		m_iState--;
	}
	else if (KEY_DOWN(VK_ESCAPE)) {
		cDirector::getInstance()->popScene();
	}
	else if (KEY_DOWN(VK_RETURN)) {
		pSceneMain->getPlayer()->havePet = true;
		cPetStore* pData = m_vecPets[m_iState];
		//cEmitter::getInstance()->emitNews("buyGoods", pData);
		//pSceneMain->getPlayer()->buyGoods(pData);
		m_vecPets.clear();
	}
	if (m_iState < 0)
		m_iState = 0;
	else if (m_iState >= m_vecPets.size())
		m_iState = m_vecPets.size() - 1;
}

void cPetStore::render() {
	//GET_pCURENTSCENE;
	GET_pSCENEMAIN;
	//玩家属性渲染
	pSceneMain->getPlayer()->propertyRender();
	//商店物品渲染
	cNPC* pNPC = pSceneMain->getNPCRuler()->getNPCByID(pSceneMain->getSurroundPlayer());
	cout << endl << endl << "\t\t" << "欢迎来到" << pNPC->getName() << "的" << pNPC->getOccupation() << endl;
	cout << "\tName\t\t" << "Img\t" << "Gain\t" << endl;
	for (int i = 0; i < m_vecPets.size(); i++) {
		cPetStore* pData = m_vecPets[i];

		if (m_iState == i)
			cout << "-->";
		else
			cout << "   ";
		cout << "\t"
			<< left << setw(8) << pData->strName << "\t"
			<< pData->iImg << "\t"
			<< pData->iGain << "\t"
			<< endl;
	}
	//玩家背包渲染
	//cout << endl << endl << "		It is " << pSceneMain->getPlayer()->getName() << "'s bag."
	//	<< endl << "\tName\t\t" << "Atk\t" << "Count\t" << "Price\t" << "Details\t" << endl;
	//for (int i = 0; i < pSceneMain->getPlayer()->getBag()->getVecBag().size(); i++)
	//{

	//	cout << "\t";
	//	cGoodsData* pData = pSceneMain->getPlayer()->getBag()->getVecBag()[i];
	//	cout
	//		<< left << setw(8) << pData->strName << "\t"
	//		<< pData->iAtk << "\t"
	//		<< pData->iBagCount << "\t"
	//		<< pData->iPrice << "\t"
	//		<< pData->strDetail << "\t" << endl;
	//}
}

//初始化
void cPetStore::storage() {
	vector<cDataBase*> vec = cDataRuler::getInstance()->getDataRuler("PetsDataRuler")->getVecData();
	for (cDataBase* pData : vec) {
		cPetStore* p = new cPetStore();
		cPetData* tempGoods = static_cast<cPetData*>(pData);
		p->init(tempGoods);
		m_vecPets.push_back(p);
	}
}

void cPetStore::init(cPetData* pData) {
	iID = pData->iID,
		iRow = pData->iRow,
		iCol = pData->iCol,
		iGain = pData->iGain,
		strName = pData->strName,
		iImg = pData->iImg;
}

//vector<cPetData*> cPetStore::getVectorPets(const int& i)
//{
//	for (cPetData* pData : m_vecPets)
//	{
//		if (pData->iID == i)
//		{
//			m_vecItems.push_back(pData);
//		}
//	}
//	return m_vecItems;
//}

//void cPetStore::initItems(const int& i)
//{
//	for (cGoodsData* pData : m_vecGoods)
//	{
//		if (pData->iNPCID == i)
//		{
//			m_vecItems.push_back(pData);
//		}
//	}
//}
//
//cPetData* cPetStore::armament(const int& i)
//{
//	for (cGoodsData* vec : m_vecGoods)
//	{
//		if (vec->iID == i)
//		{
//			return vec;
//		}
//	}
//}