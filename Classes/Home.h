#pragma once
#include "cocos2d.h"
#include "HomeBrick.h"
USING_NS_CC;

class Home : public Node {
public:
	void strengthen();		// 加强成金砖围墙
public:
	void recover(float);	// 回复到普通围墙
public:
	Vector<Brick*> *_bricks;
	HomeBrick* _homeBrick;
};

