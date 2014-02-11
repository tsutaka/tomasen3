#include "obj_wing_enemy.hpp"

#include <cmath>

#include "obj_bullet.hpp"
/*�O���[�o�����\�[�X��`*/
EnemyVsptr enemyList;				//�G�@���X�g
void enemyFactory(EnemySptr enemy, Vec2 pos, int pattern){
		enemyList.push_back( enemy );					//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;	//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(pos);								//�G�@���w��ʒu�Ɉړ�
		(*it)->setPattern(pattern);						//�G�@�̍s���p�^�[���̎w��
}

EnemyA::EnemyA(){
	/*������*/
	name = TEXT("�q�Q");	//���O
	maxHp = 5;				//�ő�ϋv�x
	imageX = 0;				//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	outputW = 2;			//�o�͕�
	outputH = 2;			//�o�͍�
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 7.0);	//�ړ���
	hp = maxHp;				//HP
}
void EnemyA::action(Object obj){
	/*�e�̔���*/
	if(perCheck(1) && canShot > 0){
		enemyBulletList.push_back( 
			EnemyBulletSptr( new SprinklerBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(makeRand(pos.x, 5), pos.y));				//�e�̏����ʒu����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//A1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(-2.5, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && pos.x < SCREEN_INDENT + 50){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -5.0);	//�ړ���
		}
		break;
	case 1: //A2
		/*�ڕW�ւ̈ړ�*/
		if(pos.x < targetPos.x - dis) move.x = dis;
		if(pos.y < targetPos.y - dis) move.y = dis;
		if(pos.x > targetPos.x + dis) move.x = -dis;
		if(pos.y > targetPos.y + dis) move.y = -dis;
		if(phase == 0){
			canShot = 1;
			phase++;
			targetPos = Vec2(SCREEN_WIDTH / 2, 150);
		}
		if(phase == 1 && pos.x > SCREEN_WIDTH / 2){
			phase++;
			targetPos = Vec2(SCREEN_WIDTH - SCREEN_INDENT + 500, -500);
		}
		break;
	case 2: //A3
		if(phase == 0){
			phase++;
			move = Vec2(0.0, -6.0);	//�ړ���
		}
		else if(phase == 1 && pos.y < 100){
			phase++;
			move = Vec2(3.0, 1.5);	//�ړ���
			canShot = 1;
		}
		break;
	case 3: //A4
		if(phase == 0){
			phase++;
			move = Vec2(0.0, -6.0);	//�ړ���
		}
		else if(phase == 1 && pos.y < 100){
			phase++;
			move = Vec2(-3.0, 1.5);	//�ړ���
			canShot = 1;
		}
		break;
	case 4: //A5
		if(phase == 0){
			phase++;
			move = Vec2(0.0, 6.0);	//�ړ���
		}
		else if(phase == 1 && pos.y > 100){
			phase++;
			canShot = 1;
			dir = PI/2 + 0.1 * makeRand(0.0, 5);	//�p�x
			dis = 5.0;
			move.x = cos(dir) * dis;
			move.y = sin(dir) * dis;
		}
		break;
	}

}

EnemyB::EnemyB(){
	/*������*/
	name = TEXT("�}�C��");	//���O
	maxHp = 50;				//�ő�ϋv�x
	imageX = 4;				//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}
void EnemyB::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new SprinklerBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	case 1:	//B2
		if(phase == 0){
			phase++;
			move = Vec2(0.0, 3.0);	//�ړ���
		}
		else if(phase == 1 && pos.y > 100){
			phase++;
			canShot = 1;
			move = Vec2(2.0, 0.0);	//�ړ���
		}
		else if(phase == 2 && pos.x > SCREEN_WIDTH - SCREEN_INDENT){
			phase++;
			canShot = 0;
			move = Vec2(2.0, 0.0);	//�ړ���
		}
		break;
	}
	
}

