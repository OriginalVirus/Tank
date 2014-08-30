#pragma once
#include "basetank.h"
class MainTank :public BaseTank
{
public:
	virtual bool init();
	CREATE_FUNC(MainTank);
public:
	virtual void fire(float t);
	int _current_life;
};

