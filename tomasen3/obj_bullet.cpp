#include <cmath>

#include "obj_bullet.hpp"


/*グローバルリソース定義*/
FriendBulletVsptr friendBulletList;					//自弾リスト
void friendBulletFactory(FriendBulletSptr friendBullet, Vec2 pos){
		friendBulletList.push_back( friendBullet );						//リストにオブジェクト追加
		FriendBulletVsptr::iterator it = friendBulletList.end() - 1;	//直前のオブジェクトを参照
		(*it)->setPos(pos);												//自弾を指定位置に移動
}
EnemyBulletVsptr enemyBulletList;					//敵弾リスト
void enemyBulletFactory(EnemyBulletSptr enemyBullet, Vec2 pos){
		enemyBulletList.push_back( enemyBullet );						//リストにオブジェクト追加
		EnemyBulletVsptr::iterator it = enemyBulletList.end() - 1;		//直前のオブジェクトを参照
		(*it)->setPos(pos);												//敵弾を指定位置に移動
}

Bullet::Bullet(){
	//デフォルト値
	pos = Vec2(0.0, 0.0);	//現在位置
	move = Vec2(0.0, 0.0);	//移動量
	dis = 0.0;				//移動量
	dir = 0.0;				//角度
	frameCnt = 0;			//経過フレーム数
	animeCnt = makeRand(4);	//アニメフレーム
	updateCheck = true;		//更新可否
	outputW = 1;			//出力幅
	outputH = 1;			//出力高

	fire = 1;				//火力
}
void FriendBullet::update(Object obj){
	/*カウントアップ*/
	frameCnt++;
	if(frameCnt > 10000) frameCnt = 0;
	/*アニメーション処理*/
	if(frameCnt % animeWait == 0){
		animeCnt++;
		if(animeCnt % animeMax == 0){
			animeCnt = 0;
		}
	}
	/*弾の位置を更新*/
	pos.x += cos(dir) * dis;
	pos.y += sin(dir) * dis;
}


NormalBullet::NormalBullet(){
	name = TEXT("通常弾");		//名前
	maxHp = 1;					//最大耐久度
	imageX = 0;					//画像x座標
	imageY = 14;				//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = 2;					//当たり判定半径
	
	hp = maxHp;								//HP
	dis = 20.0;								//移動量
	dir = -PI/2 + 0.01 * makeRand(0.0, 3);	//角度
}
void EnemyBullet::update(Object obj){
	/*カウントアップ*/
	frameCnt++;
	if(frameCnt > 10000) frameCnt = 0;
	/*アニメーション処理*/
	if(frameCnt % animeWait == 0){
		animeCnt++;
		if(animeCnt % animeMax == 0){
			animeCnt = 0;
		}
	}
	/*弾の位置を更新*/
	pos.x += cos(dir) * dis;
	pos.y += sin(dir) * dis;
}
WeakBullet::WeakBullet(){
	name = TEXT("弱弾");
	maxHp = 1;					//最大耐久度
	imageX = 4;					//画像x座標
	imageY = 14;				//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = 2;					//当たり判定半径
	
	hp = maxHp;					//HP
	dis = 6.0;								//移動量
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//角度
}
void WeakBullet::action(const Object &obj){
}
WideBullet::WideBullet(){
	name = TEXT("水球");
	maxHp = 10;				//最大耐久度
	imageX = 0;					//画像x座標
	imageY = 8;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径
	
	hp = maxHp;					//HP
	dis = 1.0;								//移動量
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//角度
}
void WideBullet::action(const Object &obj){
	dir += 0.01;
	dis += 0.01;
}
SprinklerBullet::SprinklerBullet(){
	name = TEXT("スプリンクラー");
	maxHp = 2;					//最大耐久度
	imageX = 8;					//画像x座標
	imageY = 14;				//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = 2;					//当たり判定半径
	
	hp = maxHp;					//HP
	dis = 2.2;								//移動量
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//角度
}
void SprinklerBullet::action(const Object &obj){
}
GreenBullet::GreenBullet(){
	name = TEXT("緑弾");
	maxHp = 2;					//最大耐久度
	imageX = 4;					//画像x座標
	imageY = 9;				//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = 6;					//当たり判定半径
	
	hp = maxHp;					//HP
	dis = 1.5;								//移動量
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//角度
}
void GreenBullet::action(const Object &obj){
	if(frameCnt % 71 == 0){
		if(frameCnt % 2 == 0) dir -= PI / 4;
		else dir += PI / 8;
		dis += 0.2;
	}
}