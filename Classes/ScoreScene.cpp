#include "ScoreScene.h"
#include "EnemyTank.h"

Scene * ScoreScene::createScene(int score1,int score2,int score3,int opp){
	auto s = Scene::create();
	auto l = ScoreScene::create(score1, score2, score3, opp);
	s->addChild(l);
	return s;
}

ScoreScene * ScoreScene::create(int tank1,int tank2,int tank3,int opp){
	auto score = new ScoreScene();
	if (score&&score->init(tank1, tank2, tank3, opp))
	{
		score->autorelease();
		return score;
	}
	CC_SAFE_DELETE(score);
	return NULL;
}

bool ScoreScene::init(int tank1,int tank2,int tank3,int opp){
	if (!Layer::init())
	{
		return false;
	}

	Label * _win = Label::createWithSystemFont(opp==0?"YOU LOSE":"YOU WIN", "Arial", 45);

	Label * _tank1Score = Label::createWithSystemFont(StringUtils::format(" X %d = %d", tank1, tank1*TANK1SCORE), "Arial", 20);
	Label * _tank2Score = Label::createWithSystemFont(StringUtils::format(" X %d = %d", tank2, tank2*TANK2SCORE), "Arial", 20);
	Label * _tank3Score = Label::createWithSystemFont(StringUtils::format(" X %d = %d", tank3, tank3*TANK3SCORE), "Arial", 20);

	//=======================================================
	auto sp1 = Sprite::create("enemy1U.png");
	auto sp2 = Sprite::create("enemy2U.png");
	auto sp3 = Sprite::create("enemy3U.png");

	sp1->setPosition(TANK1LABEL_POS - Vec2(100, 0));
	sp2->setPosition(TANK2LABEL_POS - Vec2(100, 0));
	sp3->setPosition(TANK3LABEL_POS - Vec2(100, 0));

	this->addChild(sp1);
	this->addChild(sp2);
	this->addChild(sp3);

	_win->setPosition(Director::getInstance()->getVisibleSize()/2 + Size(0, 100));
	_tank1Score->setPosition(TANK1LABEL_POS);
	_tank1Score->setAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);
	_tank2Score->setPosition(TANK2LABEL_POS);
	_tank2Score->setAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);
	_tank3Score->setPosition(TANK3LABEL_POS);
	_tank3Score->setAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);

	this->addChild(_win);
	this->addChild(_tank1Score);
	this->addChild(_tank2Score);
	this->addChild(_tank3Score);
	//====================================================

	auto item = MenuItemImage::create("CloseNormal.png","CloseSelected.png", 
		std::bind(&ScoreScene::quitGame, this, std::placeholders::_1));
	auto menu = Menu::create(item, NULL);
	menu->setPosition(QUITBTN_POS);
	this->addChild(menu);

	return true;
}

void ScoreScene::quitGame(Ref * sender){
	Director::getInstance()->end();
}
