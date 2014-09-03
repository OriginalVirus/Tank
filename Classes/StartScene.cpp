#include "StartScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool StartScene::init() {
	if (!Scene::init()) return false;

	auto bg1 = Sprite::create("BattleCity.png");
	bg1->setPosition(Director::getInstance()->getVisibleSize()/2 + Size(0, 40));
	
	//开始
	auto item1 = MenuItemFont::create("Start Fight",CC_CALLBACK_1(StartScene::startGame,this));
	auto menu = Menu::create(item1,NULL);
	menu->alignItemsHorizontally();
	menu->setPositionY(menu->getPositionY() - 40);

	auto layer = Layer::create();
	layer->addChild(bg1);
	layer->addChild(menu);
	this->addChild(layer);

	return true;
}

void StartScene::startGame(Ref* sender) {
	//场景转换
	auto pscene = TransitionFlipAngular::create(1.5f, GameScene::getInstance());
	//跳跃式动画
	Director::getInstance()->replaceScene(pscene);
}

void StartScene::onEnter() {
	Scene::onEnter();
	loadingRes();
	SimpleAudioEngine::getInstance()->playEffect("start.wav");
}

void StartScene::loadingRes() {
	auto audio = SimpleAudioEngine::getInstance();
	audio->preloadEffect("start.wav");
	audio->preloadEffect("respawn.wav");
	audio->preloadEffect("fire.wav");
	audio->preloadEffect("hurt.wav");
	audio->preloadEffect("boom.wav");
	
}