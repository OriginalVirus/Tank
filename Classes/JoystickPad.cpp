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
	this->_isTouching = false;	// ��ʼû����
	this->scheduleUpdate();			// ���ݴ����޸������ķ�������

	return true;
}

// ע�ᴥ���¼�������
// �ڹ���Ч����ɺ���ã����⶯��Ч����û�������ܲ���ҡ��
void JoystickPad::onEnterTransitionDidFinish() {
	_listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = bind(&JoystickPad::touchBegin, this, _1, _2);
	_listener->onTouchMoved = bind(&JoystickPad::touchMoved, this, _1, _2);
	_listener->onTouchEnded = bind(&JoystickPad::touchEnded, this, _1, _2);
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(_listener, this);

	Sprite::onEnterTransitionDidFinish();	// ���ø���
}

// ���˳���ǰ���ʱ��ע��������������������ִ���
void JoystickPad::onExit() {
	Director::getInstance()->getEventDispatcher()->removeEventListener(_listener);
	Sprite::onExit();	// ���ø���onExit���˳�
}

void JoystickPad::update(float dt) {
	if (this->_isTouching) {			// ����ڴ����У�ʵʱ���������ķ�������
		this->_mainTank->_direction = _directionVector;
		this->_mainTank->move(dt);		// �ƶ�Ӣ��
	}
}

bool JoystickPad::touchBegin(Touch* pt, Event* pe) {
	float distanceSQ = ccpDistanceSQ(pt->getLocation(), this->getPosition());	// ���������ƽ��
	if (distanceSQ <= this->_radius * this->_radius) {		// ��������ҡ������
		this->updateDirectionFoTouchLocation(pt->getLocation());	// ����Ӣ�۵ķ�������
		this->_isTouching = true;	// ����_isHeld��־Ϊtrue����ʾ��������ҡ��
		return true;				// ���ݴ����¼�
	}
	return false;
}

// ��һ�γ��������У����ᱻ���ö��
void JoystickPad::touchMoved(Touch* pt, Event* pe) {
	this->updateDirectionFoTouchLocation(pt->getLocation());	// ÿ�δ����ƶ�������һ��Ӣ�۵ķ�������
}

void JoystickPad::touchEnded(Touch* pt, Event* pe) {
	this->_directionVector = Vect::ZERO;		// ����Ӣ�۷�������
	this->_isTouching = false;					// һ�δ�������
}

void JoystickPad::updateDirectionFoTouchLocation(Point point) {
	float radians = (point - this->getPosition()).getAngle();	// �󻡶�radians
	float degrees = -1 * CC_RADIANS_TO_DEGREES(radians);		// ������ת��Ϊ�Ƕ�

	// cocos2dx �ĽǶ���˳ʱ��Ϊ������

	if (degrees > -45.0f && degrees <= 45.0f) {				// ����
		this->_directionVector = Vec2(1, 0);
	} else if (degrees > -135.0f && degrees <= -45.0f) {	// ����
		this->_directionVector = Vec2(0, 1);
	} else if (degrees <= -135.0f || degrees > 135.0f) {	// ����
		this->_directionVector = Vec2(-1, 0);
	} else if (degrees > 45.0f && degrees <= 135.0f) {		// ����
		this->_directionVector = Vec2(0, -1);
	}

	// ִ�� ���߶��������Ϸ�����ͻ����ߣ�
	this->_mainTank->_direction = this->_directionVector;
}

