#include "obj_parts.hpp"

/*グローバルリソース定義*/
PartsAVsptr partsAList;			//パーツリスト
PartsAWptr partsAFactory(PartsASptr partsA){
		partsAList.push_back( partsA );			//リストにオブジェクト追加
		PartsAVsptr::iterator it = partsAList.end() - 1;	//直前のオブジェクトを参照
		return (*it);
}
PartsBVsptr partsBList;			//パーツリスト
PartsBWptr partsBFactory(PartsBSptr partsB){
		partsBList.push_back( partsB );			//リストにオブジェクト追加
		PartsBVsptr::iterator it = partsBList.end() - 1;	//直前のオブジェクトを参照
		return (*it);
}
/*コンストラクタ*/
Parts::Parts(){
	//パーツのデフォルト値
	pos = Vec2(0.0, 0.0);	//現在位置
	move = Vec2(0.0, 0.0);	//移動量
	dis = 0.0;				//移動量
	dir = 0.0;				//角度
	frameCnt = 0;			//経過フレーム数
	animeCnt = 0;			//アニメフレーム
	updateCheck = true;		//更新可否
	outputW = 1;			//出力幅
	outputH = 1;			//出力高
	maxEnergy = 10;			//最大の弾数
	energy = maxEnergy;		//現在の弾数
	chargeEnergy = 1;		//給弾する弾数
	maxMan = 10;			//最大の人員
	man = 5;				//現在の人員
	requireMan = 0;			//必要な人員
	fire = 5;				//現在の火勢
	burnFire = 20;			//発火する火勢
	maxFire = 50;			//最大の火勢
	kaihi = 0;
}
/*add関数*/
void Parts::addKaihi(int kaihi){
	Parts::kaihi += kaihi;
	if(Parts::kaihi > 100){
		Parts::kaihi = 100;
	}else if(Parts::kaihi < 0){
		Parts::kaihi = 0;
	}
}
/*報告関数*/
void Parts::tellUp(TellUpBox &box){
	box.hp += hp;
	box.maxHp += maxHp;
	box.energy += energy;
	box.chargeEnergy += chargeEnergy;
	box.maxEnergy += maxEnergy;
	box.man += man;
	box.requireMan += requireMan;
	box.maxMan += maxMan;
	box.fire += fire;
	box.burnFire += burnFire;
	box.maxFire += maxFire;
	this->subTellUp(box);
	return;
}
/*殺傷関数*/
void Parts::killMan(int damage){
	if(perCheck(25)){
		man -= damage;
	}
}

/*コンストラクタ*/
PartsA::PartsA(){
}
/*更新関数*/
void PartsA::update(Object obj){
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
	/*パーツの位置を更新*/
	pos.x = obj.getPos().x;
	pos.y = obj.getPos().y;

	/*給弾処理*/
	if(frameCnt%2 == 0 && man >= requireMan && fire < burnFire){	//人員十分、火災なし
		if(energy < maxEnergy) energy += chargeEnergy;
	}
	else if(frameCnt%3 == 0 && man >= requireMan){					//人員十分、火災あり
		if(energy < maxEnergy) energy += chargeEnergy;
	}
}
/*アクション関数個別*/
void PartsA::action(){
}
/*サブ報告関数*/
void PartsA::subTellUp(TellUpBox &box){
	return;
}

/*コンストラクタ*/
PartsB::PartsB(){
	//パーツBのデフォルト値
	weapon[mainWeapon] = weaponEmp;		//兵装有無
	weaponPosX[mainWeapon] = 0;			//兵装X座標（親からの相対）
	weaponPosY[mainWeapon] = 0;			//兵装Y座標（親からの相対）
	weapon[subWeapon] = weaponNG;		//兵装有無
	weaponPosX[subWeapon] = 0;			//兵装X座標（親からの相対）
	weaponPosY[subWeapon] = 0;			//兵装Y座標（親からの相対）
	joint[upJoint] = jointEmp;			//ジョイント有無
	jointPosX[upJoint] = 0;				//ジョイントX座標（親からの相対）
	jointPosY[upJoint] = 0;				//ジョイントY座標（親からの相対）
	joint[rightJoint] = jointEmp;		//ジョイント有無
	jointPosX[rightJoint] = 0;			//ジョイントX座標（親からの相対）
	jointPosY[rightJoint] = 0;			//ジョイントY座標（親からの相対）
	joint[downJoint] = jointEmp;		//ジョイント有無
	jointPosX[downJoint] = 0;			//ジョイントX座標（親からの相対）
	jointPosY[downJoint] = 0;			//ジョイントY座標（親からの相対）
	joint[leftJoint] = jointEmp;		//ジョイント有無
	jointPosX[leftJoint] = 0;			//ジョイントX座標（親からの相対）
	jointPosY[leftJoint] = 0;			//ジョイントY座標（親からの相対）
}

