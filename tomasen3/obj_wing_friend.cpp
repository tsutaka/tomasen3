#include <cmath>

#include "obj_wing_friend.hpp"

/*グローバルリソース定義*/
FriendVsptr friendList;			//自機リスト
FriendWptr friendFactory(FriendSptr friendw, Vec2 pos){
		friendList.push_back( friendw );					//リストにオブジェクト追加
		FriendVsptr::iterator it = friendList.end() - 1;	//直前のオブジェクトを参照
		(*it)->setPos(pos);
		return (*it);
}

KosenWing::KosenWing(){
	/*初期化*/
	name = TEXT("コーセンウィング");				//名称の設定
	maxMove = 4.0;									//最大移動量
	subMove = 0.90;									//減少移動量倍率
	maxHp = 10;										//最大耐久度
	imageX = 0;										//画像x座標
	imageY = 0;										//画像y座標
	imageW = 1;										//画像幅
	imageH = 1;										//画像高
	size = tipSize;									//当たり判定半径
	frameCnt = 0;									//経過フレーム数
	
	partsANum = 0;	//現時点パーツA数
	partsALost = 0;	//累積喪失パーツA数
	partsBNum = 0;	//現時点パーツB数
	partsBLost = 0;	//累積喪失パーツB数


	/*自機実装*/	
	core = partsBFactory( PartsBSptr(new CoreA()) );			//弱いスマポで親子関係
	if(PartsBSptr coreSptr = core.lock()){						//コアにパーツを追加する。

/*
		//
		coreSptr->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);					//コアにエンジン追加

		PartsBSptr base1A = partsBFactory( PartsBSptr(new Base1A()) ).lock();//lock失敗のエラー処理省略
		coreSptr->setPartsB(upJoint, base1A);					//コアにベース１Ａ追加
		base1A->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//ベース１Ａにコックピット追加

		PartsBSptr base1D = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock失敗のエラー処理省略
		coreSptr->setPartsB(downJoint, base1D);					//コアにベース１Ｄ追加
		base1D->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース１ＤにマシンガンＡ追加
*/	
		coreSptr->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);					//コアにエンジン追加

		PartsBSptr base2B_E16 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		coreSptr->setPartsB(upJoint, base2B_E16);					//コアにベース１Ａ追加
		base2B_E16->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);				//ベース2Bにコックピット追加

		PartsBSptr base2F_D18 = partsBFactory( PartsBSptr(new Base2F()) ).lock();//lock失敗のエラー処理省略
		coreSptr->setPartsB(leftJoint, base2F_D18);					//コアにベース３Ａ追加
		base2F_D18->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース３ＡにマシンガンＡ追加
		
		
		PartsBSptr base2E_F18 = partsBFactory( PartsBSptr(new Base2E()) ).lock();//lock失敗のエラー処理省略
		coreSptr->setPartsB(rightJoint, base2E_F18);					//ベース３Ａにベース２Ｆ追加
		base2E_F18->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base2B_E20 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		coreSptr->setPartsB(downJoint, base2B_E20);					//ベース３Ａにベース２Ｆ追加
		base2B_E20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);				//ベース２ＦにマシンガンＡ追加
		
		PartsBSptr base1D_E22 = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock失敗のエラー処理省略
		base2B_E20->setPartsB(downJoint, base1D_E22);					//ベース３Ａにベース２Ｆ追加
		base2B_E20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base2B_E14 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		base2B_E16->setPartsB(upJoint, base2B_E14);					//ベース３Ａにベース２Ｆ追加
		base2B_E14->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//ベース２ＦにマシンガンＡ追加
		
		PartsBSptr base1A_E12 = partsBFactory( PartsBSptr(new Base1A()) ).lock();//lock失敗のエラー処理省略
		base2B_E14->setPartsB(upJoint, base1A_E12);					//ベース３Ａにベース２Ｆ追加
		base1A_E12->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base2B_D20 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		base2F_D18->setPartsB(downJoint, base2B_D20);					//ベース３Ａにベース２Ｆ追加
		base2B_D20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base2B_F20 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		base2E_F18->setPartsB(downJoint, base2B_F20);					//ベース３Ａにベース２Ｆ追加
		base2B_F20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base2B_F22 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		base2B_F20->setPartsB(downJoint, base2B_F22);					//ベース３Ａにベース２Ｆ追加
		base2B_F22->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base2B_D22 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock失敗のエラー処理省略
		base2B_D20->setPartsB(downJoint, base2B_D22);					//ベース３Ａにベース２Ｆ追加
		base2B_D22->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base1D_F24 = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock失敗のエラー処理省略
		base2B_F22->setPartsB(downJoint, base1D_F24);					//ベース３Ａにベース２Ｆ追加
		base1D_F24->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース２ＦにマシンガンＡ追加

		PartsBSptr base1D_D24 = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock失敗のエラー処理省略
		base2B_D22->setPartsB(downJoint, base1D_D24);					//ベース３Ａにベース２Ｆ追加
		base1D_D24->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//ベース２ＦにマシンガンＡ追加


		


		Object obj;					//ダミー
		this->update(obj);			//自機更新（探索木）
		startHp = maxHp;			//初期HPの記録
		startEnergy = maxEnergy;	//初期ENの記録
		startMan = maxMan;			//初期人の記録
	}
	
}


