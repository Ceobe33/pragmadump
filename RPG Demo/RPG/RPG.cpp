// RPG.cpp : 定义控制台应用程序的入口点。
//
//question: Change the map when player arrive the door			--done
//question: NPC.cpp line:35		return string or other better return method		--doing
//ppt描述自己的游戏 战斗界面  经验 升级  at least 20minutes
//额外： 任务  携带宠物 

//基本功能 扩展功能 消息机制 内存优化


//碰到敌人就报错 ._.    done
//进入训练（打怪）界面，在好电脑上运行时按回车时间过长会让 loading 界面重复加载

//玩家攻击敌人掉血，	doing
//打败敌人获得经验		done
//并在经验条上显示		done
//战斗界面退出后重置
//丢弃装备？ experienceMax 升级后加10  角色各项属性增加

//保留：直接在地图数据里写上相应角色ID就不需要手动设置他的row col 了
#include "stdafx.h"
#include "Menu.h"

//cDataRuler* dataRuler;
//cRuler* ruler;
int _tmain(int argc, _TCHAR* argv[])
{
	//初始化
	//管理者模式 每次用都需要new出来
	//dataRuler = new cDataRuler();
	//ruler = new cRuler();

	//需要#include <windows.h>
	SetConsoleTitle(L"RPG Game");//修改控制台名字  方法一
	//system("title sokoban1");	//修改控制台名字  方法二

	cLoad();
	cDirector::getInstance()->replaceScene(new cMenu());
	cDirector::getInstance()->runGame();

	return 0;
}