EnemyC::EnemyC(){
	/*������*/
	name = TEXT("���b�J�N");	//���O
	maxHp = 150;				//�ő�ϋv�x
	imageX = 8;				//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	hp = maxHp;				//HP
}

void EnemyC::action(Object obj){
	/*�e�̔���*/
	if(canShot > 0 && frameCnt % 30 == 0){
		for(shotCnt = 0.0; shotCnt < 2 * PI; shotCnt += 2 * PI / 40){
			enemyBulletList.push_back( 
				EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
			EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
			(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
			(*it)->setDir(shotCnt);							//�e�̏����p�x����
		}
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//C1
		if(phase == 0){
			phase++;
			move = Vec2(0.0, 4.0);	//�ړ���
		}
		else if(phase == 1 && pos.y > 100){
			phase++;
			canShot = 1;
			move = Vec2(0.0, 0.0);	//�ړ���
		}
		else if(phase == 2 && frameCnt > 300){
			phase++;
			canShot = 1;
			move = Vec2(1.0, 0.0);	//�ړ���
		}
		else if(phase == 3 && pos.x > SCREEN_WIDTH - SCREEN_INDENT - 50){
			phase++;
			canShot = 1;
			move = Vec2(-1.0, 0.0);	//�ړ���
		}
		else if(phase == 4 && pos.x < SCREEN_INDENT + 50){
			phase++;
			canShot = 1;
			move = Vec2(0.0, -4.0);	//�ړ���
		}
		break;
	}
	
}

EnemyD::EnemyD(){
	/*������*/
	name = TEXT("���b�N");	//���O
	maxHp = 50;				//�ő�ϋv�x
	imageX = 40;			//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 2;			//�o�͕�
	outputH = 2;			//�o�͕�
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	hp = maxHp;				//HP
}

void EnemyD::action(Object obj){

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//D1
		move += Vec2(makeRand(0.0, 4) * 0.1, makeRand(1.0, 4) * 0.1);	//�ړ���
		break;
	}
	
}

EnemyE::EnemyE(){
	/*������*/
	name = TEXT("���[�W���b�N");	//���O
	maxHp = 50;				//�ő�ϋv�x
	imageX = 40;			//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͕�
	size = tipSize*5;		//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyE::action(Object obj){
	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//E1
		move += Vec2(makeRand(0.0, 4) * 0.01, makeRand(1.0, 4) * 0.01);	//�ړ���
		break;
	}
	
}

EnemyF::EnemyF(){
	/*������*/
	name = TEXT("�^�R�X");	//���O
	maxHp = 50;				//�ő�ϋv�x
	imageX = 32;			//�摜x���W
	imageY = 14;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	size = tipSize*2;		//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyF::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		canShot = 1;
		break;
	}
	
}

EnemyG::EnemyG(){
	/*������*/
	name = TEXT("�{�[��");	//���O
	maxHp = 15;				//�ő�ϋv�x
	imageX = 0;				//�摜x���W
	imageY = 13;			//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyG::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 5 == 0){
		shotCnt += 0.5;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WideBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//G1
		phase++;
		move = Vec2(0.0, 0.0);	//�ړ���
		canShot = 1;
		break;
	}
	
}

EnemyH::EnemyH(){
	/*������*/
	name = TEXT("�o�^�t���C");	//���O
	maxHp = 60;				//�ő�ϋv�x
	imageX = 4;				//�摜x���W
	imageY = 13;			//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����

	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyH::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new GreenBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//H1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	}
	
}

