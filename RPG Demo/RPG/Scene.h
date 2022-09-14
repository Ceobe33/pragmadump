#pragma once
#include "Node.h"

class cScene :public cNode {
public:
    cScene();
    ~cScene();
    virtual void update();
    virtual void render();
    //显示节点
    void showNode(cNode* pNode);
    void showNode(string name);
    //除了记录普通场景添加孩子节点的功能
    //还要实现当前节点添加孩子节点
    //所以要重写添加孩子节点的接口
    void addChild(cNode* pNode);

private:
    cNode* m_pShowNode;

};

