#pragma once

class cEquipment:public cSceneBase
{
public:
	cEquipment();
	void update();
	void render();

	//interface
	//GET_PRIVATE(cGoodsData*,VecEquipment , m_vecEquipment);

	vector<cGoodsData*> getVecEquipment();
	void addEquipment(cGoodsData* pData);

private:
	vector<cGoodsData*> m_vecEquipment;
	int m_iState;
};

