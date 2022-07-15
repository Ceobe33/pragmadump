#include "stdafx.h"
#include "Fire.h"


cFire::cFire() {
	fireTag = eNone;
	m_iDirection = eNone;
	fireDistance = 0;
}


cFire::~cFire() {
}

void cFire::update() {
	switch (m_iDirection) {
	case eUp:
 		m_iRow--;
		break;
	case eDown:
		m_iRow++;
		break;
	case eLeft:
		m_iCol--;
		break;
	case eRight:
		m_iCol++;
		break;
	}
	//for(cFire* pData:m_)
	fireDistance = 3 <= abs(m_iBackupRow - m_iRow) || 3 <= abs(m_iBackupCol - m_iCol);
	//if (fireDistance)
	//{

	//}
}

void cFire::render() {
	switch (fireTag)	{
	case ePlayer:
		cout << "µ¶";
		break;
	case eEnemy:
		cout << "  ";
	default:
		cout << "  ";
		break;
	}
}

void cFire::setPosition(const int &r, const int &c, const int &direction, const int &tag) {
	m_iRow = r, m_iCol = c, m_iDirection = direction, fireTag = tag;
	m_iBackupRow = r, m_iBackupCol = c;
}


cFireRuler::cFireRuler() {
	fireIns = new cFire();
}

cFireRuler::~cFireRuler() {
}

void cFireRuler::load(const int & i, const int &j, const int &dir,const int &tag) {
	fireIns->setPosition(i, j,dir,tag);
	m_vecFire.push_back(fireIns);
}

void cFireRuler::update() {
	for (int i = 0; i < int(m_vecFire.size()); i++) {
		if (fireIns->fireDistance) {
			m_vecFire.erase(m_vecFire.begin() + i);
		}
	}
}
