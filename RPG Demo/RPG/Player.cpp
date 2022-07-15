#include "stdafx.h"
#include "Player.h"
#include "Clert.h"
#include "SceneMain.h"

//cPlayer* cPlayer::m_pInstancePlayer = nullptr;
cPlayer::cPlayer() {
	m_iRow = 0, m_iCol = 0, m_iHP = 0;
	m_iBackupTrainRow = 0, m_iBackupTrainCol = 0;
	m_pBag = new cBag();
	m_pEquipment = new cEquipment();
	arrowState = 0;
	m_iLevel = 0;
	m_bHurt = false;
	m_bFire = false;
	havePet = false;
	m_iEXPMax = 600, m_iEXP = 0;
	cEmitter::getInstance()->registerNews("buyGoods", bind(&cPlayer::buyGoods, this, placeholders::_1));
}

//cPlayer::cPlayer(int r, int c)
//{
//	m_iRow = r, m_iCol = c;
//}

void cPlayer::update() {
	GET_pCURENTSCENE;
	//GET_pSCENEMAIN;
	//备份玩家坐标
	backup();
	if (KEY_DOWN(VK_DOWN))
		m_iRow++;
	else if (KEY_DOWN(VK_UP))
		m_iRow--;
	else if (KEY_DOWN(VK_RIGHT))
		m_iCol++;
	else if (KEY_DOWN(VK_LEFT))
		m_iCol--;
	else if (KEY_DOWN(VK_RETURN)) {
		//m_bFire = true;
	}
	else if (KEY_DOWN(VK_SPACE)) {
		int direction = 0;
		//up
		if (1 == m_iBackupRow - m_iRow && 0 == m_iBackupCol - m_iCol) {
			direction = eUp;
		}
		//down
		else if (-1 == m_iBackupRow - m_iRow && 0 == m_iBackupCol - m_iCol) {
			direction = eDown;
		}
		//left
		else if (0 == m_iBackupRow - m_iRow && 1 == m_iBackupCol - m_iCol) {
			direction = eLeft;
		}
		//right
		else if (0 == m_iBackupRow - m_iRow && -1 == m_iBackupCol - m_iCol) {
			direction = eRight;
		}
		pCurentScene->getFireRuler()->load(m_iRow, m_iCol, direction, ePlayer);
		m_bFire = true;
	}
	//角色移动后重新设定位置
	setPosition(m_iRow, m_iCol);
	pCurentScene->getFireRuler()->fireIns->update();
	//equipmentBonus();
}

void cPlayer::surroundPlayer(const int& i) {
	GET_pSCENEMAIN;
	if (i != pSceneMain->getCurentMap()->m_arrMap[m_iRow + 1][m_iCol]) {
		setPosition(m_iRow + 1, m_iCol);
	}
	else if (i != pSceneMain->getCurentMap()->m_arrMap[m_iRow - 1][m_iCol])	{
		setPosition(m_iRow - 1, m_iCol);
	}
	else if (i != pSceneMain->getCurentMap()->m_arrMap[m_iRow][m_iCol - 1])	{
		setPosition(m_iRow, m_iCol - 1);
	}
	else if (i != pSceneMain->getCurentMap()->m_arrMap[m_iRow][m_iCol + 1])	{
		setPosition(m_iRow, m_iCol + 1);
	}
}

void cPlayer::setPosition(int r, int c) {
	m_iRow = r, m_iCol = c;
}

bool cPlayer::scan(int r, int c) {
	if (r == m_iRow && c == m_iCol)
		return true;
	return false;
}

void cPlayer::backup() {
	m_iBackupRow = m_iRow;
	m_iBackupCol = m_iCol;
}

void cPlayer::revoke() {
	m_iRow = m_iBackupRow;
	m_iCol = m_iBackupCol;
}
//
//cPlayer* cPlayer::getDetail()
//{
//	return m_pInstancePlayer;
//}

void cPlayer::initialize(cRoleSelectData* detail) {
	m_iID = detail->iID;
	m_iAtk = detail->m_iAtk;
	m_iDef = detail->m_iDef;
	m_iHPMax = m_iHP = detail->m_iHP;
	m_strName = detail->m_strName;
	m_strRole = detail->m_strRole;
	m_strGrowth = detail->m_strGrowth;
	m_strImg = detail->m_strImg;
	m_iAcount = detail->m_iAcount;
}

void cPlayer::useItem(cGoodsData* data){
}

