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
	// ��������������
	void pushScene(cSceneBase* pScene);
	// ������һ����
	void popScene();
	void runGame();
	//void loading();
	void solveFrameProblem();
	// ��ȡ��ǰ���г���
	cSceneBase* getScene();
	// ��ȡָ�����Ƶĳ���
	cSceneBase* getScene(string scene);


private:
	cDirector();
	static cDirector* m_pInstance;
	vector<cSceneBase*> m_pVecScene;
	// ��¼���ڲ��ŵĳ���
	cSceneBase* m_pRunningScene;
};

#endif // !RPG_RPG_DIRECTOR_H_