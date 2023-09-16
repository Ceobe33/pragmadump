#include "stdafx.h"
#include "SceneMain.h"
#include "Map.h"
#include "Loading.h"
#include "Emitter.h"
#include "Clert.h"
#include "Bag.h"

cSceneMain::cSceneMain()
    :pEnemyData(nullptr),
    m_iSurroundPlayer(0),
    m_bSurroundNPC(false),
    m_bTrainning(false),
    m_bEnemyPropertyRender(false),
    m_iMapID(200) {
    m_strName = "Game";
    m_pPlayer = new cPlayer();

    m_pEnemyRuler = new cEnemyRuler();
    m_pNPCRuler = new cNPCRuler();
    m_pRoleSelectRuler = new cRoleSelectRuler();
    m_pStore = new cStore();
    m_pFireRuler = new cFireRuler();

    // initialize with another way
    // pEnemyData = nullptr;
    // 玩家周围NPC的ID
    // m_iSurroundPlayer = 0;
    // NPC周围是否有玩家
    // m_bSurroundNPC = false;
    // m_bTrainning = false;
    // m_bEnemyPropertyRender = false;
    //地图ID从200开始
    // m_iMapID = 200;

    m_pCurentMap = cMap::getInstance()->getMapByID(m_iMapID);
    //初始化玩家位置
    m_pPlayer->setPosition(m_pCurentMap->m_iPlayerRow, m_pCurentMap->m_iPlayerCol);
}

void cSceneMain::update() {
    //m_pEnemy->update();
    cSceneMain* pScene = new cSceneMain();
    pScene->getPlayer();

    m_pPlayer->update();
    collide();

    //如果NPC周围四格有玩家
    if (m_bSurroundNPC) {
        if (KEY_DOWN(VK_RETURN)) {
            if (405 == m_iSurroundPlayer) {
                m_bTrainning = true;
                m_iMapID = 203;
                m_pEnemyRuler = new cEnemyRuler();
                //update();
            } else if (406 == m_iSurroundPlayer) {
                cPetStore* pPetStore = new cPetStore();
                //pPetStore->init(m_iSurroundPlayer);
                cDirector::getInstance()->pushScene(pPetStore);
                // 花里胡哨的加载界面
                cDirector::getInstance()->pushScene(new cLoading());
            } else {
                cStore* pStore = new cStore();
                pStore->initItems(m_iSurroundPlayer);
                cDirector::getInstance()->pushScene(pStore);
                //cDirector::getInstance()->replaceScene(pStore);
            }
        }
        m_bSurroundNPC = false;
    }

    //如果玩家在地图上的位置是门
    int iMapID = m_pCurentMap->m_arrMap[m_pPlayer->getRow()][m_pPlayer->getCol()];
    if ((iMapID >= 200 && iMapID < 300) || m_bTrainning) {
        int justnowMapID = m_iMapID;
        //m_bTrainning = false;
        if (!m_bTrainning)
            m_iMapID = iMapID;
        //花里胡哨的加载界面
        cDirector::getInstance()->pushScene(new cLoading());
        //return;
        //传值给地图类来切换地图
        m_pCurentMap = cMap::getInstance()->getMapByID(m_iMapID);
        //如果玩家是从战斗界面回到主界面就回到教官旁边
        if (203 == justnowMapID) {
            m_pPlayer->setPosition(m_pPlayer->getBackupTrainRow(), m_pPlayer->getBackupTrainCol());
            m_bTrainning = false;
        } else {
            //切换地图后实现角色落脚点
            m_pPlayer->surroundPlayer(eWall);
        }
        //m_pPlayer->setPosition(m_pPlayer->getRow() + 1, m_pPlayer->getCol());
    }
    if (KEY_DOWN(VK_ESCAPE)) {
        cDirector::getInstance()->pushScene(new cClert());
    } else if (KEY_DOWN(VK_B)) {
        cDirector::getInstance()->pushScene(m_pPlayer->getBag());
    } else if (KEY_DOWN(VK_E)) {
        cDirector::getInstance()->pushScene(m_pPlayer->getEquipment());
    }
    //如果玩家在战斗场景（地图）则开火设为true
    if (m_iMapID == 203) {
        m_pPlayer->setFire(true);
    }
}

bool cSceneMain::collide() {
    //如果玩家碰到NPC
    if (m_pNPCRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID)) {
        m_pPlayer->revoke();
        return true;
    }
    //判断玩家有没有与敌人重叠
    if (m_pEnemyRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID)) {

        if (203 == m_iMapID)
            m_EnemyTemp = m_pEnemyRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID);
        //m_pEnemy->render();*/
    //如果重叠就传enemyID到enemy获取enemy攻击数据 把玩家受伤设为true
        m_pPlayer->setHurt(true);
        cEnemy* pEnemy = m_pEnemyRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID);
        m_pPlayer->hurt(pEnemy->getID(), true);

        pEnemyData = m_pEnemyRuler->killed();
        m_pPlayer->revoke();
    }
    //如果玩家与墙重叠，就退一步
    if (eWall == m_pCurentMap->m_arrMap[m_pPlayer->getRow()][m_pPlayer->getCol()]) {
        m_pPlayer->revoke();
    }
    return false;
}

