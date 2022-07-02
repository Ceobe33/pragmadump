#include "stdafx.h"
#include "NodeRoleSelect.h"

cNodeRoleSelect::cNodeRoleSelect()
{
	//m_strName = "RoleSelect";
	nodeName = "NodeRoleSelect";
	vector<cDataBase*> vecData = cDataRuler::getInstance()->getDataRuler("RoleSelectDataRuler")->getVecData();
	for (cDataBase* pBase : vecData)
	{
		//cRoleSelect* pRole = new cRoleSelect();
		cRoleSelectData* pData = static_cast<cRoleSelectData*>(pBase);
		//pRole->initialize(pData);
		m_vecPlayer.push_back(pData);
	}
}


cNodeRoleSelect::~cNodeRoleSelect()
{
}

void cNodeRoleSelect::update()
{
	if (KEY_DOWN(VK_DOWN))
		m_iState++;
	else if (KEY_DOWN(VK_UP))
		m_iState--;

	if (m_iState < 0)
		m_iState = 0;
	else if (m_vecPlayer.size() - 1 < m_iState)
		m_iState = m_vecPlayer.size() - 1;

	else if (KEY_DOWN(VK_RETURN))
	{
		//cDirector::getInstance()->pushScene(this);
		//cDirector::getInstance()->replaceScene(new cSceneMain());//setState(1);
	}
	else if (KEY_DOWN(VK_ESCAPE))
	{
		cDirector::getInstance()->popScene();
	}
}

void cNodeRoleSelect::render()
{
	cout << "\tName\t" << "Role\t\t" << "Atk\t" << "Def\t" << "Growth\t" << "Img\t" << endl;
	for (int i = 0; i < m_vecPlayer.size(); i++)
	{
		if (i == m_iState)
		{
			cout << "->";
		}
		else
		{
			cout << "  ";
		}
		cRoleSelectData* role = m_vecPlayer[i];
		cout
			<< "\t"
			<< role->m_strName << "\t"
			<< role->m_strRole << "\t\t"
			<< role->m_iAtk << "\t"
			<< role->m_iDef << "\t"
			<< role->m_strGrowth << "\t"
			<< role->m_strImg << endl;
	}
}
