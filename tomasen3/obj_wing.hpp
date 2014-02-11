#ifndef INCLUDED_OBJ_WING_HPP
#define INCLUDED_OBJ_WING_HPP

#include <cmath>		//math
#include <vector>		//vector
#include <memory>		//shared_ptr

#include "common.hpp"
#include "object.hpp"

// std::tr1:: �� std:: �Ə�����悤��
namespace std {
	using namespace tr1; 
}

/*�E�B���O�N���X�i�@�́j*/
class Wing : public Object{
protected:
	/*�Œ�p�����[�^*/
	int shotInterval;	//�ˌ��Ԋu
	
public:
	/*�X�V�֐�*/
	virtual void update(Object obj) = 0;

};

/*���@�N���X*/
class Friend : public Wing{
protected:
	/*�ϓ��p�����[�^*/
	int energy;			//�G�l���M�[
	int man;			//�l��
	int fire;			//�΍Љӏ���
	int chargeEnergy;	//�񕜃G�l���M�[
	int requireMan;		//�K�v�l��
	int burnFire;		//���Βl

	int startHp;		//�X�e�[�W����HP
	int startEnergy;	//�X�e�[�W����EN
	int startMan;		//�X�e�[�W�����l
	int startFire;		//�X�e�[�W������

	int kaihi;			//���p�p�����[�^(0-100)

	/*�Œ�p�����[�^*/
	int maxEnergy;	//�ő�G�l���M�[
	int maxMan;		//�K�v�l��
	int maxFire;	//���Ήΐ�

	int partsANum;	//�����_�p�[�cA��
	int partsALost;	//�ݐϑr���p�[�cA��
	int partsBNum;	//�����_�p�[�cB��
	int partsBLost;	//�ݐϑr���p�[�cB��

public:
	/*�X�V�֐�*/
	void update(Object obj);
	/*getter�֐�*/
	int getStartHp(){return startHp;}
	int getEnergy(){return energy;}
	int getMaxEnergy(){return maxEnergy;}
	int getChargeEnergy(){return chargeEnergy;}
	int getStartEnergy(){return startEnergy;}
	int getMan(){return man;}
	int getRequireMan(){return requireMan;}
	int getMaxMan(){return maxMan;}
	int getStartMan(){return startMan;}
	int getFire(){return fire;}
	int getBurnFire(){return burnFire;}
	int getMaxFire(){return maxFire;}
	int getStartFire(){return startFire;}
	int getPartsANum(){return partsANum;}
	int getPartsALost(){return partsALost;}
	int getPartsBNum(){return partsBNum;}
	int getPartsBLost(){return partsBLost;}
	int getKaihi(){return kaihi;}

	/*setter�֐�*/
	void setKaihi(int kaihi){Friend::kaihi = kaihi;}

	/*�J�E���g�A�b�v��*/
	void addKaihi(int kaihi);

};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< Friend > FriendWptr;		//���@��weak�|�C���^
typedef shared_ptr< Friend > FriendSptr;	//���@��shared�|�C���^
typedef vector< FriendSptr > FriendVsptr;	//���@��shared�|�C���^�̔z��
extern FriendVsptr friendList;				//���@���X�g
FriendWptr friendFactory(FriendSptr friendw, Vec2 pos);	//���@�t�@�N�g���֐�

/*�G�@�N���X*/
class Enemy : public Wing{//�����蔻��C���^�t�F�[�X������
protected:
	int pattern;		//�s���p�^�[��
	Vec2 targetPos;		//�ړ��ړI���W
	int phase;			//�s���t�F�[�Y
	int canShot;		//�ˌ�����
public:
	/*�R���X�g���N�^*/
	Enemy();
	/*�X�V�֐�*/
	void update(Object obj);
	virtual void action(Object obj) = 0;

	/*setter�֐�*/
	void setPattern(int pattern){
		Enemy::pattern = pattern;
	}
	void setTargetPos(Vec2 targetPos){
		Enemy::targetPos = targetPos;
	}
};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< Enemy > EnemyWptr;		//�G�@��weak�|�C���^
typedef shared_ptr< Enemy > EnemySptr;		//�G�@��shared�|�C���^
typedef vector< EnemySptr > EnemyVsptr;		//�G�@��shared�|�C���^�̔z��
extern EnemyVsptr enemyList;				//�G�@���X�g
void enemyFactory(EnemySptr enemy, Vec2 pos, int pattern);//�G�@�t�@�N�g���֐�


#endif//INCLUDED_OBJ_WING_HPP