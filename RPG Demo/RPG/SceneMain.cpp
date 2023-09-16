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
    // �����ΧNPC��ID
    // m_iSurroundPlayer = 0;
    // NPC��Χ�Ƿ������
    // m_bSurroundNPC = false;
    // m_bTrainning = false;
    // m_bEnemyPropertyRender = false;
    //��ͼID��200��ʼ
    // m_iMapID = 200;

    m_pCurentMap = cMap::getInstance()->getMapByID(m_iMapID);
    //��ʼ�����λ��
    m_pPlayer->setPosition(m_pCurentMap->m_iPlayerRow, m_pCurentMap->m_iPlayerCol);
}

void cSceneMain::update() {
    //m_pEnemy->update();
    cSceneMain* pScene = new cSceneMain();
    pScene->getPlayer();

    m_pPlayer->update();
    collide();

    //���NPC��Χ�ĸ������
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
                // ������ڵļ��ؽ���
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

    //�������ڵ�ͼ�ϵ�λ������
    int iMapID = m_pCurentMap->m_arrMap[m_pPlayer->getRow()][m_pPlayer->getCol()];
    if ((iMapID >= 200 && iMapID < 300) || m_bTrainning) {
        int justnowMapID = m_iMapID;
        //m_bTrainning = false;
        if (!m_bTrainning)
            m_iMapID = iMapID;
        //������ڵļ��ؽ���
        cDirector::getInstance()->pushScene(new cLoading());
        //return;
        //��ֵ����ͼ�����л���ͼ
        m_pCurentMap = cMap::getInstance()->getMapByID(m_iMapID);
        //�������Ǵ�ս������ص�������ͻص��̹��Ա�
        if (203 == justnowMapID) {
            m_pPlayer->setPosition(m_pPlayer->getBackupTrainRow(), m_pPlayer->getBackupTrainCol());
            m_bTrainning = false;
        } else {
            //�л���ͼ��ʵ�ֽ�ɫ��ŵ�
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
    //��������ս����������ͼ���򿪻���Ϊtrue
    if (m_iMapID == 203) {
        m_pPlayer->setFire(true);
    }
}

bool cSceneMain::collide() {
    //����������NPC
    if (m_pNPCRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID)) {
        m_pPlayer->revoke();
        return true;
    }
    //�ж������û��������ص�
    if (m_pEnemyRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID)) {

        if (203 == m_iMapID)
            m_EnemyTemp = m_pEnemyRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID);
        //m_pEnemy->render();*/
    //����ص��ʹ�enemyID��enemy��ȡenemy�������� �����������Ϊtrue
        m_pPlayer->setHurt(true);
        cEnemy* pEnemy = m_pEnemyRuler->render(m_pPlayer->getRow(), m_pPlayer->getCol(), m_iMapID);
        m_pPlayer->hurt(pEnemy->getID(), true);

        pEnemyData = m_pEnemyRuler->killed();
        m_pPlayer->revoke();
    }
    //��������ǽ�ص�������һ��
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
                //render���� �ж�-���� Ҫ��ӡ���ַ�
                // substr(begin,count);  �ӵ� begin ��Ԫ�ؿ�ʼ�������� count ���ֽڽ��� ����ɾ��
                cNPC* npc = m_pNPCRuler->render(i, j, m_iMapID);
                //����NPC��ID��ֵ�������ΧNPC������
                //if (m_pPlayer->surroundPlayer(i, j))

                string npcOccupation = npc->getOccupation();
                int npcRow = npc->getRow(), npcCol = npc->getCol();
                string npcDialogue = npc->getDialogue();
                iTag = 1;
                cout << npcOccupation.substr(0, 2);
                //�ж������Χ�Ƿ��� NPC
                int absRow = abs(m_pPlayer->getRow() - npcRow), absCol = abs(m_pPlayer->getCol() - npcCol);
                if (absRow == 1 && absCol == 0 || absRow == 0 && absCol == 1) {
                    m_iSurroundPlayer = npc->getID();
                    m_bSurroundNPC = true;
                    cout << npcDialogue/*.substr(0, 2)*/;
                    //��¼��ҽ���ѵ������λ��
                    //��������Χnpc�Ƕű��̹٣���¼������ٷ��ش˵�ͼʱ���ֵ�λ��
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
                cout << "��";
            } else if (m_pCurentMap->m_arrMap[i][j] >= 400 && m_pCurentMap->m_arrMap[i][j] < 500) {
                iTag = 4;
                cout << m_pNPCRuler->getNPCByID(m_pCurentMap->m_arrMap[i][j])->getOccupation().substr(0, 2);
            } else if (m_pPlayer->scan(i, j)) {
                iTag = 5;
                if (m_pPlayer->getHurt()) {
                    //������ɫ
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    m_pPlayer->setHurt(false);
                    cout << m_pPlayer->getImg();
                    //7 ����������ɫ
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

                //scan �����жϸ�λ���Ƿ���NPC
            } else if (m_pCurentMap->m_arrMap[i][j] >= 200 && m_pCurentMap->m_arrMap[i][j] < 300/*100 <= m_pCurentMap->m_arrMap[i][j]*/) {
                iTag = 8;
                cout << "��";
            } else if (eAir == m_pCurentMap->m_arrMap[i][j]) {
                iTag = 9;
                cout << "  ";
            }
            // cout << iTag << "*";
        }// in-loop end
        cout << endl;
    }// out-loop end

    // ��ҵȼ�
    cout << endl << "\t\t\t  " << left << setw(2) << m_pPlayer->getLevel() << "(" << left << setw(3) << m_pPlayer->getEXP() << "/" << m_pPlayer->getEXPMax() << ")" << endl;
    // ��Ҿ�����
    m_pPlayer->experienceRender();
    if (m_EnemyTemp &&/*203 == m_iMapID  &&*/m_EnemyTemp->death/*m_pEnemyRuler->getSingleEnemy(m_EnemyTemp->getID())->death*/) {
        //m_pEnemyRuler->getSingleEnemy(m_EnemyTemp->getID())->death = false;
        m_EnemyTemp->death = false;
        //������� ɱ����Ӧ���˻�õľ���ֵ
        m_pPlayer->experience(pEnemyData->getEXPValue());
        //ɾ���������������������
    }
    // ��Ҹ�������
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
    // ����������Ϣ
    if (m_EnemyTemp) {
        m_pEnemyRuler->render(m_EnemyTemp);
    }
}