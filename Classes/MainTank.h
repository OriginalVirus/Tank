#pragma once
#include "basetank.h"
class MainTank :
	public BaseTank
{
public:
	MainTank(void);
	virtual ~MainTank(void);
public:
	int _current_life;
};

