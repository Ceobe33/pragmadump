#include "stdafx.h"
#include "Node.h"

cNode* cNode::m_pNodeInstance = nullptr;
RenderWindow cNode::window(VideoMode(1080, 720), "Arknights");
cNode::cNode() {
}

cNode::~cNode() {
}

void cNode::update() {

}

void cNode::render() {

}

void cNode::addChild(cNode* pNode) {
    //��ȫ���
    if (pNode != nullptr) {
        for (cNode* pChild : m_vecChildren) {
            //����������иú��ӽڵ�ͽ�������
            if (pChild == pNode)
                return;
        }
        //this ����ǰ�ڵ�
        pNode->m_pParent = this;
        //�� pNode ��������
        m_vecChildren.push_back(pNode);
    }
    else {
        debug.log("could not add child, because it's null");
    }
}

cNode* cNode::getChildByName(string name) {
    for (cNode* pChild : m_vecChildren)    {
        if (pChild->nodeName == name) {
            return pChild;
        }
    }
    return nullptr;
}

vector<cNode*> cNode::getChildren() {
    if (!m_vecChildren.empty())    {
        return m_vecChildren;
    }
    return {};
}

cNode* cNode::getParent() {
    return m_pParent;
}

cNode* cNode::getInstance() {
    if (!m_pNodeInstance) {
        m_pNodeInstance = new cNode();
    }
    return m_pNodeInstance;
}

void cNode::setShowNode(cNode* node) {
    m_pShowNode = node;
}
