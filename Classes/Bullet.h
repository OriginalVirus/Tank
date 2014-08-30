#pragma once
#include "cocos2d.h"
#include "MapLayer.h"
USING_NS_CC;

typedef enum {
	NORMAL = 0,
	GOLD	// gold bullet
} BulletType;

class Bullet :
	public Sprite
{
public:
	Bullet(void);
	virtual ~Bullet(void);
public:
	BulletType _type;	// NORMAL
	float _speed;
	Action* _dieAction;
	// Action* _moveAction;
public:
	void die();
	void move();
};

