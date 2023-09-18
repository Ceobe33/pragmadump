#include "stdafx.h"
#include "Menu.h"
#include "RoleSelect.h"

cMenu::cMenu()
    : shape(100.f),
      window(VideoMode(200, 200), "SFML works!")
{
    m_strName = "Menu";

    //shape = CircleShape(100.f);
    //shape.setFillColor(sf::Color::Green);
}

void cMenu::update() {
    if (KEY_DOWN(VK_RETURN)) {
        cDirector::getInstance()->pushScene(this);
        cDirector::getInstance()->pushScene(new cRoleSelectRuler());
    }
}
void cMenu::render() {
    //Event event;
    window.clear();
    window.draw(shape);
    window.display();
    cout << "\n\n\t            this is Menu\n"
        << "\t        press enter to play";
}