EnemyI::EnemyI(){
	/*������*/
	name = TEXT("�S�L");	//���O
	maxHp = 150;			//�ő�ϋv�x
	imageX = 16;			//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	size = tipSize*2;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 10;			//�t���[���҂�����
	
	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyI::action(Object obj){
	/*�e�̔���*/
	


	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//I1
		if(canShot > 0 && frameCnt % 2 == 0){
			shotCnt += PI / 15.0;
			if(shotCnt > PI / 2 ) shotCnt = - PI / 2; 
			enemyBulletList.push_back( 
				EnemyBulletSptr( new SprinklerBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
			EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
			(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
			(*it)->setDir(shotCnt);							//�e�̏����p�x����
		}
		phase++;
		move = Vec2(0.56, 1.043);	//�ړ���
		canShot = 1;
		if(phase > 120) {
			shotCnt = PI / 2; 
			phase = 0;
			pattern = 1;
		}
		break;
	case 1:	//I1
		if(canShot > 0 && frameCnt % 2 == 0){
			shotCnt -= PI / 15.0;
			if(shotCnt < PI / 2 ) shotCnt = PI * 3 / 2; 
			enemyBulletList.push_back( 
				EnemyBulletSptr( new SprinklerBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
			EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
			(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
			(*it)->setDir(shotCnt);							//�e�̏����p�x����
		}
		phase++;
		move = Vec2(-0.56, 1.443);	//�ړ���
		canShot = 1;
		if(phase > 120) {
			shotCnt = PI / 2; 
			phase = 0;
			pattern = 0;
		}
		break;
	}
	
}

EnemyJ::EnemyJ(){
	/*������*/
	name = TEXT("���~");	//���O
	maxHp = 30;				//�ő�ϋv�x
	imageX = 40;			//�摜x���W
	imageY = 14;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	size = tipSize*2;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����
	
	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyJ::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	}
	
}

EnemyK::EnemyK(){
	/*������*/
	name = TEXT("�C�X�G��");//���O
	maxHp = 20;				//�ő�ϋv�x
	imageX = 8;				//�摜x���W
	imageY = 13;			//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	size = tipSize;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����
	
	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyK::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	}
	
}

EnemyL::EnemyL(){
	/*������*/
	name = TEXT("�T�n�G��");	//���O
	maxHp = 50;				//�ő�ϋv�x
	imageX = 16;				//�摜x���W
	imageY = 14;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	size = tipSize*2;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����
	
	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyL::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	}
	
}

EnemyN::EnemyN(){
	/*������*/
	name = TEXT("�����̎g��");	//���O
	maxHp = 150;				//�ő�ϋv�x
	imageX = 24;				//�摜x���W
	imageY = 12;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	size = tipSize*2;			//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����
	
	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyN::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	}
	
}

EnemyO::EnemyO(){
	/*������*/
	name = TEXT("����");	//���O
	maxHp = 500;			//�ő�ϋv�x
	imageX = 24;			//�摜x���W
	imageY = 14;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	size = tipSize*2;		//�����蔻�蔼�a
	animeMax = 4;			//�t���[����
	animeWait = 4;			//�t���[���҂�����
	
	dis = 3.0;				//�ړ���
	move = Vec2(0.0, 2.0);	//�ړ���
	hp = maxHp;				//HP
	shotCnt = 0.0;			//�ˌ��p�x
}

void EnemyO::action(Object obj){
	/*�e�̔���*/
	if(shotCnt > 10000.0) shotCnt = 0; 
	if(canShot > 0 && frameCnt % 2 == 0){
		shotCnt += 0.2;
		enemyBulletList.push_back( 
			EnemyBulletSptr( new WeakBullet()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end()-1;	
		(*it)->setPos(Vec2(pos.x, pos.y));				//�e�̏����ʒu����
		(*it)->setDir(shotCnt);							//�e�̏����p�x����
	}

	/*�ړ������̌���*/
	switch(pattern){
	case 0:	//B1
		if(phase == 0 && pos.y > makeRand(200.0, 20)){
			phase++;
			move = Vec2(0.0, 0.0);	//�ړ���
			canShot = 1;
		}
		else if(phase == 1 && frameCnt > 600){
			phase++;
			canShot = 0;
			move = Vec2(0.0, -1.0);	//�ړ���
		}
		break;
	}
	
}
