#include "localcommon.hpp"
/*変動パラメータ*/
int musicBGM_5;
int musicShot;
int musicEnemyDown;
int musicFriendHit;

/*固定パラメータ*/
const int startMode = 0;					//初期画面
const int startStage = 1;					//初期ステージ
const int startPosX = SCREEN_WIDTH / 2;		//初期自機X座標
const int startPosY = SCREEN_HEIGHT - 50;	//初期自機Y座標
const double moveAmount = 0.2;				//移動量定義
const int wideArea = 100;					//画面外の広さ

