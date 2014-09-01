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

	return true;
}
