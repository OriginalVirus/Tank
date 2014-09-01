#include "propGod.h"
#include "BaseProp.h"
#include "Home.h"

bool PropGod::init(){
	if (!BaseProp::initWithFile("star.png"))
	{
		return false;
	}
	Vec2 v = this->randomPosition();
	this->setPosition(v);


	return true;
}

BaseProp * PropGod::create(){
	auto prop = new PropGod();
	if (prop&&prop->init())
	{
		prop->autorelease();
		return prop;
	}
	CC_SAFE_DELETE(prop);
	return nullptr;
}

 void PropGod::effect(Ref*sender){
	 //调用HOME 加强金钟罩的方法。
 }
