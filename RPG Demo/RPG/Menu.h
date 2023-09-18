#pragma once
#ifndef RPG_RPG_MENU_H_
#define RPG_RPG_MENU_H_

class cMenu :public cSceneBase {
public:
    cMenu();
    void update();
    void render();
    //static cMenu* getInstance();
    GET_SET_PRIVATE(int, State, arrowState);
private:
    //static cMenu* m_pInstanceMenu;
    //int arrowState;
    CircleShape shape;
    RenderWindow window;
};

#endif // !RPG_RPG_MENU_H_