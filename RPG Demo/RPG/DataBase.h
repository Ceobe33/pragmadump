#pragma once
#ifndef RPG_RPG_DATABASE_H_
#define RPG_RPG_DATABASE_H_

// data base
struct DataBase {
    int iID;
};

// 数据管理者基类
class cDataBaseRuler {
public:
    ~cDataBaseRuler();

    virtual void load();
    static cDataBaseRuler* getInstance();
    DataBase* getDataByID(const int& m_iID);
    vector<DataBase*> getVecData();
    //GET_PRIVATE(vector<DataBase*>, VecData, m_vecDataBase);
private:
protected:
    cDataBaseRuler();
    static cDataBaseRuler* m_pInstanceDataBaseRuler;
    vector<DataBase*> m_vecDataBase;
};

#endif // !RPG_RPG_DATABASE_H_