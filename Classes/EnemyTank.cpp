#include "EnemyTank.h"
#include "Bullet.h"
#include "GameScene.h"
#include "BaseTank.h"

bool EnemyTank::init(std::string path) {
	if (!BaseTank::initWithFile(path)) return false;
	
	isDie = false;
	_nextDecisionTime = CCRANDOM_MINUS1_1() + 1;
	_decisionTimeCounter = 0;

	auto i = rand()%3 - 1;
	_direction = Vec2(i, i != 0 ? 0 : -1);

	this->schedule(schedule_selector(EnemyTank::fire), 2);
	this->schedule(schedule_selector(EnemyTank::move), 1/60.0f);
	this->schedule(schedule_selector(EnemyTank::ai), 1/30.0f);
	
	return true;
}

void EnemyTank::ai(float t) {	// 转向
	// 决策
	if (_decisionTimeCounter > _nextDecisionTime) {
		// 转向
		Vec2 v = _direction;
		auto i = rand()%3 - 1;
		_direction = Vec2(i, i != 0 ? 0 : (rand()%2==0 ? 1 : -1));
		_nextDecisionTime = CCRANDOM_MINUS1_1() + 1;
		_decisionTimeCounter = 0;
	} else {
		_decisionTimeCounter += t;
	}	
}

void EnemyTank::fire(float t) {
	auto bullet = Bullet::create(this, 180);
	Vec2 batteryPosition = this->getPosition() + _direction * 16;
	bullet->setPosition(batteryPosition);
	bullet->_speed = 160;
	bullet->move();
	auto scene = GameScene::getInstance();
	scene->_enemyBulletsLayer->addChild(bullet);
}