void cSceneMain::render() {
    //if (KEY_DOWN(VK_ESCAPE))
    //    selectedRole->render();
    for (int i = 0; i < m_pCurentMap->m_iRow; i++) {
        for (int j = 0; j < m_pCurentMap->m_iCol; j++) {
            int iTag = 0;
            if (m_pNPCRuler->render(i, j, m_iMapID)/*m_pCurentMap->m_arrMap[i][j] >= 400 && m_pCurentMap->m_arrMap[i][j] < 500*/) {
                //render函数 判断-返回 要打印的字符
                // substr(begin,count);  从第 begin 个元素开始保留到第 count 个字节结束 其余删除
                cNPC* npc = m_pNPCRuler->render(i, j, m_iMapID);
                //将该NPC的ID赋值到玩家周围NPC变量上
                //if (m_pPlayer->surroundPlayer(i, j))

                string npcOccupation = npc->getOccupation();
                int npcRow = npc->getRow(), npcCol = npc->getCol();
                string npcDialogue = npc->getDialogue();
                iTag = 1;
                cout << npcOccupation.substr(0, 2);
                //判断玩家周围是否有 NPC
                int absRow = abs(m_pPlayer->getRow() - npcRow), absCol = abs(m_pPlayer->getCol() - npcCol);
                if (absRow == 1 && absCol == 0 || absRow == 0 && absCol == 1) {
                    m_iSurroundPlayer = npc->getID();
                    m_bSurroundNPC = true;
                    cout << npcDialogue/*.substr(0, 2)*/;
                    //记录玩家进入训练场的位置
                    //如果玩家周围npc是杜宾教官，记录当玩家再返回此地图时出现的位置
                    if (405 == m_iSurroundPlayer)
                        m_pPlayer->setBackupTrainPosition();
                    j += npcDialogue.length();
                    /*if (npc->iID == eNPCCoach && KEY_DOWN(VK_RETURN))
                    {
                    m_iMapID = eMapBattle;
                    }*/
                    //if (j >= m_pCurentMap->m_iCol)
                    break;
                }
            } else if (m_pEnemyRuler->render(i, j, m_iMapID)/*m_pCurentMap->m_arrMap[i][j] >= 500 && m_pCurentMap->m_arrMap[i][j] < 600*/) {
                iTag = 2;
                cout << m_pEnemyRuler->render(i, j, m_iMapID)->getImg();
            } else if (eWall == m_pCurentMap->m_arrMap[i][j]) {
                iTag = 3;
                cout << "■";
            } else if (m_pCurentMap->m_arrMap[i][j] >= 400 && m_pCurentMap->m_arrMap[i][j] < 500) {
                iTag = 4;
                cout << m_pNPCRuler->getNPCByID(m_pCurentMap->m_arrMap[i][j])->getOccupation().substr(0, 2);
            } else if (m_pPlayer->scan(i, j)) {
                iTag = 5;
                if (m_pPlayer->getHurt()) {
                    //受伤颜色
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    m_pPlayer->setHurt(false);
                    cout << m_pPlayer->getImg();
                    //7 正常字体颜色
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                } else {
                    cout << m_pPlayer->getImg();
                }
            } else if (m_pPlayer->havePet && i == m_pPlayer->m_iPetRow && j == m_pPlayer->m_iPetCol) {
                iTag = 6;
                m_pPlayer->m_strPetImg;
            } else if (m_pPlayer->getFire()) {
                iTag = 7;
                m_pPlayer->setFire(false);
                m_pFireRuler->fireIns->render();

                //scan 函数判断该位置是否有NPC
            } else if (m_pCurentMap->m_arrMap[i][j] >= 200 && m_pCurentMap->m_arrMap[i][j] < 300/*100 <= m_pCurentMap->m_arrMap[i][j]*/) {
                iTag = 8;
                cout << "□";
            } else if (eAir == m_pCurentMap->m_arrMap[i][j]) {
                iTag = 9;
                cout << "  ";
            }
            // cout << iTag << "*";
        }// in-loop end
        cout << endl;
    }// out-loop end

    // 玩家等级
    cout << endl << "\t\t\t  " << left << setw(2) << m_pPlayer->getLevel() << "(" << left << setw(3) << m_pPlayer->getEXP() << "/" << m_pPlayer->getEXPMax() << ")" << endl;
    // 玩家经验条
    m_pPlayer->experienceRender();
    if (m_EnemyTemp &&/*203 == m_iMapID  &&*/m_EnemyTemp->death/*m_pEnemyRuler->getSingleEnemy(m_EnemyTemp->getID())->death*/) {
        //m_pEnemyRuler->getSingleEnemy(m_EnemyTemp->getID())->death = false;
        m_EnemyTemp->death = false;
        //传给玩家 杀死相应敌人获得的经验值
        m_pPlayer->experience(pEnemyData->getEXPValue());
        //删除敌人容器里的死亡敌人
    }
    // 玩家各项属性
    cout << "\tName\t" << "Role\t" << "Atk\t" << "Def\t" << "HP\t" << "Growth\t" << "Img\t" << "Acount\t" << endl;
    cout
        << "\t"
        << m_pPlayer->getName() << "\t"
        << m_pPlayer->getRole() << "\t"
        << m_pPlayer->getAtk() << "\t"
        << m_pPlayer->getDef() << "\t"
        <</* setfill(" ") << */setw(5) << m_pPlayer->getHP() << "\t"
        << m_pPlayer->getGrowth() << "\t"
        << m_pPlayer->getImg() << "\t"
        << m_pPlayer->getAcount() << "\t" << endl;
    cout
        << "mapID: " << m_iMapID << "\t" << endl
        << "player\trows\tcols\n\t"
        << m_pPlayer->getRow() << "\t" << m_pPlayer->getCol() << endl;
    // 敌人属性信息
    if (m_EnemyTemp) {
        m_pEnemyRuler->render(m_EnemyTemp);
    }
}