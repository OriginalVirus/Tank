#pragma once

#include "basetank.h"

class MainTank :public BaseTank {
public:
	virtual bool init();
	CREATE_FUNC(MainTank);
public:
	virtual void fire(float t);
	virtual void hurtWithDemage(int demage);
	void respawn();	
	int _current_life;
};

