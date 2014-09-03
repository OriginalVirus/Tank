#pragma once

#include "cocos2d.h"
#include "HomeBrick.h"
#include "MainTank.h"
#include "Brick.h"
#include "Home.h"
USING_NS_CC;

class Bullet;

class MapLayer : public Layer {
public:
	MapLayer(void);
	virtual ~MapLayer(void);
	static MapLayer* create(MainTank* tank);
	bool init(MainTank* tank);
public:
	void removeBrick(Brick *);
	Vector<Brick *> getAllBricks() {return _bricks;}
	Home* getHome() {return _home;}
	MainTank * getMainTank() {return _mainTank;}
public:
	Vector<Brick *> _bricks;
	Home* _home;
	HomeBrick* _homeBrick;
	CC_SYNTHESIZE_RETAIN(MainTank*, _mainTank, Maintank);
	Bullet* _mainBullet;
	TMXTiledMap* _map;
	TMXLayer* _brickLayer;
};
