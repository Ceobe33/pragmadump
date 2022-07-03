#ifndef RPG_RPG_PLAYER_H_
#define RPG_RPG_PLAYER_H_

#include "Bag.h"
#include "Equipment.h"
//#include "SceneMain.h"

class cPlayer
{
public:
	cPlayer();
	// 功能
	// cPlayer(int r, int c);
	void update();
	void backup();
	void revoke();
	void bonus(string inOrOut,cGoodsData* pData);
	void surroundPlayer(const int &i);
	void setPosition(int r, int c);
	// cPlayer* getDetail();
	// static cPlayer* getInstance();
	void buyGoods(void* name);
	void initialize(cRoleSelectData* detail);
	void useItem(cGoodsData* data);
	void setBackupTrainPosition();
	void hurt(const int & enemyID, bool hurt);
	void experience(const int &EXP);
	void experienceRender();
	void propertyRender();
	void petInit(cPetData* pData);
	// 接口 interface
	bool scan(int r,int c);
	CC_GET_PRIVATE(int, Row, m_iRow);
	CC_GET_PRIVATE(int, Col, m_iCol);
	CC_GET_PRIVATE(int, Atk, m_iAtk);
	CC_GET_PRIVATE(int, Def, m_iDef);
	CC_GET_PRIVATE(int, HP, m_iHP);
	CC_GET_PRIVATE(int, Acount, m_iAcount);
	CC_GET_PRIVATE(int, BackupTrainRow, m_iBackupTrainRow);
	CC_GET_PRIVATE(int, BackupTrainCol, m_iBackupTrainCol);
	CC_GET_PRIVATE(int, BackupRow, m_iBackupRow);
	CC_GET_PRIVATE(int, BackupCol, m_iBackupCol);
	CC_GET_PRIVATE(int, Level, m_iLevel);
	CC_GET_PRIVATE(int, EXPMax, m_iEXPMax);
	CC_GET_PRIVATE(int, EXP, m_iEXP);
	CC_GET_SET_PRIVATE(bool, Hurt, m_bHurt);
	CC_GET_SET_PRIVATE(bool, Fire, m_bFire);
	CC_GET_PRIVATE(string, Img, m_strImg);
	CC_GET_PRIVATE(string, Role, m_strRole);
	CC_GET_PRIVATE(string, Growth, m_strGrowth);
	CC_GET_PRIVATE(string, Name, m_strName);
	//CC_GET_PRIVATE(vector<cGoodsData*>, VecEquipment, m_vecEquipment);
	CC_GET_PRIVATE(cBag*, Bag, m_pBag);
	CC_GET_PRIVATE(cEquipment*, Equipment, m_pEquipment);
	//CC_GETPRIVATE(int, BackupRow, m_iBackupRow);
	//CC_GETPRIVATE(int, BackupCol, m_iBackupCol);
	//bool getHurt();
	//bool getFire();
	bool havePet;
	int m_iPetRow, m_iPetCol, m_iPetRowBackup, m_iPetColBackup;
	string m_strPetImg;
private:
	//定义玩家行、列，备份行、列
	//int m_iRow, m_iCol;
	//cPlayer* m_pInstancePlayer;
	//bool m_bHurt,m_bFire;
	//int m_iEXPMax, m_iEXP;
	//int m_iBackupRow, m_iBackupCol;
	//cBag* m_pBag;

	int m_iID,m_iState,m_iHPMax;
	// player move cache, to prevent system to fluquent and player move too fast
};

#endif // !RPG_RPG_PLAYER_H_