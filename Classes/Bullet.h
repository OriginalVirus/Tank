#pragma once

#include "cocos2d.h"
#include "MapLayer.h"
#include "BaseTank.h"
USING_NS_CC;

typedef enum {
	NORMAL = 0,
	GOLD   = 1// gold bullet
} BulletType;

class Bullet :public Sprite {
protected:
	virtual void dieoneAction();  //子弹和子弹碰撞
	virtual void dietwoAction();   //子弹和其他东西碰撞
public:
	BaseTank* _tank;
	int demage;
	BulletType _type;	// NORMAL
	float _speed;
	 //死亡动画
	// Action* _moveAction;
public:
	virtual bool initWithFile(BaseTank * tank,float speed);
	static Bullet * create(BaseTank * tank,float speed);
	//死亡方法
	void die();  
	//移动方法
	void move();	
};
