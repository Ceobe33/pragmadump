#ifndef RPG_RPG_MAP_H_
#define RPG_RPG_MAP_H_

class cMap {
public:
	~cMap();
	//void initialize(cMapData* data);

	cMapData* getMapByID(const int &mapID);
	static cMap* getInstance();
	//interface
	//CC_GETPRIVATE(int, ID, m_iID);
	CC_GET_PRIVATE(vector<cMapData*>, VecMap, m_vecMap);

private:
	cMap();
	static cMap* m_pInstanceMap;
	//int m_iID, m_iRow, m_iCol, m_iPlayerRow, m_iPlayerCol;

	//vector<cMapData*> m_vecMap;

};

//class cMapRuler
//{
//public:
//	cMapRuler();
//	~cMapRuler();
//
//	void getMapByID(const int &mapID);
//
//	//interface
//	CC_GETPRIVATE(vector<cMap*>, VecMap, m_vecMap);
//private:
//};

#endif // !RPG_RPG_MAP_H_