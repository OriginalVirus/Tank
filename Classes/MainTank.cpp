#include "MainTank.h"
#include "Bullet.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool MainTank::init(){
	if (!Sprite::initWithFile("mainTank.png")) return false;

	_hp = 1;
	_speed = 130;
	_current_life = 4;
	isDie = false;
	_direction = Vec2(0, 1);

	return true;
}

void MainTank::fire(float t) {
	auto scene = GameScene::getInstance();
	auto maplayer = scene->_mapLayer;
	auto bullet = maplayer->_mainBullet;

	if (bullet->isVisible()) return;

	// move bullet
	Vec2 batteryPosition = this->getPosition() + _direction * 16;
	bullet->setPosition(batteryPosition);
	bullet->setVisible(true);

	Vect v = this->_direction;
	Size size = Director::getInstance()->getVisibleSize();
	float x = v.x == -1 ? this->getPositionX() : size.width - this->getPositionX();
	float y = v.y == -1 ? this->getPositionY() : size.height - this->getPositionY();

	float a = (v.x)*x;
	float b = (v.y)*y;
	Vect v2 = Vect(a,b);
	auto time = v2.getLength()/_speed;
	auto m = MoveBy::create(time, v2);
	auto cf = CallFunc::create([=](){
		bullet->stopAllActions();
		bullet->setVisible(false);
	});
	auto sq = Sequence::create(m,cf,NULL);
	bullet->runAction(sq);

	// play effect
	SimpleAudioEngine::getInstance()->playEffect("fire.wav");
}

void MainTank::hurtWithDemage(int demage){
	this->_hp -= demage;
	if (_hp <= 0)
	{
		_hp = 0;

		int i = -- GameScene::getInstance()->lifeCount;
		if (i > 0)
		{
			respawn();
		} else {
			GameScene::getInstance()->GameOver();
		}
	}
}

void MainTank::respawn() {
	this->setPosition(11*16, 16);
	SimpleAudioEngine::getInstance()->playEffect("respawn.wav");
}