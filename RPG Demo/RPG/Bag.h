#pragma once
#ifndef RGP_RPG_BAG_H_
#define RGP_RPG_BAG_H_

//#include "SceneMain.h"
class cBag : public cSceneBase {
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
    int bagArrowState;
    vector<cGoodsData*> m_vecBag;
};

#endif // !RGP_RPG_BAG_H_