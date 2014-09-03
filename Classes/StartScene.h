#pragma once

#include "cocos2d.h"
USING_NS_CC;

class StartScene : public Scene {
public:
	CREATE_FUNC(StartScene);
	bool init();
private:
	void startGame(Ref*);
	virtual void onEnter();
	void loadingRes();
};
