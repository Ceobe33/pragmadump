#include "stdafx.h"
#include "Menu.h"
#include "RoleSelect.h"

cMenu::cMenu()
    //: shape(100.f),
    //  window(VideoMode(800, 600), "SFML works!")
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
    //if (window.isOpen())
    //{
    //    Event event;
    //    if (window.pollEvent(event))
    //    {
    //        if (event.type == Event::Closed)
    //            window.close();
    //    }
    //    window.clear();
    //    window.draw(shape);
    //    window.display();
    //}
    cout << "\n\n\t            this is Menu\n"
        << "\t        press enter to play";
}
