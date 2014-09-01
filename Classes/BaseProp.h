#pragma once
#include "cocos2d.h"
USING_NS_CC;

class BaseProp :public Sprite {
protected :
	virtual Vec2 randomPosition();
	virtual bool initWithFile(std::string name );
public:
	virtual void effect(Ref*sender)= 0;// 吃到道具后产生效果
};
