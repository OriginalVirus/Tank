#pragma once
#include "basetank.h"

#define EnemyMaxCount 20;

class EnemyTank :public BaseTank
{
public:
	CREATE_FUNC(EnemyTank);
public:
	void ai(float dt);
private:
	int _count;
};

