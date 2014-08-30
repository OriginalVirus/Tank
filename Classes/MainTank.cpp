#include "MainTank.h"
#include "Bullet.h"

bool MainTank::init(){
	if (!Sprite::initWithFile(""))
	{
		return false;
	}
    isDie(false);
	_hp = 1;
	_speed = 50;
	_current_life = 4;

	return true;
}
void MainTank::move(float t){
	this->setPosition(this->getPosition() + _direction * t * _speed);
}
void MainTank::fire(){
	auto bullet = Bullet::create();
	//添加到我方子弹层
	auto pDirector = Director::getInstance()->getRunningScene();

}
void MainTank::hurtWithDemage(int demage){
	this->_hp -= demage;
	if (_hp < 0)
	{
		_hp = 0;
	}
	
}
void MainTank::die(){
	this->removeFromParentAndCleanup(true);
	//在主坦克与敌坦克子弹碰撞时判断生命还有多少；
}