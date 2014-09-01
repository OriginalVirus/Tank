#include "EnemyOneTank.h"
#include "BaseTank.h"

bool EnemyOneTank::init(){
	if (!Sprite::initWithFile("enemy1D.png")) return false;
	
	_hp = 1;
	_speed = 8;
	
	return true;
}
