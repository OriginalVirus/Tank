#include "PropBomb.h"
#include "BaseProp.h"
#include "GameScene.h"

bool PropBomb::init() {
	if (!BaseProp::initWithFile("timer.png")) {
		return false;
	}

	Vec2 v = this->randomPosition();
	this->setPosition(v);
	//scheduleToDisappear();
	return true;
}

BaseProp *PropBomb::create() {
	auto prop = new PropBomb();
	if (prop&&prop->init()) {
		prop->autorelease();
		return prop;
	}
	CC_SAFE_DELETE(prop);
	return nullptr;
}

void PropBomb::effect(Ref*sender) {
	// 调用敌机全消失的方法。
	auto enemies = GameScene::getInstance()->_enemyTankLayer->getChildren();
	auto ebullets = GameScene::getInstance()->_enemyBulletsLayer->getChildren();
	for (int i = 0; i < enemies.size(); i++)
	{
		auto enemy = static_cast<EnemyTank *> (enemies.at(i));
		/*enemy->stopAllActions();*/
		enemy->killed();
		enemy->removeFromParentAndCleanup(true);
	}
	for (int i = 0; i < ebullets.size();i ++)
	{
		auto ebullet = ebullets.at(i);
		ebullet->removeFromParentAndCleanup(true);
	}
}

void PropBomb::scheduleToDisappear() {
	this->scheduleOnce(schedule_selector(PropBomb::disappear), 10);
}