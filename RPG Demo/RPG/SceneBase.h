#ifndef RPG_RPG_SCENEBASE_H_
#define RPG_RPG_SCENEBASE_H_

#include "Node.h"

//��������
class cSceneBase :public cNode {
public:
	cSceneBase();
	~cSceneBase();
	//���麯������������ض��壬���������̳д��麯���Ӷ���ɳ�����
	//�����಻����ʵ����
	virtual void update() = 0;
	virtual void render() = 0;
	string getSceneName(){ return m_strName; }

protected:
	string m_strName;
};

#endif // !RPG_RPG_SCENEBASE_H_