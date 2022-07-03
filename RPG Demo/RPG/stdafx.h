// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#ifndef RPG_RPG_STDAFX_H_
#define RPG_RPG_STDAFX_H_

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
// ��ȡ�����ļ�ͷ�ļ�
#include <fstream>
#include <string>
#include <format>
#include <string_view>
// #include <fmt>
// setw�������������������Ⱥ���
#include <iomanip>
#include <time.h>
#include <vector>
// map����
#include <map>
// c++�� abs() ȡ����ֵ������ͷ�ļ�
#include <cmath>
// ��Ϣ���Ƶ�ͷ�ļ�
#include <functional>

using namespace std;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000?1:0) /*&& m_iMoveCache % */)
#define VK_B           0x42
#define VK_E           0x45

// ##��ճ�Ϸ�
#define CC_GET_SET_PRIVATE(dataType, functionName, valueName) \
	dataType get##functionName(){ return valueName; }\
	void set##functionName(dataType value){ valueName = value; } \
	private:\
	dataType valueName; \
	public:

#define CC_GET_PRIVATE(dataType, functionName, valueName) \
	dataType get##functionName(){ return valueName; } \
	private:\
	dataType valueName; \
	public:

// �õ���Ϸ������ָ��
// �����ֱַ���ʲô������ʹ�ã�������ʲô
// TODO enemy ���� bug ��ô��
#define GET_pCURENTSCENE cSceneMain* pCurentScene =static_cast<cSceneMain*>(cDirector::getInstance()->getScene())
#define GET_pSCENEMAIN cSceneMain* pSceneMain =static_cast<cSceneMain*>(cDirector::getInstance()->getScene("Game"))

enum {
	eAir,
	eWall,
	ENUM,
	eMoveCacheVal,
	eNPCCoach = 405,
	eMapBattle = 203,

	eNone = 0,
	ePlayer,
	eEnemy, 
	//eDirection,
	eUp,
	eDown,
	eLeft,
	eRight
};

// #include "Ruler.h"
#include "DataRuler.h"
#include "Director.h"
#include "SceneMain.h"
#include "Emitter.h"
// extern cDataRuler* dataRuler;
// extern cRuler* ruler;
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
int iMoveCache = 0;

#endif // !RPG_RPG_STDAFX_H_