void cPlayer::buyGoods(void* voidData) {
	cGoodsData* pData = static_cast<cGoodsData*>(voidData);
	//GET_pSCENEMAIN;
	if(pData->iID >= 600 && pData->iID < 700) {
		cPetData* pData = static_cast<cPetData*>(voidData);
		petInit(pData);
	}
	else if (pData->iID == 312)	{
		if (m_strName != "Ceobe") {
			//cClert::getInstance()->buyingPower();
			cDirector::getInstance()->pushScene(new cClert());
		}
		if (m_strName == "Ceobe") {
			if (m_iAcount < pData->iPrice) {
				cout << "you have no money";
				return;
			}
			//pName->iAmount--;
			m_iAcount -= pData->iPrice;
			m_pBag->addGoods(pData);
		}
	}
	else {
		if (m_iAcount < pData->iPrice)
			return;
		m_iAcount -= pData->iPrice;
		m_pBag->addGoods(pData);
	}
}

void cPlayer::setBackupTrainPosition() {
	m_iBackupTrainRow = m_iRow, m_iBackupTrainCol = m_iCol;
}

void cPlayer::bonus(string inOrOut, cGoodsData* pData) {
	//判断是装备/使用 还是解除
	if (inOrOut == "in") {
		if (pData->iBagCount > 0) {
			if (pData->strTag == "edible") {
				if (m_iHP < m_iHPMax) {
					pData->iBagCount--;//减少背包内相应物品数量
					m_iHP += pData->iHeal;
				}
				else {
					m_iHP = m_iHPMax;
				}
			}
			else if (pData->strTag == "arms") {
				m_iDef += pData->iDef;
				m_iAtk += pData->iAtk;
				pData->iBagCount--;
				pData->iEquipmentCount++;
				//pSceneMain->getPlayer()->getAtk()
				for (cGoodsData* vec : m_pEquipment->getVecEquipment()) {
					if (vec->iID == pData->iID) {
						m_iDef -= pData->iDef;
						m_iAtk -= pData->iAtk;
						pData->iBagCount++;
						pData->iEquipmentCount--;
						return;
					}
				}
				//将相应物品加到物品栏
				m_pEquipment->addEquipment(pData);
			}
		}
	}
	else if (inOrOut == "out") {
		m_iDef -= pData->iDef;
		m_iAtk -= pData->iAtk;
	}
}

void cPlayer::hurt(const int& enemyID, bool hurt) {
	// GET_pSCENEMAIN;
	GET_pCURENTSCENE;
	if (hurt) {
		int iDamage = pCurentScene->getEnemyRuler()->getSingleEnemy(enemyID)->getAtk();
		m_iHP -= int(iDamage > m_iDef ? iDamage - m_iDef : iDamage * 0.05);
		if (m_iHP <= 0) {
			system("cls");
			m_iHP = 0;
			cout << "you are dead!" << endl;
			Sleep(5000);
		}
	}
}

// 处理
void cPlayer::experience(const int& EXP) {
	int tempEXP = 0;
	// 当经验值盈满时升级
	m_iEXP += EXP;
	// 当获得大量经验时
	while (m_iEXP >= m_iEXPMax)	{
		tempEXP = m_iEXP - m_iEXPMax;
		m_iLevel++;
		m_iHP += 10, m_iDef += 10, m_iAtk += 10, m_iEXPMax += 10;
		m_iEXP = tempEXP;

	}
}

// 打印经验条
void cPlayer::experienceRender() {
	for (int i = 0; i < 36; i++) {
		i < 36 * m_iEXP / m_iEXPMax ? cout << "■" : cout << "□";
	}
	cout << endl;
}

void cPlayer::propertyRender() {
	// printf("\tName\tRole\t\tAtk\tDef\tHP\tGrowth\tImg\tAcount\t\n");
	cout << "\tName\t" << "Role\t\t" << "Atk\t" << "Def\t" << "HP\t" << "Growth\t" << "Img\t" << "Acount\t" << endl;
	cout
		<< "\t"
		<< m_strName << "\t"
		<< left << setw(10) << m_strRole << "\t"
		<< m_iAtk << "\t"
		<< m_iDef << "\t"
		<< m_iHP << "\t"
		<< m_strGrowth << "\t"
		<< m_strImg << "\t"
		<< m_iAcount << "\t" << endl;
}

void cPlayer::petInit(cPetData* pData) {
	m_iAtk += pData->iGain;
	m_iDef += pData->iGain;
	m_strPetImg = pData->strImg;
	m_iPetRowBackup = m_iPetRow = m_iBackupRow;
	m_iPetColBackup = m_iPetCol = m_iBackupCol;
}

//bool cPlayer::getHurt()
//{
//	return m_bHurt;
//}
//
//bool cPlayer::getFire()
//{
//	return m_bFire;
//}
