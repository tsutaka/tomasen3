#ifndef INCLUDED_LOCALCOMMOM_HPP
#define INCLUDED_LOCALCOMMOM_HPP

#include "common.hpp"
/*���̃Q�[�����ʂȐ錾*/

/*�y��ID*/
extern int musicBGM_5;
extern int musicShot;
extern int musicEnemyDown;
extern int musicFriendHit;

/***�񋓌^�̐錾***/
/*�y��ڑ����*/
enum jointOK {jointNG = -1, jointEmp, jointUpExist, jointDownExist};
/*�����ڑ����*/
enum weaponOK {weaponNG = -1, weaponEmp, weaponExist};
/*�y��ڑ��ʒu*/
enum jointIndex {upJoint, rightJoint, downJoint, leftJoint, jointIndexEnd};
/*�����ڑ��ʒu*/
enum weaponIndex {mainWeapon, subWeapon, weaponIndexEnd};

/***�\���̐錾***/
struct TellUpBox{
	int hp;
	int maxHp;
	int energy;
	int maxEnergy;
	int chargeEnergy;
	int man;
	int requireMan;
	int maxMan;
	int fire;
	int burnFire;
	int maxFire;
	int pertsANum;
	int pertsALost;
	int pertsBNum;
	int pertsBLost;
};

/*�Œ�p�����[�^*/
extern const int startMode;		//�������
extern const int startStage;	//�����X�e�[�W
extern const int startPosX;		//�������@X���W
extern const int startPosY;		//�������@Y���W
extern const double moveAmount;	//�����x�i�P�t���[�����j
extern const int wideArea;		//��ʊO�̈�̍L��

#endif//INCLUDED_LOCALCOMMOM_HPP