#include "obj_wing.hpp"
 

void Friend::update(Object obj){

}


/*コンストラクタ*/
Enemy::Enemy(){
	//デフォルト値
	pos = Vec2(0.0, 0.0);		//現在位置
	move = Vec2(0.0, 0.0);		//移動量
	dis = 5.0;					//移動量
	dir = 0.0;					//角度
	frameCnt = 0;				//経過フレーム数
	animeCnt = 0;				//アニメフレーム
	updateCheck = true;			//更新可否
	pattern = 0;				//行動パターン
	targetPos = Vec2(0.0,0.0);	//移動目的座標
	phase = 0;					//行動フェーズ
	canShot = 0;				//射撃許可
	outputW = 1;			//出力幅
	outputH = 1;			//出力高
}
void Enemy::update(Object obj){
	/*各パラメータを更新する*/
	frameCnt++;										//フレームカウントの更新
	/*アニメーション処理*/
	if(frameCnt % animeWait == 0){
		animeCnt++;
		if(animeCnt >= animeMax){
			animeCnt = 0;
		}
	}
	
	/*敵機の位置を更新*/
	pos.x += move.x;
	pos.y += move.y;
}

/*カウントアップ回数*/
void Friend::addKaihi(int kaihi){
	Friend::kaihi += kaihi;
	if(Friend::kaihi > 100){
		Friend::kaihi = 100;
	}else if(Friend::kaihi < 0){
		Friend::kaihi = 0;
	}
}