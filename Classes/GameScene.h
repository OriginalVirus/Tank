#pragma once
#include "cocos2d.h"
#include "MapLayer.h"
#include "EnemyTankLayer.h"
#include "JoystickLayer.h"
USING_NS_CC;

class GameScene : public Scene {
public:
	bool init();
	~GameScene();
public:
	MainTank * _mainTank;

	MapLayer * _mapLayer;		// ��ͼ��
	Layer * _mainBulletsLayer;			// �������ӵ���
	EnemyTankLayer * _enemyTankLayer;	// �л���
	Layer * _enemyBulletsLayer;			// �л����ӵ���
	Layer * _propsLayer;		// ���߲�
	JoystickLayer * _joystickLayer;		// ҡ�˲�

	static GameScene* getInstance();
private:
	static GameScene * _instance;
	CREATE_FUNC(GameScene);
	GameScene();
};

