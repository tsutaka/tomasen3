#include "obj_wing_enemy.hpp"

#include <cmath>

#include "obj_bullet.hpp"
/*グローバルリソース定義*/
EnemyVsptr enemyList;				//敵機リスト
void enemyFactory(EnemySptr enemy, Vec2 pos, int pattern){
		enemyList.push_back( enemy );					//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;	//直前のオブジェクトを参照
		(*it)->setPos(pos);								//敵機を指定位置に移動
		(*it)->setPattern(pattern);						//敵機の行動パターンの指定
}

EnemyA::EnemyA(){
	/*初期化*/
	name = TEXT("ヒゲ");	//名前
	maxHp = 5;				//最大耐久度
	imageX = 0;				//画像x座標
	imageY = 12;			//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	outputW = 2;			//出力幅
	outputH = 2;			//出力高
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	dis = 3.0;				//移動量
	move = Vec2(0.0, 7.0);	//移動量
	hp = maxHp;				//HP
}
void EnemyA::action(Object obj){
	/*弾の発射*/
	if(perCheck(1) && canShot > 0){
		enemyBulletList.push_back( 
			EnemyBulletSptr( new SprinklerBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(makeRand(pos.x, 5), pos.y));				//弾の初期位置決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//A1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(-2.5, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && pos.x < SCREEN_INDENT + 50){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -5.0);	//移動量
		}
		break;
	case 1: //A2
		/*目標への移動*/
		if(pos.x < targetPos.x - dis) move.x = dis;
		if(pos.y < targetPos.y - dis) move.y = dis;
		if(pos.x > targetPos.x + dis) move.x = -dis;
		if(pos.y > targetPos.y + dis) move.y = -dis;
		if(phase == 0){
			canShot = 1;
			phase++;
			targetPos = Vec2(SCREEN_WIDTH / 2, 150);
		}
		if(phase == 1 && pos.x > SCREEN_WIDTH / 2){
			phase++;
			targetPos = Vec2(SCREEN_WIDTH - SCREEN_INDENT + 500, -500);
		}
		break;
	case 2: //A3
		if(phase == 0){
			phase++;
			move = Vec2(0.0, -6.0);	//移動量
		}
		else if(phase == 1 && pos.y < 100){
			phase++;
			move = Vec2(3.0, 1.5);	//移動量
			canShot = 1;
		}
		break;
	case 3: //A4
		if(phase == 0){
			phase++;
			move = Vec2(0.0, -6.0);	//移動量
		}
		else if(phase == 1 && pos.y < 100){
			phase++;
			move = Vec2(-3.0, 1.5);	//移動量
			canShot = 1;
		}
		break;
	case 4: //A5
		if(phase == 0){
			phase++;
			move = Vec2(0.0, 6.0);	//移動量
		}
		else if(phase == 1 && pos.y > 100){
			phase++;
			canShot = 1;
			dir = PI/2 + 0.1 * makeRand(0.0, 5);	//角度
			dis = 5.0;
			move.x = cos(dir) * dis;
			move.y = sin(dir) * dis;
		}
		break;
	}

}

EnemyB::EnemyB(){
	/*初期化*/
	name = TEXT("マイン");	//名前
	maxHp = 50;				//最大耐久度
	imageX = 4;				//画像x座標
	imageY = 12;			//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}
void EnemyB::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new SprinklerBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	case 1:	//B2
		if(phase == 0){
			phase++;
			move = Vec2(0.0, 3.0);	//移動量
		}
		else if(phase == 1 && pos.y > 100){
			phase++;
			canShot = 1;
			move = Vec2(2.0, 0.0);	//移動量
		}
		else if(phase == 2 && pos.x > SCREEN_WIDTH - SCREEN_INDENT){
			phase++;
			canShot = 0;
			move = Vec2(2.0, 0.0);	//移動量
		}
		break;
	}
	
}

EnemyC::EnemyC(){
	/*初期化*/
	name = TEXT("ロッカク");	//名前
	maxHp = 150;				//最大耐久度
	imageX = 8;				//画像x座標
	imageY = 12;			//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	hp = maxHp;				//HP
}

void EnemyC::action(Object obj){
	/*弾の発射*/
	if(canShot > 0 && frameCnt % 30 == 0){
		for(shotCnt = 0.0; shotCnt < 2 * PI; shotCnt += 2 * PI / 40){
			enemyBulletList.push_back( 
				EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
			EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
			(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
			(*it)->setDir(shotCnt);							//弾の初期角度決定
		}
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//C1
		if(phase == 0){
			phase++;
			move = Vec2(0.0, 4.0);	//移動量
		}
		else if(phase == 1 && pos.y > 100){
			phase++;
			canShot = 1;
			move = Vec2(0.0, 0.0);	//移動量
		}
		else if(phase == 2 && frameCnt > 300){
			phase++;
			canShot = 1;
			move = Vec2(1.0, 0.0);	//移動量
		}
		else if(phase == 3 && pos.x > SCREEN_WIDTH - SCREEN_INDENT - 50){
			phase++;
			canShot = 1;
			move = Vec2(-1.0, 0.0);	//移動量
		}
		else if(phase == 4 && pos.x < SCREEN_INDENT + 50){
			phase++;
			canShot = 1;
			move = Vec2(0.0, -4.0);	//移動量
		}
		break;
	}
	
}

EnemyD::EnemyD(){
	/*初期化*/
	name = TEXT("ロック");	//名前
	maxHp = 50;				//最大耐久度
	imageX = 40;			//画像x座標
	imageY = 12;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 2;			//出力幅
	outputH = 2;			//出力幅
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	hp = maxHp;				//HP
}

void EnemyD::action(Object obj){

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//D1
		move += Vec2(makeRand(0.0, 4) * 0.1, makeRand(1.0, 4) * 0.1);	//移動量
		break;
	}
	
}

EnemyE::EnemyE(){
	/*初期化*/
	name = TEXT("ラージロック");	//名前
	maxHp = 50;				//最大耐久度
	imageX = 40;			//画像x座標
	imageY = 12;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力幅
	size = tipSize*5;		//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyE::action(Object obj){
	/*移動方向の決定*/
	switch(pattern){
	case 0:	//E1
		move += Vec2(makeRand(0.0, 4) * 0.01, makeRand(1.0, 4) * 0.01);	//移動量
		break;
	}
	
}

EnemyF::EnemyF(){
	/*初期化*/
	name = TEXT("タコス");	//名前
	maxHp = 50;				//最大耐久度
	imageX = 32;			//画像x座標
	imageY = 14;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	size = tipSize*2;		//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyF::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		canShot = 1;
		break;
	}
	
}

