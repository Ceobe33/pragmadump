#include "stdafx.h"
#include "Equipment.h"

cEquipment::cEquipment() 
	:arrowState(0)
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
			if (i == arrowState) {
				cGoodsData* pData = pSceneMain->getStore()->armament(m_vecEquipment[i]->iID);
				pSceneMain->getPlayer()->getBag()->addGoods(pData);//

				pSceneMain->getPlayer()->bonus("out", pData);

				if (m_vecEquipment[i]->iEquipmentCount > 0)
					m_vecEquipment[i]->iEquipmentCount--;
				if (m_vecEquipment[i]->iEquipmentCount == 0) {
					arrowState = 0;
					m_vecEquipment.erase(m_vecEquipment.begin() + i);
					system("cls");
				}
				break;
			}
		}
	} else if (KEY_DOWN(VK_DOWN))	{
		if (arrowState < equipmentContainerSize - 1)
			arrowState++;
	} else if (KEY_DOWN(VK_UP)) {
		if (arrowState > 0)
			arrowState--;
	}
}

void cEquipment::render() {
	GET_pSCENEMAIN;
	//���������ʾ
	pSceneMain->getPlayer()->propertyRender();
	//װ����ʾ
	cout << endl << endl << "		It is " << m_strName << "'s equipment."
		<< endl << "\tName\t\t" << "Atk\t" << "Count\t" << "Price\t" << "Details\t" << endl;

	for (int i = 0; i < int(m_vecEquipment.size()); i++) {
		if (i == arrowState)
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