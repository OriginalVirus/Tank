#ifndef __PROPBOMB_
#define __PROPBOMB_
#include "cocos2d.h"
using namespace cocos2d;

class PropBomb :public BaseProp{
public:
	virtual bool init();
	virtual BaseProp * create();
	virtual void effect(Ref*sender);
};

#endif
