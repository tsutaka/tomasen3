#ifndef INCLUDED_OBJ_PARTS_HPP
#define INCLUDED_OBJ_PARTS_HPP

#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: �� std:: �Ə�����悤��
namespace std {
	using namespace tr1; 
}

#include "common.hpp"
#include "localcommon.hpp"
#include "object.hpp"

class Parts : public Object{
protected:
	int energy;			//���݂̒e��
	int chargeEnergy;	//���e����e��
	int maxEnergy;		//�ő�̒e��
	int man;			//���݂̐l��
	int requireMan;		//�K�v�Ȑl��
	int maxMan;			//�ő�̐l��
	int fire;			//���݂̉ΐ�
	int burnFire;		//���΂���ΐ�
	int maxFire;		//�ő�̉ΐ�
	int kaihi;			//���l

public:
	/*�R���X�g���N�^*/
	Parts();
	/*getter�֐�*/
	int getEnergy(){return energy;}
	int getChargeEnergy(){return chargeEnergy;}
	int getMaxEnergy(){return maxEnergy;}
	int getMan(){return man;}
	int getRequireMan(){return requireMan;}
	int getMaxMan(){return maxMan;}
	int getFire(){return fire;}
	int getBurnFire(){return burnFire;}
	int getMaxFire(){return maxFire;}
	int getKaihi(){return kaihi;}
	/*getter�֐�*/
	void setKaihi(int kaihi){Parts::kaihi = kaihi;}
	/*add�֐�*/
	void addEnergy(int energy){Parts::energy += energy;}
	void addChargeEnergy(int chargeEnergy){Parts::chargeEnergy += chargeEnergy;}
	void addMaxEnergy(int maxEnergy){Parts::maxEnergy += maxEnergy;}
	void addMan(int man){Parts::man += man;}
	void addRequireMan(int requireMan){Parts::requireMan += requireMan;}
	void addMaxMan(int maxMan){Parts::maxMan += maxMan;}
	void addFire(int fire){Parts::fire += fire;}
	void addBurnFire(int burnFire){Parts::burnFire += burnFire;}
	void addMaxFire(int maxFire){Parts::maxFire += maxFire;}
	void addKaihi(int kaihi);

	/*�X�V�֐�*/
	virtual void update(Object obj) = 0;
	/*�񍐊֐�*/
	void tellUp(TellUpBox &box);
	virtual void subTellUp(TellUpBox &box) = 0;

	/*�E���֐�*/
	void killMan(int damage);
};


class PartsA : public Parts{
private:

public:
	/*�R���X�g���N�^*/
	PartsA();
	/*�X�V�֐�*/
	void update(Object obj);
	/*�s���֐��i�e�����ŗL�����j*/
	virtual void action();
	/*�񍐊֐�*/
	virtual void subTellUp(TellUpBox &box);
};

/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< PartsA > PartsAWptr;			//�p�[�c��weak�|�C���^
typedef shared_ptr< PartsA > PartsASptr;		//�p�[�c��shared�|�C���^
typedef vector< PartsASptr > PartsAVsptr;		//�p�[�c��shared�|�C���^�̔z��
extern PartsAVsptr partsAList;					//�p�[�c���X�g
PartsAWptr partsAFactory(PartsASptr partsAList);	//�p�[�c�t�@�N�g���֐�

class PartsB : public Parts{
protected:
	typedef weak_ptr< PartsA > PartsAWptr;		//�p�[�c��weak�|�C���^
	typedef shared_ptr< PartsA > PartsASptr;	//�p�[�c��shared�|�C���^
	typedef vector< PartsASptr > PartsAVsptr;	//�p�[�c��shared�|�C���^�̔z��
	weaponOK weapon[2];							//�����L��
	int weaponPosX[2];							//����X���W�i�e����̑��΁j
	int weaponPosY[2];							//����Y���W�i�e����̑��΁j
	PartsAWptr partsA0;							//�����I�u�W�F�N�g
	PartsAWptr partsA1;							//�����I�u�W�F�N�g

	typedef weak_ptr< PartsB > PartsBWptr;		//�p�[�c��weak�|�C���^
	typedef shared_ptr< PartsB > PartsBSptr;	//�p�[�c��shared�|�C���^
	typedef vector< PartsBSptr > PartsBVsptr;	//�p�[�c��shared�|�C���^�̔z��
	jointOK joint[4];							//�W���C���g�L��
	int jointPosX[4];							//�W���C���gX���W�i�e����̑��΁j
	int jointPosY[4];							//�W���C���gY���W�i�e����̑��΁j
	PartsBWptr partsB0;							//�W���C���g�I�u�W�F�N�g
	PartsBWptr partsB1;							//�W���C���g�I�u�W�F�N�g
	PartsBWptr partsB2;							//�W���C���g�I�u�W�F�N�g
	PartsBWptr partsB3;							//�W���C���g�I�u�W�F�N�g
	//�W���C���g

public:
	/*�R���X�g���N�^*/
	PartsB();
	/*setter�֐�*/
	void setPartsA(weaponIndex pos, PartsAWptr partsA);
	void setPartsB(jointIndex pos, PartsBSptr partsB);
	void setWeapon(weaponIndex index, weaponOK val);
	void setJoint(jointIndex index, jointOK val);
	/*getter�֐�*/
	PartsASptr getPartsA(weaponIndex index);
	PartsBSptr getPartsB(jointIndex index);
	/*�X�V�֐�*/
	void update(Object obj);
	/*�񍐊֐�*/
	void subTellUp(TellUpBox &box);
};

/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< PartsB > PartsBWptr;		//�p�[�c��weak�|�C���^
typedef shared_ptr< PartsB > PartsBSptr;	//�p�[�c��shared�|�C���^
typedef vector< PartsBSptr > PartsBVsptr;	//�p�[�c��shared�|�C���^�̔z��
extern PartsBVsptr partsBList;				//�p�[�c���X�g
PartsBWptr partsBFactory(PartsBSptr partsBList);	//�p�[�c�t�@�N�g���֐�



#endif//INCLUDED_OBJ_PARTS_HPP