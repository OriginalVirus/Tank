#pragma once;
#include "cocos2d.h"
#include "EnemyTank.h"
using namespace cocos2d;
class EnemyOneTank:public EnemyTank{
public:
	virtual bool init();
	CREATE_FUNC(EnemyOneTank);
	virtual void die();
	void killed();
};