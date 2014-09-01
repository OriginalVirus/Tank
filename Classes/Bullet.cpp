#include "Bullet.h"
#include "math.h"

 bool Bullet:: initWithFile(std::string name ,BaseTank * tank,float speed){
	 if (!Sprite::initWithFile(name))
	 {
		 return false;
	 }
	 this->_speed = speed;
	 Vect v = tank->_direction;
	 Size size = Director::getInstance()->getVisibleSize();
	 float x = size.width - tank->getPositionX();
	 float y = size.height - tank->getPositionY();

	 Vec2 v1 = Vec2(x,y);
	 float a = (v.x)*x;
	 float b = (v.y)*y;
	 Vect v2 = Vect(a,b);
	 auto m = MoveBy::create((v2.getLength())/_speed,v2);
	 auto cf = CallFunc::create(std::bind(&Bullet::die,this));
	 auto sq = Sequence::create(m,cf,NULL);
	 this->runAction(sq);

     return true;
 }

Bullet * Bullet::create(std::string name ,BaseTank * tank,float speed){
	 auto bullet = new Bullet();
	 if (bullet&&bullet->initWithFile(name,tank,speed))
	 {
		 bullet->autorelease();
		 return bullet;
	 }
	 demage = 1;
	 CC_SAFE_DELETE(bullet);
	 return nullptr;
 }

void Bullet::die(){
	this->removeFromParentAndCleanup(true);
}

Action *Bullet:: _dieoneAction(){
	auto animation = Animation::create();
	std::string name;
	for (int i = 5;i <= 7;i ++)
	{
		name = StringUtils::format("blast%d.png",i);
		animation->addSpriteFrameWithFile(name);
	}
	animation->setDelayPerUnit(0.1);
	animation->setLoops(1);
	auto animate = Animate::create(animation);
	this->runAction(animate);
}

Action* Bullet::_dietwoAction(){
	 auto animation = Animation::create();
	 std::string name ;
	 for (int i = 1 ; i <= 4;i ++)
	 {
		 name = StringUtils::format("blast%d.png",i);
		 animation->addSpriteFrameWithFile(name);
	 }
	 animation->setDelayPerUnit(0.1);
	 animation->setLoops(1);
	 auto animate = Animate::create(animation);
	 this->runAction(animate);
 }
