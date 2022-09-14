#ifndef RPG_RPG_LOADING_H_
#define RPG_RPG_LOADING_H_

class cLoading :public cSceneBase {
public:
    cLoading();
    cLoading(int nMapId) {
        nextMapId = nMapId;
    }
    ~cLoading();
    void update();
    void render();
    static cLoading* getInstance();
private:
    static cLoading* m_pInstanceLoading;
    int nextMapId;
};

#endif // !RPG_RPG_LOADING_H_