#pragma once
#include "cocos2d.h"
using namespace cocos2d;


class BaseTank :public Sprite
{
public:
	virtual bool init(); 
	bool isDie;
	int _hp;
	float _speed;
	// float _attack_value;
	int _score;
	Vect _direction;
	Vec2 _desiredPosition;	//
public:
	Action* _dieAction;
	Action* _hurtAction;
public:
	virtual void move(float t);
	virtual void fire();
	virtual void hurtWithDemage(int demage);
	virtual void die();
	virtual bool isDie(bool isDie);
};

