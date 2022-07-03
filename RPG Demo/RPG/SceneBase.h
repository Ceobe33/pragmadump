#ifndef RPG_RPG_SCENEBASE_H_
#define RPG_RPG_SCENEBASE_H_

#include "Node.h"

//场景基类
class cSceneBase :public cNode {
public:
	cSceneBase();
	~cSceneBase();
	//纯虚函数，子类必须重定义，否则子类会继承纯虚函数从而变成抽象类
	//抽象类不可以实例化
	virtual void update() = 0;
	virtual void render() = 0;
	string getSceneName(){ return m_strName; }

protected:
	string m_strName;
};

#endif // !RPG_RPG_SCENEBASE_H_