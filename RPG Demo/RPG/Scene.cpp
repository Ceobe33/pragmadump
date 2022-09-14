#include "stdafx.h"
#include "Scene.h"

cScene::cScene() {
}

cScene::~cScene() {
}

void cScene::showNode(cNode* pNode) {
    if (pNode) {
        for (cNode* pChild : m_vecChildren) {
            if (pChild == pNode) {
                m_pShowNode = pChild;
            }
        }
    }
}

void cScene::showNode(string name) {
    for (cNode* pChild : m_vecChildren) {
        if (pChild->nodeName == name) {
            m_pShowNode = pChild;
        }
    }
}

void cScene::addChild(cNode* pNode) {
    //执行节点（父类）添加孩子节点的接口
    cNode::addChild(pNode);
    if (!m_pShowNode) {
        //如果当前显示节点为空 则将第一个孩子作为显示节点
        m_pShowNode = m_vecChildren[0];
    }
}

void cScene::update() {
    m_pShowNode->update();
}

void cScene::render() {
    m_pShowNode->render();
}