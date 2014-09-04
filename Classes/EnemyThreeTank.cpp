#include "EnemyThreeTank.h"
#include "BaseTank.h"
#include "PropBomb.h"
#include "PropGod.h"
#include "GameScene.h"

bool EnemyThreeTank::init(){
	if (!EnemyTank::init("onetank.png")) return false;

	isDie = false;
	_hp = 1;
	_speed = 160;

	this->runAction(TintTo::create(2.0f, 0, 255, 0));
	
	return true;
}

void EnemyThreeTank::die(){

	// chan sheng daoju
	auto r = CCRANDOM_0_1();
	BaseProp * prob = NULL;
	if (r > 0.5f)
	{
		prob = PropGod::create();
	} else {
		prob = PropBomb::create();
	}
	GameScene::getInstance()->_propsLayer->addChild(prob);

	EnemyTank::die();

	killed();
}

void EnemyThreeTank::killed() {
	GameScene::getInstance()->_killTank3 ++;
}