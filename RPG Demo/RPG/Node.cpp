#include "stdafx.h"
#include "Node.h"

cNode* cNode::m_pNodeInstance = nullptr;
cNode::cNode()
{
}


cNode::~cNode()
{
}

void cNode::update()
{

}

void cNode::render()
{

}

void cNode::addChild(cNode* pNode)
{
	//��ȫ���
	if (!pNode)
	{
		for (cNode* pChild : m_vecChildren)
		{
			//����������иú��ӽڵ�ͽ�������
			if (pChild == pNode)
				return;
		}
		//this ����ǰ�ڵ�
		pNode->m_pParent = this;
		//�� pNode ��������
		m_vecChildren.push_back(pNode);
	}
}

cNode* cNode::getChildByName(string name)
{
	for (cNode* pChild : m_vecChildren)
	{
		if (pChild->nodeName == name)
		{
			return pChild;
		}
	}
	return nullptr;
}

vector<cNode*> cNode::getChildren()
{
	if (!m_vecChildren.empty())
	{
		return m_vecChildren;
	}
}

cNode* cNode::getParent()
{
	return m_pParent;
}

cNode* cNode::getInstance()
{
	if (!m_pNodeInstance)
	{
		m_pNodeInstance = new cNode();
	}
	return m_pNodeInstance;
}

void cNode::setShowNode(cNode* node)
{
	m_pShowNode = node;
}
