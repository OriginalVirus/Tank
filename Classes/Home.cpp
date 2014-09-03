#include "Home.h"
#include "GameScene.h"

#define GODTIME 10

void Home::strengthen()	// 加强成金砖围墙
{
	for (auto it = _bricks->begin();it != _bricks->end();it++) {
		if ((*it)->_tile == NULL) continue;
		auto maplayer =  GameScene::getInstance()->_mapLayer;
		
		(*it)->_type =  BrickType::kGOLD;		// 类型
		maplayer->_brickLayer->removeTileAt((*it)->_tilePoint);
		maplayer->_brickLayer->setTileGID(3, (*it)->_tilePoint);	// 
		auto brick = new Brick((*it)->_type, (*it)->_tilePoint, maplayer->_brickLayer->getTileAt((*it)->_tilePoint));
		
		maplayer->_bricks.eraseObject(*it);
		maplayer->_bricks.pushBack(brick);

		(*it)->release();
		*it = brick;
	}
	this->scheduleOnce(schedule_selector(Home::recover), GODTIME);
}

void Home::recover(float t) {
	for (auto it = _bricks->begin();it != _bricks->end();it++) {
		if ((*it)->_tile == NULL) continue;
		auto maplayer =  GameScene::getInstance()->_mapLayer;
		(*it)->_type =  BrickType::kNORMAL;

		maplayer->_brickLayer->removeTileAt((*it)->_tilePoint);
		maplayer->_brickLayer->setTileGID(1, (*it)->_tilePoint);
		auto brick = new Brick((*it)->_type, (*it)->_tilePoint, maplayer->_brickLayer->getTileAt((*it)->_tilePoint));
		
		maplayer->_bricks.eraseObject(*it);
		maplayer->_bricks.pushBack(brick);
		(*it)->release();
		*it = brick;
	}
}