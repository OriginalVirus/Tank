#ifndef __PROPBOMB_
#define __PROPBOMB_
#include "cocos2d.h"
#include "BaseProp.h"
using namespace cocos2d;

class PropBomb :public BaseProp {
public:
	virtual bool init();
	static BaseProp * create();
	virtual void effect(Ref*sender);
	virtual void scheduleToDisappear();
};

#endif
