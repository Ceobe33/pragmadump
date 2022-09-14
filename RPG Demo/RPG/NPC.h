#pragma once
#ifndef RPG_RPG_NPC_H_
#define RPG_RPG_NPC_H_

class cNPC {
public:
    cNPC();
    ~cNPC();

    void update();
    void initialize(cNPCData* data);

    //void createNPC();
    //bool scan(const int& r, const int& c, const int& i);
    //cNPC* render(const int& r, const int& c, const int& i);
    //cNPCData* dialogue(const int& r);

    //vector<cNPCData*> getNPCVector();

    //interface
    //GET_PRIVATE(vector<cNPCData*>, VecNPC, m_vecNPC);
    //static cNPC* getInstance();

    GET_PRIVATE(int, Row, m_iRow);
    GET_PRIVATE(int, Col, m_iCol);
    GET_PRIVATE(int, ID, m_iID);
    GET_PRIVATE(int, CurentMapID, m_iCurentMapID);
    GET_PRIVATE(string, Occupation, m_strOccupation);
    GET_PRIVATE(string, Dialogue, m_strDialogue);
    GET_PRIVATE(string, Name, m_strName);
private:
    //vector<cNPCData*> m_vecNPC;


    /*int m_iID, m_iRow, m_iCol, m_iCurentMapID;
    string m_strName, m_strOccupation, m_strDialogue;*/
    //static cNPC* m_pInstanceNPC;
};

class cNPCRuler {
public:
    cNPCRuler();

    void storage();
    //bool scan(const int& r, const int& c, const int& i);
    cNPC* render(const int& r, const int& c, const int& i);
    //cNPC* dialogue(const int& r);
    cNPC* getNPCByID(const int& i);

    //interface
    GET_PRIVATE(vector<cNPC*>, VecNPC, m_vecNPC);
    //GET_PRIVATE(cNPC*, NPC, m_pNPC);

private:
    //vector<cNPC*> m_vecNPC;
    ///cNPC* m_pNPC;
};

#endif // !RPG_RPG_NPC_H_