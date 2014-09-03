#include "HomeBrick.h"


Rect HomeBrick::getBoundingBox() {
	Rect box;
	box.origin = Vec2(Director::getInstance()->getVisibleSize()/2 - Size(16, 0));
	box.size = Size(32, 32);
	return box;
}