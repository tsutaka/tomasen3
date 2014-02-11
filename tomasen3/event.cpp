#include <cmath>

#include "event.hpp"

#include "localcommon.hpp"
#include "obj_effect.hpp"
#include "obj_wing_enemy.hpp"

/*グローバルリソース定義*/
EventVsptr eventList;		//イベントリスト
void eventFactory(EventSptr event){
		eventList.push_back( event );			//リストにオブジェクト追加
}

/*コンストラクタ*/
Event::Event(){
	pos = Vec2(0.0, 0.0);	//現在位置
	dis = 0.0;				//移動量
	dir = 0.0;				//角度
	frameCnt = 0;			//フレームカウント
	phase = 0;				//フェーズ
	next = 0;			//イベント終了フラグ
}

/*更新関数*/
void Event::update(){
	/*カウントアップ*/
	frameCnt++;
	/*イベントの位置を更新*/
	pos.x += cos(dir) * dis;
	pos.y += sin(dir) * dis;
}


/*アクション関数（個別）*/
void GameTitle::action(){

	/*入力受付*/
	if(GetAsyncKeyState(VK_SPACE) && phase >= 1) {//SPACE
		next = 1;	//終了判定フラグ
		effectList.clear();
	}
	/*タイムスケジュール*/
	if(phase == 0){
		phase++;
		effectFactory( EffectSptr(new DarkR()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new DarkY()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new DarkG()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new DarkB()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new LightB()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new LightG()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new LightY()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new LightR()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new TitleTo()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new TitleMa()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new TitleSe()) );		//リストにオブジェクト追加
		effectFactory( EffectSptr(new TitleNi()) );		//リストにオブジェクト追加
	}
	else if(phase == 1 && frameCnt == 100){
		phase++;
		effectFactory( EffectSptr(new PushSpace()) );	//リストにオブジェクト追加
		effectFactory( EffectSptr(new Explosion()) );	//リストにオブジェクト追加

	}
}

/*コンストラクタ*/
Stage1::Stage1(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//初期位置
}
/*アクション関数（個別）*/
void Stage1::action(){
	/*STAGE1の敵キャラ生成*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyFactory(EnemySptr( new EnemyJ ), 
			Vec2(SCREEN_WIDTH / 2, 100), 0);
	}

	/*1-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*1-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(1);										//敵機の行動パターンの指定
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*1-3*/
	if(phase == 2 && frameCnt > 650){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyB()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt < 700 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT + 80, SCREEN_HEIGHT + 50));	//敵機をイベント位置に移動
		(*it)->setPattern(2);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt < 700 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH-SCREEN_INDENT-80, SCREEN_HEIGHT + 50));	//敵機をイベント位置に移動
		(*it)->setPattern(3);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	/*1-4*/
	if(phase == 4){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyB()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT +50, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(1);										//敵機の行動パターンの指定
	}
	if(phase == 5 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2,  -50));	//敵機をイベント位置に移動
		(*it)->setPattern(4);										//敵機の行動パターンの指定
	}
	if(phase == 5 && frameCnt > 1100){
		phase++;
	}
	/*1-5*/
	if(phase == 6){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyC()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if (phase ==7 && frameCnt > 1500){
		next = 2;
	}

}
/*アクション関数（個別）*/

Stage2::Stage2(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//初期位置
}
/*アクション関数（個別）*/
void Stage2::action(){
	/*STAGE1の敵キャラ生成*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}

	/*2-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyD()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*2-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyE()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(1);										//敵機の行動パターンの指定
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*2-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyF()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase == 4 && frameCnt > 1200){
		next = 3;
	}
}
/*アクション関数（個別）*/
Stage3::Stage3(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//初期位置
}
/*アクション関数（個別）*/
void Stage3::action(){
	/*STAGE1の敵キャラ生成*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}

	/*3-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt == 0){
		enemyList.push_back( EnemySptr(new EnemyC()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*3-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyH()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(1);										//敵機の行動パターンの指定
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*3-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyI()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase == 4 && frameCnt > 1200){
		next = 4;
	}
}
/*アクション関数（個別）*/
Stage4::Stage4(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//初期位置
}
/*アクション関数（個別）*/
void Stage4::action(){
	/*STAGE1の敵キャラ生成*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}

	/*4-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt == 0){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*4-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyK()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(1);										//敵機の行動パターンの指定
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*4-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyL()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase ==4 && frameCnt > 1100){
		next = 5;
	}
}
/*アクション関数（個別）*/
Stage5::Stage5(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//初期位置
}
/*アクション関数（個別）*/
void Stage5::action(){
	/*STAGE1の敵キャラ生成*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}

	/*5-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*5-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyN()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(1);										//敵機の行動パターンの指定
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*5-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyO()) );				//リストにオブジェクト追加
		EnemyVsptr::iterator it = enemyList.end() - 1;				//直前のオブジェクトを参照
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//敵機をイベント位置に移動
		(*it)->setPattern(0);										//敵機の行動パターンの指定
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase ==4){
		//next = 2;
	}
}
/*アクション関数（個別）*/
void GameOver::action(){

}
/*アクション関数（個別）*/
void GameClear::action(){
}