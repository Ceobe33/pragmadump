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
    //ִ�нڵ㣨���ࣩ��Ӻ��ӽڵ�Ľӿ�
    cNode::addChild(pNode);
    if (!m_pShowNode) {
        //�����ǰ��ʾ�ڵ�Ϊ�� �򽫵�һ��������Ϊ��ʾ�ڵ�
        m_pShowNode = m_vecChildren[0];
    }
}

void cScene::update() {
    m_pShowNode->update();
}

void cScene::render() {
    m_pShowNode->render();
}