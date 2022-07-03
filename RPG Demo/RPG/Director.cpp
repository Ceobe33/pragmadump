#include "stdafx.h"
#include "Director.h"
#include "RoleSelect.h"

cDirector* cDirector::m_pInstance = nullptr;
cDirector::cDirector() {
	m_pRunningScene = nullptr;
}

cDirector::~cDirector() {
}

cDirector* cDirector::getInstance() {
	if (!m_pInstance) {
		m_pInstance = new cDirector();
	}
	return m_pInstance;
}

void cDirector::update() {
	m_pRunningScene->update();
}

void cDirector::render() {
	m_pRunningScene->render();
}

//游戏运行
void cDirector::runGame() {
	//m_pRunningScene = new cRoleSelect();
	while (true) {
		//clear();
		//system("cls");
		solveFrameProblem();
		update();
		render();

		cout << endl<<endl ;
		//system("clear");
		//system("clear");
	}
}

//存储场景准备切换下一场景
void cDirector::pushScene(cSceneBase* pScene) {
	//将当前场景存到容器，准备切换下个场景
	m_pVecScene.push_back(m_pRunningScene);
	//切换为传进来的场景
	m_pRunningScene = pScene;
	system("cls");

	//loading();
}

// 播放上一个场景
void cDirector::popScene() {
	if (!m_pVecScene.empty()) {
		//如果容器不为空就播放上一个场景
		m_pRunningScene = m_pVecScene.back();
		//将存在容器的上一个场景弹出
		m_pVecScene.pop_back();
		system("cls");
	}
}

// 得到当前场景
cSceneBase* cDirector::getScene() {
	return m_pRunningScene;
}

// 得到相应名称的场景
cSceneBase* cDirector::getScene(string scene) {
	for (cSceneBase* pScene : m_pVecScene) {
		if (pScene->getSceneName() == scene) {
			return pScene;
		}
	}
	return nullptr;
}

// 初始化场景
void cDirector::replaceScene(cSceneBase* pScene) {
	if (!m_pRunningScene) {
		//如果当前场景不为空就删除指针指向的内存
		delete m_pRunningScene;
		//并置空指针
		m_pRunningScene = nullptr;
	}
	m_pRunningScene = pScene;
}

// 解决画面闪烁问题
void cDirector::solveFrameProblem() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition = { 0, 0 };
	SetConsoleCursorPosition(hOut, cursorPosition);
	
	// ==隐藏光标==
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	// 输出
	SetConsoleCursorInfo(hOut, &cursorInfo);


	//HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	//GetConsoleScreenBufferInfo(hndl, &csbi);
	//DWORD written;
	//DWORD N = csbi.dwSize.X * csbi.dwCursorPosition.Y +
	//	csbi.dwCursorPosition.X + 1;
	//COORD curhome = { 0,0 };

	//FillConsoleOutputCharacter(hndl, ' ', N, curhome, &written);
	//csbi.srWindow.Bottom -= csbi.srWindow.Top;
	//csbi.srWindow.Top = 0;
	//SetConsoleWindowInfo(hndl, TRUE, &csbi.srWindow);
	//SetConsoleCursorPosition(hndl, curhome);
}
