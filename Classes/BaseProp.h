#pragma once
#include "cocos2d.h"
USING_NS_CC;

class BaseProp :
	public Sprite
{
public:
	BaseProp(void);
	virtual ~BaseProp(void);
public:
	virtual void effect(Ref*) = 0;		// 吃到道具后产生效果
};

