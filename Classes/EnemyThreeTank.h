#pragma once;
#include "cocos2d.h"
#include "EnemyTank.h"
using namespace cocos2d;
class EnemyThreeTank:public EnemyTank{
public:
	virtual bool init();
	CREATE_FUNC(EnemyThreeTank);
};