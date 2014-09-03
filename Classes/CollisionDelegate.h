#pragma once

#include "cocos2d.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "MainTank.h"
#include "Brick.h"
#include "BaseProp.h"
USING_NS_CC;

class CollisionDelegate		// 碰撞检测的代理类
{
public:
	
	// 敌机与我方子弹
	virtual void detectOfEnemiesAndOurBullets(Vector<Node*> enemies, Bullet * ourBullets) ;
	
	// 主机与敌方子弹
	void detectOfMainAndEnemyBullets(MainTank *maintank, Vector<Node *> enemyBullets) ;	

	// 主机子弹和敌机子弹
	void detectOfMainBulletAndEnemyBullets(Bullet * mainBullet, Vector<Node *> enemyBullets);

	// 主机子弹和砖
	void detectOfMainBulletAndBricks(Bullet * mainBullet, Vector<Brick *> bricks);

	// 敌方子弹和砖
	void detectOfEnemyBulletsAndBricks(Vector<Node *> enemyBullets, Vector<Brick *> bricks);

	// 主机与道具的碰撞
	void detectOfProbAndMainTank(MainTank * mainTank,Vector<Node *>probs);

	// 子弹与家墙的碰撞
	void detectOfBulletsAndHomeBrick(Vector<Node *> enemyBullets, Bullet * mainBullet, HomeBrick * homeBrick);
};

