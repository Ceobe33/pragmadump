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
	//安全检查
	if (!pNode)
	{
		for (cNode* pChild : m_vecChildren)
		{
			//如果容器内有该孩子节点就结束函数
			if (pChild == pNode)
				return;
		}
		//this 代表当前节点
		pNode->m_pParent = this;
		//将 pNode 存入容器
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
