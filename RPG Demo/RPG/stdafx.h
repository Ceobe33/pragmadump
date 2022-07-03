// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#ifndef RPG_RPG_STDAFX_H_
#define RPG_RPG_STDAFX_H_

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
// 读取数据文件头文件
#include <fstream>
#include <string>
#include <format>
#include <string_view>
// #include <fmt>
// setw（）函数，定义输出宽度函数
#include <iomanip>
#include <time.h>
#include <vector>
// map容器
#include <map>
// c++中 abs() 取绝对值函数的头文件
#include <cmath>
// 消息机制的头文件
#include <functional>

using namespace std;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000?1:0) /*&& m_iMoveCache % */)
#define VK_B           0x42
#define VK_E           0x45

// ##是粘合符
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

// 得到游戏场景的指针
// 这两种分别在什么场景下使用，作用是什么
// TODO enemy 处的 bug 怎么改
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
// TODO:  在此处引用程序需要的其他头文件
int iMoveCache = 0;

#endif // !RPG_RPG_STDAFX_H_