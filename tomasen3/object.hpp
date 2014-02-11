#ifndef INCLUDED_OBJECT_HPP
#define INCLUDED_OBJECT_HPP


#include "common.hpp"

/*�I�u�W�F�N�g�N���X*/
class Object {
protected:
	/*�ϓ��p�����[�^*/
	int hp;					//�ϋv�x
	Vec2 pos;				//�ʒu
	Vec2 move;				//�ړ���
	double dis;				//�ړ���
	double dir;				//�p�x
	long frameCnt;			//������̌o�߃t���[����
	int animeCnt;			//���݂̃A�j���t���[��
	string name;			//����
	bool updateCheck;		//�X�V��


	/*�Œ�p�����[�^const static */
	int maxHp;				//�ő�ϋv�x
	int imageX;				//�摜x���W
	int imageY;				//�摜y���W
	int imageW;				//�摜��
	int imageH;				//�摜��
	int outputW;			//�o�͕�
	int outputH;			//�o�͍�
	int animeMax;			//�A�j���[�V��������
	int animeWait;			//�A�j���[�V�����P���̃t���[����
	int size;				//�����蔻�蒼�a

	

public:
	/*getter�֐�*/
	int getHp(){ return hp; }
	Vec2 getPos(){ return pos; }
	Vec2 getMove(){ return move; }
	double getDis(){ return dis; }
	double getDir(){ return dir; }
	string getName(){ return name; }
	long getAnimeCnt(){ return animeCnt; }
	long getFrameCnt(){ return frameCnt; }
	int getMaxHp(){ return maxHp; }
	int getImageX(){ return imageX + animeCnt * imageW; }
	int getImageY(){ return imageY; }
	int getImageW(){ return imageW; }
	int getImageH(){ return imageH; }
	int getOutputW(){ return outputW; }
	int getOutputH(){ return outputH; }
	int getSize(){ return size; }

	/*setter�֐�*/
	void setHp(int hp){ Object::hp = hp; }
	void setPos(Vec2 pos){ Object::pos = pos; }
	void setMove(Vec2 move){ Object::move = move; }
	void setDis(double dis){ Object::dis = dis; }
	void setDir(double dir){ Object::dir = dir; }
	void setName(string name){ Object::name = name; }
	void setFrameCnt(int frameCnt){ Object::frameCnt = frameCnt; }

	/*�X�V�֐��i���z���\�b�h�j*/
	virtual void update(Object obj);

	/*�_���[�W�֐�*/
	void damageHp(int);
private:


};

#endif//INCLUDED_OBJECT_HPP