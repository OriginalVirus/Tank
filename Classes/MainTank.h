#pragma once
#include "basetank.h"
class MainTank :public BaseTank
{
public:
	virtual bool init();
	virtual void move(float t);
	virtual void fire();
	virtual void hurtWithDemage(int demage);
	virtual void die();
	CREATE_FUNC(MainTank);
public:
	int _current_life;
};

