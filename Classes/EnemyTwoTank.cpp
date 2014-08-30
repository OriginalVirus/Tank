#include "EnemyTwoTank.h"
#include "BaseTank.h"
bool EnemyTwoTank::init(){
	if (!Sprite::initWithFile("enemy2D.png"))
	{
		return false;
	}
	isDie(false);
	_hp = 3;
	_speed = 50;
	return true;
}