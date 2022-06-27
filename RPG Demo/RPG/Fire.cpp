#include "stdafx.h"
#include "Fire.h"


cFire::cFire()
{
	m_iTag = eNone;
	m_iDirection = eNone;
	m_iDistance = 0;
}


cFire::~cFire()
{
}

void cFire::update()
{
	
	switch (m_iDirection)
	{
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
	m_iDistance = 3 <= abs(m_iBackupRow - m_iRow) || 3 <= abs(m_iBackupCol - m_iCol);
	//if (m_iDistance)
	//{

	//}
}

void cFire::render()
{
	switch (m_iTag)
	{
	case ePlayer:
		cout << "µ¶";
		break;
	case eEnemy:

		break;
	}
}

void cFire::setPosition(const int &r, const int &c, const int &direction, const int &tag)
{
	m_iRow = r, m_iCol = c, m_iDirection = direction, m_iTag = tag;
	m_iBackupRow = r, m_iBackupCol = c;
}


cFireRuler::cFireRuler()
{
	m_pFire = new cFire();
}

cFireRuler::~cFireRuler()
{
}

void cFireRuler::load(const int & i, const int &j, const int &dir,const int &tag)
{
	m_pFire->setPosition(i, j,dir,tag);
	m_vecFire.push_back(m_pFire);
}

void cFireRuler::update()
{
	for (int i = 0; i < m_vecFire.size(); i++)
	{
		if (m_pFire->getDistance())
		{
			m_vecFire.erase(m_vecFire.begin() + i);
		}
	}
}
