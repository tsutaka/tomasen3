
#include <cassert>
#include <cmath>

#include "tomasen.hpp"
#include "event.hpp"
#include "obj_effect.hpp"
#include "obj_wing_friend.hpp"

/*::::::::メインループ::::::::*/
void Tomasen::runGame(HWND _hWnd){
	Tomasen::hWnd = _hWnd;
	//１プレイループ
	while(true){

		//ゲーム全体の初期化
		Tomasen::initGame();
		
		//フレームループ
		while(true){
			Tomasen::inputGame();			//入力処理
			Tomasen::communicationGame();	//伝達処理
			Tomasen::updateGame();			//更新処理
			Tomasen::deleteGame();			//削除処理
			Tomasen::printGame();			//描画処理
			await(1000/60);
		}
	};

	return;
}

/*::::::::初期処理::::::::*/
void Tomasen::initGame(){
	/*乱数の初期化*/
	srand((unsigned int)1);

	/*画像クラスの下準備*/
	IMAGE = new TipTile();
	IMAGE->init(hWnd, TEXT("image.bmp"), SCREEN_WIDTH, SCREEN_HEIGHT);
	IMAGE->setBasicColor(	IMAGE->tipNo(9,16), IMAGE->tipNo(10,16), IMAGE->tipNo(12,16),	//R, G, B
							IMAGE->tipNo(0,16), IMAGE->tipNo(15,16));						//B, W

	/*音楽クラスのした準備*/
	MUSIC = new Music();
	musicBGM_5 = MUSIC->Open("music/BGM_5.wav");
	musicShot = MUSIC->Open("music/Shot.wav");
	musicEnemyDown = MUSIC->Open("music/EnemyDown.wav");
	musicFriendHit = MUSIC->Open("music/UseItem.wav");
	//MUSIC->Play(musicBGM_5);

	/*各種初期設定*/
	canInput = false;			//入力可否フラグ
	stage = startStage;			//初期ステージの設定
	mode = startMode;			//初期画面の設定
	gold = 0;
	score = 0;
	stringV.push_back("←↑↓→　キー：移動");
	stringV.push_back("Shift:縮小 Z:射撃 X:主砲");

	/*自機配置*/
	kosenWing = friendFactory( 
		FriendSptr(new KosenWing()), Vec2(startPosX, startPosY) );	//弱スマポを取得

	/*ゲージの初期化*/	
	hpBar = barFactory( BarSptr(new HpBar()) );			//弱スマポを取得
	energyBar = barFactory( BarSptr(new EnergyBar()) );	//弱スマポを取得
	manBar = barFactory( BarSptr(new ManBar()) );		//弱スマポを取得
	fireBar = barFactory( BarSptr(new FireBar()) );		//弱スマポを取得


	/*ラベルの初期化*/
	goldLabel = labelFactory( LabelSptr(new GoldLabel()) );		//弱スマポを取得
	scoreLabel = labelFactory( LabelSptr(new ScoreLabel()) );	//弱スマポを取得


	/*イベントの設置*/
	eventFactory( EventSptr(new GameTitle()) );	//イベントを生成してリストへ
}

/*::::::::入力処理::::::::*/
void Tomasen::inputGame(){
	/*自機に対する入力*/
	shotPerm = 0;
	if(!canInput) return;
	if(FriendSptr tmp = kosenWing.lock()){
		/*移動量の更新*/
		if(GetAsyncKeyState(VK_UP)){//↑
			tmp->setMove(Vec2(0, -moveAmount) + tmp->getMove() );	//自機を上に移動
		}
		if(GetAsyncKeyState(VK_DOWN)) {//↓
			tmp->setMove(Vec2(0, moveAmount) + tmp->getMove() );	//自機を下に移動
		}
		if(GetAsyncKeyState(VK_LEFT)) {//←
			tmp->setMove(Vec2(-moveAmount, 0) + tmp->getMove() );	//自機を左に移動
		}
		if(GetAsyncKeyState(VK_RIGHT)) {//→
			tmp->setMove(Vec2(moveAmount, 0) + tmp->getMove() );	//自機を右に移動
		}
		if(GetAsyncKeyState('Z')) {//Z
			shotPerm = 1;											//射撃許可
			//MUSIC->Play(musicShot);
		}
		if(GetAsyncKeyState(VK_SHIFT)) {//Shift
			tmp->addKaihi(12);										//回避
			//MUSIC->Play(musicShot);
		}
	}

} 

