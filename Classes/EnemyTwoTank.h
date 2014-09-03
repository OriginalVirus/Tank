#pragma once;
#include "cocos2d.h"
#include "EnemyTank.h"
using namespace cocos2d;

// ��ɫ��̹��
class EnemyTwoTank:public EnemyTank{
public:
	virtual bool init();
	CREATE_FUNC(EnemyTwoTank);
	void hurtWithDemage(int demage);
	void die();
	void killed();
public:
	void changeColor(int index);
};