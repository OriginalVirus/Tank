#pragma once
#include "cocos2d.h"
#include "MainTank.h"
USING_NS_CC;

class JoystickLayer :
	public Layer
{
public:
	JoystickLayer(void);
	virtual ~JoystickLayer(void);
private:
	MainTank * _mainTank;
};

