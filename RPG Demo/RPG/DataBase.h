#pragma once

class cDataBase //数据基类
{
public:
	int iID;

private:
};


class cDataBaseRuler //数据管理者基类
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
