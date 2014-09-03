#pragma once
#include "cocos2d.h"
USING_NS_CC;

class MapLayer;

typedef enum {
	kNORMAL = 0,
	kGOLD,
	kHOME
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
