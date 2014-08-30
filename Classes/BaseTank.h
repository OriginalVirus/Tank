#pragma once

#include "cocos2d.h"
USING_NS_CC;

class BaseTank :
	public Sprite
{
public:
	BaseTank(void);
	virtual ~BaseTank(void);
public:
	// int _state;
	int _hp;
	float _speed;
	bool _firedBulletDispeared;
	// float _attack_value;
	int _score;
	Vect _direction;
	Vec2 _desiredPosition;	//
public:
	Action* _dieAction;
	Action* _hurtAction;
	Action* _idleAction;	// kongxian donghua
public:
	void idle();
	void move(float dt);
	void fire();
	void hurtWithDemage(int demage);
	void die();
};

