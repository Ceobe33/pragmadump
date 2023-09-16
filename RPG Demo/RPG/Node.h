#ifndef RPG_RPG_NODE_H_
#define RPG_RPG_NODE_H_

class cNode
{
public:
    ~cNode();
    // ��Ӻ��ӽڵ�
    virtual void update();
    virtual void render();
    virtual void addChild(cNode* pNode);
    // ͨ�����ƻ�ȡ��Ӧ���ӽڵ�
    virtual cNode* getChildByName(string name);
    // ��ȡȫ�����ӽڵ�
    virtual vector<cNode*> getChildren();
    // ��ȡ���ڵ�
    virtual cNode* getParent();
    // ���õ�ǰչʾ�Ľڵ�
    virtual void setShowNode(cNode* node);
    static cNode* getInstance();
    string nodeName;

protected:
    cNode();
    vector<cNode* > m_vecChildren;
    cNode* m_pParent;
    cNode* m_pShowNode;
    static cNode* m_pNodeInstance;
};

#endif // !RPG_RPG_NODE_H_