/*::::::::伝達処理::::::::*/
void Tomasen::communicationGame(){

	/*ゲージ表示の伝達*/
	if(FriendSptr tmp = kosenWing.lock()){		
		if(BarSptr tmp2 = hpBar.lock()){				
			tmp2->setValue( tmp->getHp() );					//現在HPの更新
			tmp2->setMaxValue( tmp->getMaxHp() );			//最大HPの更新
			tmp2->setStartValue( tmp->getStartHp() );		//初期HPの更新
		}
		if(BarSptr tmp2 = energyBar.lock()){				
			tmp2->setValue( tmp->getEnergy() );				//現在ENの更新
			tmp2->setMaxValue( tmp->getMaxEnergy() );		//最大ENの更新
			tmp2->setStartValue( tmp->getStartEnergy() );	//初期ENの更新
		}
		if(BarSptr tmp2 = manBar.lock()){				
			tmp2->setValue( tmp->getMan() );				//現在人の更新
			tmp2->setMaxValue( tmp->getMaxMan() );			//最大人の更新
			tmp2->setStartValue( tmp->getStartMan() );		//初期人の更新
		}
		if(BarSptr tmp2 = fireBar.lock()){				
			tmp2->setValue( tmp->getFire() );				//現在炎の更新
			tmp2->setMaxValue( tmp->getBurnFire() );		//発火炎の更新
			tmp2->setStartValue( tmp->getMaxFire() );		//最大炎の更新
		}
	}

	/*ラベルの更新*/
	if(LabelSptr tmp = goldLabel.lock()){				
		tmp->setValue( gold );			//ゴールドの更新
	}
	if(LabelSptr tmp = scoreLabel.lock()){				
		tmp->setValue( score );			//スコアの更新
	}
}

/*::::::::更新処理::::::::*/
void Tomasen::updateGame(){

	/*イベントの更新処理*/
	for(EventVsptr::iterator it = eventList.begin(); it != eventList.end(); it++){
		(*it)->update();
	}
	for(EventVsptr::iterator it = eventList.begin(); it != eventList.end(); it++){
		(*it)->action();
	}

	/*敵機の更新*/
	for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
		(*it)->action(dummy);
	}

	/*自機系統の更新*/
	if(FriendSptr tmp = kosenWing.lock()){
		Object obj;			//ダミー
		tmp->update(obj);	//自機更新（探索木）
	}
	/*各パーツ固有の処理*/
	for(PartsAVsptr::iterator it = partsAList.begin(); it != partsAList.end(); it++){
		if(shotPerm) (*it)->action();
	}

	/*自弾更新処理*/
	for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}

	/*敵弾更新処理*/
	for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
		(*it)->action(dummy);
	}

	/*エフェクト更新処理*/
	for(EffectVsptr::iterator it = effectList.begin(); it != effectList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}

	/*バーの更新*/
	for(BarVsptr::iterator it = barList.begin(); it != barList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}

	/*ラベルの更新*/
	for(LabelVsptr::iterator it = labelList.begin(); it != labelList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}
	/*イベント系統の更新*/
	/*その他系統の更新*/
}

