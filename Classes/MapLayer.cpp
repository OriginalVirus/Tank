#include "MapLayer.h"
// #include "HomeBrick.h"
#include "Bullet.h"

MapLayer::MapLayer(void)
{
}

MapLayer::~MapLayer(void)
{/*
	CC_SAFE_RELEASE(_home);
	CC_SAFE_RELEASE(_mainTank); */
}

MapLayer* MapLayer::create(MainTank* tank) {
	auto ml = new MapLayer();
	if (ml && ml->init(tank)) {
		ml->autorelease();
		return ml;
	}
	CC_SAFE_DELETE(ml);
	return NULL;
}

bool MapLayer::init(MainTank* tank) {
	if (!Layer::init()) return false;

	_home = new Home();
	_home->autorelease();
	_home->retain();
	_home->_bricks = new Vector<Brick*>();
	this->addChild(_home);

	_homeBrick = new HomeBrick();

	_map = TMXTiledMap::create("mapx.tmx");
	this->addChild(_map);

	_brickLayer = _map->getLayer("bricksLayer");

	for (int i=0; i < _map->getMapSize().width; i++) {
		for (int j=0; j < _map->getMapSize().height; j++) {
			auto tile = _brickLayer->getTileAt(Vec2(i, j));
			if (tile != NULL) {
				auto gid = _brickLayer->getTileGIDAt(Vec2(i, j));
				Brick* brick = NULL;
				if (gid == 1) {
					brick = new Brick(BrickType::kNORMAL, Vec2(i, j), tile);
					_bricks.pushBack(brick);
					if ((i==13 && (j==19 || j==18 || j==17)) || 
						(j==17 && (i==14 || i==15)) || 
						(i==16 && (j==19 || j==18 || j==17))) {
						_home->_bricks->pushBack(brick);
					} 
				} else if (gid == 3) {
					brick = new Brick(BrickType::kGOLD, Vec2(i, j), tile);
					_bricks.pushBack(brick);
				} else if (gid == 11) {
					_homeBrick->_brick11 = new Brick(BrickType::kHOME, Vec2(i, j), tile);
				} else if (gid == 12) {
					_homeBrick->_brick12 = new Brick(BrickType::kHOME, Vec2(i, j), tile);
				} else if (gid == 25) {
					_homeBrick->_brick25 = new Brick(BrickType::kHOME, Vec2(i, j), tile);
				} else if (gid == 26) {
					_homeBrick->_brick26 = new Brick(BrickType::kHOME, Vec2(i, j), tile);
				}
			}
		}
	}
	_home->_homeBrick = _homeBrick;

	// Ö÷Ì¹¿Ë
	_mainTank = tank;
	// relase retain
	Vec2 bornPosition(11*16, 16);
	_mainTank->setPosition(bornPosition);
	this->addChild(_mainTank);

	// ×Óµ¯
	_mainBullet = Bullet::create(_mainTank, 180.0f);
	_mainBullet->retain();
	_mainBullet->setVisible(false);
	_mainBullet->setPosition(-100, -100);
	this->addChild(_mainBullet);

	return true;
}

void MapLayer::removeBrick(Brick * brick) {
	_bricks.eraseObject(brick);
	_brickLayer->removeTileAt(brick->_tilePoint);
	// release
}
