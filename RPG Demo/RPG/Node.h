#ifndef RPG_RPG_NODE_H_
#define RPG_RPG_NODE_H_

class cNode
{
public:
    ~cNode();
    // 添加孩子节点
    virtual void update();
    virtual void render();
    virtual void addChild(cNode* pNode);
    // 通过名称获取相应孩子节点
    virtual cNode* getChildByName(string name);
    // 获取全部孩子节点
    virtual vector<cNode*> getChildren();
    // 获取父节点
    virtual cNode* getParent();
    // 设置当前展示的节点
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