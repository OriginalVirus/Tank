#pragma once

#include "cocos2d.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "MainTank.h"
#include "Brick.h"
USING_NS_CC;

class CollisionDelegate		// 碰撞检测的代理类
{
public:
	// 敌机与我方子弹
	virtual void detectOfEnemiesAndOurBullets(Vector<EnemyTank *> enemies, Vector<Bullet *> ourBullets) = 0;
	
	// 主机与敌方子弹
	virtual void detectOfMainAndEnemyBullets(MainTank * mainTank, Vector<Bullet *> enemyBullets) = 0;

	// 主机子弹和敌机子弹
	virtual void detectOfEnemyBulletsAndOurBullets(Vector<Bullet *> enemyBullets, Vector<Bullet *> ourBullets) = 0;

	// 主机子弹和砖
	virtual void detectOfOurBulletsAndBricks(Vector<Bullet *> ourBullets, Vector<Brick *> bricks) = 0;

	// 敌方子弹和砖
	virtual void detectOfEnemiesAndOurBullets(Vector<Bullet *> enemyBullets, Vector<Brick *> bricks) = 0;

	// 敌机与砖的碰撞
	virtual void detectOfEnemiesWithBricks(Vector<EnemyTank*> enemies, Vector<Brick *> bricks) = 0;
};

