#include <cmath>

#include "obj_bullet.hpp"


/*�O���[�o�����\�[�X��`*/
FriendBulletVsptr friendBulletList;					//���e���X�g
void friendBulletFactory(FriendBulletSptr friendBullet, Vec2 pos){
		friendBulletList.push_back( friendBullet );						//���X�g�ɃI�u�W�F�N�g�ǉ�
		FriendBulletVsptr::iterator it = friendBulletList.end() - 1;	//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(pos);												//���e���w��ʒu�Ɉړ�
}
EnemyBulletVsptr enemyBulletList;					//�G�e���X�g
void enemyBulletFactory(EnemyBulletSptr enemyBullet, Vec2 pos){
		enemyBulletList.push_back( enemyBullet );						//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyBulletVsptr::iterator it = enemyBulletList.end() - 1;		//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(pos);												//�G�e���w��ʒu�Ɉړ�
}

Bullet::Bullet(){
	//�f�t�H���g�l
	pos = Vec2(0.0, 0.0);	//���݈ʒu
	move = Vec2(0.0, 0.0);	//�ړ���
	dis = 0.0;				//�ړ���
	dir = 0.0;				//�p�x
	frameCnt = 0;			//�o�߃t���[����
	animeCnt = makeRand(4);	//�A�j���t���[��
	updateCheck = true;		//�X�V��
	outputW = 1;			//�o�͕�
	outputH = 1;			//�o�͍�

	fire = 1;				//�Η�
}
void FriendBullet::update(Object obj){
	/*�J�E���g�A�b�v*/
	frameCnt++;
	if(frameCnt > 10000) frameCnt = 0;
	/*�A�j���[�V��������*/
	if(frameCnt % animeWait == 0){
		animeCnt++;
		if(animeCnt % animeMax == 0){
			animeCnt = 0;
		}
	}
	/*�e�̈ʒu���X�V*/
	pos.x += cos(dir) * dis;
	pos.y += sin(dir) * dis;
}


NormalBullet::NormalBullet(){
	name = TEXT("�ʏ�e");		//���O
	maxHp = 1;					//�ő�ϋv�x
	imageX = 0;					//�摜x���W
	imageY = 14;				//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = 2;					//�����蔻�蔼�a
	
	hp = maxHp;								//HP
	dis = 20.0;								//�ړ���
	dir = -PI/2 + 0.01 * makeRand(0.0, 3);	//�p�x
}
void EnemyBullet::update(Object obj){
	/*�J�E���g�A�b�v*/
	frameCnt++;
	if(frameCnt > 10000) frameCnt = 0;
	/*�A�j���[�V��������*/
	if(frameCnt % animeWait == 0){
		animeCnt++;
		if(animeCnt % animeMax == 0){
			animeCnt = 0;
		}
	}
	/*�e�̈ʒu���X�V*/
	pos.x += cos(dir) * dis;
	pos.y += sin(dir) * dis;
}
WeakBullet::WeakBullet(){
	name = TEXT("��e");
	maxHp = 1;					//�ő�ϋv�x
	imageX = 4;					//�摜x���W
	imageY = 14;				//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = 2;					//�����蔻�蔼�a
	
	hp = maxHp;					//HP
	dis = 6.0;								//�ړ���
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//�p�x
}
void WeakBullet::action(const Object &obj){
}
WideBullet::WideBullet(){
	name = TEXT("����");
	maxHp = 10;				//�ő�ϋv�x
	imageX = 0;					//�摜x���W
	imageY = 8;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a
	
	hp = maxHp;					//HP
	dis = 1.0;								//�ړ���
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//�p�x
}
void WideBullet::action(const Object &obj){
	dir += 0.01;
	dis += 0.01;
}
SprinklerBullet::SprinklerBullet(){
	name = TEXT("�X�v�����N���[");
	maxHp = 2;					//�ő�ϋv�x
	imageX = 8;					//�摜x���W
	imageY = 14;				//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = 2;					//�����蔻�蔼�a
	
	hp = maxHp;					//HP
	dis = 2.2;								//�ړ���
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//�p�x
}
void SprinklerBullet::action(const Object &obj){
}
GreenBullet::GreenBullet(){
	name = TEXT("�Βe");
	maxHp = 2;					//�ő�ϋv�x
	imageX = 4;					//�摜x���W
	imageY = 9;				//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = 6;					//�����蔻�蔼�a
	
	hp = maxHp;					//HP
	dis = 1.5;								//�ړ���
	dir = +PI/2 + 0.01 * makeRand(0.0, 2);	//�p�x
}
void GreenBullet::action(const Object &obj){
	if(frameCnt % 71 == 0){
		if(frameCnt % 2 == 0) dir -= PI / 4;
		else dir += PI / 8;
		dis += 0.2;
	}
}