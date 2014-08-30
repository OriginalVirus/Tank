#include "GameScene.h"

GameScene* GameScene::_instance = NULL;

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

	_propsLayer = Layer::create();
	_propsLayer->retain();
	this->addChild(_propsLayer);

	_joystickLayer = JoystickLayer::create(_mainTank);
	_joystickLayer->retain();
	this->addChild(_joystickLayer);
	
	return true;
}

GameScene* GameScene::getInstance() {
	if (_instance == NULL) {
		_instance = GameScene::create();
	}
	return _instance;
}