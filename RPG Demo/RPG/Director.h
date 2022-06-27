#pragma once
#include "SceneBase.h"

class cDirector
{
public:
	~cDirector();

	void update();
	void render();
	static cDirector* getInstance();
	void replaceScene(cSceneBase* pScene);
	void pushScene(cSceneBase* pScene);//��������������
	void popScene();//������һ����
	void runGame();
	//void loading();
	void solveFrameProblem();

	cSceneBase* getScene();//��ȡ��ǰ���г���
	cSceneBase* getScene(string scene);//��ȡָ�����Ƶĳ���


private:
	cDirector();
	static cDirector* m_pInstance;
	vector<cSceneBase*> m_pVecScene;
	cSceneBase* m_pRunningScene;//��¼���ڲ��ŵĳ���
};

