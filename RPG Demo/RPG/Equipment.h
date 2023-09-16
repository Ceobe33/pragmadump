#pragma once
#ifndef RPG_RPG_EQUIPMENT_H_
#define RPG_RPG_EQUIPMENT_H_

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
    int arrowState;
};

#endif // !RPG_RPG_EQUIPMENT_H_