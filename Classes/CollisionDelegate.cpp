#include "CollisionDelegate.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

// 敌机与我方子弹
void CollisionDelegate::detectOfEnemiesAndOurBullets(Vector<Node *> enemies, Bullet * ourBullets){
	if (!ourBullets->isVisible()) return;
	auto box1 = ourBullets->getBoundingBox();

	for (int i=0; i<enemies.size(); i++) {
		auto enemy = static_cast<EnemyTank *> (enemies.at(i));
		auto box2 = enemy->getBoundingBox();
		if (box1.intersectsRect(box2)) {
			ourBullets->stopAllActions();
			ourBullets->setVisible(false);

			// remove enemy bullet
			enemy->hurtWithDemage(ourBullets->demage);

			// play effect
			SimpleAudioEngine::getInstance()->playEffect("boom.wav");
			break;
		}
	}
}

// 主机与敌方子弹
void CollisionDelegate::detectOfMainAndEnemyBullets(MainTank *maintank, Vector<Node *> enemyBullets){

	auto box1 = maintank ->getBoundingBox();
	for (int i = 0 ;i < enemyBullets.size();i ++ )
	{	
		auto enemybull = static_cast<Bullet*> (enemyBullets.at(i));
		auto box2 = enemybull->getBoundingBox();		
		if (box1.intersectsRect(box2))
		{
			int i = enemybull->demage;
			maintank->hurtWithDemage(i);
			enemybull->removeFromParentAndCleanup(true);

			// play effect
			SimpleAudioEngine::getInstance()->playEffect("boom.wav");
			break;
		}
	}
}

// 主机子弹和敌机子弹
void CollisionDelegate::detectOfMainBulletAndEnemyBullets(Bullet * mainBullet, Vector<Node *> enemyBullets) {
	if (!mainBullet->isVisible()) return;

	auto box1 = mainBullet->getBoundingBox();
	for (int i=0; i<enemyBullets.size(); i++) {
		auto bullet = enemyBullets.at(i);
		auto box2 = bullet->getBoundingBox();
		if (box1.intersectsRect(box2)) {
			mainBullet->stopAllActions();
			mainBullet->setVisible(false);

			// remove enemy bullet
			bullet->removeFromParentAndCleanup(true);

			// play effect
			SimpleAudioEngine::getInstance()->playEffect("hurt.wav");
			break;
		}
	}
}

// 主机子弹和砖
void CollisionDelegate::detectOfMainBulletAndBricks(Bullet * mainBullet, Vector<Brick *> bricks){
	if (!mainBullet->isVisible()) return;

	Vector<Brick *> deadBricks;
	auto box1 = mainBullet->getBoundingBox();

	for (int i=0; i<bricks.size(); i++) {
		auto brick = bricks.at(i);
		auto box2 = brick->_tile->getBoundingBox();
		if (box1.intersectsRect(box2)) {
			if (brick->_type != BrickType::kGOLD || mainBullet->_type != BulletType::NORMAL) {
				deadBricks.pushBack(brick);
			}
			mainBullet->stopAllActions();
			mainBullet->setVisible(false);

			// play effect
			SimpleAudioEngine::getInstance()->playEffect("hurt.wav");
		}
	}

	for (int i = 0; i < deadBricks.size(); i++)	{
		deadBricks.at(i)->removeFromMap(GameScene::getInstance()->_mapLayer);
	}
}

// 敌方子弹和砖
void CollisionDelegate::detectOfEnemyBulletsAndBricks(Vector<Node *> enemyBullets, Vector<Brick *> bricks){
	Vector<Bullet *> deadBullets;
	Vector<Brick *> deadBricks;

	for (int i=0; i<enemyBullets.size(); i++) {
		auto bull = static_cast<Bullet*> (enemyBullets.at(i));
		for (int j=0; j<bricks.size(); j++) {
			auto brick = bricks.at(j);
			// 碰撞检测
			auto tile = brick->_tile;
			auto box = brick->_tile->getBoundingBox();
			if (bull->getBoundingBox().intersectsRect(box)) {
				if (brick->_type == BrickType::kGOLD && bull->_type == BulletType::NORMAL) {
					// bull->die();
					deadBullets.pushBack(bull);
				} else {
					// bull->die();
					deadBullets.pushBack(bull);
					deadBricks.pushBack(brick);
				}
				// break;
				// play effect
				SimpleAudioEngine::getInstance()->playEffect("hurt.wav");
			}
		}
	}

	for (int i = 0; i < deadBullets.size(); i++)
	{
		deadBullets.at(i)->die();
	}
	for (int i = 0; i < deadBricks.size(); i++)
	{
		deadBricks.at(i)->removeFromMap(GameScene::getInstance()->_mapLayer);
	}
}

//主机与道具的碰撞
void CollisionDelegate::detectOfProbAndMainTank(MainTank * mainTank,Vector<Node *>probs){
	auto box2 = mainTank->getBoundingBox();
	for (int i= 0;  i < probs.size(); i ++)
	{
		auto prob = static_cast<BaseProp *>(probs.at(i));
		auto box1 = prob->getBoundingBox();
		if (box1.intersectsRect(box2))
		{
			prob->effect(mainTank);
			prob->disappear(0);
		}
	}	
}

void CollisionDelegate::detectOfBulletsAndHomeBrick(Vector<Node *> enemyBullets, 
		Bullet * mainBullet, HomeBrick * homeBrick) {
			for (int i = 0; i < enemyBullets.size(); i++) {
				auto bullet = static_cast<Bullet *> (enemyBullets.at(i));
				auto box = bullet->getBoundingBox();
				if (box.intersectsRect(homeBrick->_brick11->_tile->getBoundingBox())) {
					GameScene::getInstance()->GameOver();
					SimpleAudioEngine::getInstance()->playEffect("boom.wav");
					return;
				}
				if (box.intersectsRect(homeBrick->_brick12->_tile->getBoundingBox())) {
					GameScene::getInstance()->GameOver();
					SimpleAudioEngine::getInstance()->playEffect("boom.wav");
					return;
				}
				if (box.intersectsRect(homeBrick->_brick25->_tile->getBoundingBox())) {
					GameScene::getInstance()->GameOver();
					SimpleAudioEngine::getInstance()->playEffect("boom.wav");
					return;
				}
				if (box.intersectsRect(homeBrick->_brick26->_tile->getBoundingBox())) {
					GameScene::getInstance()->GameOver();
					SimpleAudioEngine::getInstance()->playEffect("boom.wav");
					return;
				}
			}

			auto box = mainBullet->getBoundingBox();
			if (box.intersectsRect(homeBrick->_brick11->_tile->getBoundingBox())) {
				GameScene::getInstance()->GameOver();
				SimpleAudioEngine::getInstance()->playEffect("boom.wav");
				return;
			}
			if (box.intersectsRect(homeBrick->_brick12->_tile->getBoundingBox())) {
				GameScene::getInstance()->GameOver();
				SimpleAudioEngine::getInstance()->playEffect("boom.wav");
				return;
			}
			if (box.intersectsRect(homeBrick->_brick25->_tile->getBoundingBox())) {
				GameScene::getInstance()->GameOver();
				SimpleAudioEngine::getInstance()->playEffect("boom.wav");
				return;
			}
			if (box.intersectsRect(homeBrick->_brick26->_tile->getBoundingBox())) {
				GameScene::getInstance()->GameOver();
				SimpleAudioEngine::getInstance()->playEffect("boom.wav");
				return;
			}
}