EnemyG::EnemyG(){
	/*初期化*/
	name = TEXT("ボール");	//名前
	maxHp = 15;				//最大耐久度
	imageX = 0;				//画像x座標
	imageY = 13;			//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyG::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 5 == 0){
		shotCnt += 0.5;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WideBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//G1
		phase++;
		move = Vec2(0.0, 0.0);	//移動量
		canShot = 1;
		break;
	}
	
}

EnemyH::EnemyH(){
	/*初期化*/
	name = TEXT("バタフライ");	//名前
	maxHp = 60;				//最大耐久度
	imageX = 4;				//画像x座標
	imageY = 13;			//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間

	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyH::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new GreenBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//H1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	}
	
}

EnemyI::EnemyI(){
	/*初期化*/
	name = TEXT("ゴキ");	//名前
	maxHp = 150;			//最大耐久度
	imageX = 16;			//画像x座標
	imageY = 12;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	size = tipSize*2;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 10;			//フレーム待ち時間
	
	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyI::action(Object obj){
	/*弾の発射*/
	


	/*移動方向の決定*/
	switch(pattern){
	case 0:	//I1
		if(canShot > 0 && frameCnt % 2 == 0){
			shotCnt += PI / 15.0;
			if(shotCnt > PI / 2 ) shotCnt = - PI / 2; 
			enemyBulletList.push_back( 
				EnemyBulletSptr( new SprinklerBullet()) );	//リストにオブジェクト追加
			EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
			(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
			(*it)->setDir(shotCnt);							//弾の初期角度決定
		}
		phase++;
		move = Vec2(0.56, 1.043);	//移動量
		canShot = 1;
		if(phase > 120) {
			shotCnt = PI / 2; 
			phase = 0;
			pattern = 1;
		}
		break;
	case 1:	//I1
		if(canShot > 0 && frameCnt % 2 == 0){
			shotCnt -= PI / 15.0;
			if(shotCnt < PI / 2 ) shotCnt = PI * 3 / 2; 
			enemyBulletList.push_back( 
				EnemyBulletSptr( new SprinklerBullet()) );	//リストにオブジェクト追加
			EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
			(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
			(*it)->setDir(shotCnt);							//弾の初期角度決定
		}
		phase++;
		move = Vec2(-0.56, 1.443);	//移動量
		canShot = 1;
		if(phase > 120) {
			shotCnt = PI / 2; 
			phase = 0;
			pattern = 0;
		}
		break;
	}
	
}

EnemyJ::EnemyJ(){
	/*初期化*/
	name = TEXT("ラミ");	//名前
	maxHp = 30;				//最大耐久度
	imageX = 40;			//画像x座標
	imageY = 14;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	size = tipSize*2;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間
	
	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyJ::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	}
	
}

EnemyK::EnemyK(){
	/*初期化*/
	name = TEXT("イスエル");//名前
	maxHp = 20;				//最大耐久度
	imageX = 8;				//画像x座標
	imageY = 13;			//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	size = tipSize;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間
	
	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyK::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	}
	
}

EnemyL::EnemyL(){
	/*初期化*/
	name = TEXT("サハエル");	//名前
	maxHp = 50;				//最大耐久度
	imageX = 16;				//画像x座標
	imageY = 14;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	size = tipSize*2;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間
	
	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyL::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	}
	
}

EnemyN::EnemyN(){
	/*初期化*/
	name = TEXT("魔王の使い");	//名前
	maxHp = 150;				//最大耐久度
	imageX = 24;				//画像x座標
	imageY = 12;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	size = tipSize*2;			//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間
	
	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyN::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	}
	
}

EnemyO::EnemyO(){
	/*初期化*/
	name = TEXT("魔王");	//名前
	maxHp = 500;			//最大耐久度
	imageX = 24;			//画像x座標
	imageY = 14;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	size = tipSize*2;		//当たり判定半径
	animeMax = 4;			//フレーム数
	animeWait = 4;			//フレーム待ち時間
	
	dis = 3.0;				//移動量
	move = Vec2(0.0, 2.0);	//移動量
	hp = maxHp;				//HP
	shotCnt = 0.0;			//射撃角度
}

void EnemyO::action(Object obj){
	/*弾の発射*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//弾の初期位置決定
		(*it)->setDir(shotCnt);							//弾の初期角度決定
	}

	/*移動方向の決定*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//移動量
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//移動量
		}
		break;
	}
	
}
