#include "stdafx.h"
#include "Emitter.h"

cEmitter* cEmitter::m_pInstance = nullptr;
cEmitter::cEmitter() {
}

cEmitter::~cEmitter() {
}

// 单例
cEmitter* cEmitter::getInstance() {
	if (!m_pInstance) {
		m_pInstance = new cEmitter();
	}
	return m_pInstance;
}

// 注册消息
void cEmitter::registerNews(string newsName, function<void(void*)> callBack) {
	m_mapMessage.insert(pair<string, function<void(void*)>>(newsName, callBack));
}

// 发送消息
void cEmitter::emitNews(string newsName, void* pData) {
	if (!newsName.empty() || pData != nullptr) {
		//使用迭代器遍历map容器
		for (auto iter = m_mapMessage.begin(); iter != m_mapMessage.end(); iter++) {
			if (iter->first == newsName) {
				iter->second(pData);
			}
		}
	}
}

// 清空消息
void cEmitter::clear() {
	m_mapMessage.clear();
}
