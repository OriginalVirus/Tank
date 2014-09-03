#pragma once
#include "cocos2d.h"
USING_NS_CC;

#define TANK1SCORE 100
#define TANK2SCORE 200
#define TANK3SCORE 300

#define TANK1LABEL_POS Vec2(240, 210)
#define TANK2LABEL_POS Vec2(240, 160)
#define TANK3LABEL_POS Vec2(240, 110)
#define QUITBTN_POS Vec2(240, 50)

class ScoreScene:public Layer {
public:
	virtual bool init(int score1,int score2,int score3,int opp);
	//CREATE_FUNC(ScoreScene);
	static ScoreScene * create(int score1,int score2,int score3,int opp);
	static Scene * createScene(int score1,int score2,int score3,int opp);
	void quitGame(Ref * sender);
};

