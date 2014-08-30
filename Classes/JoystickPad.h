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

	// ������Ӧ����
	bool touchBegin(Touch* pt, Event* pe);
	void touchMoved(Touch* pt, Event* pe);
	void touchEnded(Touch* pt, Event* pe);

	// ���ݵ��ҡ�˵�λ���޸�Ӣ�۵�_velocity��������(8����������)
	// ������ʾ��ҡ�˵Ĵ���λ��
	void updateDirectionFoTouchLocation(Point point);
public:
	MainTank* _mainTank;	// ̹��
	EventListenerTouchOneByOne* _listener;
	bool _isTouching;		// �����Ƿ����ˣ����������,Ϊtrue
	float _radius;			// ҡ�˵İ뾶
	Vect _directionVector;	// �������� velocity
};
