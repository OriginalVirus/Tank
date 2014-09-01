#include "PropBomb.h"
#include "BaseProp.h"

bool PropBomb::init() {
  if (!BaseProp::initWithFile("timer.png")) {
	  return false;
	}
	
	Vec2 v = this->randomPosition();
	this->setPosition(v);
	
	return true;
}
 
BaseProp *PropBomb::create() {
	  auto prop = new PropBomb();
	  if (prop&&prop->init()) {
		  prop->autorelease();
		  return prop;
	  }
	  CC_SAFE_DELETE(prop);
	  return nullptr;
}

void pPropBomb::effect(Ref*sender){
  // 调用敌机全消失的方法。
}
