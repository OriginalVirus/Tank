#include "EnemyTwoTank.h"
#include "BaseTank.h"
bool EnemyTwoTank::init(){
	if (!Sprite::initWithFile("enemy2D.png")) return false;
		
	_hp = 3;
	_speed = 8;
	
	return true;
}
