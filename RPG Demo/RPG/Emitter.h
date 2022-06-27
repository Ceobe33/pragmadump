#pragma once
class cEmitter
{
public:
	cEmitter();
	~cEmitter();
	static cEmitter* getInstance();
	//ע����Ϣ
	void registerNews(string newsName, function<void(void*)> callBack);
	//������Ϣ
	void emitNews(string newsName, void* pData);
	void clear();
private:
	static cEmitter* m_pInstance;
	map<string, function<void(void*)>> m_mapMessage;
};

