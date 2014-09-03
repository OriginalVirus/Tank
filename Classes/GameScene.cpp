#include "GameScene.h"
#include "ScoreScene.h"
#include "AppMacros.h"

GameScene* GameScene::_instance = NULL;

GameScene::GameScene() {
	srand(time(0));
	_killTank1 = 0;
	_killTank2 = 0;
	_killTank3 = 0;
}

GameScene::~GameScene() {

};

bool GameScene::init(void) {
	if (!Scene::init()) return false;

	_mainTank = MainTank::create();
	_mainTank->retain();
	
	_mapLayer = MapLayer::create(_mainTank);
	_mapLayer->retain();
	this->addChild(_mapLayer);

	/*
	_mainBulletsLayer = Layer::create();
	_mainBulletsLayer->retain();
	this->addChild(_mainBulletsLayer);
	*/

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

	this->schedule(schedule_selector(GameScene::collisionDetection), 1/60.0f);
	
	lifeCount = 4;

	return true;
}

GameScene* GameScene::getInstance() {
	if (_instance == NULL) {
		_instance = GameScene::create();
	}
	return _instance;
}

void GameScene::collisionDetection(float t) {
	auto enemies = _enemyTankLayer->getChildren();

	// m_delegate.detectOfEnemiesWithBricks(enemies, bricks);
	m_delegate.detectOfEnemyBulletsAndBricks(_enemyBulletsLayer->getChildren(), _mapLayer->getAllBricks());
	m_delegate.detectOfMainBulletAndBricks(_mapLayer->_mainBullet, _mapLayer->getAllBricks());
	m_delegate.detectOfMainBulletAndEnemyBullets(_mapLayer->_mainBullet, _enemyBulletsLayer->getChildren());
	m_delegate.detectOfMainAndEnemyBullets(_mainTank, _enemyBulletsLayer->getChildren());
	m_delegate.detectOfEnemiesAndOurBullets(_enemyTankLayer->getChildren(),_mapLayer->_mainBullet);
	m_delegate.detectOfProbAndMainTank(_mainTank, _propsLayer->getChildren());
	m_delegate.detectOfBulletsAndHomeBrick(_enemyBulletsLayer->getChildren(), _mapLayer->_mainBullet, _mapLayer->_homeBrick);
}

void GameScene::GameOver(){
	_mainTank->setVisible(false);
	this->unscheduleAllSelectors();	// 取消所有定时器
	this->stopAllTank();
	
	auto over = Sprite::create("over.png");
	over->setPosition(Director::getInstance()->getVisibleSize()/2 + Size(0, 400));
	auto gameoverlayer = Layer::create();
	gameoverlayer->addChild(over);
	this->addChild(gameoverlayer);

	auto move = MoveBy::create(2,Vec2(0,-400));
	auto delay = DelayTime::create(1);
	auto cal = CallFunc::create([=]() {
		int win = (_killTank1 + _killTank2 + _killTank3 == TANKALLNO) ? 1 : 0;
		auto score = ScoreScene::createScene(this->_killTank1, this->_killTank2,this-> _killTank3, win);
		Director::getInstance()->replaceScene(score);
	});
	over->runAction(Sequence::create(move, delay, cal, NULL));
}

void GameScene::stopAllTank() {
	for (auto tank : _enemyTankLayer->getChildren()) {
		tank->unschedule(schedule_selector(EnemyTank::move));	// 终止移动
	}
}