#include "EnemyThreeTank.h"
#include "BaseTank.h"

bool EnemyThreeTank::init(){
	if (!Sprite::initWithFile("enemy3D.png")) return false;
	
	isDie(false);
	_hp = 1;
	_speed = 24;
	
	return true;
}
