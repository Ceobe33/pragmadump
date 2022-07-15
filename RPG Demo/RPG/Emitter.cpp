#include "stdafx.h"
#include "Emitter.h"

cEmitter* cEmitter::m_pInstance = nullptr;
cEmitter::cEmitter() {
}

cEmitter::~cEmitter() {
}

// ����
cEmitter* cEmitter::getInstance() {
	if (!m_pInstance) {
		m_pInstance = new cEmitter();
	}
	return m_pInstance;
}

// ע����Ϣ
void cEmitter::registerNews(string newsName, function<void(void*)> callBack) {
	m_mapMessage.insert(pair<string, function<void(void*)>>(newsName, callBack));
}

// ������Ϣ
void cEmitter::emitNews(string newsName, void* pData) {
	if (!newsName.empty() || pData != nullptr) {
		//ʹ�õ���������map����
		for (auto iter = m_mapMessage.begin(); iter != m_mapMessage.end(); iter++) {
			if (iter->first == newsName) {
				iter->second(pData);
			}
		}
	}
}

// �����Ϣ
void cEmitter::clear() {
	m_mapMessage.clear();
}
