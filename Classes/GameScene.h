#pragma once
#include "cocos2d.h"
#include "MapLayer.h"
#include "EnemyTankLayer.h"
USING_NS_CC;

class GameScene :
	public Scene
{
public:
	GameScene(void);
	virtual ~GameScene(void);
public:
	MapLayer * _mapLayer;		// ��ͼ��
	Layer * _mainBulletsLayer;			// �������ӵ���
	EnemyTankLayer * _enemyTankLayer;	// �л���
	Layer * _enemyBulletsLayer;			// �л����ӵ���
	Layer * _propsLayer;		// ���߲�


};