/*更新関数*/
void PartsB::update(Object obj){
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
	/*パーツの位置を更新*/
	pos.x = obj.getPos().x;
	pos.y = obj.getPos().y;

	/*下位兵装の更新*/
	for(int cnt = 0; cnt < weaponIndexEnd; cnt++){
		if(weapon[cnt] == (int)weaponExist){
			if(PartsASptr tmp = getPartsA((weaponIndex)cnt)){	
				/*位置の更新*/
				PartsB obj = (*this);
				obj.pos.x = pos.x + weaponPosX[cnt];
				obj.pos.y = pos.y + weaponPosY[cnt];
				tmp->update((Object)obj);		//位置を示すオブジェクトを渡す。

				/*下位から兵員の輸送*/
				if(man < maxMan && tmp->getMan() > tmp->getRequireMan()){
					//人員が最大でなく下位に余剰兵員がいるとき
					man += 1;
					tmp->addMan(-1);
				}

				/*上位から兵員の輸送*/
				else if(man > requireMan && tmp->getMan() < tmp->getRequireMan()){
					//人員が最大でなく下位に余剰兵員がいるとき
					man -= 1;
					tmp->addMan(1);
				}

				/*回避値の更新*/
				tmp->setKaihi(kaihi);
			}
		}
	}
	/*下位ジョイントの更新*/
	for(int cnt = 0; cnt < jointIndexEnd; cnt++){
		if(joint[cnt] == (int)jointDownExist){
			if(PartsBSptr tmp = getPartsB((jointIndex)cnt)){
				/*位置の更新*/
				PartsB obj = (*this);
				//obj.pos.x = jointPosX[cnt] + pos.x;
				//obj.pos.y = jointPosY[cnt] + pos.y;
				//下位ジョイント位置の決定
				//縮小処理
				obj.pos.x = pos.x + jointPosX[cnt] * (100 - kaihi) / 100;
				obj.pos.y = pos.y + jointPosY[cnt] * (100 - kaihi) / 100;
				tmp->update((Object)obj);		//位置を示すオブジェクトを渡す。

				/*下位から兵員の輸送*/
				if(man < maxMan && tmp->getMan() > tmp->getRequireMan()){
					//人員が最大でなく下位に余剰兵員がいるとき
					man += 1;
					tmp->addMan(-1);
				}

				/*上位から兵員の輸送*/
				else if(man > requireMan && tmp->getMan() < tmp->getRequireMan()){
					//人員が最大でなく下位に余剰兵員がいるとき
					man -= 1;
					tmp->addMan(1);
				}

				/*回避値の更新*/
				tmp->setKaihi(kaihi);
			}
		}
	}

}

/*兵装状態設定関数*/
void PartsB::setWeapon(weaponIndex index, weaponOK val){
	weapon[index] = val;
}
/*土台状態設定関数*/
void PartsB::setJoint(jointIndex index, jointOK val){
	joint[index] = val;
}
/*兵装取得*/
PartsASptr PartsB::getPartsA(weaponIndex index){
	if(index == mainWeapon){
		return partsA0.lock();
	}
	else{//index = subWeapon
		return partsA1.lock();
	}
}
/*土台取得*/
PartsBSptr PartsB::getPartsB(jointIndex index){
	if(index == upJoint){
		return partsB0.lock();
	}
	else if(index == rightJoint){
		return partsB1.lock();
	}
	else if(index == downJoint){
		return partsB2.lock();
	}
	else{//index = leftJoint
		return partsB3.lock();
	}
}
/*兵装追加関数*/
void PartsB::setPartsA(weaponIndex pos, PartsAWptr partsA){
	weapon[pos] = weaponExist;					//下位
	switch((int)pos){
	case (int)mainWeapon:
		partsA0 = partsA;			//兵装を追加
		break;
	default://(int)subWeapon
		partsA1 = partsA;			//兵装を追加
		break;
	}
	if(PartsASptr tmp = getPartsA(pos)){	//兵装に上位層の情報を格納する場合はここ
		//tmp->setPartsB(0, 1);				//兵装の上位の設定
	}
}
/*土台追加関数*/
void PartsB::setPartsB(jointIndex pos, PartsBSptr partsB){
	jointIndex jointPos;
	joint[pos] = jointDownExist;					//下位
	switch((int)pos){
	case (int)upJoint:
		partsB0 = PartsBWptr(partsB);			//ジョイントを追加
		jointPos = downJoint;					//接続先のジョイントの指定
		break;
	case (int)rightJoint:
		partsB1 = PartsBWptr(partsB);			//ジョイントを追加
		jointPos = leftJoint;					//接続先のジョイントの指定
		break;
	case (int)downJoint:
		partsB2 = PartsBWptr(partsB);			//ジョイントを追加
		jointPos = upJoint;						//接続先のジョイントの指定
		break;
	default://(int)leftJoint
		partsB3 = PartsBWptr(partsB);			//ジョイントを追加
		jointPos = rightJoint;					//接続先のジョイントの指定
		break;
	}
}

/*サブ報告関数*/
void PartsB::subTellUp(TellUpBox &box){
	/*パーツAの探索*/
	for(int pos = (int)mainWeapon; pos < (int)weaponIndexEnd; pos++){
		if(weapon[pos] == weaponExist){	
			if( PartsASptr tmp = getPartsA((weaponIndex)pos) ){
				box.pertsANum++;
				tmp->tellUp(box);
			}
			else{
				box.pertsALost++;
				weapon[(int)pos] = weaponEmp;
			}
		}
	}
	/*パーツBの探索*/
	for(int pos = (int)upJoint; pos < (int)jointIndexEnd; pos++){
		if(joint[pos] == jointDownExist){	
			if( PartsBSptr tmp = getPartsB((jointIndex)pos) ){
				box.pertsBNum++;
				tmp->tellUp(box);
			}
			else{
				box.pertsBLost++;
				joint[(int)pos] = jointEmp;
			}
		}
	}
	return;
}