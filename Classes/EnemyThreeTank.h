#pragma once;
#include "cocos2d.h"
#include "EnemyTank.h"
using namespace cocos2d;

// 出道具的坦克
class EnemyThreeTank:public EnemyTank{
public:
	virtual bool init();
	CREATE_FUNC(EnemyThreeTank);
	virtual void die();
	void killed();
};