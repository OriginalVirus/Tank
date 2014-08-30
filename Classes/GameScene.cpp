#include "GameScene.h"

GameScene::GameScene() {
	srand(time(0));
}

GameScene::~GameScene() {

};

bool GameScene::init(void) {
	if (!Scene::init()) return false;

	_mainTank = MainTank::create();
	_mainTank->retain();

	_mapLayer = MapLayer::create();
	_mapLayer->retain();
	this->addChild(_mapLayer);

	_mainBulletsLayer = Layer::create();
	_mainBulletsLayer->retain();
	this->addChild(_mainBulletsLayer);

	_enemyTankLayer = EnemyTankLayer::create();
	_enemyTankLayer->retain();
	this->addChild(_enemyTankLayer);

	_enemyBulletsLayer = Layer::create();
	_enemyBulletsLayer->retain();
	this->addChild(_enemyBulletsLayer);
}
