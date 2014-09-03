#include "JoystickLayer.h"
#include "JoystickPad.h"

#define PAD_RADIUS 128/2

JoystickLayer* JoystickLayer::create(MainTank * tank) {
	auto jsl = new JoystickLayer();
	if (jsl && jsl->init(tank)) {
		jsl->autorelease();
		return jsl;
	}
	CC_SAFE_DELETE(jsl);
	return NULL;
}

bool JoystickLayer::init(MainTank* tank) {
	if (!Layer::init()) return false;

	auto pad = JoystickPad::createWithFile("direction.png", PAD_RADIUS);
	pad->_mainTank = tank;
	pad->setPosition(PAD_RADIUS + 10, PAD_RADIUS + 10);
	this->addChild(pad);

	auto item1 = MenuItemImage::create("fire_button_default.png", "fire_button_press.png", [=](Ref* s) {
		tank->fire(0);
		log("%f, %f", tank->getPositionX(), tank->getPositionY());
	});
	item1->setScale(0.33f);
	auto firebtn = Menu::create(item1, NULL);
	firebtn->setPosition(440, 40);
	this->addChild(firebtn);

	return true;
}
