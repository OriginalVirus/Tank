#pragma once
#include "cocos2d.h"
#include "Home.h"
#include "MainTank.h"
USING_NS_CC;

class MapLayer : public Layer {
public:
	MapLayer(void);
	virtual ~MapLayer(void);
	CREATE_FUNC(MapLayer);
	bool init();
public:
	void removeBrick(Brick *);
	Vector<Brick *> getAllBricks() {return _bricks;}
	Home* getHome() {return _home;}
	MainTank * getMainTank() {return _mainTank;}
private:
	Vector<Brick *> _bricks;
	Home* _home;
	MainTank* _mainTank;
	TMXTiledMap* _map;
	TMXLayer* _brickLayer;
};

