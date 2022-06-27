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
	void pushScene(cSceneBase* pScene);//将场景存入容器
	void popScene();//返回上一场景
	void runGame();
	//void loading();
	void solveFrameProblem();

	cSceneBase* getScene();//获取当前运行场景
	cSceneBase* getScene(string scene);//获取指定名称的场景


private:
	cDirector();
	static cDirector* m_pInstance;
	vector<cSceneBase*> m_pVecScene;
	cSceneBase* m_pRunningScene;//记录正在播放的场景
};

