#ifndef RPG_RPG_DIRECTOR_H_
#define RPG_RPG_DIRECTOR_H_

#include "SceneBase.h"

class cDirector
{
public:
	~cDirector();

	void update();
	void render();
	static cDirector* getInstance();
	void replaceScene(cSceneBase* pScene);
	// 将场景存入容器
	void pushScene(cSceneBase* pScene);
	// 返回上一场景
	void popScene();
	void runGame();
	//void loading();
	void solveFrameProblem();
	// 获取当前运行场景
	cSceneBase* getScene();
	// 获取指定名称的场景
	cSceneBase* getScene(string scene);


private:
	cDirector();
	static cDirector* m_pInstance;
	vector<cSceneBase*> m_pVecScene;
	// 记录正在播放的场景
	cSceneBase* m_pRunningScene;
};

#endif // !RPG_RPG_DIRECTOR_H_