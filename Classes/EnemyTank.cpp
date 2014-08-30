#include "EnemyTank.h"
#include "Bullet.h"
#include "GameScene.h"
#include "BaseTank.h"
bool EnemyTank::init(){
	if (!BaseTank::init())
	{
		return false;
	}
	this->schedule(schedule_selector(EnemyTank::fire),2);
	return true;
	
	
}
void EnemyTank::ai(float dt){
	
}
void EnemyTank::fire(float t){
	auto bullet = Bullet::create();
	auto scene = GameScene::getInstance();
	scene->_enemyTankLayer->addChild(bullet);
}