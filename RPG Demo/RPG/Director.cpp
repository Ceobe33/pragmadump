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

//��Ϸ����
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

//�洢����׼���л���һ����
void cDirector::pushScene(cSceneBase* pScene) {
	//����ǰ�����浽������׼���л��¸�����
	m_pVecScene.push_back(m_pRunningScene);
	//�л�Ϊ�������ĳ���
	m_pRunningScene = pScene;
	system("cls");

	//loading();
}

// ������һ������
void cDirector::popScene() {
	if (!m_pVecScene.empty()) {
		//���������Ϊ�վͲ�����һ������
		m_pRunningScene = m_pVecScene.back();
		//��������������һ����������
		m_pVecScene.pop_back();
		system("cls");
	}
}

// �õ���ǰ����
cSceneBase* cDirector::getScene() {
	return m_pRunningScene;
}

// �õ���Ӧ���Ƶĳ���
cSceneBase* cDirector::getScene(string scene) {
	for (cSceneBase* pScene : m_pVecScene) {
		if (pScene->getSceneName() == scene) {
			return pScene;
		}
	}
	return nullptr;
}

// ��ʼ������
void cDirector::replaceScene(cSceneBase* pScene) {
	if (!m_pRunningScene) {
		//�����ǰ������Ϊ�վ�ɾ��ָ��ָ����ڴ�
		delete m_pRunningScene;
		//���ÿ�ָ��
		m_pRunningScene = nullptr;
	}
	m_pRunningScene = pScene;
}

// ���������˸����
void cDirector::solveFrameProblem() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition = { 0, 0 };
	SetConsoleCursorPosition(hOut, cursorPosition);
	
	// ==���ع��==
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	// ���
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
