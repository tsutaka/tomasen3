#include "obj_print.hpp"


/*�O���[�o�����\�[�X��`*/
BarVsptr barList;					//�o�[���X�g
BarWptr barFactory(BarSptr bar){
		barList.push_back( bar );							//���X�g�ɃI�u�W�F�N�g�ǉ�
		BarVsptr::iterator it = barList.end() - 1;	//���O�̃I�u�W�F�N�g���Q��
		return (*it);
}
LabelVsptr labelList;				//���x�����X�g
LabelWptr labelFactory(LabelSptr label){
		labelList.push_back( label );							//���X�g�ɃI�u�W�F�N�g�ǉ�
		LabelVsptr::iterator it = labelList.end() - 1;	//���O�̃I�u�W�F�N�g���Q��
		return (*it);
}

Print::Print(){
	value = 0;						//���ݒl	//���邢�\��
	printValue = 0;					//�\���l
	maxValue = 0;					//�ő�l	//���Â��\��
	startValue = 0;					//�����l	//�o�[�̉E�[
	frameCnt = 0;					//������̌o�߃t���[����
	animeCnt = 0;					//���݂̃A�j���t���[��
	animeMax = 4;					//�A�j���[�V��������
	animeWait = 4;					//�A�j���[�V�����P���̃t���[����
	maxImageW = 1;					//�摜�Qx���W
	maxImageH = 1;					//�摜�Qy���W
	underImageW = 1;				//���n�摜��
	underImageH = 1;				//���n�摜��
	overImageW = 1;					//��g�摜��
	overImageH = 1;					//��g�摜��
	imageW = 1;						//�摜��
	imageH = 1;						//�摜��
	outputW = 1;			//�o�͕�
	outputH = 1;			//�o�͍�
}

void Bar::update(Object obj){
	/*���ݒl�̍X�V*/
	if(printValue > value){
		printValue--;
	}
	else if(printValue < value){
		printValue++;
	}
	/*�J�E���g�A�b�v*/
	frameCnt++;
	if(frameCnt > 50000) frameCnt = 0;
	if(frameCnt % animeWait == 0) animeCnt++;
	if(animeCnt >= animeMax) animeCnt = 0;
}

void Label::update(Object obj){
	/*���ݒl�̍X�V*/
	if(printValue - 10 > value){
		printValue -= 10;
	}
	else if(printValue + 10 < value){
		printValue += 10;
	}
}

HpBar::HpBar(){
	/*������*/
	pos = Vec2(40.0*tipSize, 5.0*tipSize);		//�ʒu
	name = "��";			//���O
	//�����l�ɂ��Ă͎��@�̃R���X�g���N�^�Őݒ�
	size = 10;				//�o�[�̕��i�����͂P�Œ�j
	imageX = 28;			//�摜x���W
	imageY = 16;			//�摜y���W
	maxImageX = 1;			//�摜�Qx���W
	maxImageY = 16;			//�摜�Qy���W
	underImageX = 24;		//���n�摜x���W
	underImageY = 17;		//���n�摜y���W
	overImageX = 24;		//��g�摜x���W
	overImageY = 16;		//��g�摜y���W
}

EnergyBar::EnergyBar(){
	/*������*/
	pos = Vec2(40.0*tipSize, 7.0*tipSize);		//�ʒu
	name = "�e";			//���O
	//�����l�ɂ��Ă͎��@�̃R���X�g���N�^�Őݒ�
	size = 10;				//�o�[�̕��i�����͂P�Œ�j
	imageX = 28;			//�摜x���W
	imageY = 17;			//�摜y���W
	maxImageX = 2;			//�摜�Qx���W
	maxImageY = 16;			//�摜�Qy���W
	underImageX = 24;		//���n�摜x���W
	underImageY = 17;		//���n�摜y���W
	overImageX = 24;		//��g�摜x���W
	overImageY = 16;		//��g�摜y���W
}
ManBar::ManBar(){
	/*������*/
	pos = Vec2(40.0*tipSize, 9.0*tipSize);		//�ʒu
	name = "�l";			//���O
	//�����l�ɂ��Ă͎��@�̃R���X�g���N�^�Őݒ�
	size = 10;				//�o�[�̕��i�����͂P�Œ�j
	imageX = 32;			//�摜x���W
	imageY = 17;			//�摜y���W
	maxImageX = 4;			//�摜�Qx���W
	maxImageY = 16;			//�摜�Qy���W
	underImageX = 24;		//���n�摜x���W
	underImageY = 17;		//���n�摜y���W
	overImageX = 24;		//��g�摜x���W
	overImageY = 16;		//��g�摜y���W
}
FireBar::FireBar(){
	/*������*/
	pos = Vec2(40.0*tipSize, 11.0*tipSize);		//�ʒu
	name = "��";			//���O
	//�����l�ɂ��Ă͎��@�̃R���X�g���N�^�Őݒ�
	size = 10;				//�o�[�̕��i�����͂P�Œ�j
	imageX = 32;			//�摜x���W
	imageY = 16;			//�摜y���W
	maxImageX = 3;			//�摜�Qx���W
	maxImageY = 16;			//�摜�Qy���W
	underImageX = 24;		//���n�摜x���W
	underImageY = 17;		//���n�摜y���W
	overImageX = 24;		//��g�摜x���W
	overImageY = 16;		//��g�摜y���W
}

GoldLabel::GoldLabel(){
	/*������*/
	pos = Vec2(38.0*tipSize, 28.0*tipSize);		//�ʒu
	name = "�f�n�k�c�@";			//���O
}
ScoreLabel::ScoreLabel(){
	/*������*/
	pos = Vec2(38.0*tipSize, 30.0*tipSize);		//�ʒu
	name = "�r�b�n�q�d";			//���O
}