/*::::::::削除処理::::::::*/
void Tomasen::deleteGame(){

	/*エフェクト消滅判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(EffectVsptr::iterator it = effectList.begin(); it != effectList.end(); it++){
			if((*it)->getTimeOfLife() == 0){	//時間消滅
				effectList.erase(it);
				cnt = 1;
				break;
			}
			if(isIn(0 - wideArea, SCREEN_HEIGHT + wideArea, 
					0 - wideArea, SCREEN_WIDTH + wideArea, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//画面外消滅
				effectList.erase(it);
				cnt = 1;
				break;
			}
		}
	}

	/*イベント終了フラグ判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(EventVsptr::iterator it = eventList.begin(); it != eventList.end(); it++){
			int next = (*it)->nextEvent();
			if(next > 0){	//フラグ判定
				eventList.erase(it);
				switch(next){
				case 1:
					stringV.push_back("Stage1開始");
					eventFactory( EventSptr(new Stage1()) );
					break;
				case 2:
					stringV.push_back("Stage2開始");
					eventFactory( EventSptr(new Stage2()) );
					break;
				case 3:
					stringV.push_back("Stage3開始");
					eventFactory( EventSptr(new Stage3()) );
					break;
				case 4:
					stringV.push_back("Stage4開始");
					eventFactory( EventSptr(new Stage4()) );
					break;
				case 5:
					stringV.push_back("Stage5開始");
					eventFactory( EventSptr(new Stage5()) );
					break;
				}
				canInput = true;
				cnt = 1;
				break;
			}
		}
	}


	/*自弾当たり判定*/
	for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
		double bulletX = (*it)->getPos().x + (*it)->getSize() / 2;		//自弾X座標
		double bulletY = (*it)->getPos().y + (*it)->getSize() / 2;		//自弾Y座標
		int bulletSize = (*it)->getSize();	//自弾サイズ
		int bulletHp = (*it)->getHp();		//自弾耐久度
		for(EnemyVsptr::iterator it2 = enemyList.begin(); it2 != enemyList.end(); it2++){
			double enemyX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//敵機X座標
			double enemyY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//敵機Y座標
			int enemySize = (*it2)->getSize();//敵機サイズ
			int enemyHp = (*it2)->getHp();	//敵機耐久度
			if(	(bulletX - enemyX) * (bulletX - enemyX) + 
			(bulletY - enemyY) * (bulletY - enemyY) <
			(bulletSize + enemySize) * (bulletSize + enemySize) ){
				(*it)->damageHp(enemyHp);	//自弾耐久度減少
				(*it2)->damageHp(bulletHp);	//敵機耐久度減少
			}
			
		}
	}
	/*自弾消滅判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
			if(isIn(0, SCREEN_HEIGHT, 
					0, SCREEN_WIDTH, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//画面外消滅
				friendBulletList.erase(it);
				cnt = 1;
				break;
			}
			if((*it)->getHp() == 0){	//耐久度消滅
				friendBulletList.erase(it);
				cnt = 1;
				break;
			}
		}
	}

	/*敵機当たり判定*/
	for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
		double EnemyX = (*it)->getPos().x + (*it)->getSize() / 2;		//敵機X座標
		double EnemyY = (*it)->getPos().y + (*it)->getSize() / 2;		//敵機Y座標
		int EnemySize = (*it)->getSize();		//敵機サイズ
		int EnemyHp = (*it)->getHp();			//敵機耐久度
		/*対パーツA*/
		for(PartsAVsptr::iterator it2 = partsAList.begin(); it2 != partsAList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//パーツX座標
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//パーツY座標
			int partsSize = (*it2)->getSize();	//パーツサイズ
			int partsHp = (*it2)->getHp();		//パーツ耐久度
			if(	(EnemyX - partsX) * (EnemyX - partsX) + 
			(EnemyY - partsY) * (EnemyY - partsY) <
			(EnemySize + partsSize) * (EnemySize + partsSize) ){
				(*it)->damageHp(partsHp);			//敵機耐久度減少
				(*it2)->damageHp(EnemyHp);			//パーツ耐久度減少
				MUSIC->Play(musicFriendHit);		//被弾音
			}
		}
		EnemyHp = (*it)->getHp();			//敵弾耐久度
		/*対パーツB*/
		for(PartsBVsptr::iterator it2 = partsBList.begin(); it2 != partsBList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//パーツX座標
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//パーツY座標
			int partsSize = (*it2)->getSize();	//パーツサイズ
			int partsHp = (*it2)->getHp();		//パーツ耐久度
			if(	(EnemyX - partsX) * (EnemyX - partsX) + 
			(EnemyY - partsY) * (EnemyY - partsY) <
			(EnemySize + partsSize) * (EnemySize + partsSize) ){
				(*it)->damageHp(partsHp);			//敵機耐久度減少
				(*it2)->damageHp(EnemyHp);			//パーツ耐久度減少
				MUSIC->Play(musicFriendHit);		//被弾音
			}
		}
	}
	/*敵機消滅判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
			if(isIn(0 - wideArea, SCREEN_HEIGHT + wideArea, 
					0 - wideArea, SCREEN_WIDTH + wideArea, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//画面外消滅
				enemyList.erase(it);
				cnt = 1;
				break;
			}
			if((*it)->getHp() == 0){					//耐久度消滅
				score += (*it)->getMaxHp() * 10;		//スコア加算
				MUSIC->Play(musicEnemyDown);			//爆破音
				//爆炎
				effectFactory(EffectSptr(new Explosion()), 
					(*it)->getPos(), Vec2( (*it)->getPos().x, (*it)->getPos().y - 100.0 )
					);
				enemyList.erase(it);
				cnt = 1;
				break;
			}
		}
	}


	/*敵弾当たり判定*/
	for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
		double bulletX = (*it)->getPos().x + (*it)->getSize() / 2;		//敵弾X座標
		double bulletY = (*it)->getPos().y + (*it)->getSize() / 2;		//敵弾Y座標
		int bulletSize = (*it)->getSize();		//敵弾サイズ
		int bulletHp = (*it)->getHp();			//敵弾耐久度
		int bulletFire = (*it)->getFire();		//弾の火力
		/*対パーツA*/
		for(PartsAVsptr::iterator it2 = partsAList.begin(); it2 != partsAList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//パーツX座標
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//パーツY座標
			int partsSize = (*it2)->getSize();	//パーツサイズ
			int partsHp = (*it2)->getHp();		//パーツ耐久度
			if(	(bulletX - partsX) * (bulletX - partsX) + 
			(bulletY - partsY) * (bulletY - partsY) <
			(bulletSize + partsSize) * (bulletSize + partsSize) ){
				(*it)->damageHp(partsHp);			//敵弾耐久度減少
				(*it2)->damageHp(bulletHp);			//パーツ耐久度減少
				(*it2)->killMan(bulletHp);			//殺傷
				(*it2)->addFire( bulletFire );		//火力ダメージ
				//爆炎
				effectFactory(EffectSptr(new Explosion()), 
					(*it)->getPos(), 
					Vec2( (*it)->getPos().x + makeRand(0.0, 50), 
						(*it)->getPos().y + makeRand(200.0, 60) )
					);
				//MUSIC->Play(musicFriendHit);		//被弾音
			}
		}
		bulletHp = (*it)->getHp();			//敵弾耐久度
		/*対パーツB*/
		for(PartsBVsptr::iterator it2 = partsBList.begin(); it2 != partsBList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//パーツX座標
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//パーツY座標
			int partsSize = (*it2)->getSize();	//パーツサイズ
			int partsHp = (*it2)->getHp();		//パーツ耐久度
			if(	(bulletX - partsX) * (bulletX - partsX) + 
			(bulletY - partsY) * (bulletY - partsY) <
			(bulletSize + partsSize) * (bulletSize + partsSize) ){
				(*it)->damageHp(partsHp);			//敵弾耐久度減少
				(*it2)->damageHp(bulletHp);			//パーツ耐久度減少
				(*it2)->killMan(bulletHp);			//殺傷
				(*it2)->addFire( bulletFire );		//火力ダメージ
				//爆炎
				effectFactory(EffectSptr(new Explosion()), 
					(*it)->getPos(), 
					Vec2( (*it)->getPos().x + makeRand(0.0, 30), 
						(*it)->getPos().y + makeRand(250.0, 90) )
					);

				//MUSIC->Play(musicFriendHit);		//被弾音
			}
		}
	}
	/*敵弾消滅判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
			if(isIn(0, SCREEN_HEIGHT, 
					0, SCREEN_WIDTH, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//画面外消滅
				enemyBulletList.erase(it);
				cnt = 1;
				break;
			}
			if((*it)->getHp() == 0){	//耐久度消滅
				enemyBulletList.erase(it);
				cnt = 1;
				break;
			}
		}
	}

	/*パーツA消滅判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(PartsAVsptr::iterator it = partsAList.begin(); it != partsAList.end(); it++){
			if((*it)->getHp() == 0){	//耐久度消滅
				partsAList.erase(it);
				cnt = 1;
				break;
			}
		}
	}
	/*パーツB消滅判定*/
	for(int cnt = 1; cnt > 0; cnt--){//イテレータの削除なので小細工
		for(PartsBVsptr::iterator it = partsBList.begin(); it != partsBList.end(); it++){
			if((*it)->getHp() == 0){	//耐久度消滅
				partsBList.erase(it);
				cnt = 1;
				break;
			}
		}
	}


}

