#include "obj_parts_B.hpp"

CoreA::CoreA(){
	name = TEXT("コアA");	//名前
	maxHp = 30;				//最大耐久度
	hp = maxHp;				//現在耐久度
	imageX = 0;				//画像x座標
	imageY = 4;				//画像y座標
	imageW = 1;				//画像幅
	imageH = 1;				//画像高
	animeMax = 4;			//アニメ枚数
	animeWait = 4;			//１枚当りのフレーム
	size = tipSize;			//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[0] = 0;
	jointPosY[0] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[1] = tipSize;
	jointPosY[1] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[2] = 0;
	jointPosY[2] = tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[3] = -tipSize;
	jointPosY[3] = 0;

}

Base2B::Base2B(){
	name = TEXT("ベース2B");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 28;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[0] = 0;
	weaponPosY[0] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointEmp;
}

Base1A::Base1A(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース1A");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 0;					//画像x座標
	imageY = 5;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointNG;
}

Base4::Base4(){
	name = TEXT("ベース4");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 4;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = tipSize;
	jointPosY[(int)downJoint] = 0;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base3A::Base3A(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース3Ａ");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 8;					//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base3B::Base3B(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース3B");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 12;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = -tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base3C::Base3C(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース3C");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 16;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = -tipSize;
	joint[(int)leftJoint] = jointNG;
}

Base3D::Base3D(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース3D");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 20;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = -tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2A::Base2A(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース2A");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 24;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2C::Base2C(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース2C");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 32;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2D::Base2D(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース2D");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 36;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointNG;
}

Base2E::Base2E(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース2E");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 40;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2F::Base2F(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース2F");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 44;				//画像x座標
	imageY = 4;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointNG;
}

Base1B::Base1B(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース1B");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 4;					//画像x座標
	imageY = 5;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base1C::Base1C(){
	/*オブジェクトパラメータ*/
	name = TEXT("ベース1C");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 8;					//画像x座標
	imageY = 5;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	/*兵装*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*ジョイント*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointNG;
}

Base1D::Base1D(){
	name = TEXT("ベース1D");	//名前
	maxHp = 10;					//最大耐久度
	hp = maxHp;					//現在耐久度
	imageX = 12;				//画像x座標
	imageY = 5;					//画像y座標
	imageW = 1;					//画像幅
	imageH = 1;					//画像高
	animeMax = 4;				//アニメ枚数
	animeWait = 4;				//１枚当りのフレーム
	size = tipSize;				//当たり判定半径

	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointNG;
}