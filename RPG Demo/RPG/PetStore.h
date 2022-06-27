#pragma once
#include "SceneBase.h"
//#include "SceneMain.h"
class cPetStore:public cSceneBase
{
public:
	cPetStore();
	~cPetStore();
	void update();
	void render();
	void storage();
	void init(cPetData* pData);
	//void initPets(const int& i);
	//cGoodsData* armament(const int& i);

	//vector<cGoodsData*> getVectorPets(const int& i);
	//vector<cGoodsData*> getVectorItems(const int &i);

	/*CC_GET_PRIVATE(vector<cGoodsData*>, VecGoods, m_vecGoods);
	CC_GET_PRIVATE(vector<cGoodsData*>, VecItems, m_vecItems);*/
	int iID, iRow, iCol, iGain;
	string	strName, iImg;
private:
	//static cStore* m_pInstance;
	int m_iState;
	vector<cPetStore*> m_vecPets;
};