/*::::::::表示処理::::::::*/
void Tomasen::printGame(){
	/*画面の塗りつぶし*/
	IMAGE->drawTip(	0.0, 0.0, 
					(double)SCREEN_WIDTH, (double)SCREEN_HEIGHT, 
					IMAGE->getBlack());
	/*エフェクト描画処理*/
	for(EffectVsptr::iterator it = effectList.begin(); it != effectList.end(); it++){
		IMAGE->drawTile((*it)->getPos(), 
						(*it)->getOutputW(), 
						(*it)->getOutputH(), 
						(*it)->getImageX(), (*it)->getImageY(), 
						(*it)->getImageW(), (*it)->getImageH());

	}
	/*パーツB描画処理*/
	for(PartsBVsptr::iterator it = partsBList.begin(); it != partsBList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	/*パーツA描画処理*/
	for(PartsAVsptr::iterator it = partsAList.begin(); it != partsAList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	
	/*自弾描画処理*/
	for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	
	/*敵機描画処理*/
	for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
		IMAGE->drawTile( (*it)->getPos().x, (*it)->getPos().y,	//x, y,
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(),		//ino
										(*it)->getImageY() ), 
						(*it)->getImageW(), (*it)->getImageH()	//ix, iy, 
						);
	}
	
	/*敵弾描画処理*/
	for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	


	/*両側塗りつぶし*/
	IMAGE->drawTip(	0.0, 0.0, 
					(double)SCREEN_INDENT, (double)SCREEN_HEIGHT, 
					IMAGE->tipNo(4,16));
	IMAGE->drawTip(	(double)(SCREEN_WIDTH - SCREEN_INDENT), 0.0, 
					(double)SCREEN_INDENT, (double)SCREEN_HEIGHT, 
					IMAGE->tipNo(4,16));

	/*デバッグ文字列表示*/
	if(FriendSptr tmp = kosenWing.lock()){
		char str[256];
		sprintf_s(str, "A:%03d, B:%03d, cnt:%d", partsAList.size(), partsBList.size(), tmp->getFrameCnt());
		IMAGE->printText(0, 0, str);
		sprintf_s(str, "X:%+03.3f  MoveX:%+03.3f", tmp->getPos().x, tmp->getMove().x);
		IMAGE->printText(0, 1, str);
		sprintf_s(str, "Y:%+03.3f  MoveY:%+03.3f", tmp->getPos().y, tmp->getMove().y);
		IMAGE->printText(0, 2, str);
		sprintf_s(str, "自弾:%03d, 敵弾:%03d", friendBulletList.size(), enemyBulletList.size());
		IMAGE->printText(0, 3, str);
		sprintf_s(str, "敵機:%03d, Event数:%03d", enemyList.size(), eventList.size());
		IMAGE->printText(0, 4, str);
		sprintf_s(str, "effect:%03d, hp:%03d/%03d", effectList.size(), tmp->getHp(), tmp->getMaxHp());
		IMAGE->printText(0, 5, str);
		sprintf_s(str, "A:%03d/%03d, B:%03d/B:%03d",	tmp->getPartsANum(), tmp->getPartsANum() + tmp->getPartsALost(), 
														tmp->getPartsBNum(), tmp->getPartsBNum() + tmp->getPartsBLost());
		IMAGE->printText(0, 6, str);
		sprintf_s(str, "%03d %03d %03d",	tmp->getFire(), tmp->getMaxMan(), tmp->getStartMan() );
		IMAGE->printText(0, 7, str);
	}
	
	/*メッセージ欄枠*/
	IMAGE->drawFillTip(1, 15, 11, 20, IMAGE->tipNo(21,17));
	/*コマンド欄*/
	IMAGE->drawFillTip(1, 36, 11, 1, IMAGE->tipNo(21,17));

	/*メッセージ*/
	int cnt = 0;	//20件まで表示
	for(StringV::iterator it = stringV.begin(); it != stringV.end(); it++){
		IMAGE->printText(1, 15 + (20 - stringV.size()) + cnt, (*it).c_str());
		cnt++;
		if(cnt >= 20) break;
	}

	/*バーの表示*/
	for(BarVsptr::iterator it = barList.begin(); it != barList.end(); it++){
		IMAGE->printText((int)(*it)->getPos().x/tipSize - 2, 
			(int)(*it)->getPos().y/tipSize, (*it)->getName().c_str());
		IMAGE->drawFillTip((*it)->getPos(), 
			(*it)->getSize(), 1, 
		IMAGE->tipNo((*it)->getUnderImageX(), (*it)->getUnderImageY()) );		//下地
		if((*it)->getStartValue() > 0){											//零除算の回避
			IMAGE->drawTip((*it)->getPos().x, (*it)->getPos().y, 
				(double)(*it)->getSize() * tipSize * (*it)->getMaxValue() / (*it)->getStartValue(), 
				(double)1 * tipSize, 
				IMAGE->tipNo((*it)->getMaxImageX(), (*it)->getMaxImageY()));	//現最大バー
			IMAGE->drawTip((*it)->getPos().x, (*it)->getPos().y, 
				(double)(*it)->getSize() * tipSize * (*it)->getPrintValue() / (*it)->getStartValue(), 
				(double)1 * tipSize, 
				IMAGE->tipNo((*it)->getImageX(), (*it)->getImageY()));			//現在値のバー
		}
		else{
			//mb("最大値が零又は負の数");
		}
		IMAGE->drawFillTip((*it)->getPos(), 
			(*it)->getSize(), 1, 
			IMAGE->tipNo((*it)->getOverImageX(), (*it)->getOverImageY()) );		//上枠
	}
	
	/*ラベルの表示*/
	for(LabelVsptr::iterator it = labelList.begin(); it != labelList.end(); it++){
		IMAGE->printText((int)(*it)->getPos().x/tipSize, 
			(int)(*it)->getPos().y/tipSize, 
			(*it)->getName().c_str());
		sprintf_s(checktext, sizeof(checktext), "%08d", (*it)->getPrintValue());
		IMAGE->printText((int)(*it)->getPos().x/tipSize + 7, 
			(int)(*it)->getPos().y/tipSize, 
			checktext);
		
	}

	/*ディスプレイに表示*/
	IMAGE->drawEnd();
}