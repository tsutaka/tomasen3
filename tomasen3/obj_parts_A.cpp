#include "obj_parts_A.hpp"
#include "obj_bullet.hpp"


EngineA::EngineA(){
	name = TEXT("ƒGƒ“ƒWƒ“‚`");	//–¼‘O
	maxHp = 10;					//Å‘å‘Ï‹v“x
	hp = maxHp;					//Œ»Ý‘Ï‹v“x
	imageX = 0;					//‰æ‘œxÀ•W
	imageY = 0;					//‰æ‘œyÀ•W
	imageW = 1;					//‰æ‘œ•
	imageH = 1;					//‰æ‘œ‚
	animeMax = 4;				//ƒAƒjƒ–‡”
	animeWait = 10;				//‚P–‡“–‚è‚ÌƒtƒŒ[ƒ€
	size = tipSize;				//“–‚½‚è”»’è”¼Œa
}

void EngineA::action(){
}

CockpitA::CockpitA(){
	name = TEXT("ƒRƒbƒNƒsƒbƒg‚`");	//–¼‘O
	maxHp = 10;						//Å‘å‘Ï‹v“x
	hp = maxHp;						//Œ»Ý‘Ï‹v“x
	imageX = 4;						//‰æ‘œxÀ•W
	imageY = 0;						//‰æ‘œyÀ•W
	imageW = 1;						//‰æ‘œ•
	imageH = 1;						//‰æ‘œ‚
	animeMax = 4;					//ƒAƒjƒ–‡”
	animeWait = 10;					//‚P–‡“–‚è‚ÌƒtƒŒ[ƒ€
	size = tipSize;					//“–‚½‚è”»’è”¼Œa
}

void CockpitA::action(){
}

MachineGunA::MachineGunA(){
	name = TEXT("‹@ŠÖe‚`");	//–¼‘O
	maxHp = 10;					//Å‘å‘Ï‹v“x
	hp = maxHp;					//Œ»Ý‘Ï‹v“x
	imageX = 8;					//‰æ‘œxÀ•W
	imageY = 0;					//‰æ‘œyÀ•W
	imageW = 1;					//‰æ‘œ•
	imageH = 1;					//‰æ‘œ‚
	animeMax = 4;				//ƒAƒjƒ–‡”
	animeWait  = 4;		        //‚P–‡“–‚è‚ÌƒtƒŒ[ƒ€
	size = tipSize;				//“–‚½‚è”»’è”¼Œa
	
	maxEnergy = 100;			//Å‘å‚Ì’e”
	energy = maxEnergy;			//Œ»Ý‚Ì’e”
	chargeEnergy = 1;			//‹‹’e‚·‚é’e”
	maxMan = 10;				//Å‘å‚Ìlˆõ
	man = maxMan;				//Œ»Ý‚Ìlˆõ
	requireMan = 2;				//•K—v‚Èlˆõ
	fire = 0;					//Œ»Ý‚Ì‰Î¨
	burnFire = 30;				//”­‰Î‚·‚é‰Î¨
	maxFire = 80;				//Å‘å‚Ì‰Î¨
	
	stopShot = 1;				//
}  

void MachineGunA::action(){
	/*ŽËŒ‚ˆ—*/
	if(energy > 0 && man >= requireMan && stopShot == 1 && kaihi == 0){
		friendBulletFactory( FriendBulletSptr( new NormalBullet()), 
			Vec2(pos.x + (rand() % 11 - 5), pos.y) );
		//ŽËŒ‚‰¹
		energy -= 1;
	}
	else if(energy <= 0){			//ŽËŒ‚•s‰Â
		stopShot = 0;
	}
	else if(energy == maxEnergy){	//ŽËŒ‚ÄŠJ
		stopShot = 1;
	}
}