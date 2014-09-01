#pragma once
#include "cocos2d.h"
#include "MapLayer.h"
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

class Brick : public Ref {
public:
	Brick(BrickType type, Vec2 tilePoint, Sprite* tile);
	virtual ~Brick(void);
public:
	BrickType _type;
	BrickSize _size;
	Vec2 _tilePoint;
	Sprite* _tile;
public:
	void removeFromMap(MapLayer *);
};
