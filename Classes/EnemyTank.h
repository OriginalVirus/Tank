#pragma once
#include "basetank.h"

#define EnemyMaxCount 20;

class EnemyTank :public BaseTank
{
public:
	virtual bool init();
	CREATE_FUNC(EnemyTank);
	void ai(float dt);
	virtual void fire(float t);
private:
	int _count;
};

