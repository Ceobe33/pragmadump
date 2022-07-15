#pragma once
#ifndef RPG_RPG_PETSTORE_H_
#define RPG_RPG_PETSTORE_H_

#include "SceneBase.h"
//#include "SceneMain.h"

class cPetStore :public cSceneBase {
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

	/*GET_PRIVATE(vector<cGoodsData*>, VecGoods, m_vecGoods);
	GET_PRIVATE(vector<cGoodsData*>, VecItems, m_vecItems);*/
	int iID, iRow, iCol, iGain;
	string	strName, strImg;
private:
	//static cStore* m_pInstance;
	int arrowState;
	vector<cPetData*> m_vecPets;
};

#endif // !RPG_RPG_PETSTORE_H_