#ifndef __PROPGOD_
#define __PROPGOD_
#include "cocos2d.h"
#include "BaseProp.h"
using namespace cocos2d;

class PropGod :public BaseProp{
public: 
	virtual bool init();
	virtual BaseProp * create();
	virtual void effect(Ref*sender);
};

#endif
