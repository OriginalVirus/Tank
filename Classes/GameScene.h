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

	MapLayer * _mapLayer;		// 地图层
	Layer * _mainBulletsLayer;			// 主机的子弹层
	EnemyTankLayer * _enemyTankLayer;	// 敌机层
	Layer * _enemyBulletsLayer;			// 敌机的子弹层
	Layer * _propsLayer;		// 道具层
	JoystickLayer * _joystickLayer;		// 摇杆层

	static GameScene* getInstance();
private:
	static GameScene * _instance;
	CREATE_FUNC(GameScene);
	GameScene();
};

