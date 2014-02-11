#ifndef INCLUDED_LOCALCOMMOM_HPP
#define INCLUDED_LOCALCOMMOM_HPP

#include "common.hpp"
/*このゲーム共通な宣言*/

/*楽曲ID*/
extern int musicBGM_5;
extern int musicShot;
extern int musicEnemyDown;
extern int musicFriendHit;

/***列挙型の宣言***/
/*土台接続状態*/
enum jointOK {jointNG = -1, jointEmp, jointUpExist, jointDownExist};
/*兵装接続状態*/
enum weaponOK {weaponNG = -1, weaponEmp, weaponExist};
/*土台接続位置*/
enum jointIndex {upJoint, rightJoint, downJoint, leftJoint, jointIndexEnd};
/*兵装接続位置*/
enum weaponIndex {mainWeapon, subWeapon, weaponIndexEnd};

/***構造体宣言***/
struct TellUpBox{
	int hp;
	int maxHp;
	int energy;
	int maxEnergy;
	int chargeEnergy;
	int man;
	int requireMan;
	int maxMan;
	int fire;
	int burnFire;
	int maxFire;
	int pertsANum;
	int pertsALost;
	int pertsBNum;
	int pertsBLost;
};

/*固定パラメータ*/
extern const int startMode;		//初期画面
extern const int startStage;	//初期ステージ
extern const int startPosX;		//初期自機X座標
extern const int startPosY;		//初期自機Y座標
extern const double moveAmount;	//加速度（１フレーム分）
extern const int wideArea;		//画面外領域の広さ

#endif//INCLUDED_LOCALCOMMOM_HPP