#ifndef INCLUDED_OBJ_EFFECT_HPP
#define INCLUDED_OBJ_EFFECT_HPP

#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: �� std:: �Ə�����悤��
namespace std {
	using namespace tr1; 
}

#include "common.hpp"
#include "object.hpp"

class Effect : public Object{
protected:
	int timeOfLife;		//�����t���[��
	Vec2 targetPos;		//�ړ��ړI���W

public:
	/*�R���X�g���N�^*/
	Effect();
	/*getter�֐�*/
	int getTimeOfLife(){return timeOfLife;}
	Vec2 getTargetPos(){return targetPos;}
	/*setter�֐�*/
	void setTimeOfLife(int timeOfLife){Effect::timeOfLife = timeOfLife;}
	void setTargetPos(Vec2 targetPos){Effect::targetPos = targetPos;}
	/*�X�V�֐�*/
	void update(Object obj);
};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< Effect > EffectWptr;		//�G�t�F�N�g��weak�|�C���^
typedef shared_ptr< Effect > EffectSptr;	//�G�t�F�N�g��shared�|�C���^
typedef vector< EffectSptr > EffectVsptr;	//�G�t�F�N�g��shared�|�C���^�̔z��
extern EffectVsptr effectList;				//�G�t�F�N�g���X�g
void effectFactory(EffectSptr effectList);	//�G�t�F�N�g�t�@�N�g���֐�
void effectFactory(EffectSptr effectList, Vec2 pos, Vec2 targetPos);	//�G�t�F�N�g�t�@�N�g���֐�

class Explosion : public Effect {
public:
	Explosion();
};
class TitleTo : public Effect {
public:
	TitleTo();
};
class TitleMa : public Effect {
public:
	TitleMa();
};
class TitleSe : public Effect {
public:
	TitleSe();
};
class TitleNi : public Effect {
public:
	TitleNi();
};

class DarkR : public Effect {
public:
	DarkR();
};
class LightR : public Effect {
public:
	LightR();
};
class DarkY : public Effect {
public:
	DarkY();
};
class LightY : public Effect {
public:
	LightY();
};
class DarkG : public Effect {
public:
	DarkG();
};
class LightG : public Effect {
public:
	LightG();
};
class DarkB : public Effect {
public:
	DarkB();
};
class LightB : public Effect {
public:
	LightB();
};
class PushSpace : public Effect {
public:
	PushSpace();
};

#endif//INCLUDED_OBJ_EFFECT_HPP