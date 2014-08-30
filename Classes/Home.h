#pragma once
#include "cocos2d.h"
#include "Brick.h"
USING_NS_CC;

class Home :
	public Node
{
public:
	Home(void);
	virtual ~Home(void);
public:
	void strengthen();	// 加强成金砖围墙
private:
	void recover();		// 回复到普通围墙
private:
	Vector<Brick*> _bricks;
};

