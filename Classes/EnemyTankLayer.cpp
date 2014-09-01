#include "EnemyTankLayer.h"
#include "EnemyOneTank.h"
#include "EnemyTwoTank.h"
#include "EnemyThreeTank.h"
#include "EnemyTank.h"

bool EnemyTankLayer::init(){
	if (!Layer::init())
	{
		return false;
	}
	
	_size = Director::getInstance()->getVisibleSize();
	 _enemy1RemainCount = 14;	// 还可以产生敌机1类型的数量
	 _enemy2RemainCount = 8;	// 
	 _enemy3RemainCount = 8;
	 this->schedule(schedule_selector(EnemyTankLayer::addEnemy1Tank),5);
	 this->schedule(schedule_selector(EnemyTankLayer::addEnemy2Tank),10);
	 this->schedule(schedule_selector(EnemyTankLayer::addEnemy3Tank),10);
	
	return true;
}

void EnemyTankLayer::addEnemy1Tank(float t){
	if (_enemy1RemainCount > 0)
	{
		auto _enemy1 = EnemyOneTank::create();
		_enemy1->setPosition(_size.width/2,_size.height - 50);
		_enemy1->ai(1);
		this->addChild(_enemy1);
		_enemy1RemainCount --;
	}
	
}

void EnemyTankLayer::addEnemy2Tank(float t){
	if (_enemy2RemainCount > 0)
	{
		auto _enemy2 = EnemyTwoTank::create();
		_enemy2->setPosition(50,_size.height - 50);
		_enemy2->ai(1);
		this->addChild(_enemy2);
		_enemy2RemainCount --;
	}
}

void EnemyTankLayer::addEnemy3Tank(float t){
	if (_enemy3RemainCount > 0)
	{
		auto _enemy3 = EnemyThreeTank::create();
		_enemy3->setPosition(_size.width - 50,_size.height - 50);
		_enemy3->ai(1);
		this->addChild(_enemy3);
		_enemy3RemainCount --;
	}
}
