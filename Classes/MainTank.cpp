#include "MainTank.h"
#include "Bullet.h"

bool MainTank::init(){
	if (!Sprite::initWithFile(""))
	{
		return false;
	}
    isDie(false);
	_hp = 1;
	_speed = 50;
	_current_life = 4;

	return true;
}
void MainTank::move(float t){
	this->setPosition(this->getPosition() + _direction * t * _speed);
}
void MainTank::fire(){
	auto bullet = Bullet::create();
	//��ӵ��ҷ��ӵ���
	auto pDirector = Director::getInstance()->getRunningScene();

}
void MainTank::hurtWithDemage(int demage){
	this->_hp -= demage;
	if (_hp < 0)
	{
		_hp = 0;
	}
	
}
void MainTank::die(){
	this->removeFromParentAndCleanup(true);
	//����̹�����̹���ӵ���ײʱ�ж��������ж��٣�
}