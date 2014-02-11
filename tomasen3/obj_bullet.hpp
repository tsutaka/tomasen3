#ifndef INCLUDED_OBJ_BULLET_HPP
#define INCLUDED_OBJ_BULLET_HPP

#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: �� std:: �Ə�����悤��
namespace std {
	using namespace tr1; 
}

#include "common.hpp"
#include "object.hpp"

class Bullet : public Object{
private:
	int fire;				//�Η�

public:
	/*�R���X�g���N�^*/
	Bullet();
	/*�X�V�֐�*/
	virtual void update(Object obj) = 0;

	/*getter�֐�*/
	int getFire(){return fire;}
};

class FriendBullet : public Bullet{
public:
	/*�X�V�֐�*/
	void update(Object obj);
};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< FriendBullet > FriendBulletWptr;			//���e��weak�|�C���^
typedef shared_ptr< FriendBullet > FriendBulletSptr;		//���e��shared�|�C���^
typedef vector< FriendBulletSptr > FriendBulletVsptr;		//���e��shared�|�C���^�̔z��
extern FriendBulletVsptr friendBulletList;					//���e���X�g
void friendBulletFactory(FriendBulletSptr friendBullet, Vec2 pos);	//���e�t�@�N�g���֐�


class NormalBullet : public FriendBullet{
public:
	/*�R���X�g���N�^*/
	NormalBullet();	
};



class EnemyBullet : public Bullet{
public:
	int phase;

	/*�X�V�֐�*/
	void update(Object obj);
	/*�s���֐�*/
	virtual void action(const Object &obj) = 0;
};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< EnemyBullet > EnemyBulletWptr;		//�G�e��weak�|�C���^
typedef shared_ptr< EnemyBullet > EnemyBulletSptr;		//�G�e��shared�|�C���^
typedef vector< EnemyBulletSptr > EnemyBulletVsptr;		//�G�e��shared�|�C���^�̔z��
extern EnemyBulletVsptr enemyBulletList;				//�G�e���X�g

class WeakBullet : public EnemyBullet{
public:
	/*�R���X�g���N�^*/
	WeakBullet();
	/*�s���֐�*/
	void action(const Object &obj);
};
class WideBullet : public EnemyBullet{
public:
	/*�R���X�g���N�^*/
	WideBullet();
	/*�s���֐�*/
	void action(const Object &obj);
};
class SprinklerBullet : public EnemyBullet{
public:
	/*�R���X�g���N�^*/
	SprinklerBullet();
	/*�s���֐�*/
	void action(const Object &obj);
};
class GreenBullet : public EnemyBullet{
public:
	/*�R���X�g���N�^*/
	GreenBullet();
	/*�s���֐�*/
	void action(const Object &obj);
};

#endif//INCLUDED_OBJ_BULLET_HPP