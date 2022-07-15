#pragma once
#ifndef RPG_RPG_FIRE_H_
#define RPG_RPG_FIRE_H_

//#include "Scene.h"

class cFire {
public:
	cFire();
	~cFire();
	void update();
	void render();
	void setPosition(const int& r, const int& c, const int& direction, const int& tag);
	//interface
	int fireTag{};
	int fireDistance{};
private:
	//int fireTag;
	int m_iDirection;
	int m_iRow, m_iCol;
	int m_iBackupRow, m_iBackupCol;
	//vector<cFire*> m_vecFire;
};

class cFireRuler {//:public cScene
public:
	cFireRuler();
	~cFireRuler();
	void update();
	void load(const int& i, const int& j, const int& dir, const int& tag);

	cFire* fireIns;
private:
	vector<cFire*> m_vecFire;
	//cFire* fireIns;
};

#endif // !RPG_RPG_FIRE_H_