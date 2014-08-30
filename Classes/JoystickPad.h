#pragma once

#include "cocos2d.h"
#include "MainTank.h"
USING_NS_CC;

class JoystickPad : public Sprite {
public:
	JoystickPad();
	virtual ~JoystickPad();
	static JoystickPad* createWithFile(std::string fileName, float padRadius);
	bool initWithFile(const std::string& filename, float padRadius);

	void onEnterTransitionDidFinish();
	void onExit();

	void update(float dt);

	// 触摸响应函数
	bool touchBegin(Touch* pt, Event* pe);
	void touchMoved(Touch* pt, Event* pe);
	void touchEnded(Touch* pt, Event* pe);

	// 根据点击摇杆的位置修改英雄的_velocity方向向量(8个方向向量)
	// 参数表示在摇杆的触摸位置
	void updateDirectionFoTouchLocation(Point point);
public:
	MainTank* _mainTank;	// 坦克
	EventListenerTouchOneByOne* _listener;
	bool _isTouching;		// 代表是否触摸了，如果触摸了,为true
	float _radius;			// 摇杆的半径
	Vect _directionVector;	// 方向向量 velocity
};
