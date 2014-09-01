#include "CollisionDelegate.h"
#include "GameScene.h"

// 敌机与我方子弹
void CollisionDelegate::detectOfEnemiesAndOurBullets(Vector<EnemyTank *> enemies, Vector<Bullet *> ourBullets){
	for (auto enemy = enemies.begin();enemy != enemies.end();enemy ++ )
	{ 
		for(auto bul = ourBullets.begin();bul != ourBullets.end();bul++){
			EnemyTank * tank = *enemy;
			Bullet * bullet = *bul;
			if (tank->getBoundingBox().intersectsRect(bullet->getBoundingBox()))
			{
			int i = bullet->demage;
			tank->hurtWithDemage(i);
			bullet->die();

			}
    }	
	}
}

// 主机与敌方子弹
 void CollisionDelegate::detectOfMainAndEnemyBullets(Vector <MainTank *>mainTank, Vector<Bullet *> enemyBullets){
	 for (auto mk = mainTank.begin();mk != mainTank.end();mk++)
	 {
		 for (auto eb = enemyBullets.begin();eb != enemyBullets.end();eb++)
		 {
			 MainTank * MK  = *mk;
			 Bullet * EB = *eb;
			 if (MK->getBoundingBox().intersectsRect(EB->getBoundingBox()))
			 {
				 MK->die();
				 EB->die();
			 }
		 }
	 }
}

 // 主机子弹和敌机子弹
 void CollisionDelegate::detectOfEnemyBulletsAndOurBullets(Vector<Bullet *> enemyBullets, Vector<Bullet *> ourBullets){
	 for (auto eb = enemyBullets.begin();eb != enemyBullets.end();eb++)
	 {
		 for (auto bul = ourBullets.begin();bul != ourBullets.end();bul++)
		 {
			 Bullet * EB = *eb;
			 Bullet *BUL = *bul;
			 if (EB->getBoundingBox().intersectsRect(BUL->getBoundingBox()))
			 {
				 EB->die();
				 BUL->die();
			 }
		 }
	 }
 }
 
 // 主机子弹和砖
 void CollisionDelegate::detectOfOurBulletsAndBricks(Vector<Bullet *> ourBullets, Vector<Brick *> bricks){
	 for (auto bul = ourBullets.begin();bul != ourBullets.end();bul ++)
	 {
		 for (auto bri = bricks.begin();bri != bricks.end();bri ++)
		 {
			 Bullet *BUL = *bul;
			 Brick * BRI = *bri;
			 if (BUL->getBoundingBox().intersectsRect(BRI->getBoundingBox()))
			 {
				 BUL->die();
				 BRI->removeFromMap(GameScene::getInstance()->_mapLayer);
			 }
		 }
	 }
 }
 
 // 敌方子弹和砖
 void CollisionDelegate::detectOfEnemiesAndOurBullets(Vector<Bullet *> enemyBullets, Vector<Brick *> bricks){
	 for (auto bul = enemyBullets.begin();bul != enemyBullets.end();bul ++)
	 {
		 for ( auto bri = bricks.begin();bri != bricks.end();bri ++)
		 {
        // 敌机转向
		 }
	 }
 }
