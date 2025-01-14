#pragma once
#ifndef RPG_RPG_STORE_H_
#define RPG_RPG_STORE_H_

//#include "SceneMain.h"
class cStore :public cSceneBase {
public:
    cStore();
    ~cStore();
    //static void getInstance();
    void update();
    void render();
    void initialize();
    void initItems(const int& i);
    cGoodsData* armament(const int& i);

    vector<cGoodsData*> getVectorGoods(const int& i);
    //vector<cGoodsData*> getVectorItems(const int &i);

    /*GET_PRIVATE(vector<cGoodsData*>, VecGoods, m_vecGoods);
    GET_PRIVATE(vector<cGoodsData*>, VecItems, m_vecItems);*/
private:
    //static cStore* m_pInstance;
    int arrowState;
    cPlayer* m_pPlayer;
    vector<cGoodsData*> m_vecGoods;
    vector<cGoodsData*> m_vecItems;
};

#endif // !RPG_RPG_STORE_H_