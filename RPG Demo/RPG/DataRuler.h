#pragma once
#ifndef RPG_RPG_DATARULER_H_
#define RPG_RPG_DATARULER_H_

#include "DataStruct.h"
#include "DataBase.h"

class cDataRuler {
public:

    void addDataRuler(string dataRulerName, cDataBaseRuler* dataRuler);
    cDataBaseRuler* getDataRuler(string dataRulerName);

    //GET_PRIVATE(map<string, cDataBaseRuler*>, MapDataRuler, m_mapDataRuler);
    map<string, cDataBaseRuler*> getMapDataRuler();
    //����ģʽ
    static cDataRuler* getInstance();
private:
    cDataRuler();//���캯���ŵ�˽�г�Ա�� ���Է�ֹ�����������ֻ��Ҫ������
    map<string, cDataBaseRuler*> m_mapDataRuler;
    static cDataRuler* m_pInstance;
};

#endif // !RPG_RPG_DATARULER_H_