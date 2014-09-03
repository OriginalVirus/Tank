#include "BaseTank.h"
#include "Bullet.h"
#include "GameScene.h"

#define TANK_CENTER_TO_SIDE 15

void BaseTank::move(float t){
	Size _size = Director::getInstance()->getVisibleSize();
	Size _tankSize = this->getContentSize();

	_desiredPosition = this->getPosition() + _direction * t * _speed;
	if (isDesiredPositionValid())
		this->setPosition(_desiredPosition);

	// 转向
	if (_direction == Vec2(0, 1)) {				// 向上
		this->setRotation(0);
	} else if (_direction == Vec2(0, -1)) {		// 向下
		this->setRotation(180);
	} else if (_direction == Vec2(-1, 0)) {		// 向左
		this->setRotation(-90);
	} else if (_direction == Vec2(1, 0)) {		// 向右
		this->setRotation(90);
	}
}

void BaseTank::fire(float t){

}

void BaseTank::hurtWithDemage(int demage){
	this->_hp -= demage;
	if (_hp <= 0)
	{
		_hp = 0;
		isDie = true;
		die();
	}
}

void BaseTank::die(){
	this->removeFromParentAndCleanup(true);
}

bool BaseTank::isDesiredPositionValid() {
	Rect box;
	box.origin = this->getBoundingBox().origin + (_desiredPosition - this->getPosition());
	box.size = Size(TANK_CENTER_TO_SIDE*2, TANK_CENTER_TO_SIDE*2);

	// detect boundary collision
	auto vsize = Director::getInstance()->getVisibleSize();
	if (_desiredPosition.x > vsize.width - TANK_CENTER_TO_SIDE || _desiredPosition.x < TANK_CENTER_TO_SIDE
		|| _desiredPosition.y > vsize.height - TANK_CENTER_TO_SIDE || _desiredPosition.y < TANK_CENTER_TO_SIDE) {
			return false;
	}
	
	// detect brick collision
	auto bricks = GameScene::getInstance()->_mapLayer->getAllBricks();
	for (int i = 0; i < bricks.size(); i++) {
		auto brick = bricks.at(i);
		if (brick->_tile->getBoundingBox().intersectsRect(box)) {
			return false;
		}
	}
	
	// detect main tank
	if (this != GameScene::getInstance()->_mainTank) {
		if (box.intersectsRect(GameScene::getInstance()->_mainTank->getBoundingBox()))
			return false;
	}

	return true;
}