/*更新関数*/
void KosenWing::update(Object obj){
	/*各パラメータを更新する*/
	frameCnt++;										//フレームカウントの更新
	if(frameCnt > 50000) frameCnt = 0;

	/*パーツ関係の更新*/
	if(PartsBSptr tmp = core.lock()){
		/*パーツからの情報収集*/
		TellUpBox box = {
			0,0,		//hp, maxHp
			0,0,0,		//energy,maxEnergy,chargeEnergy
			0,0,0,		//man,requireMan,maxMan
			0,0,0,		//fire,burnFire,maxFire
			0,0,1,0};	//A,lostA,B,lostB				
		tmp->tellUp(box);
		hp = box.hp;
		maxHp = box.maxHp;
		energy = box.energy;
		chargeEnergy = box.chargeEnergy;
		maxEnergy = box.maxEnergy;
		man = box.man;
		requireMan = box.requireMan;
		maxMan = box.maxMan;
		fire = box.fire;
		burnFire = box.burnFire;
		maxFire = box.maxFire;
		partsANum = box.pertsANum;
		partsALost += box.pertsALost;
		partsBNum = box.pertsBNum;
		partsBLost += box.pertsBLost;

		/*回避値の更新*/
		tmp->setKaihi(kaihi);
	}
	else{//コアがやられてる
		//mb("コア破壊");
	}
	
	/*自機移動*/
	dir = atan2(move.y, move.x);					//現在の進行角算出
	dis = sqrt(move.x * move.x + move.y * move.y);	//移動量算出
	if(dis > maxMove){
		dis = maxMove;						//移動量抑止
	}
	else{
		dis *= subMove;
	}
	move.x = cos(dir) * dis;				//移動量抑止
	move.y = sin(dir) * dis;				//移動量抑止
	pos.x = pos.x + cos(dir) * dis;			//自機移動
	pos.y = pos.y + sin(dir) * dis;			//自機移動
	/*移動取り消し*/
	if(pos.x < SCREEN_INDENT){
		pos.x = SCREEN_INDENT;
	}
	if(pos.y < 0){
		pos.y = 0;
	}
	if(pos.x > SCREEN_WIDTH - SCREEN_INDENT - size){
		pos.x = SCREEN_WIDTH - SCREEN_INDENT - size;
	}
	if(pos.y > SCREEN_HEIGHT - size){
		pos.y = SCREEN_HEIGHT - size;
	}

	/*コアの更新*/
	if(PartsBSptr tmp = core.lock()){
		tmp->update((Object)(*this));	//コア更新（探索木）
	}

	/*回避値の更新*/
	addKaihi(-4);
}
