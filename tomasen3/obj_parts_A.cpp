#include "obj_parts_A.hpp"
#include "obj_bullet.hpp"


EngineA::EngineA(){
	name = TEXT("�G���W���`");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 0;					//�摜x���W
	imageY = 0;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 10;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a
}

void EngineA::action(){
}

CockpitA::CockpitA(){
	name = TEXT("�R�b�N�s�b�g�`");	//���O
	maxHp = 10;						//�ő�ϋv�x
	hp = maxHp;						//���ݑϋv�x
	imageX = 4;						//�摜x���W
	imageY = 0;						//�摜y���W
	imageW = 1;						//�摜��
	imageH = 1;						//�摜��
	animeMax = 4;					//�A�j������
	animeWait = 10;					//�P������̃t���[��
	size = tipSize;					//�����蔻�蔼�a
}

void CockpitA::action(){
}

MachineGunA::MachineGunA(){
	name = TEXT("�@�֏e�`");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 8;					//�摜x���W
	imageY = 0;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait  = 4;		        //�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a
	
	maxEnergy = 100;			//�ő�̒e��
	energy = maxEnergy;			//���݂̒e��
	chargeEnergy = 1;			//���e����e��
	maxMan = 10;				//�ő�̐l��
	man = maxMan;				//���݂̐l��
	requireMan = 2;				//�K�v�Ȑl��
	fire = 0;					//���݂̉ΐ�
	burnFire = 30;				//���΂���ΐ�
	maxFire = 80;				//�ő�̉ΐ�
	
	stopShot = 1;				//
}  

void MachineGunA::action(){
	/*�ˌ�����*/
	if(energy > 0 && man >= requireMan && stopShot == 1 && kaihi == 0){
		friendBulletFactory( FriendBulletSptr( new NormalBullet()), 
			Vec2(pos.x + (rand() % 11 - 5), pos.y) );
		//�ˌ���
		energy -= 1;
	}
	else if(energy <= 0){			//�ˌ��s��
		stopShot = 0;
	}
	else if(energy == maxEnergy){	//�ˌ��ĊJ
		stopShot = 1;
	}
}