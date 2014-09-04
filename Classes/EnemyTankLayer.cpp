#include "EnemyTankLayer.h"
#include "EnemyOneTank.h"
#include "EnemyTwoTank.h"
#include "EnemyThreeTank.h"
#include "EnemyTank.h"
#include "AppMacros.h"

#define BORNPLACE1 Vec2(_size.width/2,_size.height - 16)
#define BORNPLACE2 Vec2(16,_size.height - 16)
#define BORNPLACE3 Vec2(_size.width - 16, _size.height - 16)

bool EnemyTankLayer::init() {
	if (!Layer::init()) return false;
	
	_size = Director::getInstance()->getVisibleSize();
	 _enemy1RemainCount = TANK1NO;	// 还可以产生敌机1类型的数量
	 _enemy2RemainCount = TANK2NO;	// 
	 _enemy3RemainCount = TANK3NO;
	 this->schedule(schedule_selector(EnemyTankLayer::addEnemy1Tank),5);
	 this->schedule(schedule_selector(EnemyTankLayer::addEnemy2Tank),10);
	 this->schedule(schedule_selector(EnemyTankLayer::addEnemy3Tank),10);

	 return true;
}

void EnemyTankLayer::addEnemy1Tank(float t) {
	if (_enemy1RemainCount > 0)	{
		auto _enemy1 = EnemyOneTank::create();
		auto r = rand()%3;
		_enemy1->setPosition(r == 0 ? BORNPLACE1 : (r == 1 ? BORNPLACE2 : BORNPLACE3));
		this->addChild(_enemy1);
		_enemy1RemainCount --;
	} else {
		this->unschedule(schedule_selector(EnemyTankLayer::addEnemy1Tank));
	}
	
}

void EnemyTankLayer::addEnemy2Tank(float t){
	if (_enemy2RemainCount > 0)
	{
		auto _enemy2 = EnemyTwoTank::create();
		auto r = rand()%3;
		_enemy2->setPosition(r == 0 ? BORNPLACE1 : (r == 1 ? BORNPLACE2 : BORNPLACE3));
		this->addChild(_enemy2);
		_enemy2RemainCount --;
	} else
	{
		this->unschedule(schedule_selector(EnemyTankLayer::addEnemy2Tank));
	}
}

void EnemyTankLayer::addEnemy3Tank(float t){
	if (_enemy3RemainCount > 0)
	{
		auto _enemy3 = EnemyThreeTank::create();
		auto r = rand()%3;
		_enemy3->setPosition(r == 0 ? BORNPLACE1 : (r == 1 ? BORNPLACE2 : BORNPLACE3));
		this->addChild(_enemy3);
		_enemy3RemainCount --;
	} else
	{
		this->unschedule(schedule_selector(EnemyTankLayer::addEnemy3Tank));
	}
}
