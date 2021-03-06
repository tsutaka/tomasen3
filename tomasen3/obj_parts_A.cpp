#include "obj_parts_A.hpp"
#include "obj_bullet.hpp"


EngineA::EngineA(){
	name = TEXT("エンジンＡ");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 0;					//画像x座標
	imageY = 0;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 10;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径
}

void EngineA::action(){
}

CockpitA::CockpitA(){
	name = TEXT("コックピットＡ");	//名前
	maxHp = 10;						//最大耐久度
	hp = maxHp;						//現在耐久度
	imageX = 4;						//画像x座標
	imageY = 0;						//画像y座標
	imageW = 1;						//画像幅
	imageH = 1;						//画像高
	animeMax = 4;					//アニメ枚数
	animeWait = 10;					//１枚当りのフレーム
	size = tipSize;					//当たり判定半径
}

void CockpitA::action(){
}

MachineGunA::MachineGunA(){
	name = TEXT("機関銃Ａ");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 8;					//画像x座標
	imageY = 0;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait  = 4;		        //１枚当りのフレーム
	size = tipSize;				//当たり判定半径
	
	maxEnergy = 100;			//最大の弾数
	energy = maxEnergy;			//現在の弾数
	chargeEnergy = 1;			//給弾する弾数
	maxMan = 10;				//最大の人員
	man = maxMan;				//現在の人員
	requireMan = 2;				//必要な人員
	fire = 0;					//現在の火勢
	burnFire = 30;				//発火する火勢
	maxFire = 80;				//最大の火勢
	
	stopShot = 1;				//
}  

void MachineGunA::action(){
	/*射撃処理*/
	if(energy > 0 && man >= requireMan && stopShot == 1 && kaihi == 0){
		friendBulletFactory( FriendBulletSptr( new NormalBullet()), 
			Vec2(pos.x + (rand() % 11 - 5), pos.y) );
		//射撃音
		energy -= 1;
	}
	else if(energy <= 0){			//射撃不可
		stopShot = 0;
	}
	else if(energy == maxEnergy){	//射撃再開
		stopShot = 1;
	}
}