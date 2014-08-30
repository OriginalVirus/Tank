#pragma once
#include "cocos2d.h"
#include "Home.h"
#include "MainTank.h"
USING_NS_CC;

class MapLayer :
	public Layer
{
public:
	MapLayer(void);
	virtual ~MapLayer(void);
	CREATE_FUNC(MapLayer);
public:
	void removeBrick(Brick *);
	Vector<Brick *> getAllBricks();
	Home* getHome();
	MainTank * getMainTank();
private:
	Vector<Brick *> _bricks;
	Home* _home;
	MainTank* _mainTank;
};

