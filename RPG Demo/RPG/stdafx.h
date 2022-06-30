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
#include <fstream> //��ȡ�����ļ�ͷ�ļ�
#include <string>
#include <iomanip> //setw�������������������Ⱥ���
#include <time.h>
#include <vector>
#include <map> //map����
#include <cmath>//c++�� abs() ȡ����ֵ������ͷ�ļ�
#include <functional> //��Ϣ���Ƶ�ͷ�ļ�
using namespace std;

#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)
#define VK_B           0x42
#define VK_E           0x45
//##��ճ�Ϸ�

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

//�õ���Ϸ������ָ��
//�����ֱַ���ʲô������ʹ�ã�������ʲô
//enemy ���� bug ��ô��
#define GET_pCURENTSCENE cSceneMain* pCurentScene =static_cast<cSceneMain*>(cDirector::getInstance()->getScene())
#define GET_pSCENEMAIN cSceneMain* pSceneMain =static_cast<cSceneMain*>(cDirector::getInstance()->getScene("Game"))

enum
{
	eAir,
	eWall,
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

//#include "Ruler.h"
#include "DataRuler.h"
#include "Director.h"
#include "SceneMain.h"
#include "Emitter.h"
//extern cDataRuler* dataRuler;
//extern cRuler* ruler;
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#endif // !RPG_RPG_STDAFX_H_