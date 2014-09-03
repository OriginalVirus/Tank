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
		/*
		this->setTexture("enemy2U.png");
		if (_direction == Vect(0,-1))
		{
		this->setRotation(180);
		}else if (_direction == Vect(1,0))
		{
		this->setRotation(90);
		}else 
		{
		this->setRotation(270);
		}*/
	} else if (_hp == 1) {
		changeColor(1);
		/*
		this->setTexture("enemy1U.png");
		if (_direction == Vect(0,-1))
		{
		this->setRotation(180);
		}else if (_direction == Vect(1,0))
		{
		this->setRotation(90);
		}else 
		{
		this->setRotation(270);
		}*/
	} else {
		this->_hp == 0;
		this->die();
	}
}

void EnemyTwoTank::die() {
	GameScene::getInstance()->_killTank2 ++;
}

void EnemyTwoTank::changeColor(int index) {
	if (index == 0) {
		this->setTexture("enemy1U.png");
	} else {
		this->setTexture("enemy2U.png");
	}
}

void EnemyTwoTank::killed() {
	GameScene::getInstance()->_killTank1 += 1;
}