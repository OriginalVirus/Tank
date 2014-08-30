#pragma once

#include "cocos2d.h"
#include "MainTank.h"
USING_NS_CC;

class JoystickLayer : public Layer {
public:
	static JoystickLayer* create(MainTank * tank);
	bool init(MainTank * tank);
};

