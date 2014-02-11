#ifndef INCLUDED_OBJ_BULLET_HPP
#define INCLUDED_OBJ_BULLET_HPP

#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: を std:: と書けるように
namespace std {
	using namespace tr1; 
}

#include "common.hpp"
#include "object.hpp"

class Bullet : public Object{
private:
	int fire;				//火力

public:
	/*コンストラクタ*/
	Bullet();
	/*更新関数*/
	virtual void update(Object obj) = 0;

	/*getter関数*/
	int getFire(){return fire;}
};

class FriendBullet : public Bullet{
public:
	/*更新関数*/
	void update(Object obj);
};
/*グローバルリソース宣言*/
typedef weak_ptr< FriendBullet > FriendBulletWptr;			//自弾のweakポインタ
typedef shared_ptr< FriendBullet > FriendBulletSptr;		//自弾のsharedポインタ
typedef vector< FriendBulletSptr > FriendBulletVsptr;		//自弾のsharedポインタの配列
extern FriendBulletVsptr friendBulletList;					//自弾リスト
void friendBulletFactory(FriendBulletSptr friendBullet, Vec2 pos);	//自弾ファクトリ関数


class NormalBullet : public FriendBullet{
public:
	/*コンストラクタ*/
	NormalBullet();	
};



class EnemyBullet : public Bullet{
public:
	int phase;

	/*更新関数*/
	void update(Object obj);
	/*行動関数*/
	virtual void action(const Object &obj) = 0;
};
/*グローバルリソース宣言*/
typedef weak_ptr< EnemyBullet > EnemyBulletWptr;		//敵弾のweakポインタ
typedef shared_ptr< EnemyBullet > EnemyBulletSptr;		//敵弾のsharedポインタ
typedef vector< EnemyBulletSptr > EnemyBulletVsptr;		//敵弾のsharedポインタの配列
extern EnemyBulletVsptr enemyBulletList;				//敵弾リスト

class WeakBullet : public EnemyBullet{
public:
	/*コンストラクタ*/
	WeakBullet();
	/*行動関数*/
	void action(const Object &obj);
};
class WideBullet : public EnemyBullet{
public:
	/*コンストラクタ*/
	WideBullet();
	/*行動関数*/
	void action(const Object &obj);
};
class SprinklerBullet : public EnemyBullet{
public:
	/*コンストラクタ*/
	SprinklerBullet();
	/*行動関数*/
	void action(const Object &obj);
};
class GreenBullet : public EnemyBullet{
public:
	/*コンストラクタ*/
	GreenBullet();
	/*行動関数*/
	void action(const Object &obj);
};

#endif//INCLUDED_OBJ_BULLET_HPP