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
	void strengthen();	// ��ǿ�ɽ�שΧǽ
private:
	void recover();		// �ظ�����ͨΧǽ
private:
	Vector<Brick*> _bricks;
};

