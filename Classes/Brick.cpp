#include "Brick.h"


Brick::Brick(BrickType type, Vec2 tilePoint, Sprite* tile) {
	this->_type = type;
	this->_tilePoint = tilePoint;
	this->_tile = tile;
}

Brick::~Brick(void) {

}

void Brick::removeFromMap(MapLayer * maplayer) {
	maplayer->removeBrick(this);
}
