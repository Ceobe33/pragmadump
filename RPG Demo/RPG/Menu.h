#pragma once
class cMenu:public cSceneBase
{
public:
	cMenu();
	void update();
	void render();
	//static cMenu* getInstance();
	CC_GET_SET_PRIVATE(int, State, m_iState);
private:
	//static cMenu* m_pInstanceMenu;
	//int m_iState;
};

