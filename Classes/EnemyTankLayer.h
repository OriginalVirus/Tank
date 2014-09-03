#pragma once
#include "cocos2d.h"
USING_NS_CC;

class EnemyTankLayer :public Layer {
public:
	virtual bool init();
	CREATE_FUNC(EnemyTankLayer);
	EnemyTankLayer(void){}
	virtual ~EnemyTankLayer(void){}
public:
	int _enemyCurrenCount;
	int _enemy1RemainCount;	// 还可以产生敌机1类型的数量
	int _enemy2RemainCount;	// 
	int _enemy3RemainCount;
	void addEnemy1Tank(float t);
	void addEnemy2Tank(float t);
	void addEnemy3Tank(float t);
	Size _size;
};
