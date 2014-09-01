#include "MainTank.h"
#include "Bullet.h"
#include "GameScene.h"

bool MainTank::init(){
	if (!Sprite::initWithFile("p2tankU.png"))
	{
		return false;
	}
	_hp = 1;
	_speed = 8;
	_current_life = 4;
	isDie = false;
	return true;
}

void MainTank::fire(float t){
	auto bullet = Bullet::create();
	auto scene = GameScene::getInstance();
	scene->_mainBulletsLayer->addChild(bullet);

}
