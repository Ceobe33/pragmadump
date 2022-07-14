#pragma once
//#include "SceneMain.h"
class cEnemy
{
public:
	cEnemy();
	void update();
	//void render(cEnemy* enemy);
	void initialize(cEnemyData* enemy);

	bool death;
	GET_PRIVATE(int, ID, m_iID);
	GET_SET_PRIVATE(int, Hp, m_iHp);
	GET_PRIVATE(int, Row, m_iRow);
	GET_PRIVATE(int, Col, m_iCol);
	GET_PRIVATE(int, Atk, m_iAtk);
	GET_PRIVATE(int, Def, m_iDef);
	GET_PRIVATE(int, EXPValue, m_iEXPValue);
	GET_PRIVATE(int, CurentMapID, m_iCurentMapID);
	GET_PRIVATE(string, Img, m_strImg);
	GET_PRIVATE(string, Name, m_strName);
private:
	/*int m_iID, m_iRow, m_iCol, m_iAtk, m_iDef, m_iHp, m_iCurentMapID, m_iEXPValue*/;
	/*string m_strName, m_strImg*/;
	//vector<cEnemyData*> m_vecEnemy;
};

class cEnemyRuler
{
public:
	cEnemyRuler();
	~cEnemyRuler();

	void render(cEnemy* enemy);

	cEnemy* getSingleEnemy(const int& enemyID);
	cEnemy* render(const int& r, const int& c, const int& i);
	void storage();
	//bool scan(const int& r, const int& c, const int& i);
	cEnemy* killed();
	//interface
	GET_PRIVATE(vector<cEnemy*>, VecEnemy, m_vecEnemy);
	//GET_PRIVATE(cEnemy*, Enemy, m_pEnemy);
private:

};
