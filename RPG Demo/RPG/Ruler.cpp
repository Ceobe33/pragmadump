#include "stdafx.h"
#include "Ruler.h"
//初始化单例
cRuler* cRuler::m_pInstanceRuler = nullptr;
cRuler::cRuler()
{
	m_pSceneMain = new cSceneMain();
	//m_pRoleSelect = new cRoleSelect();
	//m_pNPC = new cNPC();
	//m_pMap = new cMap();
	//m_pLoading = new cLoading();
	m_iState = 0;
}


void cRuler::update()
{

	if (KEY_DOWN(VK_ESCAPE))
	{
		system("cls");
		cRuler();
		m_iState = 0;
	}
	switch (m_iState)
	{
	case 0:
		m_pSceneMain->getRoleSelect()->update();
		break;
	case 1:
		m_pSceneMain->update();
		break;
	}
}
void cRuler::render()
{
	switch (m_iState)
	{
	case 0:
		m_pSceneMain->getRoleSelect()->render();
		break;
	case 1:
		m_pSceneMain->render();
		break;
	}

}

void cRuler::solveFrameProblem()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition = { 0, 0 };
	SetConsoleCursorPosition(hOut, cursorPosition);

	//==隐藏光标==
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	//输出
	SetConsoleCursorInfo(hOut, &cursorInfo);
}

cRuler* cRuler::getInstance()
{
	if (!m_pInstanceRuler)
	{
		m_pInstanceRuler = new cRuler;
	}
	return m_pInstanceRuler;
}
