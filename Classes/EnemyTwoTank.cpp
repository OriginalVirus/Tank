#include "EnemyTwoTank.h"
#include "BaseTank.h"
#include "GameScene.h"

bool EnemyTwoTank::init(){
	if (!EnemyTank::init("twotank.png")) return false;

	_hp = 3;
	_speed = 80;
	
	return true;
}

void EnemyTwoTank::hurtWithDemage(int demage){

	this->_hp -= demage;
	if (_hp == 2)
	{
		changeColor(0);
	} else if (_hp == 1) {
		changeColor(1);
	} else {
		this->_hp == 0;
		this->die();
	}
}

void EnemyTwoTank::die() {
	killed();
	EnemyTank::die();
}

void EnemyTwoTank::changeColor(int index) {
	if (index == 0) {
		this->setTexture("enemy1U.png");
	} else {
		this->setTexture("enemy2U.png");
	}
}

void EnemyTwoTank::killed() {
	GameScene::getInstance()->_killTank2 ++;
}