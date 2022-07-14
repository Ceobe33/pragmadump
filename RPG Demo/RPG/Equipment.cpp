#include "stdafx.h"
#include "Equipment.h"

cEquipment::cEquipment() 
	:m_iState(0)
{
	m_strName = "Equipment";
}

void cEquipment::update() {
	int equipmentContainerSize(m_vecEquipment.size());
	//GET_pCURENTSCENE;
	GET_pSCENEMAIN;
	if (KEY_DOWN(VK_ESCAPE)) {
		cDirector::getInstance()->popScene();
		//cDirector::getInstance()->popScene();
	} else if (KEY_DOWN(VK_RETURN)) {
		for (int i = 0; i < equipmentContainerSize; i++) {
			if (i == m_iState) {
				cGoodsData* pData = pSceneMain->getStore()->armament(m_vecEquipment[i]->iID);
				pSceneMain->getPlayer()->getBag()->addGoods(pData);//

				pSceneMain->getPlayer()->bonus("out", pData);

				if (m_vecEquipment[i]->iEquipmentCount > 0)
					m_vecEquipment[i]->iEquipmentCount--;
				if (m_vecEquipment[i]->iEquipmentCount == 0) {
					m_iState = 0;
					m_vecEquipment.erase(m_vecEquipment.begin() + i);
					system("cls");
				}
				break;
			}
		}
	} else if (KEY_DOWN(VK_DOWN))	{
		if (m_iState < equipmentContainerSize - 1)
			m_iState++;
	} else if (KEY_DOWN(VK_UP)) {
		if (m_iState > 0)
			m_iState--;
	}
}

void cEquipment::render() {
	GET_pSCENEMAIN;
	//玩家属性显示
	pSceneMain->getPlayer()->propertyRender();
	//装备显示
	cout << endl << endl << "		It is " << m_strName << "'s equipment."
		<< endl << "\tName\t\t" << "Atk\t" << "Count\t" << "Price\t" << "Details\t" << endl;

	for (int i = 0; i < int(m_vecEquipment.size()); i++) {
		if (i == m_iState)
			cout << "-->\t";
		else
			cout << "   \t";
		cGoodsData* pData = m_vecEquipment[i];
		cout
			<< left << setw(8) << pData->strName << "\t"
			<< pData->iAtk << "\t"
			<< pData->iEquipmentCount << "\t"
			<< pData->iPrice << "\t"
			<< pData->strDetail << "\t" << endl;
	}
}

vector<cGoodsData*> cEquipment::getVecEquipment() {
	return m_vecEquipment;
}

void cEquipment::addEquipment(cGoodsData* pData) {
	m_vecEquipment.push_back(pData);
}