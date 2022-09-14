#include "stdafx.h"
#include "Menu.h"
#include "RoleSelect.h"

cMenu::cMenu() {
    m_strName = "Menu";
}

void cMenu::update() {
    if (KEY_DOWN(VK_RETURN)) {
        cDirector::getInstance()->pushScene(this);
        cDirector::getInstance()->pushScene(new cRoleSelectRuler());
    }
}
void cMenu::render() {
    cout << endl << endl << endl << "		    this is Menu";
    cout << endl << endl << endl << "		press enter to play";
}
