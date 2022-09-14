#pragma once
#include "Node.h"

class cScene :public cNode {
public:
    cScene();
    ~cScene();
    virtual void update();
    virtual void render();
    //��ʾ�ڵ�
    void showNode(cNode* pNode);
    void showNode(string name);
    //���˼�¼��ͨ������Ӻ��ӽڵ�Ĺ���
    //��Ҫʵ�ֵ�ǰ�ڵ���Ӻ��ӽڵ�
    //����Ҫ��д��Ӻ��ӽڵ�Ľӿ�
    void addChild(cNode* pNode);

private:
    cNode* m_pShowNode;

};

