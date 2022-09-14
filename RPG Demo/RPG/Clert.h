#pragma once

class cClert :public cSceneBase {
public:
    cClert();
    ~cClert();
    void update();
    void render();
    void buyingPower();
    static cClert* getInstance();
private:
    static cClert* m_pInstance;

};

