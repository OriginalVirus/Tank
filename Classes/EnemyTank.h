#pragma once
#include "basetank.h"

#define EnemyMaxCount 20;

class EnemyTank :public BaseTank {
public:
	virtual bool init(std::string path);
	void ai(float);
	virtual void fire(float t);
	virtual void killed() = 0;
private:
	int _count;
	float _nextDecisionTime;	// �´ξ���ʱ��
	float _decisionTimeCounter;
};

