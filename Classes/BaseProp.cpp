#include "BaseProp.h"


Vec2  BaseProp::randomPosition(){
	Size size = Director::getInstance()->getVisibleSize();
	float x = CCRANDOM_0_1()* size.width;
	float y = CCRANDOM_0_1()* size.height;
	return  Vec2(x,y);
}

bool BaseProp::initWithFile(std::string name ){
	if (!Sprite::initWithFile(name)) {
		return false;
	}
	return true;
}
