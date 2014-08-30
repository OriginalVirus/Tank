#pragma once

#include "cocos2d.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "MainTank.h"
#include "Brick.h"
USING_NS_CC;

class CollisionDelegate		// ��ײ���Ĵ�����
{
public:
	// �л����ҷ��ӵ�
	virtual void detectOfEnemiesAndOurBullets(Vector<EnemyTank *> enemies, Vector<Bullet *> ourBullets) = 0;
	
	// ������з��ӵ�
	virtual void detectOfMainAndEnemyBullets(MainTank * mainTank, Vector<Bullet *> enemyBullets) = 0;

	// �����ӵ��͵л��ӵ�
	virtual void detectOfEnemyBulletsAndOurBullets(Vector<Bullet *> enemyBullets, Vector<Bullet *> ourBullets) = 0;

	// �����ӵ���ש
	virtual void detectOfOurBulletsAndBricks(Vector<Bullet *> ourBullets, Vector<Brick *> bricks) = 0;

	// �з��ӵ���ש
	virtual void detectOfEnemiesAndOurBullets(Vector<Bullet *> enemyBullets, Vector<Brick *> bricks) = 0;

	// �л���ש����ײ
	virtual void detectOfEnemiesWithBricks(Vector<EnemyTank*> enemies, Vector<Brick *> bricks) = 0;
};

