#pragma once
#include "cocos2d.h"
USING_NS_CC;

typedef enum {
	NORMAL = 0,
	GOLD,
	HOME
} BrickType;

typedef enum {
	SMALL = 0,
	BIG
} BrickSize;

class Brick :
	public Sprite
{
public:
	Brick(void);
	virtual ~Brick(void);
public:
	BrickType _type;
	int _hp;
	BrickSize _size;
};

