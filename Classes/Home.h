#pragma once
#include "cocos2d.h"
#include "HomeBrick.h"
USING_NS_CC;

class Home : public Node {
public:
	void strengthen();		// ��ǿ�ɽ�שΧǽ
public:
	void recover(float);	// �ظ�����ͨΧǽ
public:
	Vector<Brick*> *_bricks;
	HomeBrick* _homeBrick;
};

