#include "JoystickPad.h"

#include <functional>
using namespace std;
using namespace std::placeholders;

JoystickPad::JoystickPad() {
	this->_mainTank = NULL;
}

JoystickPad::~JoystickPad() {
	
}

JoystickPad* JoystickPad::createWithFile(std::string fileName, float padRadius) {
	auto pad = new JoystickPad();
	if (pad && pad->initWithFile(fileName, padRadius)) {
		pad->autorelease();
		return pad;
	}
	CC_SAFE_DELETE(pad);
	return NULL;
}

bool JoystickPad::initWithFile(const std::string& filename, float padRadius) {
	if (!Sprite::initWithFile(filename)) return false;

	this->_radius = padRadius;
	this->_directionVector = Vect::ZERO;	// (0 , 0)
	this->_isTouching = false;	// 初始没触摸
	this->scheduleUpdate();			// 根据触摸修改主机的方向向量

	return true;
}

// 注册触摸事件监听器
// 在过渡效果完成后调用，避免动画效果还没结束就能操作摇杆
void JoystickPad::onEnterTransitionDidFinish() {
	_listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = bind(&JoystickPad::touchBegin, this, _1, _2);
	_listener->onTouchMoved = bind(&JoystickPad::touchMoved, this, _1, _2);
	_listener->onTouchEnded = bind(&JoystickPad::touchEnded, this, _1, _2);
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(_listener, this);

	Sprite::onEnterTransitionDidFinish();	// 调用父类
}

// 在退出当前层的时候注销触摸监听器，避免出现错误
void JoystickPad::onExit() {
	Director::getInstance()->getEventDispatcher()->removeEventListener(_listener);
	Sprite::onExit();	// 调用父类onExit来退出
}

void JoystickPad::update(float dt) {
	if (this->_isTouching) {			// 如果在触摸中，实时更新主机的方向向量
		this->_mainTank->_direction = _directionVector;
		this->_mainTank->move(dt);		// 移动英雄
	}
}

bool JoystickPad::touchBegin(Touch* pt, Event* pe) {
	float distanceSQ = ccpDistanceSQ(pt->getLocation(), this->getPosition());	// 两点间距离的平方
	if (distanceSQ <= this->_radius * this->_radius) {		// 触摸点在摇杆上面
		this->updateDirectionFoTouchLocation(pt->getLocation());	// 更新英雄的方向向量
		this->_isTouching = true;	// 更新_isHeld标志为true，表示触摸到了摇杆
		return true;				// 传递触摸事件
	}
	return false;
}

// 在一次长安触摸中，它会被调用多次
void JoystickPad::touchMoved(Touch* pt, Event* pe) {
	this->updateDirectionFoTouchLocation(pt->getLocation());	// 每次触摸移动都更新一下英雄的方向向量
}

void JoystickPad::touchEnded(Touch* pt, Event* pe) {
	this->_directionVector = Vect::ZERO;		// 重载英雄方向向量
	this->_isTouching = false;					// 一次触摸结束
}

void JoystickPad::updateDirectionFoTouchLocation(Point point) {
	float radians = (point - this->getPosition()).getAngle();	// 求弧度radians
	float degrees = -1 * CC_RADIANS_TO_DEGREES(radians);		// 将弧度转换为角度

	// cocos2dx 的角度是顺时针为正方向

	if (degrees > -45.0f && degrees <= 45.0f) {				// 向右
		this->_directionVector = Vec2(1, 0);
	} else if (degrees > -135.0f && degrees <= -45.0f) {	// 向上
		this->_directionVector = Vec2(0, 1);
	} else if (degrees <= -135.0f || degrees > 135.0f) {	// 向左
		this->_directionVector = Vec2(-1, 0);
	} else if (degrees > 45.0f && degrees <= 135.0f) {		// 向下
		this->_directionVector = Vec2(0, -1);
	}

	// 执行 行走动作（按上方向键就会行走）
	this->_mainTank->_direction = this->_directionVector;
}

