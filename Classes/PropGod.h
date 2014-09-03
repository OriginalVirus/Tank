#ifndef __PROPGOD_
#define __PROPGOD_
#include "cocos2d.h"
#include "BaseProp.h"
using namespace cocos2d;

class PropGod :public BaseProp{
public: 
	virtual bool init();
	static BaseProp * create();
	virtual void effect(Ref*sender);
	virtual void scheduleToDisappear();
};

#endif
