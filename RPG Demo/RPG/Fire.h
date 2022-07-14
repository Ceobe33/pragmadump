#pragma once
//#include "Scene.h"

class cFire
{
public:
	cFire();
	~cFire();
	void update();
	void render();
	void setPosition(const int &r, const int &c, const int &direction, const int &tag);
	//interface
	GET_SET_PRIVATE(int, Tag, m_iTag);
	GET_SET_PRIVATE(int, Distance, m_iDistance);
private:
	//int m_iTag;
	int m_iDirection;
	int m_iRow, m_iCol;
	int m_iBackupRow, m_iBackupCol;
	//vector<cFire*> m_vecFire;
};

class cFireRuler //:public cScene
{
public:
	cFireRuler();
	~cFireRuler();
	void update();
	void load(const int & i, const int &j, const int &dir, const int &tag);

	GET_SET_PRIVATE(cFire*, Fire, m_pFire);
private:
	vector<cFire*> m_vecFire;
	//cFire* m_pFire;
};

