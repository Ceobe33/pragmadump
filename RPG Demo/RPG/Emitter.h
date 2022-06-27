#pragma once
class cEmitter
{
public:
	cEmitter();
	~cEmitter();
	static cEmitter* getInstance();
	//注册消息
	void registerNews(string newsName, function<void(void*)> callBack);
	//发送消息
	void emitNews(string newsName, void* pData);
	void clear();
private:
	static cEmitter* m_pInstance;
	map<string, function<void(void*)>> m_mapMessage;
};

