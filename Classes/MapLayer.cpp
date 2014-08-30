#include "MapLayer.h"
#include "HomeBrick.h"


MapLayer::MapLayer(void)
{
}

MapLayer::~MapLayer(void)
{
	CC_SAFE_RELEASE(_home);
	CC_SAFE_RELEASE(_mainTank);
}

bool MapLayer::init() {
	if (!Layer::init()) return false;

	_home = new Home();

	_map = TMXTiledMap::create("map.tmx");
	this->addChild(_map);

	_brickLayer = _map->getLayer("bricksLayer");

	for (int i=0; i < _map->getMapSize().height; i++) {
		for (int j = 0; j < _map->getMapSize().width; j++) {
			auto tile = _brickLayer->getTileAt(Vec2(i, j));
			if (tile != NULL) {
				auto gid = _brickLayer->getTileGIDAt(Vec2(i, j));
				Brick* brick = NULL;
				if (gid == 113) {
					brick = new Brick(BrickType::NORMAL, Vec2(i, j), tile);
				} else if (gid == 114) {
					brick = new Brick(BrickType::GOLD, Vec2(i, j), tile);
				} else if (gid == 118) {
					auto homeBrick = new Brick(BrickType::HOME, Vec2(i, j), tile);
					_home->_homeBrick = homeBrick;
				}
			}
		}
	}

	return true;
}

void MapLayer::removeBrick(Brick * brick) {
	_bricks.eraseObject(brick);
	_brickLayer->removeTileAt(brick->_tilePoint);
}
