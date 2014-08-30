#include "BaseBrick.h"


<<<<<<< HEAD
Brick::Brick(BrickType type, Vec2 tilePoint, Sprite* tile) {
	this->_type = type;
	this->_tilePoint = tilePoint;
	this->_tile = tile;
=======
BaseBrick::BaseBrick(void)
{
>>>>>>> b28289224eaae95c46d29de571362caf58b7c3f7
}

Brick::~Brick(void) {

<<<<<<< HEAD
}

void Brick::removeFromMap(MapLayer * maplayer) {
	maplayer->removeBrick(this);
=======
BaseBrick::~BaseBrick(void)
{
>>>>>>> b28289224eaae95c46d29de571362caf58b7c3f7
}
