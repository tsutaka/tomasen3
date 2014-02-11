#include "obj_effect.hpp"

#include "localcommon.hpp"

/*グローバルリソース定義*/
EffectVsptr effectList;				//エフェクトリスト
void effectFactory(EffectSptr effect){
		effectList.push_back( effect );							//リストにオブジェクト追加
}
void effectFactory(EffectSptr effect, Vec2 pos, Vec2 targetPos){
		effectList.push_back( effect );							//リストにオブジェクト追加
		EffectVsptr::iterator it = effectList.end() - 1;		//直前のオブジェクトを参照
		(*it)->setPos(pos);										//エフェクトを指定位置に移動
		(*it)->setTargetPos(targetPos);							//エフェクト目標位置を指定
}

Effect::Effect(){
	hp = 1;						//耐久度
	pos = Vec2(0.0, 0.0);		//位置
	targetPos = Vec2(0.0, 0.0);	//位置
	dis = 0.0;					//移動量
	dir = 0.0;					//角度
	frameCnt = 0;				//生成後の経過フレーム数
	animeCnt = 0;				//現在のアニメフレーム
	updateCheck = 0;			//更新可否
	outputW = 1;			//出力幅
	outputH = 1;			//出力高
}

void Effect::update(Object obj){
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
	/*オブジェクト移動*/
	pos.x += (targetPos.x - pos.x) / 50;
	pos.y += (targetPos.y - pos.y) / 50;

	/*カウントダウン*/
	timeOfLife--;
	if(timeOfLife < 0) timeOfLife = 0;
}

Explosion::Explosion(){
	maxHp = 1;				//最大耐久度
	imageX = 32;			//画像x座標
	imageY = 18;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 2;			//出力幅
	outputH = 2;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 1;				//サイズ
	timeOfLife = 50;		//生存フレーム
	pos = Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);					//初期位置
	targetPos = Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2+100);		//目標位置
}

TitleTo::TitleTo(){
	maxHp = 1;				//最大耐久度
	imageX = 0;				//画像x座標
	imageY = 18;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_WIDTH+wideArea/2, 10*tipSize);					//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, 10*tipSize);		//目標位置
}

TitleMa::TitleMa(){
	maxHp = 1;				//最大耐久度
	imageX = 8;				//画像x座標
	imageY = 18;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, SCREEN_HEIGHT+wideArea/2);	//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, 10*tipSize);			//目標位置
}

TitleSe::TitleSe(){
	maxHp = 1;				//最大耐久度
	imageX = 16;			//画像x座標
	imageY = 18;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(-wideArea/2, 14*tipSize);							//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, 10*tipSize);	//目標位置
}

TitleNi::TitleNi(){
	maxHp = 1;				//最大耐久度
	imageX = 24;			//画像x座標
	imageY = 18;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, -wideArea/2);		//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, 10*tipSize);	//目標位置
}


DarkR::DarkR(){
	maxHp = 1;				//最大耐久度
	imageX = 0;				//画像x座標
	imageY = 22;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, SCREEN_HEIGHT+wideArea/2);	//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, 10*tipSize);			//目標位置
}

LightR::LightR(){
	maxHp = 1;				//最大耐久度
	imageX = 8;				//画像x座標
	imageY = 22;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_WIDTH+wideArea/2, SCREEN_HEIGHT+wideArea/2);		//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, 10*tipSize);		//目標位置
}

DarkY::DarkY(){
	maxHp = 1;				//最大耐久度
	imageX = 0;				//画像x座標
	imageY = 20;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(-wideArea/2, SCREEN_HEIGHT+wideArea/2);				//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, 10*tipSize);	//目標位置
}

LightY::LightY(){
	maxHp = 1;				//最大耐久度
	imageX = 8;				//画像x座標
	imageY = 20;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_WIDTH+wideArea/2, -wideArea/2);				//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, 10*tipSize);	//目標位置
}

DarkG::DarkG(){
	maxHp = 1;				//最大耐久度
	imageX = 16;			//画像x座標
	imageY = 22;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(-wideArea/2, -wideArea/2);							//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, 10*tipSize);	//目標位置
}

LightG::LightG(){
	maxHp = 1;				//最大耐久度
	imageX = 24;			//画像x座標
	imageY = 22;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_WIDTH+wideArea/2, 10*tipSize);							//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, 10*tipSize);	//目標位置
}

DarkB::DarkB(){
	maxHp = 1;				//最大耐久度
	imageX = 16;			//画像x座標
	imageY = 20;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, -wideArea/2);		//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, 10*tipSize);	//目標位置
}

LightB::LightB(){
	maxHp = 1;				//最大耐久度
	imageX = 24;			//画像x座標
	imageY = 20;			//画像y座標
	imageW = 2;				//画像幅
	imageH = 2;				//画像高
	outputW = 4;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(-wideArea/2, 10*tipSize);							//初期位置
	targetPos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, 10*tipSize);	//目標位置
}

PushSpace::PushSpace(){
	maxHp = 1;				//最大耐久度
	imageX = 0;				//画像x座標
	imageY = 24;			//画像y座標
	imageW = 8;				//画像幅
	imageH = 2;				//画像高
	outputW = 16;			//出力幅
	outputH = 4;			//出力高
	animeMax = 4;			//アニメーション枚数
	animeWait = 6;			//アニメーション１枚のフレーム数
	size = 2;				//サイズ
	timeOfLife = 3000;		//生存フレーム
	pos = Vec2(SCREEN_WIDTH/2-4*tipSize*2, SCREEN_HEIGHT+wideArea/2);	//初期位置
	targetPos = Vec2(SCREEN_WIDTH/2-4*tipSize*2, 20*tipSize);	//目標位置
}