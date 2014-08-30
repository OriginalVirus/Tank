#pragma once
#include "basetank.h"

#define EnemyMaxCount 20;

class EnemyTank :
	public BaseTank
{
public:
	EnemyTank(void);
	virtual ~EnemyTank(void);
public:
	void ai(float dt);
private:
	int _count;
};

