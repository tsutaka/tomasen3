#include "obj_wing.hpp"
 

void Friend::update(Object obj){

}


/*�R���X�g���N�^*/
Enemy::Enemy(){
	//�f�t�H���g�l
	pos = Vec2(0.0, 0.0);		//���݈ʒu
	move = Vec2(0.0, 0.0);		//�ړ���
	dis = 5.0;					//�ړ���
	dir = 0.0;					//�p�x
	frameCnt = 0;				//�o�߃t���[����
	animeCnt = 0;				//�A�j���t���[��
	updateCheck = true;			//�X�V��
	pattern = 0;				//�s���p�^�[��
	targetPos = Vec2(0.0,0.0);	//�ړ��ړI���W
	phase = 0;					//�s���t�F�[�Y
	canShot = 0;				//�ˌ�����
	outputW = 1;			//�o�͕�
	outputH = 1;			//�o�͍�
}
void Enemy::update(Object obj){
	/*�e�p�����[�^���X�V����*/
	frameCnt++;										//�t���[���J�E���g�̍X�V
	/*�A�j���[�V��������*/
	if(frameCnt % animeWait == 0){
		animeCnt++;
		if(animeCnt >= animeMax){
			animeCnt = 0;
		}
	}
	
	/*�G�@�̈ʒu���X�V*/
	pos.x += move.x;
	pos.y += move.y;
}

/*�J�E���g�A�b�v��*/
void Friend::addKaihi(int kaihi){
	Friend::kaihi += kaihi;
	if(Friend::kaihi > 100){
		Friend::kaihi = 100;
	}else if(Friend::kaihi < 0){
		Friend::kaihi = 0;
	}
}