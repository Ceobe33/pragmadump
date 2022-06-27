#pragma once
#include "DataStruct.h"
#include "DataBase.h"

class cDataRuler
{
public:

	void addDataRuler(string dataRulerName, cDataBaseRuler* dataRuler);
	cDataBaseRuler* getDataRuler(string dataRulerName);

	//CC_GET_PRIVATE(map<string, cDataBaseRuler*>, MapDataRuler, m_mapDataRuler);
	//map<string, cDataBaseRuler*> getMapDataRuler();
	//����ģʽ
	static cDataRuler* getInstance();
private:
	cDataRuler();//���캯���ŵ�˽�г�Ա�� ���Է�ֹ�����������ֻ��Ҫ������
	map<string, cDataBaseRuler*> m_mapDataRuler;
	static cDataRuler* m_pInstance;
};

