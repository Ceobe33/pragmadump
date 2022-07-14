#pragma once
#ifndef RPG_RPG_DATABASE_H_
#define RPG_RPG_DATABASE_H_

// 数据基类
class cDataBase {
public:
	int iID;

private:
};

// 数据管理者基类
class cDataBaseRuler {
public:
	~cDataBaseRuler();

	virtual void load();
	static cDataBaseRuler* getInstance();
	cDataBase* getDataByID(const int& m_iID);
	vector<cDataBase*> getVecData();
	//GET_PRIVATE(vector<cDataBase*>, VecData, m_vecDataBase);
private:
protected:
	cDataBaseRuler();
	static cDataBaseRuler* m_pInstanceDataBaseRuler;
	vector<cDataBase*> m_vecDataBase;
};

#endif // !RPG_RPG_DATABASE_H_