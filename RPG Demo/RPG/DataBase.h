#pragma once

class cDataBase //���ݻ���
{
public:
	int iID;

private:
};


class cDataBaseRuler //���ݹ����߻���
{
public:
	~cDataBaseRuler();

	virtual void load();
	static cDataBaseRuler* getInstance();
	cDataBase* getDataByID(const int& m_iID);
	vector<cDataBase*> getVecData();
	//CC_GET_PRIVATE(vector<cDataBase*>, VecData, m_vecDataBase);
private:
protected:
	cDataBaseRuler();
	static cDataBaseRuler* m_pInstanceDataBaseRuler;
	vector<cDataBase*> m_vecDataBase;
};
