#pragma once

//#include "SceneMain.h"
class cBag:public cSceneBase
{
public:
	cBag();
	void update();
	void render();

	//vector<cGoodsData*> getVectorBag();
	void addGoods(cGoodsData* name);
	//void unload(cGoodsData* pData);
	vector<cGoodsData*> getVecBag();
	cGoodsData* takeGoods(string name);
	void deleteGoods(string name);

private:
	int m_iState;
	vector<cGoodsData*> m_vecBag;
};