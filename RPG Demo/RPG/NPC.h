#pragma once
class cNPC
{
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
	//CC_GET_PRIVATE(vector<cNPCData*>, VecNPC, m_vecNPC);
	//static cNPC* getInstance();

	CC_GET_PRIVATE(int, Row, m_iRow);
	CC_GET_PRIVATE(int, Col, m_iCol);
	CC_GET_PRIVATE(int, ID, m_iID);
	CC_GET_PRIVATE(int, CurentMapID, m_iCurentMapID);
	CC_GET_PRIVATE(string, Occupation, m_strOccupation);
	CC_GET_PRIVATE(string, Dialogue, m_strDialogue);
	CC_GET_PRIVATE(string, Name, m_strName);
private:
	//vector<cNPCData*> m_vecNPC;


	/*int m_iID, m_iRow, m_iCol, m_iCurentMapID;
	string m_strName, m_strOccupation, m_strDialogue;*/
	//static cNPC* m_pInstanceNPC;
};

class cNPCRuler
{
public:
	cNPCRuler();

	void storage();
	//bool scan(const int& r, const int& c, const int& i);
	cNPC* render(const int& r, const int& c, const int& i);
	//cNPC* dialogue(const int& r);
	cNPC* getNPCByID(const int& i);

	//interface
	CC_GET_PRIVATE(vector<cNPC*>, VecNPC, m_vecNPC);
	//CC_GET_PRIVATE(cNPC*, NPC, m_pNPC);

private:
	//vector<cNPC*> m_vecNPC;
	///cNPC* m_pNPC;
};

