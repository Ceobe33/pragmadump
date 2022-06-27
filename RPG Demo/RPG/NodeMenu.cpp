#include "stdafx.h"
#include "NodeMenu.h"


cNodeMenu::cNodeMenu()
{
	nodeName = "NodeMenu";
}


cNodeMenu::~cNodeMenu()
{
}

void cNodeMenu::update()
{
	if (KEY_DOWN(VK_RETURN))
	{
		/*cDirector::getInstance()->pushScene(this);
		cDirector::getInstance()->replaceScene(new cRoleSelect());*/
		this->getParent()->setShowNode(this->getParent()->getChildByName("NodeRoleSelect"));
	}
}

void cNodeMenu::render()
{

	cout << endl << endl << endl << "this is Menu";
}
