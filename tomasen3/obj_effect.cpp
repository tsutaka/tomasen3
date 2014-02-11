#include "obj_effect.hpp"

#include "localcommon.hpp"

/*�O���[�o�����\�[�X��`*/
EffectVsptr effectList;				//�G�t�F�N�g���X�g
void effectFactory(EffectSptr effect){
		effectList.push_back( effect );							//���X�g�ɃI�u�W�F�N�g�ǉ�
}
void effectFactory(EffectSptr effect, Vec2 pos, Vec2 targetPos){
		effectList.push_back( effect );							//���X�g�ɃI�u�W�F�N�g�ǉ�
		EffectVsptr::iterator it = effectList.end() - 1;		//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(pos);										//�G�t�F�N�g���w��ʒu�Ɉړ�
		(*it)->setTargetPos(targetPos);							//�G�t�F�N�g�ڕW�ʒu���w��
}

Effect::Effect(){
	hp = 1;						//�ϋv�x
	pos = Vec2(0.0, 0.0);		//�ʒu
	targetPos = Vec2(0.0, 0.0);	//�ʒu
	dis = 0.0;					//�ړ���
	dir = 0.0;					//�p�x
	frameCnt = 0;				//������̌o�߃t���[����
	animeCnt = 0;				//���݂̃A�j���t���[��
	updateCheck = 0;			//�X�V��
	outputW = 1;			//�o�͕�
	outputH = 1;			//�o�͍�
}

void Effect::update(Object obj){
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
	/*�I�u�W�F�N�g�ړ�*/
	pos.x += (targetPos.x - pos.x) / 50;
	pos.y += (targetPos.y - pos.y) / 50;

	/*�J�E���g�_�E��*/
	timeOfLife--;
	if(timeOfLife < 0) timeOfLife = 0;
}

Explosion::Explosion(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 32;			//�摜x���W
	imageY = 18;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 2;			//�o�͕�
	outputH = 2;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 1;				//�T�C�Y
	timeOfLife = 50;		//�����t���[��
	pos = Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);					//�����ʒu
	targetPos = Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2+100);		//�ڕW�ʒu
}

TitleTo::TitleTo(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 0;				//�摜x���W
	imageY = 18;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_WIDTH+wideArea/2, 10*tipSize);					//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, 10*tipSize);		//�ڕW�ʒu
}

TitleMa::TitleMa(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 8;				//�摜x���W
	imageY = 18;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, SCREEN_HEIGHT+wideArea/2);	//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, 10*tipSize);			//�ڕW�ʒu
}

TitleSe::TitleSe(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 16;			//�摜x���W
	imageY = 18;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(-wideArea/2, 14*tipSize);							//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

TitleNi::TitleNi(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 24;			//�摜x���W
	imageY = 18;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, -wideArea/2);		//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}


DarkR::DarkR(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 0;				//�摜x���W
	imageY = 22;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, SCREEN_HEIGHT+wideArea/2);	//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, 10*tipSize);			//�ڕW�ʒu
}

LightR::LightR(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 8;				//�摜x���W
	imageY = 22;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_WIDTH+wideArea/2, SCREEN_HEIGHT+wideArea/2);		//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+0*tipSize*4, 10*tipSize);		//�ڕW�ʒu
}

DarkY::DarkY(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 0;				//�摜x���W
	imageY = 20;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(-wideArea/2, SCREEN_HEIGHT+wideArea/2);				//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

LightY::LightY(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 8;				//�摜x���W
	imageY = 20;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_WIDTH+wideArea/2, -wideArea/2);				//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+1*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

DarkG::DarkG(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 16;			//�摜x���W
	imageY = 22;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(-wideArea/2, -wideArea/2);							//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

LightG::LightG(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 24;			//�摜x���W
	imageY = 22;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_WIDTH+wideArea/2, 10*tipSize);							//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

DarkB::DarkB(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 16;			//�摜x���W
	imageY = 20;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_INDENT+72.0+2*tipSize*4, -wideArea/2);		//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

LightB::LightB(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 24;			//�摜x���W
	imageY = 20;			//�摜y���W
	imageW = 2;				//�摜��
	imageH = 2;				//�摜��
	outputW = 4;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(-wideArea/2, 10*tipSize);							//�����ʒu
	targetPos = Vec2(SCREEN_INDENT+72.0+3*tipSize*4, 10*tipSize);	//�ڕW�ʒu
}

PushSpace::PushSpace(){
	maxHp = 1;				//�ő�ϋv�x
	imageX = 0;				//�摜x���W
	imageY = 24;			//�摜y���W
	imageW = 8;				//�摜��
	imageH = 2;				//�摜��
	outputW = 16;			//�o�͕�
	outputH = 4;			//�o�͍�
	animeMax = 4;			//�A�j���[�V��������
	animeWait = 6;			//�A�j���[�V�����P���̃t���[����
	size = 2;				//�T�C�Y
	timeOfLife = 3000;		//�����t���[��
	pos = Vec2(SCREEN_WIDTH/2-4*tipSize*2, SCREEN_HEIGHT+wideArea/2);	//�����ʒu
	targetPos = Vec2(SCREEN_WIDTH/2-4*tipSize*2, 20*tipSize);	//�ڕW�ʒu
}