#include "BaseTank.h"
#include "Bullet.h"

void BaseTank::move(float t){
	Size _size = Director::getInstance()->getVisibleSize();
	Size _tankSize = this->getContentSize();
	this->setPosition(this->getPosition() + _direction * t * _speed);
	//防止坦克移动出屏幕
	if (this->getPositionX() < 0 || this->getPositionX() > _size.width)
	{
		this->setPosition(this->getPositionX(),_tankSize.height/2);
	}
	if (this->getPositionY() < 0 || this->getPositionY() > _size.height)
	{
		this->setPosition(this->getPositionY(),_tankSize.height/2);
	}
}

void BaseTank::fire(float t){

}

void BaseTank::hurtWithDemage(int demage){
	this->_hp -= demage;
	if (_hp < 0)
	{
		_hp = 0;
		isDie = true;		
	}
}

void BaseTank::die(){
	this->removeFromParentAndCleanup(true);
}


