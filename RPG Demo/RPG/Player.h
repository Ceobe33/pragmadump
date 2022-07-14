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
	GET_PRIVATE(int, Row, m_iRow);
	GET_PRIVATE(int, Col, m_iCol);
	GET_PRIVATE(int, Atk, m_iAtk);
	GET_PRIVATE(int, Def, m_iDef);
	GET_PRIVATE(int, HP, m_iHP);
	GET_PRIVATE(int, Acount, m_iAcount);
	GET_PRIVATE(int, BackupTrainRow, m_iBackupTrainRow);
	GET_PRIVATE(int, BackupTrainCol, m_iBackupTrainCol);
	GET_PRIVATE(int, BackupRow, m_iBackupRow);
	GET_PRIVATE(int, BackupCol, m_iBackupCol);
	GET_PRIVATE(int, Level, m_iLevel);
	GET_PRIVATE(int, EXPMax, m_iEXPMax);
	GET_PRIVATE(int, EXP, m_iEXP);
	GET_SET_PRIVATE(bool, Hurt, m_bHurt);
	GET_SET_PRIVATE(bool, Fire, m_bFire);
	GET_PRIVATE(string, Img, m_strImg);
	GET_PRIVATE(string, Role, m_strRole);
	GET_PRIVATE(string, Growth, m_strGrowth);
	GET_PRIVATE(string, Name, m_strName);
	//GET_PRIVATE(vector<cGoodsData*>, VecEquipment, m_vecEquipment);
	GET_PRIVATE(cBag*, Bag, m_pBag);
	GET_PRIVATE(cEquipment*, Equipment, m_pEquipment);
	//GET_PRIVATE(int, BackupRow, m_iBackupRow);
	//GET_PRIVATE(int, BackupCol, m_iBackupCol);
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