#include "Bullet.h"
#include "math.h"

#define PATH "bullet.png"

 bool Bullet:: initWithFile(BaseTank * tank, float speed){
	 if (!Sprite::initWithFile(PATH)) return false;

	 demage = 1;
	 this->_speed = speed;

	 this->_tank = tank;
	 this->_tank->retain();
	 this->_type = BulletType::NORMAL;

	 // move();

     return true;
}

void Bullet::move() {
	Vect v = this->_tank->_direction;
	Size size = Director::getInstance()->getVisibleSize();
	float x = v.x == -1 ? this->getPositionX() : size.width - this->getPositionX();
	float y = v.y == -1 ? this->getPositionY() : size.height - this->getPositionY();

	float a = (v.x)*x;
	float b = (v.y)*y;
	Vect v2 = Vect(a,b);
	auto m = MoveBy::create((v2.getLength())/_speed,v2);
	auto cf = CallFunc::create(std::bind(&Bullet::die,this));
	auto sq = Sequence::create(m,cf,NULL);
	this->runAction(sq);
}

Bullet * Bullet::create(BaseTank * tank, float speed){
	 auto bullet = new Bullet();
	 if (bullet&&bullet->initWithFile(tank,speed)) {
		 bullet->autorelease();
		 return bullet;
	 }
	 CC_SAFE_DELETE(bullet);
	 return nullptr;
}

void Bullet::die() {
	/*log("remove bullet by die");*/
	this->removeFromParentAndCleanup(true);
}

void Bullet:: dieoneAction(){
	auto animation = Animation::create();
	std::string name;
	for (int i = 5;i <= 7;i ++)	{
		name = StringUtils::format("blast%d.png",i);
		animation->addSpriteFrameWithFile(name);
	}
	animation->setDelayPerUnit(0.1);
	animation->setLoops(1);
	auto animate = Animate::create(animation);
	this->runAction(animate);
}

void Bullet::dietwoAction(){
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
