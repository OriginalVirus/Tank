#include "EnemyOneTank.h"
#include "BaseTank.h"
#include "GameScene.h"

bool EnemyOneTank::init(){
	if (!EnemyTank::init("onetank.png")) return false;

	_hp = 1;
	_speed = 80;
	
	return true;
}

void EnemyOneTank::die() {
	killed();
	EnemyTank::die();
}

void EnemyOneTank::killed() {
	GameScene::getInstance()->_killTank1 ++;
}