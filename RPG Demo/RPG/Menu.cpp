#include "stdafx.h"
#include "Menu.h"
#include "RoleSelect.h"

cMenu::cMenu()
    //: shape(100.f),
    //  window(VideoMode(200, 200), "SFML works!")
{
    m_strName = "Menu";

    //shape.setFillColor(Color::Green);
}

void cMenu::update() {
    if (KEY_DOWN(VK_RETURN)) {
        cDirector::getInstance()->pushScene(this);
        cDirector::getInstance()->pushScene(new cRoleSelectRuler());
    }
}
void cMenu::render() {
    //Event event;
    //window.clear();
    //window.draw(shape);
    //window.display();
    cout << endl << endl << endl << "		    this is Menu";
    cout << endl << endl << endl << "		press enter to play";
}
